#pragma once

#define forever() while(true)

enum eCommands
{
    ADD = 1,
    REMOVE,
    PRINT,
    FIND,
    EXIT
};

void showMenu();

void clear();