//
// Layer.h - Definition of a layer and its functions.
//
// Written by Alexander Stenlund, Västerås, Sweden (c) 2020
//

//
// This class defines our layer
//

#ifndef LAYER_H
#define LAYER_H

#include <Neuron.h>
#include <list>

class Layer {
    public:

        //Default constructor & destructor
        Layer() = default;
        ~Layer() = default;

        void addNeuron(Neuron* neuron);

    private:
        std::list<Neuron*> neurons;
};

#endif