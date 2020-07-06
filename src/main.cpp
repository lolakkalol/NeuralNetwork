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
    Layer l1;
    Layer l2;

    Network n;

    Neuron n1;
    Neuron n2;
    Neuron n3;
    Neuron n4;
    Neuron n5;
    Neuron n6;

    n1.value = 1;
    n2.value = 2;
    n3.value = 3;
    n4.value = 4;
    n5.value = 5;
    n6.value = 6;

    l1.addNeuron(&n1);
    l1.addNeuron(&n2);

    l2.addNeuron(&n3);
    l2.addNeuron(&n4);
    l2.addNeuron(&n5);
    l2.addNeuron(&n6);

    n.addLayerToBack(&l1);
    n.addLayerToBack(&l2);
    n.createConnections();

    /*n.hiddenLayers.back()->neurons.front()->input.front()->weight;
    n.hiddenLayers.back()->neurons.front()->input.back()->weight;
    n.hiddenLayers.back()->neurons.back()->input.front()->weight;
    n.hiddenLayers.back()->neurons.back()->input.back()->weight;*/

    n.printInputLayer();
    

    return 0;
}