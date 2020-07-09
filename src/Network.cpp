//
// Network.cpp - Implementaion of a Network
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//
#include <iostream>
#include <math.h>

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

void Network::printOutputLayer() {
    std::cout << "------Output Layer------" << std::endl;
    std::list<Neuron*> outputNeurons = (*layers.back()).neurons;

    std::list<Neuron*>::iterator i;
    for(i = outputNeurons.begin(); i != outputNeurons.end(); i++) {
        std::cout << "Value: " << (*i)->value << std::endl;
    }
}

// Adds a layer filled with neurons
void Network::addFilledLayer(size_t quantity) {
    Layer* layer = new Layer();
    layer->fillLayer(quantity);
    layers.push_back(layer);
}

// Drives the input through the network
void Network::predict(std::list<double>* inputValues) {

    fillInput(inputValues);

    std::list<Layer*>::iterator itLayers;
    std::list<Neuron*>::iterator itNeurons;
    std::list<Connection*>::iterator itConnections;
    std::list<Neuron*>* neurons;
    std::list<Connection*>* connections;
    double sum = 0;
    
    for(itLayers = std::next(layers.begin()); itLayers != layers.end(); itLayers++) {
        neurons = &(*itLayers)->neurons;
        for(itNeurons = neurons->begin(); itNeurons != neurons->end(); itNeurons++) {

            sum = 0;
            connections = &((*itNeurons)->input);
            for(itConnections = connections->begin(); itConnections != connections->end(); itConnections++) {
                sum += (*itConnections)->connectedNeuron->value * (double) (*itConnections)->weight;
                //std::cout << (*itConnections)->connectedNeuron->value << "   " << (*itConnections)->connectedNeuron->value * (*itConnections)->weight << "  " <<  sum << "   weight: " << (*itConnections)->weight << std::endl;
            }
            (*itNeurons)->value = sum;
        }
    }
}

void Network::fillInput(std::list<double>* inputValues) { // Maybe change to array instead?
    std::list<Neuron*>::iterator itNeuron;
    std::list<double>::iterator itInput = inputValues->begin();
    std::list<Neuron*> neurons = layers.front()->neurons;

    for(itNeuron = neurons.begin(); 
        itNeuron != neurons.end() && itInput != inputValues->end(); 
        itNeuron++) {

        (*itNeuron)->value = *itInput;
        itInput++;
    }
}

// Activation functions
double Network::binaryStep(double x) {
    if (x < 0)
        return 0;
    return 1;
}

double Network::sigmoid(double x) {
    return (1/(1+exp(-x)));
}

double Network::tanH(double x) {
    return tanh(x);
}

double Network::reLU(double x) {
    if (x <= 0)
        return 0;
    return x;
}

double Network::gelu(double x) {
    return x*( 1+erf(x/sqrt(2)) )/2;
}

double Network::softPlus(double x) {
    return log(1+exp(x));
}

double Network::elu(double x) {
    return x;
}

double Network::selu(double x) {
    return x;
}

double Network::arctan(double x) {
    return x;
}

double Network::softSign(double x) {
    return x;
}

double Network::bentIdentity(double x) {
    return x;
}

double Network::siLU(double x) {
    return x;
}

double Network::sinusoid(double x) {
    return x;
}

double Network::sinc(double x) {
    return x;
}

double Network::gaussian(double x) {
    return x;
}
