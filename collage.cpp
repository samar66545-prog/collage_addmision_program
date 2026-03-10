#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    string className;
    string phone;
};

Student students[100];
int count = 0;
int nextID = 1001;

// Save students to file
void saveToFile() {
    ofstream file("students.csv");

    for(int i = 0; i < count; i++) {
        file << students[i].id << ","
             << students[i].name << ","
             << students[i].className << ","
             << students[i].phone << endl;
    }

    file.close();
}

// Load students from file
 void loadFromFile() {

    ifstream file("students.csv");
    string line;

    while(getline(file, line)) {

        stringstream ss(line);
        string temp;

        getline(ss, temp, ',');
        students[count].id = stoi(temp);

        getline(ss, students[count].name, ',');
        getline(ss, students[count].className, ',');
        getline(ss, students[count].phone, ',');

        if(students[count].id >= nextID)
            nextID = students[count].id + 1;

        count++;
    }

    file.close();
}

// Add student
void addStudent() {

    students[count].id = nextID++;

    cout << "\nEnter Student Name: ";
    cin >> students[count].name;

    cout << "Enter Class: ";
    cin >> students[count].className;

    cout << "Enter Phone Number: ";
    cin >> students[count].phone;

    count++;

    saveToFile(); // save after adding

    cout << "Student added successfully! ID: " << students[count-1].id << endl;
}

// Show students
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

// Search student
void searchStudent() {

    string query;
    bool found = false;

    cout << "\nEnter any detail to search (ID, Name, Class, Phone): ";
    cin >> query;

    for(int i = 0; i < count; i++) {

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

// Update student
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

            saveToFile(); // save updated data

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student ID not found.\n";
}

int main() {

    loadFromFile(); // load old students when program starts

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
