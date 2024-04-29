#include "hotel.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib> // exit()

using namespace std;

void hotel::secure_login() {
    const char* correct_password = "password";
    char verify[20];
    int chance = 3;

    cout << "\nEnter the password to verify: ";

    while (chance > 0) {
        cin.getline(verify, 20);

        if (strcmp(correct_password, verify) == 0) {
            cout << "\nPassword Matched...";
            cout << "\nWelcome Shubham Agrawal....";
            return;
        } else {
            cout << "\nPassword Wrong....\n";
            cout << chance << " used of 3 chances...";
            cout << "\nEnter the correct credentials: ";
            chance--;
        }
    }

    cout << "\nMaximum number of tries exceeded. Exiting program.";
    exit(0);
}

void hotel::main_menu() {
    int choice;
    while (true) {
        cout << "\n\t\t\t\t*************";
        cout << "\n\t\t\t\t* MAIN MENU *";
        cout << "\n\t\t\t\t*************";
        cout << "\n\n\n\t\t\t1. Book A Room";
        cout << "\n\t\t\t2. Customer Record";
        cout << "\n\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t4. Edit Record";
        cout << "\n\t\t\t5. Exit";
        cout << "\n\n\t\t\t Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                rooms();
                break;
            case 4:
                edit();
                break;
            case 5:
                return;
            default:
                cout << "\n\n\t\t\tWrong choice...!!!";
                cout << "\n\t\t\tPress any key to continue..!!";
                cin.ignore(); // Cleaning Process
                cin.get();
        }
    }
}

void hotel::add() {
    int r, flag;
    ofstream fout("Record", ios::app);

    cout << "\n Enter Customer Details";
    cout << "\n --------";
    cout << "\n\n Room no: ";
    cin >> r;
    flag = check(r);

    if (flag)
        cout << "\n Sorry..!!! Room is already booked";
    else {
        room_no = r;
        cout << " Name: ";
        cin.ignore(); // Cleaning
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone No: ";
        cin >> phone;
        fout.write((char*)this, sizeof(hotel));
        cout << "\n Room is booked...!!!";
    }

    cout << "\n Press any key to continue...!!";
    cin.ignore(); // Cleaning
    cin.get();
    fout.close();
}

void hotel::display() {
    int r, flag;
    ifstream fin("Record", ios::in);

    cout << "\n Enter room no: ";
    cin >> r;

    while (fin.read((char*)this, sizeof(hotel))) {
        if (room_no == r) {
            cout << "\n Customer Details";
            cout << "\n -------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant..!!";

    cout << "\n\n Press any key to continue..!!";
    cin.ignore(); // Cleaning
    cin.get();
    fin.close();
}

// Here for the others
