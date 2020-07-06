//
// Neuron.h - Definition of a neuron, its behaviour and connections.
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

//
// This class defines our neuron
//

#ifndef NEURON_H
#define NEURON_H

#include <list>

class Neuron;

class Connection {
    public:
        Connection(Neuron* pNeuron, double weight);

        Neuron* connectedNeuron;
        double weight;
};

class Neuron {
    public:

        // Constructor & destructor
        Neuron();
        ~Neuron();

        // Variables
        std::list<Connection*> input; // If createConnections is ran twice you get multiple connections to the same neuron. Fix?
        double bias;
        double value;

        // Functions
        void addConnection(Neuron* pNeuronToConnect);
};

#endif