/*
    54. Spiral Matrix

    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example:
    Input:
    [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]
    ]
    Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

    Idea:
    Use four boundaries: top, bottom, left, right.
    Move in four directions:
        1. left → right
        2. top → bottom
        3. right → left
        4. bottom → top
    After each movement, shrink the boundary.
    Continue until boundaries cross.

    Time Complexity: O(m * n)
    Space Complexity: O(1) (apart from result vector)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        // Move left → right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        

        // Move top → bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            // Move right → left
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            // Move bottom → top
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> a = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};

    auto r1 = spiralOrder(a);
    for (int x : r1) cout << x << " ";
    cout << endl;  // Expected: 1 2 3 6 9 8 7 4 5

    vector<vector<int>> b = {{1, 2, 3, 4},
                             {5, 6, 7, 8}};

    auto r2 = spiralOrder(b);
    for (int x : r2) cout << x << " ";
    cout << endl;  // Expected: 1 2 3 4 8 7 6 5

    return 0;
}
