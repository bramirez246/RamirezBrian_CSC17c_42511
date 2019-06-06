/* 
 * File:   main.cpp
 * Author: Brian Ramirez
 *
 * Created on April 11, 2019, 1:56 PM
 */

// Include libraries
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include "tictac.h"
#include "AI.h"
using namespace std;

int main(int argc, char** argv) {
    // Declare and initialize variables
    int choice=0;
    bool retry=true;
    Board tictac1;
    AI tictac2;
    
    // Ask player(s) what mode they would like to play
    cout << "Select one of the following modes: " << endl;
    cout << "\t1. Human vs. Human \n\t2. Human vs. Comp (you play as 'X')\n" << endl;
    
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1 || choice == 2)
            retry = false;
        else{
            retry = true;
            cout << "Invalid input, try again." << endl;
        }
    }while(retry==true);
    cout << endl;
    
    // There are 2 cases that can happen
    // If players choose option 1 then run pvp mode
    // if option 2 run player vs cpu mode
    switch(choice){
        case 1: tictac1.play_pvp();
           break;
        case 2: tictac2.play_cpu();
            break;
        default: cout << "Invalid input, try again.\n";
            break;
    }
    
    return 0;
}
