#ifndef NetworkUnit_h
#define NetworkUnit_h
//.....BUILT-IN LIBRARIES.....
#include <vector>

template<typename T>
class NetworkUnit
{
    public:
        virtual std::vector<T> forwardPropagate(std::vector<T> inputs)=0;
};
#endif