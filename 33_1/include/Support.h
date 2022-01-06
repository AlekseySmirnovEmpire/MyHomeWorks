#pragma once
#include <exception>

#define forever() while(true)

enum eCommands
{
    ADD_IN_CART = 1,
    REMOVE_FROM_CART,
    EXIT
};

void clear();
void wait();
void showMenu();

class BadArticleError : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "BAD ARTICLE";
    }
};

class BadAmountError : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "BAD AMOUNT";
    }
};

class NoProductInMarket : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "NO PRODUCT ANY MORE";
    }
};