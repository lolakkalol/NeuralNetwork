//
// Layer.cpp - Implementaion of a layer
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

#include <Layer.h>
#include <Neuron.h>

// Adds the neuron to the layer
void Layer::addNeuron(Neuron* neuron) {
    neurons.push_back(neuron);
}