#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    string email;
    string phoneNumber;
};

void addStudent(vector<Student>& students, int id, const string& name, const string& email, const string& phoneNumber) {
    Student newStudent = {id, name, email, phoneNumber};
    students.push_back(newStudent);
}

void displayStudents(const vector<Student>& students) {
    cout << "Student List:\n";
    for (const Student& s : students) {
        cout << "ID: " << s.id
             << ", Name: " << s.name 
             << ", Email: " << s.email
             << ", Phone: " << s.phoneNumber
             << endl;
    }
}

int main() {
    vector<Student> students;

    addStudent(students, 1001, "Alice Tan", "alice.tan@email.com", "012-3456789");
    addStudent(students, 1002, "Bob Lee", "bob.lee@email.com", "013-9876543");
    addStudent(students, 1003, "Chong Wei", "chong.wei@email.com", "014-1122334");

    displayStudents(students);

    return 0;
}
