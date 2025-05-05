#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
        if (value < node->val) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->val) {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    void printInorder(TreeNode* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int x) {
        root = insertHelper(root, x);
    }

    void print() {
        cout << "Tree values (in-order): ";
        printInorder(root);
        cout << endl;
    }
};

class AVLTree {
private:
    struct AVLNode {
        int val;
        AVLNode* left;
        AVLNode* right;
        int height;
        AVLNode(int v) : val(v), left(nullptr), right(nullptr), height(1) {}
    };

    AVLNode* root;

    int getNodeHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node) {
        if (!node) return 0;
        return getNodeHeight(node->left) - getNodeHeight(node->right);
    }

    int max(int a, int b) { return (a > b) ? a : b; }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* orphan = x->right;
        x->right = y;
        y->left = orphan;
        y->height = 1 + max(getNodeHeight(y->left), getNodeHeight(y->right));
        x->height = 1 + max(getNodeHeight(x->left), getNodeHeight(x->right));
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* orphan = y->left;
        y->left = x;
        x->right = orphan;
        x->height = 1 + max(getNodeHeight(x->left), getNodeHeight(x->right));
        y->height = 1 + max(getNodeHeight(y->left), getNodeHeight(y->right));
        return y;
    }

    AVLNode* insertHelper(AVLNode* node, int value) {
        if (!node) return new AVLNode(value);

        if (value < node->val)
            node->left = insertHelper(node->left, value);
        else if (value > node->val)
            node->right = insertHelper(node->right, value);
        else
            return node;

        node->height = 1 + max(getNodeHeight(node->left), getNodeHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && value < node->left->val)
            return rotateRight(node);

        if (balance < -1 && value > node->right->val)
            return rotateLeft(node);

        if (balance > 1 && value > node->left->val) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && value < node->right->val) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void printInorder(AVLNode* node) {
        if (!node) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int x) {
        root = insertHelper(root, x);
    }

    void print() {
        cout << "AVL tree values: ";
        printInorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    AVLTree avl;

    cout << "Testing both trees...\n\n";

    bst.insert(42);
    bst.insert(23);
    bst.insert(55);
    bst.insert(11);
    bst.print();

    avl.insert(42);
    avl.insert(23);
    avl.insert(55);
    avl.insert(11);
    avl.print();

    return 0;
}
