/* 
 * File:   tictac.cpp
 * Author: Brian Ramirez
 *
 * Created on April 12, 2019, 2:20 PM
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


// Initializes the board with blanks
void Board::initBoard(){
    // Initialize and resize board vector
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            this->board[i][j]= ' ';
        }
        
    }

}


/******************************************************************************
* displayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
* 	 			   1 	    2 	     3
*				 [1][1] | [1][2] | [1][3]
* 					| 	 |
* 	 1 			        | 	 |
* 				        |        |
* 				 --------------------------
* 				 [2][1] | [2][2] | [2][3]
* 					|        |
* 	 2 			        |        |
* 				        |        |
* 				 --------------------------
* 				 [3][1] | [3][2] | [3][3]
* 				        |        |
* 	 3 				|        |
*					|        |
*
* RETURNS: nothing
* -> outputs the current state of the board
*****************************************************************************/

void Board::displayBoard(){
    
    system("cls");
    
    cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
    for (int i=0; i < 3; i++) {
        cout << setw(7) << "[" << i + 1 << "][1] | " << "[" << i + 1;
        cout << "][2] | " << "[" << i + 1 << "][3]" << endl;
        cout << setw(14) << "|" << setw(9) << "|" << endl;

        for (int j = 0; j < 3; j++) {
            switch (j) {
                case 0: cout << i + 1 << setw(9) << this->board[i][j];
                    cout << setw(4) << "|";
                    break;

                case 1: cout << setw(4) << this->board[i][j];
                    cout << setw(5) << "|";
                    break;

                case 2: cout << setw(4) << this->board[i][j] << endl;
                    break;

                default: cout << "ERROR!\n\n";
            }
        }
        cout << setw(14) << "|" << setw(10) << "|\n";

        if (i != 2) {
            cout << setw(32) << "--------------------------\n";
        }
    }
    cout << endl << endl;
}

/******************************************************************************
* outputInstruct
* This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
*
* RETURNS: nothing
* -> Displays the instructions to the user
*****************************************************************************/
void Board::outputInstruct()
{
    cout << "*TIC-TAC-TOE" << endl << endl;
    cout << "*There are two players 'X' and 'O'. " << endl << endl;
    cout << "*X always goes first." << endl << endl;
    cout << "*Players alternate placing Xs and Os on the board until " << endl;
    cout <<	" either (a) one player has three in a row, horizontally, " << endl;
    cout << " vertically or diagonally, or (b) all nine squares are " << endl;
    cout <<	" filled." << endl << endl;
    cout << "*If a player is able to draw three X's or three O's in a " << endl;
    cout <<	" row, that player wins." << endl << endl;
    cout << "*If all nine squares are filled and neither player has " << endl;
    cout <<	" three in a row, the game is a draw." << endl << endl;
}

void Board::getPlayers(){
    string playerName="\0";
    cin.ignore(100, '\n');
    cout << "\nEnter the first player's name:  ";
    getline(cin, playerName);
    this->player1.first='X';
    this->player1.second=playerName;

    cout << "\nEnter the second player's name: ";
    getline(cin, playerName);
    this->player2.first='O';
    this->player2.second=playerName;
}

void Board::getCheckInput() {
    // Declare variables
    bool retry;
    int column;
    int row;
    
    switch (this->token) {
        case 'X': cout << this->player1.second << " it's your turn." << endl;
            break;
        case 'O': cout << this->player2.second << " it's your turn." << endl;
            break;
    }
   

    do {
        cout << "Enter your move(row then col): "<< endl;
        cin >> row;
        cin >> column;
        if (row < 1 || row > 3 || column < 1 || column > 3)
            retry = true;
        else if (this->board[row - 1][column - 1] != ' ')
            retry = true;
        else
            retry = false;
        if (retry == true){
            cout << "Invalid move, try again ";
            cin>>row;
            cin>>column;
        } else
            this->board[row - 1][column - 1] = this->token;
    } while (retry == true);
}


char Board::checkWin(){
    int r = 0; // Number for rows
    int c = 0; // Number for columns
    char W; // Winning

    // Check 3 rows of X
    if (this->board[r][c] == 'X' && this->board[r][c + 1] == 'X'
            && this->board[r][c + 2] == 'X')
        W = 'X';
    else if (this->board[r + 1][c] == 'X' && this->board[r + 1][c + 1] == 'X'
            && this->board[r + 1][c + 2] == 'X')
        W = 'X';
    else if (this->board[r + 2][c] == 'X' && this->board[r + 2][c + 1] == 'X'
            && this->board[r + 2][c + 2] == 'X')
        W = 'X';

        // Check 3 columns of X
    else if (this->board[r][c] == 'X' && this->board[r + 1][c] == 'X'
            && this->board[r + 2][c] == 'X')
        W = 'X';
    else if (this->board[r][c + 1] == 'X' && this->board[r + 1][c + 1] == 'X'
            && this->board[r + 2][c + 1] == 'X')
        W = 'X';
    else if (this->board[r][c + 2] == 'X' && this->board[r + 1][c + 2] == 'X'
            && this->board[r + 2][c + 2] == 'X')
        W = 'X';

        // Check diagonally for X
    else if (this->board[r][c] == 'X' && this->board[r + 1][c + 1] == 'X'
            && this->board[r + 2][c + 2] == 'X')

        W = 'X';
    else if (this->board[r + 2][c] == 'X' && this->board[r + 1][c + 1] == 'X'
            && this->board[r][c + 2] == 'X')
        W = 'X';
        // Check 3 rows for O
    else if (this->board[r][c] == 'O' && this->board[r][c + 1] == 'O'
            && this->board[r][c + 2] == 'O')
        W = 'O';
    else if (this->board[r + 1][c] == 'O' && this->board[r + 1][c + 1] == 'O'
            && this->board[r + 1][c + 2] == 'O')
        W = 'O';
    else if (this->board[r + 2][c] == 'O' && this->board[r + 2][c + 1] == 'O'
            && this->board[r + 2][c + 2] == 'O')
        W = 'O';
        // Check 3 columns for O
    else if (this->board[r][c] == 'O' && this->board[r + 1][c] == 'O'
            && this->board[r + 2][c] == 'O')
        W = 'O';
    else if (this->board[r][c + 1] == 'O' && this->board[r + 1][c + 1] == 'O'
            && this->board[r + 2][c + 1] == 'O')
        W = 'O';
    else if (this->board[r][c + 2] == 'O' && this->board[r + 1][c + 2] == 'O'
            && this->board[r + 2][c + 2] == 'O')
        W = 'O';
        // Check diagonally for O
    else if (this->board[r][c] == 'O' && this->board[r + 1][c + 1] == 'O'
            && this->board[r + 2][c + 2] == 'O')
        W = 'O';
    else if (this->board[r + 2][c] == 'O' && this->board[r + 1][c + 1] == 'O'
            && this->board[r][c + 2] == 'O')
        W = 'O';
        // Check if the game is a tie
    else if (this->board[r][c] != ' ' && this->board[r][c + 1] != ' '
            && this->board[r][c + 2] != ' ' && this->board[r + 1][c] != ' '
            && this->board[r + 1][c + 1] != ' ' && this->board[r + 1][c + 2] != ' '
            && this->board[r + 2][c] != ' ' && this->board[r + 2][c + 1] != ' '
            && this->board[r + 2][c + 2] != ' ')
        W = 'T';
        // Check if the game is still playing
    else
        W = 'N';

    return W;
}

char Board::switchTokens(){
    // If token is currently X, switch it to O
    if(this->token == 'X')
    {
        this->token = 'O';
    }

    // If token is currently O, switch it to X
    else
    {
        this->token = 'X';
    }
    return this->token;
}

void Board::outputWinner(char gameStatus){
    this->gameStatus=gameStatus;
    // 	Switch on winner
    switch (this->gameStatus) 
    {
        // Player X wins
        case 'X': cout << this->player1.second << " is The Winner!" << endl;
            break;

            // Player O wins
        case 'O': cout << this->player2.second << " is The Winner!" << endl;
            break;

            // Tie
        case 'T': cout << "The game is a tie, git gud." << endl;
            break;
    }
}
