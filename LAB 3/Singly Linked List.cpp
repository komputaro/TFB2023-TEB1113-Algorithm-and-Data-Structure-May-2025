/*
  LAB 3
  DATE : 11/6/2025
  ID : 24003464
*/

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

// LinkedList class
class LinkedList {
public:

    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Add element to the end
    void add_element(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display list
    void display_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Delete node by value (name)
    void delete_by_value(string val) {
        if (head == nullptr) return;

        // If head needs to be deleted
        if (head->name == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->name != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value '" << val << "' not found in list.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
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

    cout << "\nDeleting 'Bob':\n";
    list.delete_by_value("Bob");
    list.display_list();

    cout << "\nDeleting 'Alice':\n";
    list.delete_by_value("Alice");
    list.display_list();

    cout << "\nDeleting 'Charlie':\n";
    list.delete_by_value("Charlie");
    list.display_list();

    cout << "\nTrying to delete 'David' (not in list):\n";
    list.delete_by_value("David");

    return 0;
}
