/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PQ_Referenzfeld.h
 * Author: tiseidel
 *
 * Created on 17. November 2016, 20:43
 */

#ifndef PQ_REFERENZFELD_H
#define PQ_REFERENZFELD_H

#include "Element.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

class PQ_Dijkstra {
public:
    int size;
    int maxSize;
    Element* heap;
    int* posZuIndex;

public:

    PQ_Dijkstra(int);

    ~PQ_Dijkstra();

    bool isHeap(int);
    void insert(Element);
    void insert(Node*);
    void upheap(int);
    void downheap(int);
    Node* extractMin();
    void update(int, double);
    bool empty();

    void swap(int, int);
    void swapRef(int a, int b);
    void ausgabeHeap();

    int getSize() {
        return size;
    }

    int getMaxSize() {
        return maxSize;
    }



};

#endif /* PQ_REFERENZFELD_H */

