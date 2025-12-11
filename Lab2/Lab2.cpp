#include <iostream>
#include "Element.h"

using namespace std;

void printHeader() {
    cout << "--------------------------------------------------------" << endl;
    cout << "  Num  |      Name       |  Mass  |  Half-Life  " << endl;
    cout << "--------------------------------------------------------" << endl;
}

int main() {
    Element elem1(93, "Neptunium", 237, 220000);
    Element elem2(97, "Berkelium", 247, 700);
    Element result;
    int choice;

    do {
        cout << "Current Objects:" << endl;
        printHeader();
        cout << "1: " << elem1 << endl;
        cout << "2: " << elem2 << endl;
        cout << "--------------------------------------------------------" << endl;

        cout << "1. >> (Input new data for Object 1)" << endl;
        cout << "2. =  (Assign Obj 2 to Obj 1)" << endl;
        cout << "3. +  [Member] (Obj 1 + Obj 2)" << endl;
        cout << "4. +  [Friend] (Obj 1 + Integer)" << endl;
        cout << "5. == [Member] (Check if Obj 1 == Obj 2)" << endl;
        cout << "6. == [Friend] (Check if Obj 1 atomic number == Integer)" << endl;
        cout << "7. [] (Get length of Obj 1 name)" << endl;
        cout << "8. () (Re-initialize Obj 1 with custom params)" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data for Object 1:\n";
            cin >> elem1;
            break;

        case 2:
            cout << "Assigning Object 2 to Object 1...\n";
            elem1 = elem2;
            cout << "Done.\n";
            break;

        case 3:
            result = elem1 + elem2;
            cout << "Result of addition (Synthesis):\n";
            printHeader();
            cout << result << endl;
            break;

        case 4:
            int val;
            cout << "Enter integer to add to Mass Number: ";
            cin >> val;
            result = elem1 + val;
            cout << "Result:\n";
            printHeader();
            cout << result << endl;
            break;

        case 5:
            if (elem1 == elem2)
                cout << "Objects are EQUAL.\n";
            else
                cout << "Objects are DIFFERENT.\n";
            break;

        case 6:
            int checkNum;
            cout << "Enter Atomic Number to check against Obj 1: ";
            cin >> checkNum;
            if (elem1 == checkNum)
                cout << "Match! Atomic numbers are equal.\n";
            else
                cout << "No match.\n";
            break;

        case 7:
            cout << "Length of name '" << "Obj 1" << "': " << elem1[0] << " characters.\n";
            break;

        case 8:
            cout << "Initializing Obj 1 with (98, Californium, 251, 660)...\n";
            elem1(98, "Californium", 251, 660);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}