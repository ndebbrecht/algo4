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
    
    it = adjaz.find(e->getFirst());
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
    size++;
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
    cout << "\n\nDaten erfolgreich eingelesen!\n\n";
    
}

int DirectedGraph::findShortestWay(string st, string go, int c){
    Node* s = this->findNode(st);
    Node* t = this->findNode(go);
    if(t == NULL || s == NULL){
        return -2;
    }
    Node* v = NULL;
    int tmp = 0;
    s->setPrev(NULL);
    s->setMarked(true);
    queue<Node*> pq;
    pq.push(s);
    while(!pq.empty()){
        v = pq.front();
        pq.pop();
        if(v == t){
            while(v != s){
                v = v->getPrev();
                tmp++;
            }
            if(tmp<=c){
                return tmp;
            } else {
                return -1;
            }
        }
        int i = 0;
        for(i = 0; i<adjaz.find(v)->second.size(); i++){
            if(!adjaz.find(v)->second[i]->getSecond()->getMarked()){
                adjaz.find(v)->second[i]->getSecond()->setMarked(true);
                adjaz.find(v)->second[i]->getSecond()->setPrev(v);
                pq.push(adjaz.find(v)->second[i]->getSecond());
            }
        }
    }
    return -3;
}

void DirectedGraph::printNodes(){
    cout << endl << endl;
    map<Node*, vector<Edge*> >::iterator it;
    for(it = adjaz.begin(); it != adjaz.end(); it++){
        cout << it->first->getMarkierung() << endl;
    }
    cout << "\n\n";
}

void DirectedGraph::single_shortest_path(Node* s){
    PriorityQueue pq(this->size);
    map<Node*, vector<Edge*> >::iterator it;
    for(it = adjaz.begin(); it != adjaz.end(); it++){
        it->first->setMarked(false);
        it->first->setPrev(NULL);
        if(it->first->getMarkierung() == s->getMarkierung()){
            it->first->setDist(0);
        } else {
            it->first->setDist(numeric_limits<float>::max());
        }
        pq.insert(*(it->first));
    }
    Node* v = NULL;
    while(pq.size()!=0){
        v=pq.extractMin();
        v->setMarked(true);
        for(int i = 0; i<adjaz.find(v)->second.size();i++){
            Edge* vi = adjaz.find(v)->second[i];
            if((!vi->getSecond()->getMarked()) && (vi->getSecond()->getDist() > v->getDist() + vi->getWeight())){
                vi->getSecond()->setDist(v->getDist() + vi->getWeight());
                vi->getSecond()->setPrev(v);
                pq.update(vi->getSecond()->getMarkierung(), vi->getSecond());

            }
        }
    }
    //alle markierungen zurueck auf false
    for(it = adjaz.begin(); it != adjaz.end(); it++){
        it->first->setMarked(false);
    }   
}

int DirectedGraph::dijkstra(string st, string go, int c){
    cout << st << go;
    Node* start = this->findNode(st);
    Node* target = this->findNode(go);
    if(start == NULL || target == NULL){
        return -2;
    } else {
        cout << "1";
        this->single_shortest_path(start);
        cout << "2";
        Node* tmp = target;
        int count = 0;
        while(tmp != start){
            cout << "ping";
            count++;
            tmp = tmp->getPrev();
        }
        if(count <=c){
            return count;
        } else {
            return -1;
        }
    }
}