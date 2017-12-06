/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.h
 * Author: niklas_debbrecht
 *
 * Created on 6. Dezember 2017, 14:36
 */

#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

namespace std;

class Edge {
public:
    Edge(float weight, Node* first, Node* second);
    Edge(const Edge& orig);
    virtual ~Edge();
    void setWeight(float weight);
    void setFirst(Node* first);
    void setSecond(Node* second);
    float getWeight();
    Node* getFirst();
    Node* getSecond();
private:
    Node* first;
    Node* second;
    float weight;

};

#endif /* EDGE_H */

