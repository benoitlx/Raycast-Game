#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <fstream>
#include <iostream>
#include <vector>


class Map 
{
    public:
        Map(char path[], int size);
        ~Map();

        int blocSize;
        std::vector<std::vector<unsigned int>> vecMap;

    protected:
        void parseMap(char p[]);
        
};

#endif