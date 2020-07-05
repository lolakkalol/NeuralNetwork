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

        std::list<Connection*> input;
        double bias;
        double value;

        void addConnection(Neuron* pNeuronToConnect, double weight);


    private:

};

#endif