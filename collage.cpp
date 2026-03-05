#include <iostream>
using namespace std;

struct Student {
    int id;          // Unique Student ID
    string name;
    string className;
    string phone;
};

Student students[100];
int count = 0;
int nextID = 1001; // Starting Student ID

// Add a new student
void addStudent() {
    students[count].id = nextID++; // Assign and increment ID

    cout << "\nEnter Student Name: ";
    cin >> students[count].name;

    cout << "Enter Class: ";
    cin >> students[count].className;

    cout << "Enter Phone Number: ";
    cin >> students[count].phone;

    count++;

    cout << "Student added successfully! ID: " << students[count-1].id << endl;
}

// Show all students
void showStudents() {

    if(count == 0) {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";

    for(int i = 0; i < count; i++) {
        cout << "\nID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Class: " << students[i].className << endl;
        cout << "Phone: " << students[i].phone << endl;
    }
}

// Search student by any detail
void searchStudent() {

    string query;
    bool found = false;

    cout << "\nEnter any detail to search (ID, Name, Class, Phone): ";
    cin >> query;

    for(int i = 0; i < count; i++) {

        // Check if query matches ID, name, class, or phone
        if(to_string(students[i].id) == query ||
           students[i].name == query ||
           students[i].className == query ||
           students[i].phone == query) {

            cout << "\nStudent Found:\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Class: " << students[i].className << endl;
            cout << "Phone: " << students[i].phone << endl;

            found = true;
        }
    }

    if(!found)
        cout << "No matching student found.\n";
}

// Update student by ID
void updateStudent() {
    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            cout << "Enter new name: ";
            cin >> students[i].name;

            cout << "Enter new class: ";
            cin >> students[i].className;

            cout << "Enter new phone: ";
            cin >> students[i].phone;

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student ID not found.\n";
}

int main() {

    int choice;

    while(true) {
        cout << "\n===== College Admission Script =====\n";
        cout << "1 Add Student\n";
        cout << "2 Show Students\n";
        cout << "3 Search Student\n";
        cout << "4 Update Student\n";
        cout << "5 Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
            addStudent();
        else if(choice == 2)
            showStudents();
        else if(choice == 3)
            searchStudent();
        else if(choice == 4)
            updateStudent();
        else if(choice == 5)
            break;
        else
            cout << "Invalid choice\n";
    }

    return 0;
}
