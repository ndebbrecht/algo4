/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prioriatenElement.cpp
 * Author: sandragall
 * 
 * Created on November 21, 2017, 6:15 PM
 */

#include <iostream>
#include "PQelement.h"

using namespace std;

PQelement::PQelement(int id, int prio){
    this->id = id;
    this->prio = prio;
};

//Getter Setter
int PQelement::getPrio() const{
    return this->prio;
}
int PQelement::getID()const {
    return this->id;
}
void PQelement::setID(int id) {
    this->id=id;
}
void PQelement::setPrio(int priority) {
    this->prio=priority;
}

void PQelement::vertausche(PQelement* a){
    PQelement hilfe = *this;
    *this=*a;
    *a=hilfe;
}

void PQelement::print() {
    cout<<"ID: "<<this->getID()<<"  Priorität: "<<this->getPrio()<<endl;
}

// = Operator für Zuweisungen
PQelement* PQelement::operator=(PQelement* other) {
    this->setID(other->getID());
    this->setPrio(other->getPrio());
    return this;
}

// kleiner als Operator für Vergleiche
bool PQelement::operator<(const PQelement &other) const {
    return (this->prio)<(other.getPrio());
}