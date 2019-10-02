
using namespace std;

class Game{
    char gameSpace[4][4];
    string playerXName;
    string playerOName;

    public:
    void setXName(string name);
    void setOName(string name);
    bool gameOver = false;
    Game();
    void fillPositionX(int x, int y);
    void fillPositionO(int x, int y);
    void printGameInfo();
    void winnerCheck();
    bool emptyCheck(int i, int j);
    void playerXTurn();
    void playerOTurn();
    bool drawCheck();
};

Game::Game(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4 ; j++){
            gameSpace[i][j] = '-';
        }
    }
    gameOver = false;
}

void Game::setXName(string name){
    playerXName = name;
}

void Game::setOName(string name){
    playerOName = name;
}

void Game::playerXTurn(){
    int x,y;
    cout << "insert position of X: ";
    cin >> x >> y;
    fillPositionX(x,y);
}

void Game::playerOTurn(){
    int x,y;
    cout << "insert position of O: ";
    cin >> x >> y;
    fillPositionO(x,y);
}

bool Game::emptyCheck(int i, int j){
    if (gameSpace[i][j] != '-'){
        return false;
    }
    else{
        return true;
    }

}

void Game::fillPositionX(int x, int y){
    if(x > 3 || y > 3){
        cout << "Please choose x and y in range\n";
        playerXTurn();
    }
    else{
        if (emptyCheck(x,y) == true){
            gameSpace[x][y] = 'X';
        }
        else{
            cout << "This slot is taken, please choose another coordinates\n";
            playerXTurn();

        }
    }
}

void Game::fillPositionO(int x, int y){
    if(x > 3 || y > 3){
        cout << "Please choose x and y in range\n";
        playerOTurn();
    }
    else{
        if (emptyCheck(x,y) == true){
            gameSpace[x][y] = 'O';
        }
        else {
            cout << "This slot is taken, please choose another coordinates \n";
            playerOTurn();
        }
    }
}

void Game::printGameInfo(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4 ; j++){
            cout << " " << gameSpace[i][j];
        }
        cout << "\n";
    }
}

void Game::winnerCheck(){
     int Xcount_diag = 0;
     int Ocount_diag = 0;
     int Xcount_diag_right = 0;
     int Ocount_diag_right = 0;

    for (int i=0; i<4; i++){
        int Xcount_horiz = 0;
        int Ocount_horiz = 0;

        int Xcount_vert = 0;
        int Ocount_vert = 0;

        for (int j=0; j<4; j++){
            if (gameSpace[i][j] == 'X'){
                Xcount_horiz += 1;
            }
            else if (gameSpace[i][j] == 'O'){
                Ocount_horiz += 1;
            }
            if (gameSpace[j][i] == 'X'){
                Xcount_vert +=1;
            }
            else if (gameSpace[j][i] == 'O'){
                Ocount_vert += 1;
            }

        }
         if (gameSpace[i][i] == 'X'){
                Xcount_diag += 1;
        }
        else if (gameSpace[i][i] == 'O'){
            Ocount_diag += 1;
        }
        if (gameSpace[i][3-i] == 'X'){
            Xcount_diag_right += 1;

        }
        else if (gameSpace[i][3-i] == 'O'){
            Ocount_diag_right += 1;
        }
     if (Xcount_horiz == 4 || Xcount_vert == 4 || Xcount_diag == 4 || Xcount_diag_right == 4){
        cout << "Player X won, congrats " << playerXName << "\n";
        gameOver = true;
    }
    else if (Ocount_horiz == 4 || Ocount_vert == 4 || Ocount_diag== 4 || Ocount_diag_right == 4){
        cout << "Player O won, congrats " << playerOName << "\n";
        gameOver = true;
    }
    }
}

bool Game::drawCheck(){
    bool check = false;
   for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        if(emptyCheck(i,i) == false){
            check = true;
        }
        else{
            return false;
        }
    }
   }
   if(check == true){cout << "Game Draw\n\n";}
   return check;
}

