#include <iostream>
#include <string>
using namespace std;

// Node class
class Node {
public:
    string name;
    Node* next;
    Node* prev; // Added previous pointer for double

    Node(string nameVal) {
        name = nameVal;
        next = nullptr;
        prev = nullptr; // Initialize prev to nullptr
    }
};

// DoublyCircularLinkedList class
class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() {
        head = nullptr;
    }

    // Add element to the end
    void add_element(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself for circularity
            head->prev = head; // Point to itself for circularity (prev)
        }
        else {
            Node* tail = head->prev; // The last node is head->prev in a doubly circular list

            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Display list starting from head (forward traversal)
    void display_list_forward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly Circular Linked List (Forward): ";
        do {
            cout << temp->name;
            temp = temp->next;
            if (temp != head) {
                cout << " <-> ";
            }
        } while (temp != head);
        cout << " <-> " << head->name << "\n";
    }

    // Display list starting from tail (backward traversal)
    void display_list_backward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head->prev; // Start from the last node
        cout << "Doubly Circular Linked List (Backward): ";
        do {
            cout << temp->name;
            temp = temp->prev;
            if (temp != head->prev) { // Check if loop back to the original tail
                cout << " <-> ";
            }
        } while (temp != head->prev);
        cout << " <-> " << head->prev->name << "\n"; // Show the circular link back to the tail
    }
};

// Main function
int main() {
    DoublyCircularLinkedList list;

    list.add_element("Jaun");
    list.add_element("Bob");
    list.add_element("Charlie");
    list.add_element("David");

    list.display_list_forward();
    list.display_list_backward();

    return 0;
}
