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
        void addFilledLayer(size_t quantity, double (*activationFunc)(double));
        void predict(std::list<double>* inputValues);

        // Variables
        Layer inputLayer;
        std::list<Layer*> layers;
        Layer outputLayer;

        // Info about network
        size_t hiddenLayerSize;
        size_t numberOfNeurons;

        // Activation functions
        static double linear(double x);
        static double binaryStep(double x);
        static double sigmoid(double x);
        static double tanH(double x);
        static double reLU(double x);
        static double gelu(double x);
        static double softPlus(double x);
        static double elu(double alpha, double x);
        static double selu(double x);
        static double arctan(double x);
        static double softSign(double x);
        static double bentIdentity(double x);
        static double siLU(double x);
        static double sinusoid(double x);
        static double sinc(double x);
        static double gaussian(double x);

    private:
        void fillInput(std::list<double>* inputValues);
};

#endif