#pragma once
#include <string>
#include <map>

class Market
{
private:
    std::map<std::string, int> product;
public:
    Market();
    std::pair<std::string, int> getProduct(const std::string& article, const int& amount);
};