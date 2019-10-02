#include <iostream>
#include "mainClasses.cpp"

void gameState();
void playGame();


string xPlayerName;
string oPlayerName;
int x,y;
int a,b;

int main(){

    const int Size=2;


    cout << "Player x insert your name please: \n";
    cin >> xPlayerName;

    cout << "Hello " << xPlayerName << " ,hope you enjoy the game \n\n";

    cout << "Player o insert your name please: \n";
    cin >> oPlayerName;

    cout << "Hello " << oPlayerName << " ,hope you enjoy the game \n\n";

    playGame();

    return 0;
}


void playGame(){
    Game game;
    game.setXName(xPlayerName);
    game.setOName(oPlayerName);
    game.printGameInfo();
    cout << " -------------------- \n" ;
    cout << " -------------------- \n" ;

    while (game.gameOver == false){
        cout << xPlayerName <<"'s turn \n";
        game.playerXTurn();
        game.printGameInfo();
        game.winnerCheck();
        if (game.gameOver == true){
            break;
        }

        cout << oPlayerName <<"'s turn \n";
        game.playerOTurn();
        game.printGameInfo();
        game.winnerCheck();
        game.gameOver = game.drawCheck();
    }
    gameState();

}

void gameState(){
    char state;
    cout << "Play Again (y), Quit(q)";
    cin >> state;
    switch(state){
        case 'y':
            playGame();
            break;

        case 'q':
            break;
    }
}

