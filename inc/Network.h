//
// Network.h - Definition of a network and its functions.
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

//
// This class defines our network
//

#ifndef NETWORK_H
#define NETWORK_H

#include <Layer.h>

class Network {
    public:
        // Constructor
        Network();

        // Funcations
        void addLayerToBack(Layer* layer);
        void createConnections();
        void printInputLayer();
        void printOutputLayer();
        void addFilledLayer(size_t quantity);
        void predict();
        void fillInput(std::list<double>* inputValues);

        // Variables
        Layer inputLayer;
        std::list<Layer*> layers;
        Layer outputLayer;

        // Info about network
        size_t hiddenLayerSize;
        size_t numberOfNeurons;

    private:
};

#endif