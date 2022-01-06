#include <iostream>
#include <string>
#include "Market.h"
#include "Support.h"

inline void checkArticle(std::string& input)
{
    if(input.length() < 6)
    {
        std::string temp = "";

        while(temp.length() + input.length() != 6)
            temp += '0';

        input = temp + input;
    }
}

Market::Market()
{
    for (int i = 0; i < 10; ++i)
    {
        std::string article = "";
        article += std::to_string(std::rand() % 999999 + 1);
        checkArticle(article);

        product.emplace(article, static_cast<int>(std::rand() % 20 + 1));
    }
}

std::pair<std::string, int> Market::getProduct(const std::string& article, const int& amount)
{
    auto it = product.find(article);

    if(it == product.end())
    {
        throw BadArticleError();
    }
    else if (it->second <= 0)
    {
        throw BadAmountError();
    }
    else if(it->second - amount < 0 || amount < 0)
    {
        throw BadAmountError();
    }
    else
    {
        return std::make_pair(article, amount);
    }
}