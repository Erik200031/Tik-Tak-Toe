#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <string>
class Game{
  public:
  Game();

    private:
    void display();
    void play();
    void play_again();
    bool check_is_empty(char);
    bool check_win();
    char arr[3][3];
    char tmp;
    std::string name1;
    std::string name2;
    short index_i;
    short index_j;
    short count;
};




#endif //GAME_H_