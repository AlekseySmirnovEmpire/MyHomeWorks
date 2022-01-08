#pragma once
#include <vector>
#include <map>

template<typename T1, typename T2>
class Reestr
{
private:
    std::vector<std::map<T1, T2>> reded;
public:
    void addKey(T1 key, T2 data);
    void removeKey(T1 key);
    void printKey(T1 key);
    void findKey(T1 key);
};