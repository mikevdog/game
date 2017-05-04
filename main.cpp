
//CIS 252 Final Project - MichaelVaught

/*Play the "Tieless Tic-Tac-Toe" game! Regular Tic-Tac-Toe always ends in a tie!
Are you kidding me! Boring! This game keeps going until someone wins! Exciting!

Using the tried and true public classes, functions and loops as in all assigned chapters and
chapter 19-20 recursive code instead of using a bunch of repetitive lines of code!
Functions call each other at the end of each turn.
*/

//main.cpp

#include <iostream>
#include <limits> //This is required to catch bad input by user

class tic_tac_toe //Contain all functions
{
    public: //All functions are available everywhere

    char board[3][3]; //Second Board Array
    char previousPlayerPiece; //variable for multiple functions
    char previousPlayer2Piece; //varibable for multiple functions

    void init_board()//The board
    {
        //initializes a blank board
        for(int a = 0; a < 3; a++){
            std::cout << "\n";
            for (int b = 0; b < 3; b++){
                board[a][b] = '-';
                std::cout << board[a][b];
            }
        }
    }

    void print_board(char playerPiece, int pos1 = 0, int pos2 = 0)//Displays the Board
    {
        //prints out the updated board when called
        for(int a = 0; a < 3; a++){
            std::cout << "\n";
            for (int b = 0; b < 3; b++){
                board[pos1][pos2] = playerPiece;
                std::cout << board[a][b];
            }
        }
    }

    int check_for_overlap(int pos1, int pos2, char playerPiece)//Prevents overlapping selections in a game. Very recursive and loopy
    {
        switch(pos1)
        {
        case 1:
            if (pos2 == 1){
                if (board[0][0] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
            if (pos2 == 2){
                if (board[0][1] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
            if (pos2 == 3){
                if (board[0][2] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
        case 2:
            if (pos2 == 1){
                if (board[1][0] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
            if (pos2 == 2){
                if (board[1][1] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
            if (pos2 == 2){
                if (board[1][2] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
        case 3:
            if (pos2 == 1){
                if (board[2][0] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
            if (pos2 == 2){
                if (board[2][1] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
            if (pos2 == 3){
                if (board[2][2] != '-'){
                    std::cout << "\nYou selected a grid that was already selected!" << std::endl;
                    return true;
                }
            }
        }
        return false;
    }

    void update_board(char playerPiece)
    {
        //updates the board based on user input
        int x, y;
        std::cout << "Enter a grid position to place the " << playerPiece << " on the board" << std::endl;
        while (true){
            std::cout << "Enter row: " << std::endl;
            std::cin >> x;
            if (x < 1 || x > 3 || std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Your number is not valid. Try it again. " << std::endl;
            } else {
                break;
            }
        }

        while (true)
        {
            std::cout << "Enter column: " << std::endl;
            std::cin >> y;
            if (y < 1 || y > 3 || std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Your number is invalid. Try again. " << std::endl;
            } else {
                break;
            }
        }

       if (check_for_overlap(x, y, previousPlayerPiece) == true){
            x--;y--;print_board(previousPlayer2Piece, x, y);
            std::cout << "\nThe board has been re-set. Try again!" << std::endl;
       }
       else if (check_for_overlap(x, y, previousPlayer2Piece) == true){
            x--;y--;print_board(previousPlayerPiece, x, y);
            std::cout << "\nThe board has been re-set. Try it again." << std::endl;
       } else {
            x--;y--;print_board(playerPiece, x, y);
        }
     }

    //Slightly recursive

    int check_for_win(char playerPiece)
    {
        /*Looks to see if playerPiece occupies that grid location.
        If the player gets 3 in  a row, print that playerPiece has won
        and exit the current game.*/

        if (board[0][0] == playerPiece && board[0][1] == playerPiece && board[0][2] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[1][0] == playerPiece && board[1][1] == playerPiece && board[1][2] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[2][0] == playerPiece && board[2][1] == playerPiece && board[2][2] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[0][0] == playerPiece && board[1][0] == playerPiece && board[2][0] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[0][1] == playerPiece && board[1][1] == playerPiece && board[2][1] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[0][2] == playerPiece && board[1][2] == playerPiece && board[2][2] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[0][0] == playerPiece && board[1][1] == playerPiece && board[2][2] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
        else if(board[0][2] == playerPiece && board[1][1] == playerPiece && board[2][0] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        } else {
            return false;
          }
    }
};

//More slicing!

void run_game()
{
    char letter_o = 'O';
    char letter_x = 'X';
    tic_tac_toe ttt; //creates an object "ttt" for later use
    ttt.previousPlayerPiece = letter_x;
    ttt.previousPlayer2Piece = letter_o;
    std::cout << "Welcome to tic-tac-toe!" << std::endl;
    std::cout << "Here is the empty board (3 rows and 3 columns, using dashes): " << std::endl;
    ttt.init_board();
    while (true){
        std::cout << "\nPlayer one, take your turn\n" << std::endl;
        ttt.update_board(letter_x);
        if (ttt.check_for_win(letter_x) == true){
            break;
        }
        std::cout << "\nPlayer two, take your turn\n" << std::endl;
        ttt.update_board(letter_o);
        if (ttt.check_for_win(letter_o) == true){
            break;
        }
    }
}

int main() //Driver calls "run_game() function"
{
    run_game();
    return 0;
}
