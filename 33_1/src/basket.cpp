#include <iostream>
#include <string>
#include <map>
#include <exception>
#include "Basket.h"
#include "Support.h"

inline void searchInBasket(std::map<std::string, int>& basket, const std::string& article, const int& amount)
{
    auto it = basket.find(article);

    if(it == basket.end())
        throw BadArticleError();
    else if(it->second - amount < 0 || amount < 0)
        throw BadAmountError();
}

void ShoppingBasket::add(const std::string &article, const int &amount)
{
    try
    {
        basket.emplace(getProduct(article, amount));
    }
    catch (const BadArticleError& x)
    {

    }
    catch(const BadAmountError& x)
    {

    }
    catch (const NoProductInMarket& x)
    {

    }

    clear();
}

void ShoppingBasket::remove(const std::string &article, const int &amount)
{
    try
    {
        searchInBasket(basket, article, amount);
        basket.find(article)->second -= amount;
    }
    catch (const BadArticleError& x)
    {
        std::cerr << "Article: " << x.what() << std::endl;
    }
    catch (const BadAmountError& x)
    {
        std::cerr << "Amount: " << x.what() << std::endl;
    }

    clear();
}