#include <iostream>
#include <vector>
#include <ctime>
#include <exception>

#define forever() for(;;)

class FoundFishException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Fishing is over!";
    }
};

void refreshPound(std::vector<std::string>& pound)
{
    for(int i = 0; i < pound.size(); ++i)
        pound[i] = "none";

    int boots = 0;
    while(boots != 3)
    {
        int ind = std::rand() % 9;

        if(pound[ind] == "none")
        {
            pound[ind] = "boot";
            ++boots;
        }
    }

    forever()
    {
        int ind = std::rand() % 9;

        if(pound[ind] == "none")
        {
            pound[ind] = "fish";
            break;
        }
    }
}

bool fishing(const std::vector<std::string>& vec, const int& i)
{
    if (i < 0 || i > 9)
        throw std::invalid_argument("sector");
    else if(vec[i] == "fish")
        throw FoundFishException();

    return vec[i] == "boot";
}

int main() {
    std::srand(std::time(nullptr));
    int count = 0;

    std::vector<std::string> pound(9, "none");

    std::cout << "==================WELCOME!===================" << std::endl;

    forever()
    {
        std::cout << "Input number of sector u wish to fish: ";
        int answer;
        std::cin >> answer;

        refreshPound(pound);

        try
        {
            if(fishing(pound, answer))
                std::cout << "You catch boot!" << std::endl;
            else
                std::cout << "You catch nothing!" << std::endl;

            ++count;
        }
        catch(const std::invalid_argument& x)
        {
            std::cerr << "Error, wrong: " << x.what() << std::endl;
        }
        catch(const FoundFishException& x)
        {
            std::cout << "You catch fish!" << std::endl;
            std::cerr << x.what() << std::endl;
            break;
        }
    }
    std::cout << "============GOODBYE!==============" << std::endl;
}
