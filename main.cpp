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
    if(argc==2){
        graph.insertData(string(argv[1]));
    } else {
        printf("Np file was initialized!\n");
        return 1;
    }
    
    bool weiter = true;
    while(weiter){
        cout << "[s]tarte Navigation\nstarte Navigation mit dem [d]ijkstra-Algorithmus\n[z]eige Städte\n[b]eenden\n>";
        char choice;
        scanf("%c",&choice);
        if(choice == 'b'){
            cout << "\nAuf Wiedersehen!" << endl;
            weiter = false;
        } else if(choice == 'z'){
            graph.printNodes();
            char y;
            scanf("%c",&y);
            weiter = true;
        } else {
            cout << choice << "Bitte Startort eingeben!\n>";
            char start[50];
            scanf("%50s", &start[0]);
            fflush(stdin);
            string a = string(start);
            cout << "Bitte Zielort eingeben!\n>";
            char ziel[50];
            scanf("%50s", &ziel[0]);
            fflush(stdin);
            string b = string(ziel);
            cout << "Über wie viele Knoten soll die Strecke maximal gehen?\n>";
            int n = 5;
            scanf("%d", &n);
            fflush(stdin);
            int result = 0;
            if(choice == 's'){
                result = graph.findShortestWay(a, b, n);
            } else {
                result = graph.dijkstra(a, b, n);    
            }
            if(result >= 0){
                cout << "Die Strecke verläuft über " << result << " Knoten\n\n";
                if(choice == 'd'){
                    Node* target = graph.findNode(b);
                    cout << "Die Strecke von " << a << " nach " << b << " beträgt " << target->getDist() << "km\n\n";
                }
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
            char y;
            scanf("%c",&y);
            cout << "Fortfahren? (y/n)\n>";
            char x;
            fflush(stdin);
            scanf("%c",&x);
            scanf("%c",&y);
            if(x=='y'){
                weiter=true;
            } else {
                weiter=false;
            }
            
        }
    }
    
    return 0;
}