// A Maze is given as 5*5 binary matrix of blocks and there is a rat initially at the upper left most block i.e., maze[0][0] and the rat wants to eat food which is present at some given block in the maze (fx, fy). In a maze matrix, 0 means that the block is a dead end and 1 means that the block can be used in the path from source to destination. The rat can move in any direction (not diagonally) to any block provided the block is not a dead end.

// Your task is to implement a function with following prototype to check if there exists any path so that the rat can reach the food or not:
// bool canEatFood(int maze[5][5], int fx, int fy);

// Template:

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

// class node {
// public:
//     int x, y;
//     int dir;
//     node(int i, int j)
//     {
//         x = i;
//         y = j;
  
//         // Initially direction
//         // set to 0
//         dir = 0;
//     }
// };

// Some suggestions: 
// - X : x coordinate of the node
// - Y : y coordinate of the node
// - dir : This variable will be used to tell which all directions we have tried and which to choose next. We will try all the directions in anti-clockwise manner starting from up.

// If dir=0 try up direction.
// If dir=1 try left direction.
// If dir=2 try down direction.
// If dir=3 try right direction.

bool isSafe(int maze[5][5], int x, int y, vector<vector<bool>>& visited) {
    return x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 1 && !visited[x][y];
}

bool canEatFoodUtil(int maze[5][5], int x, int y, int fx, int fy, vector<vector<bool>>& visited) {
    if (x == fx && y == fy) {
        return true; // Rat has reached the food.
    }

    visited[x][y] = true; // Mark the current cell as visited.

    // Possible moves (up, left, down, right)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Check if the new cell is valid and unvisited.
        if (isSafe(maze, newX, newY, visited)) {
            if (canEatFoodUtil(maze, newX, newY, fx, fy, visited)) {
                return true; // If there is a path, return true.
            }
        }
    }

    return false;
}

bool canEatFood(int maze[5][5], int fx, int fy) {
    if (maze[0][0] == 0 || maze[fx][fy] == 0) {
        return false; // Starting or food location is not valid.
    }

    vector<vector<bool>> visited(5, vector<bool>(5, false));

    return canEatFoodUtil(maze, 0, 0, fx, fy, visited);
}