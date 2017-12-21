/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Element.cpp
 * Author: niklas_debbrecht
 * 
 * Created on 6. Dezember 2017, 14:32
 */

#include "Element.h"
#include <iostream>

Element::Element(){
    priowert = 0.0;
    nummer = 0;
}

Element::~Element(){
}

Element::Element(double _priowert, int _nummer, Node* _orig) {
    priowert = _priowert;
    nummer = _nummer;
    orig = _orig;
}

Element::Element(Node* n){
    nummer = n->getIndex();
    priowert = n->getDist();
    orig = n;
}

Element& Element::operator=(const Element& rhs) {
    this->nummer = rhs.nummer;
    this->priowert = rhs.priowert;
    this->orig = rhs.orig;

    return *this;
}

bool Element::operator>=(Element& rhs) {
    return (this->priowert >= rhs.priowert);
}