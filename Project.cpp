
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

int ids[MAX_STUDENTS];
string names[MAX_STUDENTS];
double marks[MAX_STUDENTS];
int studentCount = 0;

void addStudent()
{
    if (studentCount == MAX_STUDENTS)
    {
        cout << "Student list is full!\n";
        return;
    }


    int newID;

    cout << "Enter student ID: ";
    cin >> newID;

    for (int i = 0; i < studentCount; i++)
    {
        if (ids[i] == newID)
        {
            cout << "This ID already exists!\n";
            return;
        }
    }

    ids[studentCount] = newID;


    cout << "Enter student name: ";
    getline(cin >> ws, names[studentCount]);


    do
    {
        cout << "Enter student marks (0-100): ";
        cin >> marks[studentCount];

        if (marks[studentCount] < 0 ||
            marks[studentCount] > 100)
        {
            cout << "Invalid marks! Try again.\n";
        }

    } while (marks[studentCount] < 0 ||
        marks[studentCount] > 100);


    studentCount++;
    cout << "Student added successfully!\n";
}

void displayStudents()
{
    if (studentCount == 0)
    {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        cout << "\nID: " << ids[i]
            << "\nName: " << names[i]
            << "\nMarks: " << marks[i] << "\n";
    }
}

void searchStudent()
{
    int target;
    cout << "Enter student ID to search: ";
    cin >> target;

    for (int i = 0; i < studentCount; i++)
    {
        if (ids[i] == target)
        {
            cout << "Name: " << names[i]
                << "\nMarks: " << marks[i] << "\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void calculateAverage()
{
    if (studentCount == 0)
    {
        cout << "No students to calculate.\n";
        return;
    }

    double total = 0;

    for (int i = 0; i < studentCount; i++)
        total += marks[i];

    cout << "Average marks: "
        << total / studentCount << "\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n=== Student Record Manager ===\n";
        cout << "1. Add student\n";
        cout << "2. Display students\n";
        cout << "3. Search by ID\n";
        cout << "4. Calculate average\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        switch (choice)
        {
        case 1: addStudent(); break;
        case 2: displayStudents(); break;
        case 3: searchStudent(); break;
        case 4: calculateAverage(); break;
        case 0: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
