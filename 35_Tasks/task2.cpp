#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <memory>

auto ptr = [](std::vector<int> vec)
    {
        std::unordered_set<int> temp;

        for(const auto& el : vec)
            if(!temp.count(el))
                temp.insert(el);

        vec.clear();

        for(const auto& it : temp)
            vec.push_back(it);

        return std::make_unique<std::vector<int>>(vec);
    };

int main()
{
    std::vector<int> input {1, 2, 1, 3, 1, 2, 3, 1, 4, 5, 6, 3, 3, 4, 5, 2, 1, 3};

    auto result = ptr(input);
}