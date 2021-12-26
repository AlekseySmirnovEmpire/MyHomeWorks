#pragma once

#include <iostream>

enum eCommands {
	GET = 1,
	POST,
	PUT,
	eDELETE,
	PATCH,
	EXIT
};

void showMenu();
void doRequest(const int& reqNumber);