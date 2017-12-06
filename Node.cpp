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

std::string markierung;

Node::Node(std::string markierung) {
    this->markierung = markierung;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

std::string Node::getMarkierung(){
    return this->markierung;
}

void Node::setMarkierung(std::string markierung){
    this->markierung = markierung;
}