/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PQ_Dijkstra.h"

PQ_Dijkstra::PQ_Dijkstra(int ms)
{
    size = 0;
    maxSize = ms;
    heap = new Element[maxSize+1];
    posZuIndex = new int[maxSize+1];

}

PQ_Dijkstra::~PQ_Dijkstra()
{
    delete []heap;

    delete []posZuIndex;
}


void PQ_Dijkstra::insert(Element e)
{
    if (size == maxSize) {
        cout << "Heap voll! " << endl;
        return;
    }
    size++;
    heap[size] = e;
    posZuIndex[e.getNummer()] = size;
    upheap(size);
}

void PQ_Dijkstra::insert(Node* n){
    insert(Element(n));
    
}

bool PQ_Dijkstra::empty(){
    if(size==0) return true;
    return false;
}

void PQ_Dijkstra::upheap(int pos)
{
    bool weiter = true;
    while (pos > 1 and weiter == true) {
        if (heap[pos / 2].getPriowert() >= heap[pos].getPriowert()) {
            swap(pos / 2, pos);
            swapRef(heap[pos / 2].getNummer(), heap[pos].getNummer());
            pos = pos / 2;
        } else {
            weiter = false;
        }
    }
}

void PQ_Dijkstra::downheap(int index)
{
    while (2 * index <= size) {
        int pos = 2 * index;
        if ((pos < size)) {
            if ((heap[pos].getPriowert() >= heap[pos + 1].getPriowert())) pos++;
        } //Rechter Nachfolger groesser
        if (heap[index].getPriowert() <= heap[pos].getPriowert()) break;
        swap(index, pos);
        swapRef(heap[index].getNummer(), heap[pos].getNummer());
        index = pos;
    }
}

void PQ_Dijkstra::swap(int l, int r)
{
    Element hilf;
    hilf = heap[l];
    heap[l] = heap[r];
    heap[r] = hilf;
}

void PQ_Dijkstra::ausgabeHeap()
{
    for (int i = 1; i <= getSize(); i++) {
        cout << "(ID: " << heap[i].getNummer() << ",Prio: " << heap[i].getPriowert() << ") ";
    }
    cout << endl;
}

Node* PQ_Dijkstra::extractMin()
{
    Element max = heap[1];
    heap[1] = heap[size];
    size--;
    this->downheap(1);
    return max.getOrig();

}

bool PQ_Dijkstra::isHeap(int pos)
{
    if (pos * 2 > size) return true; //Keinen Nachfolger mehr
    if (pos * 2 == size) return heap[pos].getPriowert() >= heap[pos * 2].getPriowert(); //linker Nachfolger muss kleiner oder gleich sein
    //Fehler wenn linker groesser ist, oder rechter kleiner
    if ((heap[pos].getPriowert() < heap[pos * 2].getPriowert()) || (heap[pos].getPriowert() < heap[pos * 2 + 1].getPriowert())) {
        cout << heap[pos].getPriowert() << " " << heap[pos * 2].getPriowert() << " " << heap[pos * 2 + 1].getPriowert() << endl;
        return false;
    }
    //Weitermachen mit nachfolgern
    return isHeap(pos * 2) && isHeap(pos * 2 + 1);
}

void PQ_Dijkstra::update(int id, double wert)
{
    int pos = posZuIndex[id]; //Referenzzugriff
    if (wert < heap[pos].getPriowert()) {
        heap[pos].setPriowert(wert);
        upheap(pos);
    } else if (wert > heap[pos].getPriowert()) {
        heap[pos].setPriowert(wert);
        downheap(pos);
    }
   
}

void PQ_Dijkstra::swapRef(int a, int b)
{
    int hilf = posZuIndex[a];
    posZuIndex[a] = posZuIndex[b];
    posZuIndex[b] = hilf;
}