#ifndef L2LOSS_H
#define L2LOSS_H
//.....BUILT-IN LIBRARIES.....
#include <cmath>
#include <vector>
#include <cstdint>
//.....CUSTOM LIBRARIES.....
#include "LossFunction.h"

template<typename T>
class L2Loss : public LossFunction<T> {
public:
    L2Loss() {
        this->loss = std::vector<T>();
    }
    std::vector<T> calculateLoss(const std::vector<T>& predicted, const std::vector<T>& actual) override {
        this->loss.clear();
        for (size_t i = 0; i < predicted.size(); i++) {
            this->loss.push_back(pow(predicted[i] - actual[i], 2));
        }
        return this->loss;
    }
    std::vector<T> calculateGradient(const std::vector<T>& predicted, const std::vector<T>& actual) override {
        std::vector<T> gradient(predicted.size());
        for (size_t i = 0; i < predicted.size(); i++) {
            gradient[i] = 2 * (predicted[i] - actual[i]);
        }
        return gradient;
    }
};

#endif