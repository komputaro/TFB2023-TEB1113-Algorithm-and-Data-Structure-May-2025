#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    // Insert node into BST
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        else {
            cout << "Duplicate value '" << val << "' not inserted.\n";
        }

        return node;
    }

    void add_element(int val) {
        root = insert(root, val);
    }

    // Traversals
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void display_traversals() {
        cout << "Inorder Traversal   : ";
        inorder(root);
        cout << "\n";

        cout << "Preorder Traversal  : ";
        preorder(root);
        cout << "\n";

        cout << "Postorder Traversal : ";
        postorder(root);
        cout << "\n";
    }

    Node* delete_node(Node* node, int val) {
        if (node == nullptr) {
            cout << "Value '" << val << "' not found in tree.\n";
            return node;
        }

        if (val < node->data) {
            node->left = delete_node(node->left, val);
        }
        else if (val > node->data) {
            node->right = delete_node(node->right, val);
        }
        else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with 2 children
            Node* successor = node->right;
            while (successor->left != nullptr)
                successor = successor->left;

            node->data = successor->data;
            node->right = delete_node(node->right, successor->data);
        }

        return node;
    }

    void delete_by_value(int val) {
        root = delete_node(root, val);
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int val : values) {
        bst.add_element(val);
    }

    cout << "BST Traversals:\n";
    bst.display_traversals();

    cout << "\nDeleting 20 (leaf):\n";
    bst.delete_by_value(20);
    bst.display_traversals();

    cout << "\nDeleting 30 (node with one child):\n";
    bst.delete_by_value(30);
    bst.display_traversals();

    cout << "\nDeleting 50 (node with two children):\n";
    bst.delete_by_value(50);
    bst.display_traversals();

    return 0;
}
