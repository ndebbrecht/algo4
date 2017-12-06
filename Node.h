/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: niklas_debbrecht
 *
 * Created on 6. Dezember 2017, 14:32
 */

#ifndef NODE_H
#define NODE_H

namespace std;

class Node {
public:
    Node(std::string markierung);
    Node(const Node& orig);
    virtual ~Node();
    std::string getMarkierung();
    void getMarkierung(std::string markierung;
private:
    std::string markierung;

};

#endif /* NODE_H */

