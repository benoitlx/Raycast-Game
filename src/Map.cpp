#include "../headers/Map.h"

Map::Map(char path[], int size)
{
    this->parseMap(path);

    blocSize = size;
}

Map::~Map()
{

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
    while (std::getline(infile, str))
    {
        if (isdigit(str[0]))
        {
            std::vector<unsigned int> line;
            for (int j=0; j<str.size(); j++)
            {
                line.push_back(str[j] - '0');
            }
            vecMap.push_back(line);
            line.clear();
        }
    }

    /* Check the vector */
    for (int i=0; i<vecMap.size(); i++)
    {
        for (int j=0; j<vecMap[i].size(); j++)
        {
            std::cout << vecMap[i][j];
        }
        std::cout << std::endl;
    }

    infile.close();
}

const int Map::getCase(unsigned int x, unsigned int y) const
{
    return vecMap[x][y];
}