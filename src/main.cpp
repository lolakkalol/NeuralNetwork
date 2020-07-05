//
// main.cpp
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

// Standard includes
#include <iostream>

// Neural network includes
#include <Neuron.h>

// Main to test the neural network
int main(void)
{
    Neuron b;
    std::cout << "Bias: " << b.bias << "  Value: " << b.value << std::endl;

    return 0;
}