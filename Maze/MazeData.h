/***************************
Created by 涵小书 on 2018/11/4.
人生若只如初见
***************************/

#ifndef MAZE_MAZEDATA_H
#define MAZE_MAZEDATA_H

#include <iostream>
using namespace std;

class MazeData {

    char maze[101][101];
    bool visited[101][101];
    int Direct[4][2] = {
            {1,  0},
            {-1, 0},
            {0, -1},
            {0,  1}
    };
private:
    int M, N;  // 迷宫行列数
    int StartX, StartY;
    int EndX, EndY;
public:
    void InitMaze(int N, int M);
    void PrintMaze();
    void DFSMaze(int Startx, int Starty);
    void DFSMaze_Re(int Startx, int Starty);
    void BFSMaze_Re(int Startx, int Starty);
    void RandomMaze(int Startx, int Starty);
    bool EdgeCheck(int x, int y);
    int row() { return M; }
    int col() { return N; }
    int startx() { return StartX;}
    int starty() { return StartY; }
    int endx() { return EndX; }
    int endy() { return EndY; }
public:
    MazeData();
    ~MazeData();
};


#endif //MAZE_MAZEDATA_H
