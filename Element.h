/*
 * File:   Element.h
 * Author: tiseidel
 *
 * Created on 4. November 2016, 12:46
 */

#ifndef ELEMENT_H
#define ELEMENT_H


#include <cstdlib>
#include "Node.h"

using namespace std;

class Element {
    double priowert;
    int nummer;
    Node* orig;
    

public:

    Element();
    ~Element();
    Element(double, int, Node*);
    Element(Node*);
    Element& operator=(const Element& rhs);
    bool operator>=(Element& rhs);

    double getPriowert() const {
        return priowert;
    }

    int getNummer() const {
        return nummer;
    }
    
    Node* getOrig(){
        return orig;
    }

    void setPriowert(double p) {
        priowert = p;
    }

    void setNummer(int n) {
        nummer = n;
    }

    void setOrig(Node* o){
        orig = o;
    }

};




#endif /* ELEMENT_H */