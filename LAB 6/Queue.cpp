#include <iostream>
#include <string>
#include <vector>
#include <limits> 
using namespace std;

class ArrayQueue {
private:
    vector<string> arr; // Dynamic array to store queue elements
    int capacity;        // Maximum capacity of the queue
    int frontIndex;      // Index of the front element
    int rearIndex;       // Index of the rear element
    int currentSize;     // Current number of elements in the queue

public:
    // Constructor
    ArrayQueue(int size) {
        capacity = size;
        arr.resize(capacity); // Allocate memory for the array
        frontIndex = 0;
        rearIndex = -1; // Initialize rearIndex to -1 to indicate an empty queue
        currentSize = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return currentSize == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return currentSize == capacity;
    }

    // Add an element to the rear of the queue (enqueue)
    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue '" << name << "'.\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity; // Circular increment for rear
        arr[rearIndex] = name;
        currentSize++;
        cout << "'" << name << "' enqueued successfully.\n";
    }

    // Remove an element from the front of the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        string dequeuedName = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity; // Circular increment for front
        currentSize--;
        cout << "'" << dequeuedName << "' dequeued successfully.\n";
    }

    // Get the front element of the queue without removing it
    string front() {
        if (isEmpty()) {
            return ""; // Return an empty string to indicate no element
        }
        return arr[frontIndex];
    }

    // Display the elements in the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int count = 0;
        int i = frontIndex;
        while (count < currentSize) {
            cout << arr[i];
            if (count < currentSize - 1) {
                cout << " -> ";
            }
            i = (i + 1) % capacity;
            count++;
        }
        cout << "\n";
    }

    // Get the current size of the queue
    int size() {
        return currentSize;
    }
};

// Main function
int main() {
    int queueCapacity;
    cout << "Enter the maximum capacity for the queue: ";
    // Input validation for queue capacity
    while (!(cin >> queueCapacity) || queueCapacity <= 0) {
        cout << "Invalid input. Please enter a positive integer for capacity: ";
        cin.clear(); // Clear error flags
        // Ignore remaining characters in the input buffer up to the newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ArrayQueue myQueue(queueCapacity); // Create a queue with user-defined capacity

    int choice;
    string name;

    do {
        cout << "\n--- Queue Operations Menu ---\n";
        cout << "1. Enqueue (Add element)\n";
        cout << "2. Dequeue (Remove element)\n";
        cout << "3. View Front Element\n";
        cout << "4. Display All Elements\n";
        cout << "5. Check Queue Size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        // Input validation for menu choice
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Consume the newline character left by cin >> choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            cout << "Enter name to enqueue: ";
            getline(cin, name); // Use getline to read names with spaces
            myQueue.enqueue(name);
            break;
        case 2:
            myQueue.dequeue();
            break;
        case 3:
            if (!myQueue.isEmpty()) {
                cout << "Front element: '" << myQueue.front() << "'\n";
            }
            else {
                cout << "Queue is empty. No front element.\n";
            }
            break;
        case 4:
            myQueue.displayQueue();
            break;
        case 5:
            cout << "Current queue size: " << myQueue.size() << "\n";
            break;
        case 6:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
