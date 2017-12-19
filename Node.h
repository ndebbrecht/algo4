/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: niklas_debbrecht
 *
 * Created on 6. Dezember 2017, 14:32
 */

#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node {
public:
    Node(string markierung, int index);
    Node(const Node& orig);
    virtual ~Node();
    string getMarkierung();
    void setMarkierung(string markierung);
    void setIndex(int index);
    int getIndex();
    bool getMarked();
    void setMarked(bool marked);
    Node* getPrev();
    void setPrev(Node* prev);
private:
    string markierung;
    int index;
    bool marked;
    Node* prev;

};

#endif /* NODE_H */

