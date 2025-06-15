/*

    Search in a row wise and column wise sorted matrix

    Given a matrix mat[][] and an integer x, the task is to check if x is present in mat[][] or not. Every row and column of the matrix is sorted in increasing order.

*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) 
{
    if (mat.empty() || mat[0].empty()) return false;

    int rows = mat.size();
    int cols = mat[0].size();

    // Start from the top-right corner
    int i = 0, j = cols - 1;

    while (i < rows && j >= 0) 
    {
        if (mat[i][j] == x) 
        {
            return true;
        }
        else if (mat[i][j] > x) 
        {
            j--; // Move left
        }
        else 
        {
            i++; // Move down
        }
    }

    return false;
}

int main() 
{
    int rows, cols, x;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter matrix elements (row-wise, sorted in increasing order):\n";
    for (int i = 0; i < rows; i++) 
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) 
        {
            cin >> mat[i][j];
        }
    }

    cout << "Enter number to search: ";
    cin >> x;

    bool found = searchMatrix(mat, x);
    cout << (found ? "true" : "false") << endl;

    return 0;
}
