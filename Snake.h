#pragma once

#include <vector>
#include <array>
using std::vector;
using std::array;
using tup2 = array<int, 2>; //type def

class Snake
{
public:
    // type definitions
    using body_t = vector<tup2>;

    // constructors
    Snake();
    Snake(body_t init_body, tup2 init_dir): 
        body(init_body), direction(init_dir) {}; 

    // interface
    body_t get_body() { return body; }
    void extend_body();
    void set_direction(tup2 dir) { direction = dir; }
    void take_step(tup2 );
    tup2 head() { return body[0]; }

private:
    body_t body;
    tup2 direction;
};