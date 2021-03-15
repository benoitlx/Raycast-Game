#include "../headers/Map.h"

Map::Map(char path[])
{
    // std::printf(path);
    this->parseMap(path);
}

void Map::parseMap(char p[])
{
    std::ifstream infile;

    infile.open(p);

    if (!infile)
    {
        std::printf("Unable to open file\n");

        return;
    } 
    
    std::string str;
    int i = 0;
    while (std::getline(infile, str))
    {
        if (isdigit(str[0]))
        {
            for (int j=0; j<str.size(); j++)
            {
                vecMap[i][j] = std::atoi(str[j]);
                std::cout << vecMap[i][j];
            }
            std::printf("\n");
        }
        i++;
    }

    infile.close();
}

