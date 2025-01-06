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
        std::vector<T>outputs;
        //functional
        float learningRate;
    public:

        Layer(size_t inputs,size_t perceptronsCount,float learningRate)
        {
            this->weights=generateRandomMatrix<T>(perceptronsCount,inputs);
            this->biases=generateRandomVector<T>(perceptronsCount);
            this->learningRate=learningRate;
        }
        std::vector<T> forwardPropagate(std::vector<T> inputs)
        {
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
            return this->outputs=outputs;
        }
};
#endif