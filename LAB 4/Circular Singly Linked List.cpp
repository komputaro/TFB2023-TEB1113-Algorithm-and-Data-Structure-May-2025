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

// CircularLinkedList class
class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // Add element to the end
    void add_element(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself to make it circular
        }
        else {
            Node* temp = head;
            // Traverse until we reach the last node (which points back to head)
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make new node point back to head
        }
    }

    // Display list starting from head
    void display_list() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->name;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);
        cout << " -> " << head->name << "\n";
    }
};

// Main function
int main() {
    CircularLinkedList list;

    list.add_element("Jaun");
    list.add_element("Bob");
    list.add_element("Charlie");

    list.display_list();

    return 0;
}
