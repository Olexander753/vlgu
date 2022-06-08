#pragma once
#define _WIN32_WINNT 0x501
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#include "Server.h"
#include <string>

class Server;

/*Класс клиента*/
class Client
{
private:
	/*Сокет*/
	SOCKET socket;
	/*Ссылка на сервер*/
	Server& server;
	/*Имя пользователя*/
	std::wstring name;
	/*Лог вывода*/
	std::wostream& log;
	/*Пользовательский цикл*/
	void clientLoop();
	/*Окончание работы пользовательского цикла*/
	void stop();
public:

	Client(SOCKET socker, Server& server, std::wstring name, std::wostream& log);
	/*Запуск*/
	void start();

	/*Получение сокета и имени*/

	inline SOCKET getSocket() {
		return socket;
	}
	inline std::wstring getName() {
		return name;
	}
};
