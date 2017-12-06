/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 6. Dezember 2017, 14:36
 */

#include "Edge.h"
#include "Node.h"

float weight;
Node* first;
Node* second;


Edge::Edge(float weight, Node* first, Node* second) {
    this->first = first;
    this->second = second;
    this->weight = weight;
}

Edge::Edge(const Edge& orig) {
}

Edge::~Edge() {
}

void Edge::setFirst(Node* first){
    this->first = first;
}

void Edge::setSecond(Node* second){
    this->second = second;
}

void Edge::setWeight(float weight){
    this->weight = weight;
}

float Edge::getWeight(){
    return this->weight;
}

Node* Edge::getFirst(){
    return this->first;
}

Node* Edge::getSecond(){
    return this->second;
}