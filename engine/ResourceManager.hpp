#ifndef SIMPLEGAMEENGINE_RESOURCEMANAGER_HPP
#define SIMPLEGAMEENGINE_RESOURCEMANAGER_HPP

#include <string>
#include <unordered_map>

template< class T >
class ResourceManager {
    public :
        void add( const std::string key, const T value ) {
            resources.insert( std::make_pair( key, value ));
        }

        const T &get( const std::string key ) {
            return resources.at( key );
        }

    private:
        std::unordered_map< std::string, T > resources;
};

#endif //SIMPLEGAMEENGINE_RESOURCEMANAGER_HPP
