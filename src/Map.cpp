#include "../headers/Map.h"

Map::Map(char path[])
{
    // std::printf(path);
    this->parseMap(path);
}

void Map::parseMap(char path[])
{

    std::string p = "map.txt";
    std::ifstream input;

    input.open("map.txt");

    if (!input.is_open())
    {
        std::printf("Files not open error");
        return;
    }

    while (input)
    {
        std::string line;

        std::getline(input, line);

        std::cout << line << std::endl;
    }

    input.close();
}

