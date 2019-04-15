/* 
 * File:   tictac.h
 * Author: Brian Ramirez
 *
 * Created on April 11, 2019, 1:59 PM
 */

#ifndef TICTAC_H
#define TICTAC_H

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
#include <list>
#include <iomanip>

using namespace std;

class Board{
    private:
        char gameStatus;                // Character that is used to determine the status of game
        char play;                      // Holds user's decision when prompted if they want to play
        char token;                     // Holds the current player's character
        char changeName;                // Holds user's decision when prompted to change name
        pair<char, string> player1;
        pair<char, string> player2;
        vector < vector<char> > board{3, vector<char>(3, ' ')};
        vector < vector<char> >::iterator row;
        vector <int>::const_iterator i, j;
        
    public:
        void initBoard();
        void outputInstruct();
        void displayBoard();
        void getCheckInput();
        void getPlayers();
        void outputWinner(char);
        char checkWin();
        char switchTokens();
        char getGameStatus(){return gameStatus;}
        char getToken(){return token;}
        char getChangeName(){return changeName;}
        char getPlay(){return play;}
        void setPlay(char play){this->play=play;}
        void setChangeName(char changeN){this->changeName=changeN;}
        void setGameStatus(char gameStatus){this->gameStatus=gameStatus;}
        void setToken(){this->token='X';}
};

#endif /* TICTAC_H */
