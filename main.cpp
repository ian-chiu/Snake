#include <iostream>
#include "Snake.h"
#include "Game.h"
#include <ncurses.h>
using namespace std;

void initial();

int main()
{
    Game myGame;
    initial();
    while(!myGame.game_over())
    {
        myGame.render();
        myGame.pilot_snake();
        if(myGame.eat_apple())
        {
            myGame.gain_point();
            myGame.produce_apple();
            myGame.get_snake().extend_body();
        }            
    }
    cout << "GAME OVER" << endl;
    endwin();
    return 0;
}

void initial()                     /* 自定開啟 curses 函式 */
{
    initscr();
    cbreak();
    nonl();
    noecho();
    intrflush(stdscr,FALSE);
    keypad(stdscr,TRUE);
    nodelay(stdscr, TRUE);
    refresh();
}