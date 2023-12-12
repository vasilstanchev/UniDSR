// UniDSR_Airplane_Flights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

const int ARR_MAX = 50;

struct Date {
    int day;
    int month;
    int year;
};
struct Flight {
    string id;
    string destination;
    string nameOfPilot;
    string nameOfPassenger;
    float basePrice;
    bool firstClass = false;
    bool secondClass = false;
    Date date;
};

bool menu(Flight arr, const int& n)
{
    int choice;
    while (choice != 4)
    {
        cout << "Welcome to my menu for flights. Please select from the following choices:" << endl;
        cout << "1. Add flights" << endl;
        cout << "2. Show flights" << endl;
        cout << "3.Search for a flight via a pilot's name. Show the flights with the lowest price." << endl;
        cout << "4. Exit the program" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        default: break;
        }
    }
}

int main()
{
    Flight arr[ARR_MAX];
    int n;
    cout << "Enter the number of flights you want to register. The maxium is 50." << endl;
    cin >> n;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
