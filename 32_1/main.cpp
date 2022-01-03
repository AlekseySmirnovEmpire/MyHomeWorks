#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

struct Records 
{
    std::string firstName;
    std::string lastName;
    int age;
    bool married;
};

int main(int, char**) 
{
    Records record;

    std::cin >> record.firstName >> record.lastName >> record.age >> record.married;

    std::ofstream file("record.json");

    nlohmann::json dict = 
    {
        {"First name", record.firstName},
        {"Last name", record.lastName},
        {"Age", record.age},
        {"Married", record.married}
    };

    file << dict;
    
    file.close();
}
