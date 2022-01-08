#include <iostream>
#include <vector>

template<typename T>
std::vector<T> addNewArray()
{
    std::cout << "Size of array: ";
    int answer;
    std::cin >> answer;

    std::vector<T> arr(answer);

    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << "Input #" << i + 1 << ": ";
        std::cin >> arr[i];
    }

    return arr;
}

template<typename T>
T averageArr(const std::vector<T>& arr)
{
    T output = 0;

    for(int i = 0; i < arr.size(); ++i)
        output += arr[i];

    output /= arr.size();

    return output;
}

int main(int, char**) 
{
    std::cout << "==========Input array of INT============" << std::endl;
    std::vector<int> arrInt(addNewArray<int>());

    std::cout << "==========Input array of DOUBLE============" << std::endl;
    std::vector<double> arrDouble(addNewArray<double>());

    std::cout << "==========Input array FLOAT============" << std::endl;
    std::vector<float> arrFloat(addNewArray<float>());

    std::cout << "===================AVERAGE===================" << std::endl;

    std::cout << "1. INT " << static_cast<int>(averageArr(arrInt)) << std::endl;
    std::cout << "2. DOUBLE " << averageArr<double>(arrDouble) << std::endl;
    std::cout << "3. FLOAT " << averageArr<float>(arrFloat) << std::endl;
}
