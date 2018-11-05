/***************************
Created by 涵小书 on 2018/11/4.
人生若只如初见
***************************/


#include "MazeData.h"
#include<stack>
#include<vector>
#include <queue>
#include "RandomQueue.h"
const char Road = ' ';
const char Wall = '#';

void MazeData::InitMaze(int M, int N) {

    this->N = N;
    this->M = M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                maze[i][j] = Road;
            }
            else {
                maze[i][j] = Wall;
            }
            visited[i][j] = false;
        }
    }
    StartX = 1;
    StartY = 0;
    EndX = M - 2;
    EndY = N - 1;
    maze[StartX][StartY] = Road;
    maze[EndX][EndY] = Road;
}

void MazeData::PrintMaze() {
    int trow = row();
    int tcol = col();
    for (int i = 0; i < trow; i++) {

        for (int j = 0; j < tcol; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}
/*
 * 深度优先搜索
 */
void MazeData::DFSMaze(int Startx, int Starty)
{
    //将第一个作为已访问
    visited[Startx][Starty] = true;
    for(int i = 0; i < 4; i++) {
        int newX = Startx + Direct[i][0] * 2;
        int newY = Starty + Direct[i][1] * 2;
        // 边界判断
        if (EdgeCheck(newX, newY) && (!visited[newX][newY])) {
            int Wallx = Startx + Direct[i][0];
            int Wally = Starty + Direct[i][1];
            maze[Wallx][Wally] = Road;
            //system("cls");
            system("clear");    //清
            PrintMaze();
            DFSMaze(newX, newY);
        }
    }
}
//深度优先搜索非递归
void MazeData::DFSMaze_Re(int Startx, int Starty)
{
    stack<position> stack;
    Pos pos;
    pos.x = Startx;
    pos.y = Starty;
    visited[Startx][Starty] = true;
    stack.push(pos);
    while (!stack.empty()) {
        pos = stack.top();
        stack.pop();
        for (int i = 0; i < 4; i++) {
            int newX = pos.x + Direct[i][0] * 2;
            int newY = pos.y + Direct[i][1] * 2;
            if (EdgeCheck(newX, newY) && (!visited[newX][newY])) {
                int Wallx = pos.x + Direct[i][0];
                int Wally = pos.y + Direct[i][1];
                pos.x = newX;
                pos.y = newY;
                stack.push(pos);
                visited[newX][newY] = true;
                maze[Wallx][Wally] = Road;
                system("cls");
                PrintMaze();
            }
        }

    }
}




bool MazeData::EdgeCheck(int x, int y)
{
    return x >= 0 && x < row() && y >= 0 && y < col();
}


MazeData::MazeData()
{
}


MazeData::~MazeData()
{
}

/*
 * 广度优先搜索非递归
 */
void MazeData::BFSMaze_Re(int Startx, int Starty) {
    queue<position> queue;
    Pos pos;
    pos.x = Startx;
    pos.y = Starty;
    visited[Startx][Starty] = true;
    queue.push(pos);
    while (!queue.empty()) {
        pos = queue.front();
        queue.pop();
        for(int i = 0; i < 4; i++) {
            int newX = pos.x + Direct[i][0] * 2;
            int newY = pos.y + Direct[i][1] * 2;
            if (EdgeCheck(newX, newY) && (!visited[newX][newY])) {
                int Wallx = pos.x + Direct[i][0];
                int Wally = pos.y + Direct[i][1];
                pos.x = newX;
                pos.y = newY;
                queue.push(pos);
                visited[newX][newY] = true;
                maze[Wallx][Wally] = Road;
                //system("cls");
                PrintMaze();
            }
        }

    }
}
/*
 * 随机队列
 */
void MazeData::RandomMaze(int Startx, int Starty) {
    RandomQueue Queue;
    Pos pos;
    pos.x = Startx;
    pos.y = Starty;
    visited[Startx][Starty] = true;
    Queue.Addlast(pos);
    while (!Queue.empty()) {
        pos = Queue.removeLast();
        for(int i = 0; i < 4; i++) {
            int newX = pos.x + Direct[i][0] * 2;
            int newY = pos.y + Direct[i][1] * 2;
            if (EdgeCheck(newX, newY) && (!visited[newX][newY])) {
                int Wallx = pos.x + Direct[i][0];
                int Wally = pos.y + Direct[i][1];
                pos.x = newX;
                pos.y = newY;
                Queue.Addlast(pos);
                visited[newX][newY] = true;
                maze[Wallx][Wally] = Road;
                //system("cls");
                PrintMaze();
            }
        }

    }

}

