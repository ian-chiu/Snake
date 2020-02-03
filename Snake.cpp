#include "Snake.h"
using namespace std;

Snake::Snake()
{
    tup2 pos0 = {0, 0}, pos1 = {1, 0}, pos2 = {2, 0}, pos3 = {3, 0};
    body = {pos3, pos2, pos1, pos0};
    direction = {1, 0}; //right
}

void Snake::take_step(tup2 pos)
{
    body.erase(body.end()-1);
    body.insert(body.begin(), pos);
}

void Snake::extend_body()
{
    
    tup2 ext_pos{};
    int last = body.size() - 1;
    Snake::body_t myBody = body;
    if(myBody[last][0] == myBody[last-1][0])
    {
        if(!myBody[last-1][1] == myBody[last][1]+1)
            ext_pos = {myBody[last][0], myBody[last][1]+1};
        else
            ext_pos = {myBody[last][0], myBody[last][1]-1};
    }
    else
    {
        if(!myBody[last-1][0] == myBody[last][0]+1)
            ext_pos = {myBody[last][0]+1, myBody[last][1]};
        else
            ext_pos = {myBody[last][0]-1, myBody[last][1]};
    }

    body.push_back(ext_pos);
}