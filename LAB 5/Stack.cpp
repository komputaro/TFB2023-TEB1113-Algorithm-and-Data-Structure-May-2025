#include <iostream>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string name;
    Node* next;

    Node(string nameVal) {
        name = nameVal;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push element onto the stack
    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
        cout << "Pushed '" << name << "' onto the stack.\n";
    }

    // Pop element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty - nothing to pop.\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped '" << temp->name << "' from the stack.\n";
        delete temp;
    }

    // Peek at the top element
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty - nothing to peek.\n";
        }
        else {
            cout << "Top element: '" << top->name << "'\n";
        }
    }

    // Display stack
    void display() {
        Node* temp = top;
        cout << "Stack (TOP to BOTTOM): ";
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Main function
int main() {
    Stack stack;
    int choice;
    string name;

    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name to push: ";
            cin.ignore(); // To clear the input buffer
            getline(cin, name);
            stack.push(name);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
