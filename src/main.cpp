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

    Neuron n1;
    Neuron n2;
    Neuron n3;

    n1.value = 1;
    n2.value = 1;
    n3.value = 1;

    Layer l;
    l.addNeuron(&n1);
    l.addNeuron(&n2);
    l.addNeuron(&n3);

    n.addLayerToBack(&l);

    n.addFilledLayer(3);
    n.createConnections();

    n.predict();
    

    /*n.hiddenLayers.back()->neurons.front()->input.front()->weight;
    n.hiddenLayers.back()->neurons.front()->input.back()->weight;
    n.hiddenLayers.back()->neurons.back()->input.front()->weight;
    n.hiddenLayers.back()->neurons.back()->input.back()->weight;*/

    n.printInputLayer();
    n.printOutputLayer();
    

    return 0;
}