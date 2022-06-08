#include "Client.h"
#include <iostream>

/*Цикл работы клиента*/
void Client::clientLoop() 
{
	/*Пока сервак работает*/
	while (server.getIsWork()) 
	{

		/*Получем длину сообщения, сообщение и пересылаем всем*/
		int len = 0;
		recv(socket, (char*)&len, sizeof(int), 0);
		if (socket == SOCKET_ERROR || socket == INVALID_SOCKET || len <= 0)
			break;
		len = ntohl(len);
		auto data = new char[len + 1]{ 0 };
		recv(socket, data, len, 0);
		if (socket == SOCKET_ERROR || socket == INVALID_SOCKET || strlen(data) == 0)
			break;

		log << get_utf16(std::string(data)) << std::endl;
		server.broadcastSend(data, len);

		delete[] data;
	}


	stop();
}

/*Остановка*/
void Client::stop() 
{
	server.closeClient(this);
	if (socket != SOCKET_ERROR)
	{
		closesocket(socket);
	}
}

Client::Client(SOCKET socker, Server& server, std::wstring name, std::wostream& log)
	:socket(socker), server(server), name(name), log(log) {}

/*Запуск клиента - просто стартанем его метод в другом потоке*/
void Client::start() 
{
	std::thread(&Client::clientLoop, this).detach();
}
