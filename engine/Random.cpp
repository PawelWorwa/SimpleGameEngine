#include "Random.hpp"

Random::Random() : Random( static_cast<long unsigned int>(time( nullptr ))) {
}

Random::Random( unsigned int seed ) {
    Random::seed = seed;
}

float Random::randomFloat( float min, float max ) {
    thread_local std::default_random_engine engine = std::default_random_engine( seed );
    thread_local std::mt19937 generator = std::mt19937( engine());
    std::uniform_real_distribution< float > distribution( min, max );
    return distribution( generator );
}

unsigned int Random::randomInteger( unsigned int min, unsigned int max ) {
    thread_local std::default_random_engine engine = std::default_random_engine( seed );
    thread_local std::mt19937 generator = std::mt19937( engine());
    return std::uniform_int_distribution< unsigned int >{min, max}( generator );
}
