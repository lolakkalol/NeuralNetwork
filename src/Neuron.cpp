//
// Neuron.cpp - Implementaion of a neuron
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

#include <Neuron.h>
#include <iostream>

// Constructor
Neuron::Neuron() {
    bias = 0;   // Make random
    value = 0;
    
    std::cout << "Neuron constructor!!" << std::endl;
}

Neuron::~Neuron() {
    // Destroy input list! MOHAHAHA
}

Connection::Connection(Neuron* pNeuron, double aWeight) {
    connectedNeuron = pNeuron;
    weight = aWeight;

}

void Neuron::addConnection(Neuron* pNeuronToConnect, double weight) {
    input.push_back(new Connection(pNeuronToConnect, weight));
}