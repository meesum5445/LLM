#ifndef NetworkUnit_h
#define NetworkUnit_h
//.....BUILT-IN LIBRARIES.....
#include <vector>

template<typename T>
class NetworkUnit
{
    public:
        // Structure Variables
        std::vector<T>inputs;
        // Method to forward propagate
        virtual std::vector<T> forwardPropagate(std::vector<T> inputs)=0;
        // Method to backward propagate
        virtual std::vector<T> backwardPropagate(std::vector<T> gradient)=0;
};
#endif