/***************************
Created by 涵小书 on 2018/11/5.
人生若只如初见
***************************/

#ifndef MAZE_FIRSTQUEUE_H
#define MAZE_FIRSTQUEUE_H

#include <iostream>
#include <vector>
#include "Position.h"
using namespace std;

class RandomQueue {
public:
    vector<position> RQueue;
    void Addlast(Pos pos);
    position removeLast();
    bool empty();
    //bool isRQueueEmpty();
};


#endif //MAZE_FIRSTQUEUE_H
