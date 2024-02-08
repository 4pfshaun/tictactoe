#include <iostream>
#include <cstdlib>
using namespace std;

class TicTacToe {
   private:
       int board[3][3] = {
          {0, 0, 0},
          {0, 0, 0},
          {0, 0, 0}
       };
   public:
       int X = 1;
       int O = -1;
       char currentPlayer = 'X';

       void clearTerminal() {
           system("cls");
       }

       void showBoard() {
          for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (this->board[i][j] == 1)
                    cout<<"X"<<" ";
                else if (this->board[i][j] == -1)
                    cout<<"O"<<" ";
                else
                    cout<<"-"<<" ";
            }
            cout<<endl;
          }
       }

       void choosePosition() {
           this->showBoard();
           int x, y;
           if (this->currentPlayer == 'X')
                cout<<"X's turn. Please choose row and column (1-3):"<<endl;
           else
                cout<<"O's turn. Please choose row and column (1-3):"<<endl;

           cin>>x>>y;
           x -= 1;
           y -= 1;

           if (this->board[x][y] != 0) {
              cout<<"This position is already occupied"<<endl;
           } else {
              if (this->currentPlayer == 'X')
                this->board[x][y] = this->X;
              else
                this->board[x][y] = this->O;
           }

           if (this->currentPlayer == 'X')
             this->currentPlayer = 'O';
           else
             this->currentPlayer = 'X';
       }

       int checkWinner() {

           //Lines

           int s;

           for (int i = 0; i < 3; i++) {
             s = 0;
             for (int j = 0; j < 3; j++)
                s += this->board[i][j];

             if (s == 3)
                return this->X;
             else if (s == -3)
                return this->O;
           }

           // Columns

           for (int j = 0; j < 3; j++) {
              s = 0;
              for (int i = 0; i < 3; i++)
                s += this->board[i][j];

              if (s == 3)
                 return this->X;
              else if (s == -3)
                 return this->O;
           }

           // Diag

           s = 0;
           for (int i = 0; i < 3; i++)
              s += this->board[i][i];

           if (s == 3)
              return this->X;
           else if (s == -3)
              return this->O;

           // 2nd diag

           s = 0;

           for (int i = 0; i < 3; i++)
              s+= this->board[i][2-i];

           if (s == 3)
              return this->X;
           else if (s == -3)
              return this->O;

           // Checking for tie

           for (int i = 0; i < 3; i++) {
              for (int j = 0; j < 3; j++)
                if (this->board[i][j] == 0)
                   return NULL;
           }

           return 2;
       }
};

int main() {
    TicTacToe game;
    int x = 0;

    while (x == 0) {
        game.choosePosition();
        int winner = game.checkWinner();
        if (winner) {
           game.clearTerminal();
           switch (winner) {
              case 1:
                 cout<<"X won";
                 x = 1;
                 break;
              case -1:
                 cout<<"O won";
                 x = 1;
                 break;
              default:
                 cout<<"It's a tie";
                 x = 1;
                 break;
           }
        }
    }

    return 0;
}
