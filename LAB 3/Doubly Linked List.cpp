#include <iostream>
#include <string>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string nameVal) {
        name = nameVal;
        next = nullptr;
        prev = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;
    Node* tail; // Optional, but useful for fast delete_last()

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add element to the end
    void add_element(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display list from head to tail
    void display_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Delete the last node only
    void delete_last() {
        if (tail == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        // Only one node in the list
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* toDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete toDelete;
        }
    }
};

// Main function
int main() {
    LinkedList list;

    list.add_element("Alice");
    list.add_element("Bob");
    list.add_element("Charlie");

    cout << "Initial List:\n";
    list.display_list();

    cout << "\nDeleting last node:\n";
    list.delete_last();
    list.display_list();

    cout << "\nDeleting again:\n";
    list.delete_last();
    list.display_list();

    cout << "\nDeleting last remaining node:\n";
    list.delete_last();
    list.display_list();

    cout << "\nTrying to delete from empty list:\n";
    list.delete_last();

    return 0;
}
