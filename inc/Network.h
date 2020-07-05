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
        //Default constructor
        Network() = default;

        void addLayerToBack(Layer* layer);
        void insertLayer(Layer* layer, size_t index);
        void removeLayer(size_t index);

        int numberOfHiddenLayers();

    private:
        Layer inputLayer;
        std::list<Layer*> hiddenLayers;
        Layer outputLayer;

        size_t hiddenLayerSize;
};

#endif