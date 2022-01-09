#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers {1, 2, 3, 4, 5};

    for(const auto& el : numbers)
        std::cout << el << " ";
    std::cout << std::endl;
}