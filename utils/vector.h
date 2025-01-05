#ifndef UTILS_VECTOR_H
#define UTILS_VECTOR_H
//.....BUILT-IN LIBRARIES.....
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
std::vector<std::vector<T>> generateRandomMatrix(size_t rows, size_t cols, size_t minVal = 0, size_t maxVal = 1) {
    srand(time(0));
    std::vector<std::vector<T>> matrix(rows, std::vector<T>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = minVal + static_cast<T>(rand()) / RAND_MAX * (maxVal - minVal);
        }
    }
    return matrix;
}

template<typename T>
std::vector<T> generateRandomVector(size_t size, size_t minVal = 0, size_t maxVal = 1) {
    std::vector<T> vector(size);
    for (int i = 0; i < size; ++i) {
        vector[i] = minVal + static_cast<T>(rand()) / RAND_MAX * (maxVal - minVal);
        
    }
    return vector;
}

template<typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void printVector(std::vector<T> vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
#endif