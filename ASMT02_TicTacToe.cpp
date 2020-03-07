#include<iostream>
#include<stdlib.h>
using namespace std;
bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);
int main() {
//
// PLEASE DO NOT CHANGE main()
//
char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
displayBoard(board);
while (true) {
// The first player makes a move
makeAMove(board, 'X');
displayBoard(board);
if (isWon('X', board)) {
cout << " !!! YAY!! VICTORY!!! \n";
cout << "---> X player won <---" << endl;
exit(0);
}
else if (isDraw(board)) {
cout << "OOPS!! No winner" << endl;
exit(0);
}
// The second player makes a move
makeAMove(board, 'O');
displayBoard(board);
if (isWon('O', board)) {
cout << " !!! YAY!! VICTORY!!! \n";
cout << "--> O player won <---" << endl;
exit(0);
}
else if (isDraw(board)) {
cout << "No winner" << endl;
exit(0);
}
}

system("pause");
return 0;

}

bool isWon(char a, char board[][3]){

    for (int i = 0; i<3; i++){
        if (board[i][0] == a && board[i][1] == a && board[i][2] == a)
           return true;
        if (board[0][i] == a && board[1][i] == a && board[2][i] == a)
           return true;
    }
    if (board[0][0] == a && board[1][1] == a && board[2][2] == a)
       return true;
    if (board[0][2] == a && board[1][1] == a && board[2][0] == a)
       return true;
    return false;
}

bool isDraw(char board[][3]){

    int count = 0;
    for(int i = 0; i<3; i++){
       for (int j = 0; j<3; j++){
          if (board[i][j] == 'X' || board[i][j] == 'O')
             count++;
       }
    }
    if (count != 9)
       return false;
    if (!isWon('X', board) && !isWon('O',board))
       return true;
}

void displayBoard(char board[][3]){

   cout << "*** TIC - TAC - TOE ****\n\n";
   cout << "-------------------\n";
   for (int i = 0; i<3; i++){
       cout << "|";
       for (int j = 0; j<3; j++){
           cout << board[i][j] << "    |";
       }
       cout << endl;
       cout << "-------------------\n\n";


   }
}


void makeAMove(char board[][3], char a){

   while(true){
       cout << "Enter Your Move(0,1,2) in a ROW --> PLAYER " << a << " :";
       int b;
       cin >> b;
       int c;
       cout << "Enter Your Move(0,1,2) in a ROW --> PLAYER " << a << ":";
       cin >> c;
       if ( b < 0 || b > 2 || c < 0 || c > 2){
          cout << "You Cant Do That !! Try again\n";
       }
       else {
           if (board[b][c] != 'X' && board[b][c] != 'O'){
              board[b][c] = a;
              break;
           }
           else {
               cout << "Sorry !! Space Already Filled Try Again\n";
           }
       }
   }
}
