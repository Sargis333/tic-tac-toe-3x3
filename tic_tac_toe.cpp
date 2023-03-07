#include <iostream>
using namespace std;
char board[9] = {};

void clear_t (){
    for( int i = 0; i<40; i++){
        cout<<endl;
    }
}
void clear(){
    for(int i = 0 ; i<9; i++){
        board[i]='-';
    }
}
bool win(char player){
    int win[][3] = {{0,1,2},{3,4,5},{6,7,8}, {0,3,6},{1,4,7},
                    {2,5,8}, {0,4,8}, {2,4,6}};
    for(int i = 0 ; i< 8; i++){
        int count = 0;
        for(int j = 0 ; j<3; j++){
            if(board[win[i][j]] == player) 
                count++;
        }
        if(count == 3){
            return true;
        }
    }
    return false;
}
void _board_(){
    cout<<"-"<<board[6]<<"-|-"<<board[7]<<"-|-"<<board[8]<<"-\n";
    cout<<"-"<<board[3]<<"-|-"<<board[4]<<"-|-"<<board[5]<<"- \n";
    cout<<"-"<<board[0]<<"-|-"<<board[1]<<"-|-"<<board[2]<<"-\n";
}
int user_input(){
    cout<<"motion selection: \n";
    cout<<"-7-|-8-|-9-\n";
    cout<<"-4-|-5-|-6- \n";
    cout<<"-1-|-2-|-3-\n";
    cout<<"\n\n";
    
    cout<<"game board: \n";
    _board_();
    cout<<"\n your move: ";
    int move;
    cin>>move;
    while(move > 9 || move < 1 || board[move-1] != '-'){
        cout<<"enter the correct value ";
        cin>>move;
    }
    return move;
}
char get_winer(){
    int turn = 1;
    while(!win('X') && !win('O')){
        clear_t();
        int move = user_input();
        cout<<"the move you entered:  "<<move<<"\n";
        if(turn %2 == 1){
            board[move-1]='X';
            if(win('X')){
                _board_();
                cout<<"X is winner!";
                return 'X';
            }
        }else{
            board[move-1]='O';
            if(win('O')){
                _board_();
                cout<<"O is winner!";
                return 'O';
            }
        }
        turn++;
        if(turn == 10){
            cout << "Draw";
            return 'D';
        }
        
    }
    return 's';
}
int main(){
    clear();
    get_winer();
}