#include "Server.h"
#include <iostream>

/*Инициализация сокета для прослушивания*/
int Server::initWSAServer() {
	//Инициализация WSA, 
	//перед началом работы с сокетами необходимо провести 
	//инициализацию Windows Sockets API.
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (result != 0) {
		log << "WSAStartup failed: " << result << "\n";
		return result;
	}

	//Подготовка данных для создания сокета
	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));
	
	//AF_INET указывает, что используется четвертая версия IP протокола.
	//SOCK_STREAM используется для определения потока сокета.
	//IPPROTO_TCP используется для определения TCP протокола.
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	//Функция getaddrinfo используется 
	//для определения значений в структуре sockaddr.
	result = getaddrinfo(get_utf8(ip).c_str(), get_utf8(port).c_str(), &hints, &addr);

	if (result != 0) {
		log << "getaddrinfo failed: " << result << "\n";
		WSACleanup();
		return EXIT_FAILURE;
	}

	//Создание сокета
	//Для создания сокета вызываем функцию socket с данными,
	//подготовленными в предыдущем шаге, если создание пройдет успешно,
	//то функция вернет дескриптор сокета.
	listen_socket = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	if (listen_socket == INVALID_SOCKET) {
		log << "Error at socket: " << WSAGetLastError() << "\n";
		close();
		return EXIT_FAILURE;
	}

	//Связывание сокета с сетвевым адресом
	//После того, как мы создали сокет, 
	//его необходимо связать с конкретным сетевым адресом.
	//Для этого надо вызвать функцию bind 
	//и передать ей в качестве аргументов дескриптор сокета и данные 
	//из структуры sockaddr.
	result = bind(listen_socket, addr->ai_addr, (int)addr->ai_addrlen);

	if (result == SOCKET_ERROR) {
		log << "bind failed with error: " << WSAGetLastError() << "\n";
		close();
		return EXIT_FAILURE;
	}

	//Прослушивание подключений
	//Для прослушивания входящих подключений надо вызывать функцию listen, 
	//в аргументах передать созданный сокет и
	//максимальную длину очереди клиентов ожидающих подключения.
	if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
		log << "listen failed with error: " << WSAGetLastError() << "\n";
		close();
		return EXIT_FAILURE;
	}

	return 0;
}

/*Цикл сервера*/
int Server::serverLoop() {
	/*Если работает*/
	while (isWork) {
		/*Получем клиента*/
		int client_socket = accept(listen_socket, NULL, NULL);
		if (client_socket == INVALID_SOCKET) {
			log << "accept failed: " << WSAGetLastError() << "\n";
			close();
			return EXIT_FAILURE;
		}

		/*Если есть место, то запрашиваем имя, если нет, то просто отвечае кодом -1*/
		if (clients.size() >= max_pool) {
			std::string msg = get_utf8(L"Too many users");
			log << "Too many users\n";
			int code = ntohl(-1);
			send(client_socket, (char*)&code, sizeof(int), 0);
			closesocket(client_socket);
		}
		else {
			try {
				int len = 0;
				recv(client_socket, (char*)&len, sizeof(int), 0);
				len = ntohl(len);
				char* name = new char[len + 1]{ 0 };
				recv(client_socket, name, len, 0);

				auto userName = get_utf16(std::string(name));
				userName = userName.substr(0, userName.length() - 1);

				log << L"New user: " << userName << std::endl;
				Client* newCl = new Client(client_socket, *this, userName, log);
				newCl->start();
				{
					lkm lg(m);
					clients.push_back(newCl);
				}

				std::string msg = get_utf8(userName + L" log in");
				broadcastSend((char*)msg.data(), msg.length());
			}
			catch (...) {
				log << "Client error connect\n";
			}
		}

		Sleep(50);
	}

	return 0;
}

/*Чтение команад - происходит асинхронно*/
void Server::readServerCommands() {

	std::wstring cmd;

	while (isWork) {
		std::getline(std::wcin, cmd);
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), std::tolower);

		if (cmd == L"quit") {
			isWork = false;
		}
	}

	log << L"Server was stopped" << std::endl;
	exit(0);
}

Server::Server(std::wstring port, std::wstring ip, std::wostream& log, int max_pool)
	:port(port), ip(ip), log(log), listen_socket(SOCKET_ERROR), max_pool(max_pool) {
}

/*Запуск сервака*/
int Server::start() {

	auto res = initWSAServer();
	isWork = true;
	std::thread(&Server::readServerCommands, this).detach();
	log << "Success start chat server " << ip << ":" << port << std::endl;
	serverLoop();
	close();
	log << "Server was stopped" << std::endl;
	return 0;
}

/*Закрытие сервака*/
void Server::close() {
	closesocket(listen_socket);
	freeaddrinfo(addr);
	WSACleanup();
}

/*Широковещательное сообщение*/
void Server::broadcastSend(char* msg, int len) {
	lkm lg(m);

	for (auto u : clients) {
		auto tmplen = htonl(len);
		send(u->getSocket(), (char*)&tmplen, sizeof(int), 0);
		send(u->getSocket(), msg, len, 0);
	}
}

/*Закрытие клиента*/
void Server::closeClient(Client* cl) {
	auto msg = cl->getName() + L" logout";
	log << msg << std::endl;
	std::string msgStd = get_utf8(msg);
	broadcastSend((char*)msgStd.data(), msgStd.length());

	lkm lg(m);
	auto iter = std::find(clients.begin(), clients.end(), cl);
	if (iter != clients.end())
		clients.erase(iter);
}

/*Конвертации*/

std::string get_utf8(const std::wstring& wstr) {
	if (wstr.empty()) return std::string();
	int sz = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], -1, 0, 0, 0, 0);
	std::string res(sz, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], -1, &res[0], sz, 0, 0);
	return res;
}

std::wstring get_utf16(const std::string& str) {
	if (str.empty()) return std::wstring();
	int sz = MultiByteToWideChar(CP_UTF8, 0, &str[0], -1, 0, 0);
	std::wstring res(sz, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], -1, &res[0], sz);
	return res;
}

