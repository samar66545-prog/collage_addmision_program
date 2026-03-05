#include <iostream>
using namespace std;

struct Student {
    string name;
    string className;
    string phone;
};

Student students[100];
int count = 0;

void addStudent() {
    cout << "\nEnter Student Name: ";
    cin >> students[count].name;

    cout << "Enter Class: ";
    cin >> students[count].className;

    cout << "Enter Phone: ";
    cin >> students[count].phone;

    count++;

    cout << "Student added successfully!\n";
}

void showStudents() {

    if(count == 0) {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";

    for(int i = 0; i < count; i++) {
        cout << "\nName: " << students[i].name << endl;
        cout << "Class: " << students[i].className << endl;
        cout << "Phone: " << students[i].phone << endl;
    }
}

void searchStudent() {

    string query;
    bool found = false;

    cout << "\nEnter any detail (name/class/phone): ";
    cin >> query;

    for(int i = 0; i < count; i++) {

        if(students[i].name == query ||
           students[i].className == query ||
           students[i].phone == query) {

            cout << "\nStudent Found\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Class: " << students[i].className << endl;
            cout << "Phone: " << students[i].phone << endl;

            found = true;
        }
    }

    if(!found) {
        cout << "No matching student found.\n";
    }
}

int main() {

    int choice;

    while(true) {

        cout << "\n===== College Admission Script =====\n";
        cout << "1 Add Student\n";
        cout << "2 Show Students\n";
        cout << "3 Search Student\n";
        cout << "4 Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
            addStudent();
        else if(choice == 2)
            showStudents();
        else if(choice == 3)
            searchStudent();
        else if(choice == 4)
            break;
        else
            cout << "Invalid choice\n";
    }

    return 0;
}