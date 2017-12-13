/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 6. Dezember 2017, 14:32
 */

#include "Node.h"
#include <string>

using namespace std;

string markierung;

Node::Node(string markierung, int index) {
    this->markierung = markierung;
    this->index = index;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

string Node::getMarkierung(){
    return this->markierung;
}

void Node::setMarkierung(string markierung){
    this->markierung = markierung;
}

int Node::getIndex(){
    return index;
}

void Node::setIndex(int index){
    this->index = index;
}