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
    DirectedGraph graph;
    if(argc==2 || true){
        graph.insertData("OS_Map.txt"/*string(argv[1])*/);
    } else {
        printf("Np file was initialized!\n");
        return 1;
    }
    
    bool weiter = true;
    while(weiter){
        cout << "[s]tarte Navigation\n[z]eige Städte\n[b]eenden\n>";
        char choice;
        scanf("%s",&choice);
        if(choice == 'b'){
            cout << "\nAuf Wiedersehen!" << endl;
            weiter = false;
        } else if(choice == 'z'){
            graph.printNodes();
            weiter = true;
        } else {
            cout << "Bitte Startort eingeben!\n>";
            char start[50];
            scanf("%s",&start);
            cout << "Bitte Zielort eingeben!\n>";
            char ziel[50];
            scanf("%s",&ziel);
            cout << "Über wie viele Knoten soll die Strecke maximal gehen?\n>";
            char max;
            scanf("%i",&max);
            int n = max - 0;
            int result = graph.findShortestWay(string(start), string(ziel), n);
            if(result > 0){
                cout << "Die Strecke verläuft über " << result << " Knoten\n\n";
            } else {
                switch(result){
                    case -1:
                        cout << "Es konnte keine Route mit " << n << " oder weniger Knoten gefunden werden!\n" << endl;
                        break;
                    case -2:
                        cout << "Mindestens eine der eingegebenen Städte sind nicht verfügbar!\n" << endl;
                        break;
                    case -3:
                        cout << "Es existiert keine Route zwischen den eingegebenen Städten!\n" << endl;
                        break;
                }
            }
            weiter = true;
            
        }
    }
    
    return 0;
}