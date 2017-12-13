/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirectedGraph.h
 * Author: niklas_debbrecht
 *
 * Created on 6. Dezember 2017, 14:37
 */

#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include "Node.h"
#include "Edge.h"
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class DirectedGraph {
public:
    DirectedGraph();
    DirectedGraph(const DirectedGraph& orig);
    virtual ~DirectedGraph();
    void insertEdge(string start, string target, float weight);
    void insertEdge(Edge* e);
    void insertNode(Node* newNode);
    void insertData(string filename);
    Node* findNode(string name);
    vector<Node*> findShortestWay(Node* start, Node* target);
    void printData();
private:
    int size;
    map< Node*, vector<Edge*> > adjaz;

};

#endif /* DIRECTEDGRAPH_H */

