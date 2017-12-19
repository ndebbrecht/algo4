/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PQelement.h
 * Author: sandragall
 *
 * Created on November 21, 2017, 6:15 PM
 */

#ifndef PQELEMENT_H
#define PQELEMENT_H

class PQelement{
private:
    int prio;
    int id;
public:
    PQelement(){}
    PQelement(int id, int prio);
    int getID()const ;
    int getPrio()const ;
    void setID(int id);
    void setPrio(int priority);
    void vertausche(PQelement* a);
    void print();
    
    
    PQelement* operator=(PQelement* other);
    bool operator<(const PQelement &other) const;
};

#endif /* PQELEMENT_H */
