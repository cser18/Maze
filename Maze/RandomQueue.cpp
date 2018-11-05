/***************************
Created by 涵小书 on 2018/11/5.
人生若只如初见
***************************/


#include "RandomQueue.h"

void RandomQueue::Addlast(Pos pos) {
    RQueue.push_back(pos);
}

position RandomQueue::removeLast() {
    Pos pos;
    if (RQueue.empty()) {
        cout<<"队列为空";
    }
    int index = int(rand() % RQueue.size());
    pos = RQueue[index];
    RQueue[index] = RQueue[RQueue.size() - 1];
    RQueue.pop_back();
    return pos;
}

bool RandomQueue::empty() {
    if(RQueue.size() == 0) {
        return true;
    }
    return false;
}



