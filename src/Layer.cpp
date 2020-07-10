//
// Layer.cpp - Implementaion of a layer
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

#include <Layer.h>
#include <Neuron.h>
#include <Network.h>

Layer::Layer() {
    numberOfNeurons = 0;
    activationFunc = Network::linear;
}

// Adds the neuron to the layer
void Layer::addNeuron(Neuron* neuron) {
    neurons.push_back(neuron);
    numberOfNeurons++;
}

// Fills the layer with an amount of neurons
void Layer::fillLayer(size_t quantity) {
    for (int i = 0; i < quantity; i++)
        neurons.push_back(new Neuron);
}