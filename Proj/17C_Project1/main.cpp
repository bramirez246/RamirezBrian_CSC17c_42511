/* 
 * File:   main.cpp
 * Author: Brian Ramirez
 *
 * Created on April 11, 2019, 1:56 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
#include <list>
#include <iomanip>
#include <string>
#include "tictac.h"

using namespace std;

int main(int argc, char** argv) {
    char gameStatus = 'N';          // Character that is used to determine the status of game
    char play;                      // Holds user's decision when prompted if they want to play
    char changeN = 'Y';             // Holds user's decision when prompted to change name
    string player1;                 // Holds player 1's name
    string player2;                 // Holds player 2's name
    bool retry;                     // Holds 
    Board ticTac;
    
    // Output instructions
    ticTac.outputInstruct();
    
    //	Prompting players if they want to play
    cout << "Do you want to start the game (Y/N): ";
    cin >> play;
    ticTac.setPlay(play);
    cout << endl;
    
    //	While loop that runs the actual tic tac toe game
    while (play == 'Y' || play == 'y'){
        // Initializes board with blanks
        ticTac.initBoard();
        
        // Set the token
        ticTac.setToken();
        
        // Loop that runs if changeName is 'y' or 'Y'
        ticTac.setChangeName(changeN);
        if (ticTac.getChangeName() == 'Y' || ticTac.getChangeName() == 'y')
            // Calling on GetPlayers function
            ticTac.getPlayers();

        do {
            ticTac.displayBoard();
            ticTac.getCheckInput();
            ticTac.switchTokens();
            gameStatus = ticTac.checkWin();
        } while (gameStatus == 'N');

        ticTac.displayBoard();
        ticTac.setGameStatus(gameStatus);
        ticTac.outputWinner(gameStatus);

        // Prompt players to start a new game
        cout << "Do you want to play again? ";
        cin >> play;
        
        // Validate user input
        if (play == 'y' || play == 'Y' || play == 'n' || play == 'N'){
            retry = false;
        } 
        else
            retry = true;
        
        while(retry == true){
            cout << "Please enter 'y', or 'n': ";
            cin >> play;
            
            if (play == 'y' || play == 'Y' || play == 'n' || play == 'N'){
                retry = false;
            }
            
            else
                retry = true;
        }
            
        ticTac.setPlay(play);
        play = ticTac.getPlay();
        cout << endl;
        
        // Prompt players to change their names
        if (play == 'Y' || play == 'y') {
            cout << "Would you like to change your names? ";
            cin >> changeN;
            ticTac.setChangeName(changeN);
        }
    }
    
    return 0;
}
