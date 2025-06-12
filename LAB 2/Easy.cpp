/*

	Sort a Matrix in all way increasing order

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortMatrix(vector<vector<int>>& matrix) 
{
    int N = matrix.size();
    vector<int> temp;

    // Step 1: Flatten the matrix into a 1D vector
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp.push_back(matrix[i][j]);

    // Step 2: Sort the flattened array
    sort(temp.begin(), temp.end());

    // Step 3: Refill the matrix in row-wise order
    int index = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = temp[index++];
}

void printMatrix(const vector<vector<int>>& matrix) 
{
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() 
{
    int N;
    cout << "Enter the order N of the square matrix: ";
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    cout << "Enter the matrix elements (with a space between each elements):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];

    sortMatrix(matrix);

    cout << "\nSorted Matrix:\n";
    printMatrix(matrix);

    return 0;
}
