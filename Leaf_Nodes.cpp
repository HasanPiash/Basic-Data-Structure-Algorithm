#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert nodes in level order
TreeNode* insertLevelOrder(int arr[], int n) {
    if (n == 0) return NULL;

    // Create the root of the tree
    TreeNode* root = new TreeNode(arr[0]);

    // Queue to keep track of nodes
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* currentNode = q.front();
        q.pop();

        // Insert the left child
        if (arr[i] != -1) {
            currentNode->left = new TreeNode(arr[i]);
            q.push(currentNode->left);
        }
        i++;

        // Insert the right child
        if (i < n && arr[i] != -1) {
            currentNode->right = new TreeNode(arr[i]);
            q.push(currentNode->right);
        }
        i++;
    }
    return root;
}

// Function to collect leaf nodes
void collectLeafNodes(TreeNode* root, vector<int>& leafNodes) {
    if (!root) return;

    // Check if the node is a leaf node
    if (!root->left && !root->right) {
        leafNodes.push_back(root->val);
    }

    // Recursively check left and right subtrees
    collectLeafNodes(root->left, leafNodes);
    collectLeafNodes(root->right, leafNodes);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, -1, 60, -1, -1, -1, -1, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = insertLevelOrder(arr, n);

    vector<int> leafNodes;
    collectLeafNodes(root, leafNodes);

    // Sort the leaf nodes in descending order
    sort(leafNodes.rbegin(), leafNodes.rend());

    // Print the leaf nodes
    for (int val : leafNodes) {
        cout << val << " ";
    }

    return 0;
}
