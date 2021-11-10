#include "game.h"

Game::Game(){
play();
}

void Game::play()
{
    count=0;
  tmp=' ';
for(int i=0;i<3;++i){
  for(int j=0;j<3;++j){
    arr[i][j]=tmp;
  }
}
  system("clear");
  std::cout<<"______________________________\n";
  std::cout<<"__________TIK TAK TOE_________\n";
  std::cout<<"------------------------------\n";
  std::cout<<"ENTER FIRST PLAYER NAME : _\b";
  std::cin>>name1;
  std::cout<<"\nENTER SECOND PLAYER NAME : _\b";
  std::cin>>name2;
  display();
}

void Game::display(){
 while(count<=3){
    system("clear");
  if(count==0){
  std::cout<<"______________________________\n";
  std::cout<<"__________GAME STARTED_________\n";
  std::cout<<"------------------------------\n\n";
  }
   
  std::cout<<"  __0___1____2__\n";
  for(int i=0;i<3;++i){
  for(int j=0;j<3;++j){
    if(j==0){ 
      std::cout<<i<<"| "<<arr[i][j]<<" |";    
      }
      else{
    std::cout<<"| "<<arr[i][j]<<" |";  
      }  
  }
    std::cout<<"\n  _____________\n";
  }
    std::cout<<"Enter index_i : ";
    std::cin>>index_i;
    std::cout<<"Enter index_j : ";
    std::cin>>index_j;
    if(check_is_empty(arr[index_i][index_j]) && count%2==0){
      arr[index_i][index_j]='X';
    }
    else if(check_is_empty(arr[index_i][index_j]) && count%2==1){
      arr[index_i][index_j]='O';
    }
    count++;
  }
  while(count>=4 && count<9){
    system("clear");
     
  std::cout<<"  __0___1____2__\n";
  for(int i=0;i<3;++i){
  for(int j=0;j<3;++j){
    if(j==0){ 
      std::cout<<i<<"| "<<arr[i][j]<<" |";    
      }
      else{
    std::cout<<"| "<<arr[i][j]<<" |";  
      }  
  }
    std::cout<<"\n  _____________\n";
  }
    std::cout<<"Enter index_i : ";
    std::cin>>index_i;
    std::cout<<"Enter index_j : ";
    std::cin>>index_j;
    if(check_is_empty(arr[index_i][index_j]) && count%2==0 && !check_win()){
      arr[index_i][index_j]='X';
    }
    else if(check_is_empty(arr[index_i][index_j]) && count%2==1 && !check_win()){
      arr[index_i][index_j]='O';
    }
    else{
      play_again();
    }
    count++;
  
  }

}
void Game::play_again(){
  system("clear");
  int tmp_in;
  if(count%2==0){
    std::cout<<name2<<" IS WON!!\n";
    std::cout<<"PLAY AGAIN  \n YES(1)  NO(0) ";
  }
   else if(count%2==1){
    std::cout<<name1<<" IS WON!!\n";
    std::cout<<"PLAY AGAIN  \n YES(1)  NO(0) ";
  }
  else if (count ==  8 && check_win()){
    std::cout<<"ERROR WINNER NOT FOUND (nichia)!!\n";
    std::cout<<"PLAY AGAIN  \n YES(1)  NO(0) ";
  }
      std::cin>>tmp_in;
      if(tmp_in==0){
        exit(0);
      }
      else if(tmp_in==1){
        play();
    }

}
    
bool Game::check_is_empty(char checker){
  bool flag=false;
  if(count%2==1){
    if(checker==' '){
      flag= true;
    }
    else
    flag = false;
  }
  else if(count%2==0){
        if(checker==' '){
      flag= true;
    }
    else{
    flag= false;
    }
  }
  
  return flag;
}

  bool Game::check_win(){
      bool flag=false;
      //horizonal
 if(arr[0][0]!=' ' && arr[0][0]==arr[0][1] && arr[0][1]==arr[0][2]){
   flag=true;
 }
 else if(arr[1][0]!=' ' && arr[1][0]==arr[1][1] && arr[1][1]==arr[1][2]){
   flag=true;
 }
   else if(arr[2][0]!=' ' && arr[2][0]==arr[2][1] && arr[2][1]==arr[2][2]){
   flag=true;
 } 
//vertical
  if(arr[0][0]!=' ' && arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0]){
   flag=true;
 }
 else if(arr[0][1]!=' ' && arr[0][1]==arr[1][1] && arr[1][1]==arr[2][1]){
   flag=true;
 } 
  else if(arr[0][2]!=' ' && arr[0][2]==arr[1][2] && arr[1][2]==arr[2][2]){
   flag=true;
 } 
 //diagonal
   if(arr[0][0]!=' ' && arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]){
   flag=true;
 } 
   else if(arr[2][0]!=' ' && arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2]){
   flag=true;
 } 
 return flag;
 }
