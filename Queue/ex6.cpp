// Given a n*m grid where each cell in the grid can have a value of 0, 1 or 2, which has the following meaning:
// 1. Empty cell
// 2. This cell contains a fresh apple
// 3. This cell contains a rotten apple
// After 1 second, the cell with rotten apple will rot all fresh apples in all the cells adjacent to it (i.e the cells (x+1, y), (x-1, y), (x, y+1), (x, y-1))
// Determine the minimum time (in seconds) required to rot all apples. If this cannot be done, return -1.
// Note: iostream, vector, and queue are already included.

// Constraint:
// 1 <= n, m <= 500

// Hint: Have you ever heard about breadth-first-search?

// Example 1:
// Input: grid = {{2,2,0,1}}
// Output: -1
// Explanation:
// The grid is
// 2 2 0 1
// The apple at (0, 3) cannot be rotten

// Example 2:
// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation:
// The grid is
// 0 1 2
// 0 1 2
// 2 1 1
// Apples at positions (0,2), (1,2), (2,0)
// will rot apples at (0,1), (1,1), (2,2) and (2,1) after 1 second.



// iostream, vector and queue are included
// Hint: use breadth-first-search
#include<bits/stdc++.h>
using namespace std;

int secondsToBeRotten(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh_count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh_count++;
            }
        }
    }

    int time = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty() && fresh_count > 0) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto current = q.front();
            q.pop();
            for (auto dir : directions) {
                int new_r = current.first + dir.first;
                int new_c = current.second + dir.second;
                if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && grid[new_r][new_c] == 1) {
                    grid[new_r][new_c] = 2;
                    fresh_count--;
                    q.push({new_r, new_c});
                }
            }
        }
        if (!q.empty()) {
            time++;
        }
    }

    return fresh_count == 0 ? time : -1;
}
