#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>

class Map 
{
    public:
        Map(char path[]);

        int getCase(unsigned int x, unsigned int y);

    protected:
        void parseMap(char path[]);
        
        std::vector<std::vector<unsigned int>> vecMap;

};

#endif