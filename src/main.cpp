//
// main.cpp
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

// Standard includes
#include <iostream>

// Neural network includes
#include <Neuron.h>
#include <Layer.h>
#include <Network.h>

// Main to test the neural network
int main(void)
{
    srand(time(NULL)); //Is needed for random weigths and biases; Try to find a better solution

    Network n;

    n.addFilledLayer(3);
    n.addFilledLayer(3);
    n.addFilledLayer(6);
    n.createConnections();

    std::list<double> in;
    in.push_back(3.52523);
    in.push_back(2.375);
    in.push_back(8.15467934);

    // There is a problem with variables value being cut off in predict

    n.fillInput(&in);

    n.predict();
    

    /*n.hiddenLayers.back()->neurons.front()->input.front()->weight;
    n.hiddenLayers.back()->neurons.front()->input.back()->weight;
    n.hiddenLayers.back()->neurons.back()->input.front()->weight;
    n.hiddenLayers.back()->neurons.back()->input.back()->weight;*/

    n.printInputLayer();
    n.printOutputLayer();
    

    return 0;
}