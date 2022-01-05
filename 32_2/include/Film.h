#pragma once
#include <string>
#include <map>
#include "nlohmann/json.hpp"

enum eFilms
{
    SHAWSHANK_REDEMPTION = 1,
    LORD_OF_THE_RING,
    STAR_WARS,
    STAR_TREK,
    BREAKING_BAD
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
    std::map<std::string, std::string> actors;
public:
    Film(const nlohmann::json& dict);

    void showInfo();
};
