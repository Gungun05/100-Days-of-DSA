/*
    118. Pascal's Triangle

    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle:
    - The first and last elements of each row are always 1.
    - Every inner element is the sum of the two numbers directly above it.

    Example:
    Input: numRows = 5
    Output:
    [
        [1],
        [1,1],
        [1,2,1],
        [1,3,3,1],
        [1,4,6,4,1]
    ]

    Idea:
    Start from the first row and build each next row using the previous one.
    ans[i][j] = ans[i-1][j-1] + ans[i-1][j]

    Time Complexity: O(numRows^2)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.resize(numRows);

    for (int i = 0; i < numRows; i++) {
        ans[i].resize(i + 1);     
        ans[i][0] = 1;            
        ans[i][i] = 1;            

        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}

int main() {
    int numRows = 5;
    auto res = generate(numRows);

    for (auto &row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
