#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>
class Game
{
  public:
    Game();

  private:
    void start();
    void display();
    void play();
    void play_again();
    void enter_index();
    void enter_index1();
    bool check_is_empty(char);
    void check_is_full(char);
    bool check_win();
    char arr[3][3];
    char tmp;
    std::string name1;
    std::string name2;
    short index;
    short count;
};

#endif //GAME_H_