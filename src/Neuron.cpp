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
    value = 1;
}

Neuron::~Neuron() {
    // Destroy input list! MOHAHAHA
}

Connection::Connection(Neuron* pNeuron, double aWeight) {
    connectedNeuron = pNeuron;
    weight = aWeight;

}

void Neuron::addConnection(Neuron* pNeuronToConnect) {
    double weight = 1; //(double) std::rand() / (double) (RAND_MAX/100);
    input.push_back(new Connection(pNeuronToConnect, weight));
}