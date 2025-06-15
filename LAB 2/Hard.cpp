/*

  Largest Rectangular Area in a Histogram using Segment Tree

  Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
  For simplicity, assume that all bars have same width and the width is 1 unit. 

*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Segment tree node structure
struct SegmentTreeNode 
{
    int minIndex; // Index of minimum value in the range
    int left, right; // Range represented by this node
    SegmentTreeNode* leftChild;
    SegmentTreeNode* rightChild;

    SegmentTreeNode(int l, int r) : left(l), right(r), leftChild(nullptr), rightChild(nullptr) {}
};

// Function to build the segment tree
SegmentTreeNode* buildSegmentTree(const vector<int>& hist, int l, int r) 
{
    SegmentTreeNode* node = new SegmentTreeNode(l, r);

    if (l == r) 
    {
        node->minIndex = l;
        return node;
    }

    int mid = l + (r - l) / 2;
    node->leftChild = buildSegmentTree(hist, l, mid);
    node->rightChild = buildSegmentTree(hist, mid + 1, r);

    // Determine which child has the smaller value
    if (hist[node->leftChild->minIndex] < hist[node->rightChild->minIndex]) 
    {
        node->minIndex = node->leftChild->minIndex;
    }
    else 
    {
        node->minIndex = node->rightChild->minIndex;
    }

    return node;
}

// Function to query the segment tree for minimum value index in range [l, r]
int queryMinIndex(SegmentTreeNode* root, const vector<int>& hist, int l, int r) 
{
    // If current node's range is completely outside query range
    if (root->right < l || root->left > r) 
    {
        return -1;
    }

    // If current node's range is completely inside query range
    if (root->left >= l && root->right <= r) 
    {
        return root->minIndex;
    }

    // Otherwise query both children
    int leftMin = queryMinIndex(root->leftChild, hist, l, r);
    int rightMin = queryMinIndex(root->rightChild, hist, l, r);

    if (leftMin == -1) return rightMin;
    if (rightMin == -1) return leftMin;

    return (hist[leftMin] < hist[rightMin]) ? leftMin : rightMin;
}

// Recursive function to calculate maximum area
int calculateMaxArea(SegmentTreeNode* root, const vector<int>& hist, int l, int r) 
{
    if (l > r) return INT_MIN;
    if (l == r) return hist[l];

    // Find the index of the minimum value in current range
    int minIndex = queryMinIndex(root, hist, l, r);

    // Calculate maximum area for left of min, right of min, and including min
    int leftArea = calculateMaxArea(root, hist, l, minIndex - 1);
    int rightArea = calculateMaxArea(root, hist, minIndex + 1, r);
    int currentArea = hist[minIndex] * (r - l + 1);

    return max(currentArea, max(leftArea, rightArea));
}

// Main function to get largest rectangular area
int largestRectangleArea(vector<int>& heights) 
{
    if (heights.empty()) return 0;

    // Build segment tree
    SegmentTreeNode* root = buildSegmentTree(heights, 0, heights.size() - 1);

    // Calculate maximum area
    int maxArea = calculateMaxArea(root, heights, 0, heights.size() - 1);

    return maxArea;
}

int main() 
{
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;

    vector<int> hist(n);
    cout << "Enter the heights of the " << n << " bars (separated by spaces): ";
    for (int i = 0; i < n; i++) 
    {
        cin >> hist[i];
    }

    cout << "Maximum rectangular area is " << largestRectangleArea(hist) << endl;
    return 0;
}
