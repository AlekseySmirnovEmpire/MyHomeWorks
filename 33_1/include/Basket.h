#pragma once
#include <string>
#include <map>
#include "Market.h"

class ShoppingBasket : public Market
{
private:
    std::map<std::string, int> basket;
public:
    void add(const std::string& article, const int& amount);
    void remove(const std::string& article, const int& amount);
};