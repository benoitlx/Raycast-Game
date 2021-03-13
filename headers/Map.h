#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

class Map 
{
    public:
        Map();

        int getCase(unsigned int x, unsigned int y);

    private:
        void parseMap();

}

#endif