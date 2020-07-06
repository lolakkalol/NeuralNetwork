//
// Network.cpp - Implementaion of a Network
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//
#include <iostream>

#include <Network.h>
#include <Layer.h>

Network::Network() {
    hiddenLayerSize = 0;
    numberOfNeurons = 0;
}

//Adds the specified layer to the network
void Network::addLayerToBack(Layer* layer) {
    layers.push_back(layer);

    // updates info about the network
    hiddenLayerSize++;
    numberOfNeurons += layer->numberOfNeurons;
};

// Establishes connections between every layers neurons
void Network::createConnections() {
    std::list<Neuron*>::iterator itContactNeurons;
    std::list<Neuron*>::iterator itSocketNeurons;
    std::list<Layer*>::iterator itNetworkLayers;

    std::list<Neuron*> socketNeurons;
    std::list<Neuron*> contactNeurons;

    // Loop through each layer of the network
    for(itNetworkLayers = std::next(layers.begin()); itNetworkLayers != layers.end(); itNetworkLayers++) {
        contactNeurons = (*itNetworkLayers)->neurons;
        socketNeurons = (*(std::prev(itNetworkLayers)))->neurons;

        // Loops through all the contact neurons and establishes a connection with the socket neurons
        for(itContactNeurons = contactNeurons.begin(); itContactNeurons != contactNeurons.end(); itContactNeurons++) {
            for(itSocketNeurons = socketNeurons.begin(); itSocketNeurons != socketNeurons.end(); itSocketNeurons++) {
                (*itContactNeurons)->addConnection(*itSocketNeurons);
            }
        }
    }
}

void Network::printInputLayer() {
    std::cout << "------Input Layer------" << std::endl;
    std::list<Neuron*> inputNeurons = (*layers.front()).neurons;

    std::list<Neuron*>::iterator i;
    for(i = inputNeurons.begin(); i != inputNeurons.end(); i++) {
        std::cout << "Value: " << (*i)->value << std::endl;
    }
}