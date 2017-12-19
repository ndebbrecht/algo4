//
// Created by niklas_debbrecht on 19.12.2017.
//
#include "PriorityQueue.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue(int l) {
    this->length=l+1;
    this->heapSize=0;
    this->a = new Node[length];
//    this->referencefield = new int[length];
}

int PriorityQueue::size() {
    return this->heapSize;
}

void PriorityQueue::insert(const Node &anew) {
    if(heapSize<this->length){
        heapSize++;
        int pos = heapSize;
        //neues Element an Ende einfuegen
        this->a[heapSize]=anew;
        //upheap
        while((pos>1)&&(a[pos/2].getDist()>a[pos].getDist())){
            swapElements((pos/2),pos);
            pos=pos/2;
        }
//        referencefield[anew.getID()] = pos;
    }
    else{
        cout<<"heap is full!"<<endl;
    }
}
Node& PriorityQueue::minimum() const {
    return this->a[1];
}
Node* PriorityQueue::extractMin() {
    //tausch wurzel letztes
    swapElements(1,heapSize);
    heapSize--;
    downHeapMin(1,heapSize,this->a);
//    referencefield[this->a[heapSize+1].getID()]=0;
    return &this->a[heapSize+1];
}
void PriorityQueue::downHeapMin(int i, int n, Node a[]) {
    //left and right child
    int l=2*i;
    int r=2*i+1;
    int smallest;
    //first check if left child smaller
    if(l <= n && (a[l].getDist() < a[i].getDist())){
        smallest = l;
    }
    else{
        smallest = i;
    }
    //now check if right child even smaller then left, or at all smaller than a[i]
    if(r <= n && (a[r].getDist() < a[smallest].getDist())){
        smallest=r;
    }
    if(smallest !=i){
        swapElements(i,smallest);
        downHeapMin(smallest,n,a);
    }
}
void PriorityQueue::delWithRef(int id) {
    int el = 0;
    el = referencefield[id];
    if(el!=0){
        swapElements(el,heapSize);
        heapSize--;
        downHeapMin(el,heapSize,a);
    }
}
void PriorityQueue::del(string mark) {
    int el = 0;
    for(int i =1; i<this->length;i++){
        if(this->a[i].getMarkierung()==mark){
            el = i;
        }
    }
    if(el!=0){
        swapElements(el,heapSize);
        heapSize--;
        downHeapMin(el,heapSize,a);
    }
}
void PriorityQueue::increaseWithRef(int id, int d) {
    //Test ob ueberhaupt veraenderung
    if(d!=0){
        int el = 0;
        float oldPrio = 0;
        //Suche nach Element
        el = referencefield[id];
        //test ob id gefunden
        if(el!=0){
            oldPrio = this->a[el].getDist();
            float newPrio = oldPrio+d;
            this->a[el].setDist(newPrio);
            //wenn nun groesser down heap
            if(oldPrio<newPrio){
                this->downHeapMin(el,heapSize,a);
            }
                //Wenn nun kleiner upHeap
            else{
                int pos = el;
                while((pos>1)&&(a[pos/2].getDist()>a[pos].getDist())){
                    swapElements((pos/2),pos);
                    pos=pos/2;
                }
            }
        }
    }
}
void PriorityQueue::increase(string mark, int d) {
    //Test ob ueberhaupt veraenderung
    if(d!=0){
        int el = 0;
        float oldPrio = 0;
        //Suche nach Element
        for(int i =1; i<this->length;i++){
            if(this->a[i].getMarkierung()==mark){
                el = i;
            }
        }
        //test ob id gefunden
        if(el!=0){
            oldPrio = this->a[el].getDist();
            float newPrio = oldPrio+d;
            this->a[el].setDist(newPrio);
            //wenn nun groesser down heap
            if(oldPrio<newPrio){
                this->downHeapMin(el,heapSize,a);
            }
                //Wenn nun kleiner upHeap
            else{
                int pos = el;
                while((pos>1)&&(a[pos/2].getDist()>a[pos].getDist())){
                    swapElements((pos/2),pos);
                    pos=pos/2;
                }
            }
        }
    }
}

void PriorityQueue::swapElements(int pos1, int pos2) {
    this->a[pos1].swap(&(this->a[pos2]));
  //  referencefield[this->a[pos1].getID()]=pos1;
  //  referencefield[this->a[pos2].getID()]=pos2;

}
void PriorityQueue::printQueue() {
    cout<<"Print queue: "<<endl;
    for(int i=1;i<=heapSize;i++){
        //cout<<"~Element "<<i<<"~"<<endl;
        //this->a[i].printNode();
    }
    cout<<endl;
}
void PriorityQueue::update(string mark, Node* other) {
    int el = 0;
    //Suche nach Element
    for(int i = 1; i<this->length;i++){
        if(this->a[i].getMarkierung()==mark){
            el = i;
        }
    }
    //test ob id gefunden
    if(el!=0){
        float oldDist = this->a[el].getDist();

        this->a[el].setMarkierung(other->getMarkierung());
        this->a[el].setDist(other->getDist());
        this->a[el].setPrev(other->getPrev());
      //  this->a[el].setParent(other->getParent());

        float newDist = this->a[el].getDist();

        //wenn nun groesser down heap
        if(oldDist<newDist){
            this->downHeapMin(el,heapSize,a);
        }
        //Wenn nun kleiner upHeap
        else{
            int pos = el;
            while((pos>1)&&(a[pos/2].getDist()>a[pos].getDist())){
                swapElements((pos/2),pos);
                pos=pos/2;
            }
        }
    }

}