#ifndef SIMPLEGAMEENGINE_RANDOM_HPP
#define SIMPLEGAMEENGINE_RANDOM_HPP

#include <ctime>
#include <random>

class Random {
    private :
        unsigned int seed;

    public :
        Random();
        explicit Random( unsigned int seed );

        float randomFloat( float min, float max );
        unsigned int randomInteger( unsigned int min, unsigned int max );
};

#endif //SIMPLEGAMEENGINE_RANDOM_HPP
