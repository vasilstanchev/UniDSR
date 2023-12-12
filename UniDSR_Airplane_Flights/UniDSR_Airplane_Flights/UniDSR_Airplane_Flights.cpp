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

void enterFlight(Flight arr[], const int& n)
{
    char answerTicketClass;
    bool flag = false;
    cout << "Enter the list with the flights:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a Id:" << endl;
        cin >> arr[i].id;
        cout << "Enter a destination:" << endl;
        cin >> arr[i].destination;
        cout << "Enter the name of the pilot:" << endl;
        cin >> arr[i].nameOfPilot;
        cout << "Enter the name of the passenger:" << endl;
        cin >> arr[i].nameOfPassenger;
        cout << "Enter the base price of the flight" << endl;
        cin >> arr[i].basePrice;
        cout << "Is your ticket first class? Y(y) or N(n)" << endl;
        flag = false;
        while (flag != true)
        {
            cin >> answerTicketClass;
            switch (answerTicketClass)
            {
            case 'Y':
            case 'y':
                arr[i].firstClass = true;
                flag = true;
                break;
            case 'N':
            case 'n':
                arr[i].secondClass = true;
                flag = true;
            default:cout << "Enter a valid answer!" << endl;
                break;
            }
        }
        cout << "Enter a date of the flight: day, month and year" << endl;
        cin >> arr[i].date.day;
        cin >> arr[i].date.month;
        cin >> arr[i].date.year;
    }
}

void showFlights(const Flight arr[], const int& n)
{
    string classType;
    cout << "Here is the list with the flights: " << endl;
    cout << "ID | DESTINATION | PILOT'S NAME | PASSENGER'S NAME | BASE PRICE | CLASS | DATE" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "First class" : "Second class";
        cout << arr[i].id << " " << arr[i].destination << " " << arr[i].nameOfPilot << " " << arr[i].nameOfPassenger
            << " " << arr[i].basePrice << " " << classType << " " << arr[i].date.day << "."
            << arr[i].date.month << "." << arr[i].date.year << endl;
    }
}

bool menu(Flight arr[], const int& n)
{
    int choice = 0;
    while (choice != 4)
    {
        cout << "\tWelcome to my menu for flights.\nPlease select from the following choices:" << endl;
        cout << "1. Add flights" << endl;
        cout << "2. Show flights" << endl;
        cout << "3. Search for a flight via a pilot's name. Show the flights with the lowest price." << endl;
        cout << "4. Exit the program" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            enterFlight(arr, n);
            break;
        case 2:
            showFlights(arr, n);
                break;
        case 3: break;
        case 4:
            cout << "Goodbye!" << endl;
            return false;
            break;
        default:
            cout << "Enter a correct choice" << endl;
            break;
        }
    }
    return true;
}

int main()
{
    Flight arr[ARR_MAX];
    int n;
    cout << "Enter the number of flights you want to register. The maxium is 50." << endl;
    cin >> n;
    menu(arr, n);
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
