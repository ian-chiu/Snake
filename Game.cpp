#include "Game.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ncurses.h>
using namespace std;

void Game::render()
{
    clear();
    board_type matrix = board_matrix();
    printw("Score: %d\n", score);

    //set apple position
    int a_row = apple_pos[1], a_col = apple_pos[0];
    matrix[a_row][a_col] = '0';

    //set snake position 
    for(auto pos : snake.get_body())
    {
        int row = pos[1]+1, col = pos[0]+1;
        if(pos == snake.get_body()[0])
        {
            matrix[row][col] = 'X';
        }
        else
            matrix[row][col] = 'O';
    }

    // print the board - reverse the print so (0,0) is at the left down corner
    for(int row_idx = matrix.size()-1; row_idx >= 0; row_idx--)
    {
        for(auto c : matrix[row_idx])
            addch(c);
        addch('\n');
        if(row_idx == 0) //prevent out of array problem
            break;
    }         
}

Game::board_type Game::board_matrix()
{
    vector<char> row(scr_width, ' ');
    board_type board(scr_height, row);
    //build the wall
    int maxRowIdx{scr_height-1}, maxColIdx{scr_width-1};
    board[0][0] = '+'; board[0][maxColIdx] = '+';
    board[maxRowIdx][0] = '+'; board[maxRowIdx][maxColIdx] = '+';
    for(auto itr = board[0].begin()+1; itr != board[0].end()-1; ++itr)
        *itr = '-';
    for(auto itr = board[maxRowIdx].begin()+1; itr != board[maxRowIdx].end()-1; ++itr)
        *itr = '-';
    for(auto itr = board.begin()+1; itr != board.end()-1; itr++)
    {
        (*itr)[0] = '|'; (*itr)[maxColIdx] = '|';
    }
    return board;
}

void Game::pilot_snake()
{
    int ctrl{};
    ctrl = getch();
    tup2 new_head_pos = snake.head();
    switch(ctrl)
    {
    case 119: //w
        snake.set_direction(UP);
        new_head_pos[1]++;
        break;
    case 97: //a
        snake.set_direction(LEFT);
        new_head_pos[0]--;
        break;
    case 115: //s
        snake.set_direction(DOWN);
        new_head_pos[1]--;
        break;
    case 100: //d
        snake.set_direction(RIGHT);
        new_head_pos[0]++;
        break;
    case ERR:
        if(snake.get_direciton() == UP)
            new_head_pos[1]++;
        if(snake.get_direciton() == LEFT)
            new_head_pos[0]--;
        if(snake.get_direciton() == DOWN)
            new_head_pos[1]--;
        if(snake.get_direciton() == RIGHT)
            new_head_pos[0]++;
        sleep(250);
    }
    slither(new_head_pos);
}

void Game::sleep(int millisec)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
}

void Game::slither(tup2 new_head_pos)
{

    //wrap the wall 
    if(new_head_pos[0] > scr_width - 3)
        new_head_pos[0] = 0;
    if(new_head_pos[0] < 0)
        new_head_pos[0] = scr_width - 3;
    if(new_head_pos[1] > scr_height - 3)
        new_head_pos[1] = 0;
    if(new_head_pos[1] < 0)
        new_head_pos[1] = scr_height - 3;

    snake.take_step(new_head_pos);
}

bool Game::game_over()
{
    for(int idx = 1; idx < snake.get_body().size(); ++idx)
        if(snake.head() == snake.get_body()[idx])
            return true;
    return false;
}

//TODO: produce apple where snake is not on
void Game::produce_apple()
{
    int rand_x = rand() % (scr_width-3) + 1;
    int rand_y = rand() % (scr_height-3) + 1;
    apple_pos = {rand_x, rand_y};
}

bool Game::eat_apple()
{
    tup2 board_head_pos = {snake.head()[0]+1, snake.head()[1]+1};
    if(board_head_pos == apple_pos)
        return true;
    else
        return false;
}