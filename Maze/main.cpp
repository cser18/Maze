#include <iostream>
#include "MazeData.h"
using namespace std;
int main() {
    MazeData Maze;
    Maze.InitMaze(31,31);
    //Maze.DFSMaze(1,1);
    //Maze.DFSMaze_Re(1, 1);
    //Maze.BFSMaze_Re(1, 1);
    Maze.RandomMaze(1, 1);
    return 0;
}