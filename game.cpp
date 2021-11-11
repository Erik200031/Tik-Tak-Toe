#include "game.h"

Game::Game()
{
  int ii=0;
  using namespace std::chrono_literals;
  system("clear");
  std::string tak="TAK";
  std::string tik= "TIK";
  std::string toe="TOE";
  int counter {};
  std::string tmp_anim= "|";
  label0:
  if(counter==100){
    goto lbl4;
  }
  std::cout<<"__________"<<tik<<"  "<<tak<<"  "<<toe<<"________";
  if(counter==25 ||  counter==50 ||counter==75 ){
    std::reverse(tik.begin(),tik.end());
    std::this_thread::sleep_for (50ms);
    std::reverse(tak.begin(),tak.end());
    std::reverse(toe.begin(),toe.end());
  }
    std::this_thread::sleep_for (20ms);
    system("clear");
    goto label1;
  label1:
  ++counter;
  std::cout<<"\n\n";
  std::cout<<"LOADING\n\n";
  std::cout<<tmp_anim<<std::endl;
  if(counter%5==0){
    tmp_anim="|"+tmp_anim;
    goto lbltmp;
  }
  lbltmp:
  std::cout<<"\n";
  std::cout<<ii<<"%"<<std::endl;
  ++ii;
    goto label0;
  lbl4:
   system("clear");

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
  std::string tak="TAK";
  std::string tik= "TIK";
  std::string toe="TOE";
  system("clear");
  std::cout<<"______________________________\n";
  std::cout<<"__________"<<tik<<"  "<<tak<<"  "<<toe<<"_______\n";
  std::cout<<"------------------------------\n";
  std::cout<<"ENTER FIRST PLAYER NAME : _\b";
  std::cin>>name1;
  std::cout<<"\nENTER SECOND PLAYER NAME : _\b";
  std::cin>>name2;

  start();
}

void Game::start()
{
  system("clear");
  std::cout<<"______________________________\n";
  std::cout<<"__________GAME STARTED________\n";
  std::cout<<"------------------------------\n\n";
  std::cout<<"  ____________\n";
  for(int i=1;i<=9;++i){
    if(i==4 || i==7){
      std::cout<<"\n  ____________\n";
    } 
    std::cout<<"| "<<i<<" |";  
  }
  std::cout<<"\n  ____________\n";
  int ch;
  std::cout<<" 0.EXIT\n 1.CONTINUE\n \nEnter your choice:  _\b";
  std::cin>>ch;
  if(!std::cin.good()){
    std::cout<<"ERROR Undefined Input!!\n";
    exit(0);
  }
  if(ch==0){
    exit(0);
  }

  display();
}
  
void Game::display()
{
  while(count<=4){
    system("clear");
    std::cout<<"  ____________\n";
    for(int i=0;i<3;++i){
      for(int j=0;j<3;++j){
        if(j==0){ 
          std::cout<<"| "<<arr[i][j]<<" |";    
        }
        else{
          std::cout<<"| "<<arr[i][j]<<" |";  
        }  
      }
      std::cout<<"\n  ____________\n";
    }
    if(count>0){
      std::cout<<"\t\t\t\t\tLast selected index : "<<index<<"\n";
      std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    enter_index();
  }
  while(count>4 && count<9){
    system("clear");
    if(check_win()){
      play_again();
    }
    if (count==8 && !check_win()){
      int tmp_in;
      std::cout<<"ERROR WINNER NOT FOUND (nichia)!!\n";
      std::cout<<"PLAY AGAIN  \n YES(1)  NO(0) \nEnter your choice:  _\b";
      std::cin>>tmp_in;
      if(tmp_in==0){
        exit(0);
      }
      else if(tmp_in==1){
        play();
      }
    }
    std::cout<<"  ____________\n";
    for(int i=0;i<3;++i){
      for(int j=0;j<3;++j){
        if(j==0){ 
         std::cout<<"| "<<arr[i][j]<<" |";    
        }
        else{
         std::cout<<"| "<<arr[i][j]<<" |";  
        }  
      }
      std::cout<<"\n  ____________\n";
    }
    if(count>0){
      std::cout<<"\t\t\t\t\tLast selected index : "<<index<<"\n";
      std::this_thread::sleep_for (std::chrono::seconds(1));
    }
    enter_index1();
  }
}
 
bool Game::check_is_empty(char checker)
{
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

bool Game::check_win()
{
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

void Game::enter_index()
{
  std::cout<<"Enter index :     (1-9)\b\b\b\b\b\b\b";
  std::cin>>index;
  if(!std::cin.good() || index<1 || index>9 ){
    std::cout<<"ERROR Undefined Input!!\n";
    exit(0);
  }
  if(index==1){
      check_is_full(arr[0][0]);
    if(check_is_empty(arr[0][0]) && count%2==0){
      arr[0][0]='X';
    }
    else if(check_is_empty(arr[0][0]) && count%2==1){
      arr[0][0]='O';
    }
  }
  else if(index==2){
    check_is_full(arr[0][1]);
    if(check_is_empty(arr[0][1]) && count%2==0){
      arr[0][1]='X';
    }
    else if(check_is_empty(arr[0][1]) && count%2==1){
      arr[0][1]='O';
    }
  }    
  else if(index==3){
    check_is_full(arr[0][2]);
    if(check_is_empty(arr[0][2]) && count%2==0){
      arr[0][2]='X';
    }
    else if(check_is_empty(arr[0][2]) && count%2==1){
      arr[0][2]='O';
    }
  }
  else if(index==4){
    check_is_full(arr[1][0]);
    if(check_is_empty(arr[1][0]) && count%2==0){
      arr[1][0]='X';
    }
    else if(check_is_empty(arr[1][0]) && count%2==1){
      arr[1][0]='O';
    }
  }
  else if(index==5){
    check_is_full(arr[1][1]);
    if(check_is_empty(arr[1][1]) && count%2==0){
      arr[1][1]='X';
    }
    else if(check_is_empty(arr[1][1]) && count%2==1){
      arr[1][1]='O';
    }
  }
  else if(index==6){
    check_is_full(arr[1][2]);
    if(check_is_empty(arr[1][2]) && count%2==0){
      arr[1][2]='X';
    }
    else if(check_is_empty(arr[1][2]) && count%2==1){
      arr[1][2]='O';
    }
  }
  else if(index==7){
    check_is_full(arr[2][0]);
    if(check_is_empty(arr[2][0]) && count%2==0){
      arr[2][0]='X';
    }
    else if(check_is_empty(arr[2][0]) && count%2==1){
      arr[2][0]='O';
    }
  }
  else if(index==8){
    check_is_full(arr[2][1]);
     if(check_is_empty(arr[2][1]) && count%2==0){
       arr[2][1]='X';
    }
    else if(check_is_empty(arr[2][1]) && count%2==1){
      arr[2][1]='O';
    }
  }
  else if(index==9){
    check_is_full(arr[2][2]);
    if(check_is_empty(arr[2][2]) && count%2==0){
      arr[2][2]='X';
    }
    else if(check_is_empty(arr[2][2]) && count%2==1){
      arr[2][2]='O';
    }
  }    
  count++;
}

void Game::enter_index1()
{
  std::cout<<"Enter index :     (1-9)\b\b\b\b\b\b\b";
  std::cin>>index;
  if(!std::cin.good() || index<1 || index>9 ){
    std::cout<<"ERROR Undefined Input!!\n";
    exit(0);
  }
  if(index==1){
    check_is_full(arr[0][0]);
    if(check_is_empty(arr[0][0]) && count%2==0 && !check_win()){
      arr[0][0]='X';
    }
    else if(check_is_empty(arr[0][0]) && count%2==1 && !check_win()){
      arr[0][0]='O';
    }
  }
  else if(index==2){
    check_is_full(arr[0][1]);
    if(check_is_empty(arr[0][1]) && count%2==0 && !check_win()){
      arr[0][1]='X';
    }
    else if(check_is_empty(arr[0][1]) && count%2==1 && !check_win()){
      arr[0][1]='O';
    }
  }    
  else if(index==3){
    check_is_full(arr[0][2]);
    if(check_is_empty(arr[0][2]) && count%2==0&& !check_win()){
      arr[0][2]='X';
    }
    else if(check_is_empty(arr[0][2]) && count%2==1&& !check_win()){
      arr[0][2]='O';
    }
  }
  else if(index==4){
    check_is_full(arr[1][0]);
    if(check_is_empty(arr[1][0]) && count%2==0&& !check_win()){
      arr[1][0]='X';
    }
    else if(check_is_empty(arr[1][0]) && count%2==1&& !check_win()){
      arr[1][0]='O';
    }
  }
  else if(index==5){
    check_is_full(arr[1][1]);
    if(check_is_empty(arr[1][1]) && count%2==0&& !check_win()){
      arr[1][1]='X';
    }
    else if(check_is_empty(arr[1][1]) && count%2==1&& !check_win()){
      arr[1][1]='O';
    }
  }
  else if(index==6){
    check_is_full(arr[1][2]);
    if(check_is_empty(arr[1][2]) && count%2==0&& !check_win()){
      arr[1][2]='X';
    }
    else if(check_is_empty(arr[1][2]) && count%2==1&& !check_win()){
      arr[1][2]='O';
    }
  }
  else if(index==7){
    check_is_full(arr[2][0]);
    if(check_is_empty(arr[2][0]) && count%2==0&& !check_win()){
      arr[2][0]='X';
    }
    else if(check_is_empty(arr[2][0]) && count%2==1&& !check_win()){
      arr[2][0]='O';
    }
  }
  else if(index==8){
    check_is_full(arr[2][1]);
    if(check_is_empty(arr[2][1]) && count%2==0&& !check_win()){
      arr[2][1]='X';
    }
    else if(check_is_empty(arr[2][1]) && count%2==1&& !check_win()){
      arr[2][1]='O';
    }
  }
  else if(index==9){
    check_is_full(arr[2][2]);
    if(check_is_empty(arr[2][2]) && count%2==0&& !check_win()){
      arr[2][2]='X';
    }
    else if(check_is_empty(arr[2][2]) && count%2==1&& !check_win()){
      arr[2][2]='O';
    }
  }    
  count++;
}

void Game::check_is_full(char checker)
{
  using namespace std::chrono_literals;
  if(checker=='X' || checker=='O'){
    std::cout<<"This index is full!!\n";
    std::cout<<"Please Enter right index:\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    display();
  }
}

void Game::play_again()
{
  system("clear");
  int tmp_in;
  if(count%2==0){
    std::cout<<name2<<" IS WON!!\n";
    std::cout<<"PLAY AGAIN  \n YES(1)  NO(0)  \nEnter your choice:  _\b";
  }
  else if(count%2==1){
    std::cout<<name1<<" IS WON!!\n";
    std::cout<<"PLAY AGAIN  \n YES(1)  NO(0)  \nEnter your choice:  _\b";
  }
  std::cin>>tmp_in;
  if(tmp_in==0){
    exit(0);
  }
  else if(tmp_in==1){
    play();
  }
}