#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool checkwin(vector<vector<char>>&grid){
  char ch[10];
  for(int i=1;i<10;i++){
    int row = (i-1)/3;
    int column = (i-1)%3;
    ch[i] = grid[row][column];
  }

  if(ch[1]!='-' && ch[1]==ch[5] && ch[1]==ch[9]){return true;}
  if(ch[3]!='-' && ch[3]==ch[5] && ch[3]==ch[7]){return true;}

  if(ch[1]!='-' && ch[1]==ch[2] && ch[1]==ch[3]){return true;}
  if(ch[4]!='-' && ch[4]==ch[5] && ch[4]==ch[6]){return true;}
  if(ch[7]!='-' && ch[7]==ch[8] && ch[7]==ch[9]){return true;}

  if(ch[1]!='-' && ch[1]==ch[4] && ch[1]==ch[7]){return true;}
  if(ch[2]!='-' && ch[2]==ch[5] && ch[2]==ch[8]){return true;}
  if(ch[3]!='-' && ch[3]==ch[6] && ch[3]==ch[9]){return true;}
  
 return false;
   
}
void player1( vector<vector<char>>&grid, bool &gameover){
    start:
    cout<<"where do you want to place your mark?"<<endl;
    int x;
    cin>>x;
    if(x<1 || x>9){cout<<"invalid move"<<endl; goto start;}
    int row = (x-1)/3;
    int column = (x-1)%3;
   
    if(grid[row][column] != '-'){cout<<"invalid move"<<endl; goto start;}
    grid[row][column] = 'X';

    if (checkwin(grid) == true){gameover = true;cout<<"PLayer 1 wins!"<<endl;}
}
void player2( vector<vector<char>>&grid, bool &gameover){
       start:
    cout<<"where do you want to place your mark?"<<endl;
    int x;
    cin>>x;
    if(x<1 || x>9){cout<<"invalid move"<<endl; goto start;}
    int row = (x-1)/3;
    int column = (x-1)%3;
   
    if(grid[row][column] != '-'){cout<<"invalid move"<<endl; goto start;}
    grid[row][column] = 'O';

    if (checkwin(grid) == true){gameover = true;cout<<"PLayer 2 wins!"<<endl;}
}


int main(){                                                         
    
    vector<vector<char>> grid(3 , {'-','-','-'});
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            grid[i][j] = '-';
        }
    }
    bool gameover = false;
    int moves = 0;
    while(true){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        player1(grid,gameover); moves++;
        if(gameover){break;}
        if(moves==9){cout<<"its a tie!"<<endl;break;}

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }       

        player2(grid,gameover);moves++;
        if(gameover){break;}
        if(moves==9){cout<<"its a tie!"<<endl;break;}
    }

    for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

    return 0;
    
}