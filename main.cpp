#include <iostream>
#include "NeuralNetwork.h"

int main() {
    NeuralNetwork<float> nn;
    nn.addLayer(2, 2, 0.1);
    nn.addActivationFunction("sigmoid");
    nn.addLayer(2, 1, 0.1);
    nn.addActivationFunction("sigmoid");

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

    nn.train(inputs, outputs, 10000);
    
    // Test the model
    for (size_t i = 0; i < inputs.size(); i++) {
        std::vector<float> result = nn.infer(inputs[i]);
        std::cout << "Input: " << inputs[i][0] << " " << inputs[i][1] << " Output: " << result[0] << std::endl;
    }
    return 0;
}