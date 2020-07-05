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
        Layer();
        ~Layer() = default;

        void addNeuron(Neuron* neuron);
        
        std::list<Neuron*> neurons;
        size_t numberOfNeurons;

    private:
};

#endif