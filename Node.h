//#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "CovidData.h"

class Node {

    private:

    vector<CovidData> chave; //chave do nó
    Node *rght, *left; //nó da direita e nó da esquerda, respectivamente

    public:

    Node();

    ~Node();
};