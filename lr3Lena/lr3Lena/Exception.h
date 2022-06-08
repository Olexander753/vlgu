#pragma once
#include <iostream>
#include <exception>
#include <string>

using namespace std;


enum errors {
	FILE_CANNOT_OPEN,
	PRINT_ERROR,	
	FILE_IS_EMPTY,
	HAVE_NOT_BOOK
};

//класс ошибок
class Exception {
public:
	Exception(errors reason, string message) : errorReason(reason), errorMessage(message) {};
	~Exception() {};
	void printError() {
		switch (errorReason) {
		case FILE_IS_EMPTY:
		case PRINT_ERROR:
		case HAVE_NOT_BOOK:
		case FILE_CANNOT_OPEN: {
			cerr << errorMessage << endl;
			break;
		}
		}
	}

private:
	errors errorReason;
	string errorMessage;
};