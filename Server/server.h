#pragma once
#include "Client.h"

#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <algorithm>
#include <mutex>

class Client;

/*Конвертирование данных из wstring <-> string*/
std::string get_utf8(const std::wstring& wstr);
std::wstring get_utf16(const std::string& str);

/*Класс сервака*/
class Server
{
	/*Мьютекс для блокирования потоков (дает доступ для списка пользователей)*/
	std::mutex m;
	/*Сокращение*/
	typedef std::lock_guard<std::mutex> lkm;

private:
	/*Сокет и настройка*/
	SOCKET listen_socket;
	addrinfo* addr{ nullptr };

	/*IP и порт*/
	std::wstring port, ip;
	/*Максимальное количество пользователей*/
	unsigned max_pool{ 0 };
	/*Вывод*/
	std::wostream& log;
	/*Находится ли в работе сервак*/
	std::atomic<bool> isWork{ false };
	/*Инициализация*/
	int initWSAServer();
	/*Цикл сервера*/
	int serverLoop();
	/*Чтение команД*/
	void readServerCommands();
	/*Список клиентов*/
	std::vector<Client*> clients;
public:
	Server(std::wstring port, std::wstring ip, std::wostream& wlog, int max_pool);
	/*Запуск*/
	int start();
	/*Закрытие*/
	void close();
	/*Широковещательное сообщение*/
	void broadcastSend(char* msg, int len);
	/*В работе ли?*/
	inline bool getIsWork() {
		return isWork;
	}
	/*Закрыть клиент*/
	void closeClient(Client* cl);
};
