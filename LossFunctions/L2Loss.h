#ifndef L2LOSS_H
#define L2LOSS_H
//.....BUILT-IN LIBRARIES.....
#include <cmath>
#include <vector>
#include <cstdint>
template<typename T>
class L2Loss {
public:
    static T calculateLoss(std::vector<T> inputs, std::vector<T> targets) {
        T loss = 0;
        for (size_t i = 0; i < inputs.size(); i++) {
            loss += pow(inputs[i] - targets[i], 2);
        }
        return loss;
    }
};

#endif