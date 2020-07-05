//
// Neuron.cpp - Implementaion of a neuron
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//
#include <stdio.h>
#include <iostream>

#include <Neuron.h>

// Constructor
Neuron::Neuron() {
    bias = (double) std::rand() / (double) (RAND_MAX/100);
    value = 0;
}

Neuron::~Neuron() {
    // Destroy input list! MOHAHAHA
}

Connection::Connection(Neuron* pNeuron, double aWeight) {
    connectedNeuron = pNeuron;
    weight = aWeight;

}

void Neuron::addConnection(Neuron* pNeuronToConnect) {
    double weight = (double) std::rand() / (double) (RAND_MAX/100);
    std::cout << "Connection made between: " << value << " and " << pNeuronToConnect->value << std::endl;
    input.push_back(new Connection(pNeuronToConnect, weight));
}