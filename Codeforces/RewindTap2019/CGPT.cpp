#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_isolated(const vector<string>& grid, int i, int j, const string& direction) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (direction == "up" || direction == "down") {
        return (j == 0 || grid[i][j-1] != '*') && (j == cols-1 || grid[i][j+1] != '*');
    } else if (direction == "left" || direction == "right") {
        return (i == 0 || grid[i-1][j] != '*') && (i == rows-1 || grid[i+1][j] != '*');
    }
    return false;
}

int count_rosarios(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int rosario_count = 0;

    for (int i = 1; i < rows - 2; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            if (grid[i][j] == '*') {

                int up_count = 0;
                int k = i - 1;
                while (k >= 0 && grid[k][j] == '*' && is_isolated(grid, k, j, "up")) {
                    up_count++;
                    k--;
                }


                int left_count = 0;
                k = j - 1;
                while (k >= 0 && grid[i][k] == '*' && is_isolated(grid, i, k, "left")) {
                    left_count++;
                    k--;
                }


                int right_count = 0;
                k = j + 1;
                while (k < cols && grid[i][k] == '*' && is_isolated(grid, i, k, "right")) {
                    right_count++;
                    k++;
                }

                int down_count = 0;
                k = i + 1;
                while (k < rows && grid[k][j] == '*' && is_isolated(grid, k, j, "down")) {
                    down_count++;
                    k++;
                }


                if (up_count >= 1 && left_count >= 1 && right_count >= 1 &&
                    down_count >= up_count + 1 && down_count >= left_count + 1 && down_count >= right_count + 1) {
                    rosario_count++;
                }
            }
        }
    }

    return rosario_count;
}

int main() {
    int height, width;
    cin >> height >> width;

    
    vector<string> grid(height);
    for (int i = 0; i < height; ++i) {
        cin >> grid[i];
    }

    cout << count_rosarios(grid) << endl;

    return 0;
}
