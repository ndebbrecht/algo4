/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: niklas_debbrecht
 *
 * Created on 6. Dezember 2017, 14:31
 */

#include <cstdlib>
#include "DirectedGraph.h"
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    DirectedGraph graph = new DirectedGraph();
    graph.insertData("OS_Map.txt");
    graph.printData();
    return 0;
}

