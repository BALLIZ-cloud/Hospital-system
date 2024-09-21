
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_PATIENTS_PER_SPECIALIZATION = 5;

vector<int> x;        // Specialization
vector<string> y;     // Name
vector<bool> z;       // Status (0: waiting, 1: urgent)

// Add a new patient
void add() {
    int a;
    string b;
    bool c;

    cout << "Enter specialization, name, status (0 for waiting, 1 for urgent): " << endl;
    cin >> a >> b >> c;

    // Count how many patients already exist for the given specialization
    int count = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == a) {
            count++;
        }
    }

    // Check if the specialization has reached the limit
    if (count >= MAX_PATIENTS_PER_SPECIALIZATION) {
        cout << "Sorry, the specialization is full. You cannot add more than "
             << MAX_PATIENTS_PER_SPECIALIZATION << " patients for specialization " << a << "." << endl;
        return;
    }

    // Add the new patient to the vectors
    x.push_back(a);
    y.push_back(b);
    z.push_back(c);

    // Move urgent patients to the front
    for (int i = 0; i < z.size(); ++i) {
        if (z[i]) {
            // Move the urgent patient to the beginning
            rotate(z.begin(), z.begin() + i, z.begin() + i + 1);
            rotate(x.begin(), x.begin() + i, x.begin() + i + 1);
            rotate(y.begin(), y.begin() + i, y.begin() + i + 1);
        }
    }
}

// Print all patients
void print() {
    for (int i = 0; i < x.size(); ++i) {
        cout << "Specialization: " << x[i]
             << ", Name: " << y[i]
             << ", Status: " << (z[i] ? "Urgent" : "Waiting")
             << endl;
    }
}

// Get the next patient based on specialization
void get() {
    int v;
    cout << "Enter specialization: ";
    cin >> v;

    bool patientFound = false;
    for (int i = 0; i < x.size(); ++i) {
        if (v == x[i]) {
            cout << "Next patient is: " << y[i] <<" please go with the DR" endl;
            // Remove the patient once retrieved
            x.erase(x.begin() + i);
            y.erase(y.begin() + i);
            z.erase(z.begin() + i);
            patientFound = true;
            break;
        }
    }

    if (!patientFound) {
        cout << "No patient at the moment. Have rest, doctor!" << endl;
    }
}

// Menu to handle the user input
void menu() {
    while (true) {
        cout << "ENTER YOUR CHOICE:" << endl;
        cout << "1) ADD NEW PATIENT" << endl;
        cout << "2) PRINT ALL PATIENTS" << endl;
        cout << "3) GET NEXT PATIENT" << endl;
        cout << "4) EXIT" << endl;
        int choice = 0;
        cin >> choice;

        if (choice == 1) {
            add();
        } else if (choice == 2) {
            print();
        } else if (choice == 3) {
            get();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
