/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueue.cpp
 * Author: sandragall
 * 
 * Created on November 21, 2017, 6:16 PM
 */


#include <iostream>
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(int l) {
    this->length=l+1;
    this->n=0;
    this->a= new PQelement[length];
    
    this->referenzfeld = new int[length];
}

PQelement& PriorityQueue::minimum() const {
    return this->a[1];
}

PQelement PriorityQueue::extractMin() {
    //Wurzel und Letztes Tauschen
    vertauscheElemente(1,this->n);
    this->n--;
    
    //Heap Eigenschaft wieder herstellen
    downMinHeap(1,this->n,this->a);
    return this->a[this->n+1];
}

void PriorityQueue::insert(const PQelement &anew) {
    if(n<this->length){
        n++;
        int pos =n;
        //neues Element an Ende einfuegen
        this->a[n]=anew;
        //upheap
        while((pos>1)&&(a[pos/2].getPrio()>a[pos].getPrio())){
            vertauscheElemente((pos/2),pos);
            pos=pos/2;
        }
        referenzfeld[anew.getID()]=pos;
    }
    else{
        cout<<"Der Heap ist voll"<<endl;
    }
}

void PriorityQueue::increase(int id, int d) {
    //Gab es Veränderung
    if(d!=0){
        int el = 0;
        int oldPrio = 0;
        for(int i =1; i<this->length;i++){
            if(this->a[i].getID()==id){
                el = i;
            }
        }
        //Id gefunden?
        if(el!=0){
            oldPrio = this->a[el].getPrio();
            int newPrio = oldPrio+d;
            this->a[el].setPrio(newPrio);
            //Wenn neues Element Größer DownHeap sonst UpHeap
            if(oldPrio<newPrio){
                this->downMinHeap(el,n,a);
            }
            else{
                int pos = el;
                while((pos>1)&&(a[pos/2].getPrio()>a[pos].getPrio())){
                    vertauscheElemente((pos/2),pos);
                    pos=pos/2;
                }
            }
        }
    }
}

void PriorityQueue::del(int id) {
    int el = 0;
    for(int i =1; i<this->length;i++){
        if(this->a[i].getID()==id){
            el = i;
        }
    }
    if(el!=0){
        vertauscheElemente(el,n);
        n--;
        downMinHeap(el,n,a);
    }
}

void PriorityQueue::increaseRef(int id, int d) {
    //Gab es Veränderung
    if(d!=0){
        int el = 0;
        int oldPrio = 0;

        el = referenzfeld[id];
        //Id gefunden?
        if(el!=0){
            oldPrio = this->a[el].getPrio();
            int newPrio = oldPrio+d;
            this->a[el].setPrio(newPrio);
            //Wenn neues Element Größer DownHeap sonst UpHeap
            if(oldPrio<newPrio){
                this->downMinHeap(el,n,a);
            }
            else{
                int pos = el;
                while((pos>1)&&(a[pos/2].getPrio()>a[pos].getPrio())){
                    vertauscheElemente((pos/2),pos);
                    pos=pos/2;
                }
            }
        }
    }
}

void PriorityQueue::delRef(int id) {
    int el = 0;
    el = referenzfeld[id];
    if(el!=0){
        vertauscheElemente(el,n);
        n--;
        downMinHeap(el,n,a);
    }
}

int PriorityQueue::size() {
    return this->n;
}

void PriorityQueue::downMinHeap(int i, int n, PQelement *) {
    //Rechtes und linkes Element
    int l=2*i;
    int r=2*i+1;
    int kleinstes;
    
    if(l<=n&&(a[l]<a[i])){
        kleinstes = l;
    }
    else{
        kleinstes = i;
    }
    
    if(r<=n&&(a[r]<a[kleinstes])){
        kleinstes=r;
    }
    if(kleinstes !=i){
        vertauscheElemente(i,kleinstes);
        downMinHeap(kleinstes,n,a);
        referenzfeld[this->a[n+1].getID()]=0;
    }
}

void PriorityQueue::vertauscheElemente(int pos1, int pos2) {
    this->a[pos1].vertausche(&(this->a[pos2]));
    
    referenzfeld[this->a[pos1].getID()]=pos1;
    referenzfeld[this->a[pos2].getID()]=pos2;
}