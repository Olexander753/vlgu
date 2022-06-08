// ChatServer.cpp
#include "Server.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>

int main(int argc, char** args)
{
	/*Поддержка русского. Теперь работаем только с wchar_t*/
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	/*Нам нужны все аргументы*/
	if (argc < 4) 
	{
		std::wcout << "Enter port,ip and max pool\n";
		return EXIT_FAILURE;
	}

	/*Стартр сервака*/
	Server server(get_utf16(args[2]), get_utf16(args[1]), std::wcout, std::stoi(args[3]));
	server.start();
}