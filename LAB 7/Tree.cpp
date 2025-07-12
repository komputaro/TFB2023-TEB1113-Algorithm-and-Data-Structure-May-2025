#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        // Set root to default node "A"
        root = new Node("A");
    }

    void add_left(string parent_name, string name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            parent->left = new Node(name);
        }
    }

    void add_right(string parent_name, string name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            parent->right = new Node(name);
        }
    }

  Node* find_node(Node* current, string name) {
        if (current == nullptr) return nullptr;
        if (current->name == name) return current;

        Node* left_search = find_node(current->left, name);
        if (left_search) return left_search;

        return find_node(current->right, name);
    }
};

int main() {
    Tree tree;

    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");

    cout << "Root: " << tree.root->name << endl;
    cout << "Left child of root: " << tree.root->left->name << endl;
    cout << "Right child of root: " << tree.root->right->name << endl;
    cout << "Left child of B: " << tree.root->left->left->name << endl;
    cout << "Right child of B: " << tree.root->left->right->name << endl;
    cout << "Left child of C: " << tree.root->right->left->name << endl;
    cout << "Right child of C: " << tree.root->right->right->name << endl;

    return 0;
}
