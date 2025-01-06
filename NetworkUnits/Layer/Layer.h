#ifndef Layer_h
#define Layer_h
//.....BUILT-IN LIBRARIES.....
#include<vector>
//.....CUSTOM LIBRARIES.....
#include"../../utils/vector.h"
#include"../NetworkUnit.h"
template<typename T>
class Layer : public NetworkUnit<T>
{
    private:
        //structure 
        std::vector<std::vector<T>>weights;
        std::vector<T>biases;
        //functional
        float learningRate;
    public:

        Layer(size_t inputs,size_t perceptronsCount,float learningRate)
        {
            this->weights=generateRandomMatrix<T>(perceptronsCount,inputs);
            this->biases=generateRandomVector<T>(perceptronsCount);
            this->learningRate=learningRate;
        }
        std::vector<T> forwardPropagate(std::vector<T> inputs) override
        {
            this->inputs=inputs;    //store inputs for backpropagation
            std::vector<T> outputs(weights.size());
            for(size_t i=0;i<weights.size();i++)
            {
                T sum=0;
                for(size_t j=0;j<weights[i].size();j++)
                {
                    sum+=weights[i][j]*inputs[j];
                }
                outputs[i]=sum+biases[i];
            }
            return outputs;
        }
        std::vector<T> backwardPropagate(std::vector<T> gradients) override
        {
            // calculate gradients of weights and adjust weights
            for(size_t i=0;i<weights.size();i++)
            {
                for(size_t j=0;j<weights[i].size();j++)
                {
                    weights[i][j]-=learningRate*gradients[i]*this->inputs[j];
                }
            }
            // calculate gradients of biases and adjust biases
            for(size_t i=0;i<biases.size();i++)
            {
                biases[i]-=learningRate*gradients[i];
            }
            // calculate gradients of inputs and return
            std::vector<T> updatedGradients(this->inputs.size());
            for(size_t i=0;i<this->inputs.size();i++)
            {
                T sum=0;
                for(size_t j=0;j<weights.size();j++)
                {
                    sum+=weights[j][i]*gradients[j];
                }
                updatedGradients[i]=sum;
            }
            return updatedGradients;
        }
        size_t getOutputSize() override
        {
            return weights.size();
        }
};
#endif