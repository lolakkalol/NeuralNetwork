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
#include <iomanip>

// Main to test the neural network
int main(void)
{
    srand(time(NULL)); //Is needed for random weigths and biases; Try to find a better solution

    Network n;

    // Creates the network
    n.addFilledLayer(3);
    n.addFilledLayer(3);
    n.addFilledLayer(6);
    n.createConnections();

    n.layers.front()->pFunc = Network::sigmoid;

    // Fills in with data thats going to be processed by the NN
    std::list<double> in;
    in.push_back(3.52523);
    in.push_back(2.375);
    in.push_back(8.15467934);

    // Will run the data through the NN
    n.predict(&in);
    
    n.printInputLayer();
    n.printOutputLayer();
    

    return 0;
}