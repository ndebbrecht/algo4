/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueue.h
 * Author: sandragall
 *
 * Created on November 21, 2017, 6:16 PM
 */

#ifndef PRIORITATENWARTESCHLANGE_H
#define PRIORITATENWARTESCHLANGE_H

#include "PQelement.h"

class PriorityQueue{
private:
    int n; /* aktuelle Laenge */
    int length; /* Gesamtlaenge=Aufnahmekapazitaet */
    PQelement *a; /* fuer das Feld */
    int *referenzfeld;
    
public:
    PriorityQueue(){};
    PriorityQueue(int l);

    PQelement& minimum(void) const;
    PQelement extractMin(void);
    void insert(const PQelement& anew);
    int size();
    void downMinHeap(int i,int n,PQelement[]);
    void vertauscheElemente(int pos1, int pos2);
    
    void increase(int id, int d);
    void del(int id);
    
    void increaseRef(int id, int d);
    void delRef(int id);
};

#endif /* PRIORITATENWARTESCHLANGE_H */
