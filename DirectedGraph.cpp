/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirectedGraph.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 6. Dezember 2017, 14:37
 */

#include "DirectedGraph.h"

DirectedGraph::DirectedGraph() {
    adjaz = map< Node*, vector<Edge*> >();
    size = 0;
}

DirectedGraph::DirectedGraph(const DirectedGraph& orig) {
}

DirectedGraph::~DirectedGraph() {
}

void DirectedGraph::insertEdge(string start, string target, float weight){
    if(findNode(start) == NULL){
        Node* n = new Node(start, ++size);
        insertNode(n);
    }
    if(findNode(target) == NULL){
        Node* n = new Node(target, ++size);
        insertNode(n);
    }
    insertEdge(new Edge(findNode(start), findNode(target), weight));
}

void DirectedGraph::insertEdge(Edge* e){
    map<Node*, vector<Edge*> >::iterator it;
    
    it = adjaz.find(e->getSecond());
    it->second.push_back(e);
}

Node* DirectedGraph::findNode(string name){
    map<Node*, vector<Edge*> >::iterator it;
    for(it = adjaz.begin(); it != adjaz.end(); it++){
        if(it->first->getMarkierung() == name){
            return it->first;
        }
    }
    return NULL;
}

void DirectedGraph::insertNode(Node* newNode){
    pair<Node*, vector<Edge*> > neu;
    vector<Edge*> ve;
    neu.first = newNode;
    neu.second = ve;
    adjaz.insert(neu);
}

void DirectedGraph::insertData(string filename){
    FILE *dataFile = NULL;
    dataFile = fopen(filename.c_str(), "r");
    if(dataFile == NULL){
        perror("Error! ");
        return;
    }
    char from[50];
    char to[50];
    float value =0.0;
    while(fscanf(dataFile, "%s %s %f\n", from, to, &value)==3) {
        this->insertEdge(string(from),string(to),value);
    }
    fclose(dataFile);
    
}

vector<Node*> DirectedGraph::findShortestWay(Node* start, Node* target){
    vector<Node*> path;
    return path;
}

void DirectedGraph::printData(){
    map<Node*, vector<Edge*> >::iterator it;
    for(it = adjaz.begin(); it != adjaz.end(); it++){
        cout << it->first->getMarkierung() << " ";
        int i = 0;
        for(i=0; i < it->second.size(); i++){
            cout << it->second[i]->getWeight() << " ";
        }
        cout << endl;
    }
}