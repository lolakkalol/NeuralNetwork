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
        void predict(std::list<double>* inputValues);

        // Variables
        Layer inputLayer;
        std::list<Layer*> layers;
        Layer outputLayer;

        // Info about network
        size_t hiddenLayerSize;
        size_t numberOfNeurons;

    private:
        void fillInput(std::list<double>* inputValues);

        // Activation functions
        double binaryStep(double x);
        double sigmoid(double x);
        double tanH(double x);
        double reLU(double x);
        double gelu(double x);
        double softPlus(double x);
        double elu(double alpha, double x);
        double selu(double x);
        double arctan(double x);
        double softSign(double x);
        double bentIdentity(double x);
        double siLU(double x);
        double sinusoid(double x);
        double sinc(double x);
        double gaussian(double x);
};

#endif