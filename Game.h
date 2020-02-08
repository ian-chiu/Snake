#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "Snake.h"

class Game
{
public:
    using board_type = std::vector<std::vector<char>>;
    //constructors
    Game(int w, int h, tup2 a, int s, std::string player_name): 
        scr_width(w), scr_height(h), apple_pos({w/2, h/2}), score(s) {}
    Game(): Game(23, 15, {scr_width/2, scr_height/2}, 0, "") {}

    // interface
    Snake& get_snake() { return snake; }
    void gain_point() { score++; }
    void render();
    board_type board_matrix();
    void pilot_snake();
    bool game_over();
    bool eat_apple();
    void produce_apple();
    void slither(tup2 pos);
    //TODO: leaderboard
    void memu();
    void write_record();
    void print_leader_board();
    void load_leaders();

    // directions
    tup2 UP{0, 1}, DOWN{0, -1};
    tup2 RIGHT{1, 0}, LEFT{-1, 0};
    tup2 DIAG_UP_RIGHT{1, 1}, DIAG_UP_LEFT{-1, 1};
    tup2 DIAG_DOWN_RIGHT{1, -1}, DIAG_DOWN_LEFT{-1, -1};

private:
    int scr_width;
    int scr_height;
    std::string player_name;
    Snake snake;
    tup2 apple_pos;
    int score;
    void sleep(int );
};