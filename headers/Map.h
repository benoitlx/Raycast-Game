#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <fstream>
#include <iostream>


class Map 
{
    public:
        Map(char path[], int size);
        ~Map();

        const int getCase(unsigned int x, unsigned int y) const;

        int blocSize;

    protected:
        void parseMap(char p[]);
        
        int vecMap[200][200];

};

#endif