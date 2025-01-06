#include <iostream>
#include "NeuralNetwork.h"

int main() {
    NeuralNetwork<float> nn;
    nn.setLearningRate(0.1);
    nn.setInputSize(2);
    nn.setLossFunction("crossentropy");
    nn.addLayer(3);
    nn.addActivationFunction("sigmoid");
    nn.addLayer(2);
    nn.addActivationFunction("sigmoid");

    #include <vector>
    #include <cmath>

    std::vector<std::vector<float>> inputs = {
        {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {-1.0, -2.0}, {-3.0, -4.0}, {-5.0, -6.0}
    };

    std::vector<std::vector<float>> outputs;

    for (const auto& input : inputs) {
        float distance = std::sqrt(input[0] * input[0] + input[1] * input[1]);
        if (distance <= 5.0) {
            outputs.push_back({1.0});
        } else {
            outputs.push_back({0.0});
        }
    }

    nn.train(inputs, outputs, 1000);

    std::vector<std::vector<float>> testInputs = {
        {0.5, 0.5}, {2.0, 2.0}, {4.0, 4.0}, {-0.5, -0.5}, {-2.0, -2.0}, {-4.0, -4.0}, {6.0, 6.0}, {-6.0, -6.0}
    };
    std::vector<float> testOutputs;
    for(const auto& testInput : testInputs) {
        float distance = std::sqrt(testInput[0] * testInput[0] + testInput[1] * testInput[1]);
        if (distance <= 5.0) {
            testOutputs.push_back(1.0);
        } else {
            testOutputs.push_back(0.0);
        }
    }
    float threshold = 0.5;
    for (size_t i = 0; i < testInputs.size(); ++i) {
        std::vector<float> prediction = nn.infer(testInputs[i]);
        std::cout << "Input: (" << testInputs[i][0] << ", " << testInputs[i][1] << ") "
                  << "Predicted Output: " << (prediction[0] > threshold ? 1.0 : 0.0) << " "
                  << "Expected Output: " << testOutputs[i] << std::endl;
    }
    
    return 0;
}