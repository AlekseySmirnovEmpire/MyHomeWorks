#include <iostream>
#include <vector>
#include "Reestr.h"
#include "Support.h"

template<typename T1, typename T2>
void Reestr<T1, T2>::addKey(T1 key, T2 data)
{
    clear();
    reded.push_back(std::make_pair(key, data));
}


template<typename T1, typename T2>
void Reestr<T1, T2>::removeKey(T1 key, T2 data)
{
    clear();

    for (int i = 0; i < reded.size(); ++i)
    {
        auto it = reded[i].find(key);

        if (it == reded[i].end())
            std::cout << key << " doesn't exist!" << std::endl;
        else
        {
            reded[i].erase(it);
            std::cout << key << " has been deleted!" << std::endl;

            return;
        }
    }
}

template<typename T1, typename T2>
void Reestr<T1, T2>::findKey(T1 key, T2 data)
{
    clear();

    for (int i = 0; i < reded.size(); ++i)
    {
        auto it = reded[i].find(key);

        if(it != reded[i].end())
        {
            std::cout << "Key: " << key << std::endl << "Data: " << data << std::endl;

            return;
        }
    }
    std::cout << key << " didn' found!" << std::endl;
}

template<typename T1, typename T2>
void Reestr<T1, T2>::printKey(T1 key, T2 data)
{
    clear();

    for(int i = 0; i < reded.size(); ++i)
    {
        auto it = reded[i].begin();

        while(it != reded[i].end())
        {
            std::cout << "Key: " << it->first << std::endl << "Data: " << it->second << std::endl;

            ++it;
        }
    }
}