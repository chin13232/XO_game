#include <iostream>
#include <ctime>
#include <cstdlib>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer, int &scoreWin, int &scoreLose);
bool checkTie(char *spaces, int &scoreTie);
bool playAgain(int scoreWin, int scoreLose, int scoreTie);

int main(){

    int scoreWin = 0;
    int scoreLose = 0;
    int scoreTie = 0;   

    char player = 'X';
    char computer = 'O';
    bool running = true;

    while(running){
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        drawBoard(spaces);
        
        while(running){
            playerMove(spaces, player);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer, scoreWin, scoreLose)){
                running = false;
                break;
            } else if (checkTie(spaces, scoreTie)){
                running = false;
                break;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer, scoreWin, scoreLose)){
                running = false;
                break;
            } else if (checkTie(spaces, scoreTie)){
                running = false;
                break;
            }
        }
        if(playAgain(scoreWin, scoreLose, scoreTie)) {
            running = true;
        }
    }

    std::cout << '\n';
    std::cout << "THANKS FOR PLAYING!\n";

    system("pause");

    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player){
    int number;

    do
    {
        std::cout << "Enter a spot to place a marker(1-9): ";
        std::cin >> number;
        number--;

        std::cin.clear();
        fflush(stdin);

        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
    
}

void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer, int &scoreWin, int &scoreLose){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        if(spaces[0] == player){
            std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
        }
    } 
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        if(spaces[3] == player){
            std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
        }
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
       if(spaces[6] == player){
           std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
       }
    }

    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        if(spaces[0] == player){
           std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
       }
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        if(spaces[1] == player){
           std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
       }
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        if(spaces[2] == player){
           std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
       }
    }

    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        if(spaces[0] == player){
           std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
       }
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        if(spaces[2] == player){
           std::cout << "YOU WIN!";
            scoreWin++;
        } else {
            std::cout << "YOU LOSE!";
            scoreLose++;
       }
    }

    else {
        return false;
    }
    
    return true;
}

bool checkTie(char *spaces, int &scoreTie){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    scoreTie++;
    std::cout << "IT'S A TIE!\n";
    return true;
}

bool playAgain(int scoreWin, int scoreLose, int scoreTie){
    std::string userChoice;

    std::cout << "YOUR CURRENT SCORE IS:\n";
    std::cout << "WINS: " << scoreWin << " LOSES: " << scoreLose << " TIES: " << scoreTie << '\n';
    std::cout << "Do you want to play again? ('yes'-'no')";
    std::cin >> userChoice;

    if(userChoice == "yes"){
        return true;
    } else {
        return false;
    }
    return 0;
}