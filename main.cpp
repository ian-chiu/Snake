#include <iostream>
#include "Snake.h"
#include "Game.h"
using namespace std;

int main()
{
    Game myGame;
    while(!myGame.game_over())
    {
        myGame.render();
        myGame.pilot_snake(cin);
        if(myGame.eat_apple())
        {
            myGame.gain_point();
            myGame.produce_apple();
            myGame.get_snake().extend_body();
        }            
    }
    cout << "GAME OVER" << endl;
    return 0;
}