//
// Network.cpp - Implementaion of a Network
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

#include <Network.h>
#include <Layer.h>

//Adds the layer and establishes a connections between neurons
void Network::addLayerToBack(Layer* layer) {
    hiddenLayers.push_back(layer);

    if(numberOfHiddenLayers == 0) {
        // Connect input layer to hidden layer 0
    }
};