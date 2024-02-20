#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void preOrderTraversal(TreeNode *root, vector<int> &preOrder) {
    if (root == nullptr) return;
    preOrder.push_back(root->data);
    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
}

void inOrderTraversal(TreeNode *root, vector<int> &inOrder) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->data);
    inOrderTraversal(root->right, inOrder);
}

void postOrderTraversal(TreeNode *root, vector<int> &postOrder) {
    if (root == nullptr) return;
    postOrderTraversal(root->left, postOrder);
    postOrderTraversal(root->right, postOrder);
    postOrder.push_back(root->data);
}

vector<vector<int> > getTreeTraversal(TreeNode *root) {
    vector<vector<int> > traversal(3); 
    preOrderTraversal(root, traversal[0]);
    inOrderTraversal(root, traversal[1]);
    postOrderTraversal(root, traversal[2]);
    return traversal;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int> > traversals = getTreeTraversal(root);

    cout << "Pre-order traversal: ";
    for (int num : traversals[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "In-order traversal: ";
    for (int num : traversals[1]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Post-order traversal: ";
    for (int num : traversals[2]) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
