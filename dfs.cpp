#include <bits/stdc++.h>
using namespace std;

const int N = 3;

vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char dir[] = {'D', 'L', 'U', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isGoal(vector<vector<int>>& b) {
    return b == goal;
}

void printBoard(vector<vector<int>>& b) {
    for (auto &row : b) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
    cout << "\n";
}

bool dfs(vector<vector<int>>& board, int x, int y, 
         set<vector<vector<int>>>& visited,
         string& path, int depth, int limit) {

    if (isGoal(board)) return true;
    if (depth > limit) return false;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            vector<vector<int>> newBoard = board;
            swap(newBoard[x][y], newBoard[newX][newY]);

            if (visited.find(newBoard) == visited.end()) {
                visited.insert(newBoard);
                path.push_back(dir[i]);

                if (dfs(newBoard, newX, newY, visited, path, depth + 1, limit))
                    return true;

                path.pop_back();  
            }
        }
    }
    return false;
}

void solveDFS(vector<vector<int>> initial, int x, int y) {
    set<vector<vector<int>>> visited;
    visited.insert(initial);

    string path = "";
    int depthLimit = 25;   // you can increase this

    if (dfs(initial, x, y, visited, path, 0, depthLimit)) {
        cout << "Solution found using DFS in " << path.size() << " moves:\n\n";
        vector<vector<int>> tmp = initial;
        int blankX = x, blankY = y;
        printBoard(tmp);

        for (char move : path) {
            int idx = string("DLUR").find(move);
            int newX = blankX + dx[idx];
            int newY = blankY + dy[idx];
            swap(tmp[blankX][blankY], tmp[newX][newY]);
            blankX = newX;
            blankY = newY;
            printBoard(tmp);
        }
    } else {
        cout << "No solution within depth limit.\n";
    }
}

int main() {
    vector<vector<int>> initial = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int x = 1, y = 2;

    cout << "Initial State:\n";
    printBoard(initial);

    cout << "Goal State:\n";
    printBoard(goal);

    cout << "\nSolving using DFS...\n\n";
    solveDFS(initial, x, y);

    return 0;
}
