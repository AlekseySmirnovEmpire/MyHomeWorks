#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"

//#define TEST

void clear()
{
#ifdef _WIN32
    system("cls");
#elif (_LINUX_)
    system("clear");
#else
    for (int i = 0; i < 10; ++i)
        std::cout << std::endl;
#endif
}

class Actor
{
private:
    std::string name;
    std::string role;

public:
    Actor(const std::string& name, const std::string& role)
    {
        this->name = name;
        this->role = role;
    }

    std::string getName() { return name;}
    std::string getRole() { return role;}
};

class Film
{
private:
    std::string name;
    std::string country;
    std::string date;
    std::string filmStudio;
    std::string scriptwriter;
    std::string producer;
    std::vector<Actor> actors;
public:
    Film();
    void inputActors();

    std::string getName() { return name;}
    std::string getCountry() { return country;}
    std::string getDate() { return date;}
    std::string getFilmStudio() {return filmStudio;}
    std::string getScriptWriter() {return scriptwriter;}
    std::string getProducer() {return producer;}
    std::vector<Actor> getActors() const {return actors;}
};

Film::Film()
{
    std::cout << "Input film's name: ";
    std::getline(std::cin, name);

    std::cout << "Input it's country: ";
    std::getline(std::cin, country);

    std::cout << "Input it's date of production (DD.MM.YYYY): ";
    std::getline(std::cin, date);

    std::cout << "Input name of film studio: ";
    std::getline(std::cin, filmStudio);

    std::cout << "Input script writer's name: ";
    std::getline(std::cin, scriptwriter);

    std::cout << "Input producer's name: ";
    std::getline(std::cin, producer);

    clear();
    inputActors();
    clear();
}

void Film::inputActors()
{
    std::cout << "How many actors you want to input: ";
    int answer;
    std::cin >> answer;
    std::cin.ignore();

    while(answer > 0)
    {
        std::cout << "Input actor's name: ";
        std::string tempName;
        std::getline(std::cin, tempName);

        std::cout << "Input actor's role: ";
        std::string tempRole;
        std::getline(std::cin, tempRole);

        Actor* temp = new Actor(tempName, tempRole);

        actors.push_back(*temp);

        delete temp;
        temp = nullptr;
        --answer;
    }
}

int main()
{
#ifdef TEST
    nlohmann::json dict1;

    std::ofstream file1("film.json");

    std::string name = "Anna";

    dict1["Actors"].emplace(name + "in role", name);

    name = "Vladimir";

    dict1["Actors"].emplace(name + "in role", name);

    file1 << dict1;

    file1.close();
#else
    Film myFavouriteFilm;

    nlohmann::json dict;

    std::ofstream file("film.json");

    if(file.is_open())
    {
        dict["Title"] = myFavouriteFilm.getName();
        dict["Country"] = myFavouriteFilm.getCountry();
        dict["Date"] = myFavouriteFilm.getDate();
        dict["Film studio"] = myFavouriteFilm.getFilmStudio();
        dict["Script writer"] = myFavouriteFilm.getScriptWriter();
        dict["Producer"] = myFavouriteFilm.getProducer();

        for (int i = 0; i < myFavouriteFilm.getActors().size(); ++i)
            dict["Actors"].emplace(myFavouriteFilm.getActors()[i].getName() + " in role ",
                                   myFavouriteFilm.getActors()[i].getRole());

        file << dict;

        file.close();
    }
    else
    {
        std::cout << "File not found!" << std::endl;
    }

#endif

    std::cout << "=============GOODBYE!===============" << std::endl;
}
