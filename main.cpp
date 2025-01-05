#include <iostream>
#include "NeuralNetwork.h"

int main() {
    NeuralNetwork<float> nn;
    nn.addLayer(2, 2, 0.1);
    nn.addActivationFunction("sigmoid");
    nn.addLayer(2, 1, 0.1);
    nn.setLossFunction("l2");
    std::vector<std::vector<float>> inputs = {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 0.0},
        {1.0, 1.0}
    };

    std::vector<std::vector<float>> outputs = {
        {0.0},
        {1.0},
        {1.0},
        {0.0}
    };

    nn.train(inputs, outputs, 1);
    std::cout << "For 0, 0: Result: " << nn.infer({0.0, 0.0})[0] << std::endl;
    return 0;
}