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
    myGame.memu();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
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
    nodelay(stdscr, FALSE);
    printw("GAME OVER...");
    getch();
    endwin();
    myGame.load_leaders();
    myGame.write_record();
    myGame.print_leader_board();
    return 0;
}

void initial()                     /* 自定開啟 curses 函式 */
{
    initscr();
    nonl();
    intrflush(stdscr,FALSE);
    keypad(stdscr,TRUE);
    refresh();
}