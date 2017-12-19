//
// Created by Milena on 08.06.2016.
//

#ifndef PRAKTIKUM4_PRIORITYQUEUE_H
#define PRAKTIKUM4_PRIORITYQUEUE_H


#include "PQElement.h"
#include "Node.h"
class PriorityQueue {
private:
    int heapSize; //aktuelle größe
    int length;	//Max größe
    Node *a; //Ein array
public:
    int *referencefield;
    PriorityQueue(int l);
    ~PriorityQueue(){delete(a); delete(referencefield);};
    void downHeapMin(int i,int n,Node a[]);
    Node& minimum(void) const;
    Node* extractMin(void);
    void insert(const Node& anew);
    int size();
    void swapElements(int pos1, int pos2);
    void increase(std::string mark, int d);
    void del(std::string mark);
    void increaseWithRef(int id, int d);
    void delWithRef(int id);
    void update(std::string mark, Node* other);
   // void updateWRef(int id, Node* other);
    void printQueue();
};



#endif //PRAKTIKUM4_PRIORITYQUEUE_H
