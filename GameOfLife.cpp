#include <bits/stdc++.h>
using namespace std;

class Universe {
    char grid[20][20] = {};
public:
    const int rows = 20, cols = 20;

    void reset() {
        for (auto &i: grid) {
            for (auto &j: i) {
                j = 0;
            }
        }
    }

    void set(int x, int y, char val) {
        grid[x][y] = val;
    }

    void initialize() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (rand() % 2)
                    set(i, j, (char) 220);
    }

    int CountNeighbors(int x, int y) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (!((i == x && j == y) || (i < 0 || j < 0) || (i >= 20 || j >= 20)))
                    if (grid[i][j] == (char) 220)
                        count++;
            }
        }
        return count;
    }

    void display() {
        for (auto &i: grid) {
            for (auto j: i) {
                cout << j << " ";
            }
            cout << endl;
        }
        _sleep(500);
        system("cls");
    }

    void NextGeneration() {
        int neighbors[20][20] = {0};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                neighbors[i][j] = CountNeighbors(i, j);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (neighbors[i][j] < 2 || neighbors[i][j] > 3) {
                    grid[i][j] = ' ';
                } else if (neighbors[i][j] == 3) {
                    grid[i][j] = (char) 220;
                }
            }
        }
    }

    void Run(int generations) {
        for (int i = 0; i < generations; i++) {
            NextGeneration();
            display();
        }
    }
};

int main() {
    system("color 7D");
    cout << "Welcome to the Game of Life!" << endl;
    cout << "Rules: " << endl;
    cout << "1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation." << endl;
    cout << "2. Any live cell with two or three live neighbours lives on to the next generation." << endl;
    cout << "3. Any live cell with more than three live neighbours dies, as if by overpopulation." << endl;
    cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
    cout << endl;
    cout << "Enter the number of generations: ";
    int generations;
    cin >> generations;

    Universe u;
    u.initialize();
    u.display();
    u.Run(generations);
    u.reset();
    return 0;
}

