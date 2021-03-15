#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <fstream>
#include <iostream>


class Map 
{
    public:
        Map(char path[]);

        const int getCase(unsigned int x, unsigned int y) const;

    protected:
        void parseMap(char p[]);
        
        int vecMap[200][200];

};

#endif