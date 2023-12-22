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
Flight exampleArr[] = {
    {"23453443", "Burgas", "Ivan Petrov", "Vasil Stanchev", 23.253, true, false, {2, 12, 2004}},
    {"23453444", "Rome", "Ivan Ivanov", "Vasil Stanimirov", 19.34, false, true, {3, 12, 2004}},
    {"23453445", "Paris", "Ivan Cvetkov", "Petar Petrov", 25.3, false, true, {14, 10, 2015}},
    {"23453446", "London", "Pesho Hacka", "Ivan Stanev", 42.55, true, false, {12,3,1991}},
    {"23453447", "Tokyo", "Vasil Vasilev", "Petko Stankov", 19.34, true, false, {31, 12, 1999}}
};

void enterFlight(Flight arr[], const int& n)
{
    char answerTicketClass;
    bool flag = false;
    cout << "Enter the list with the flights:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a Id:" << endl;
        getline(cin, arr[i].id);
        cout << "Enter a destination:" << endl;
        getline(cin, arr[i].destination);
        cout << "Enter the name of the pilot:" << endl;
        getline(cin, arr[i].nameOfPilot);
        cout << "Enter the name of the passenger:" << endl;
        getline(cin, arr[i].nameOfPassenger);
        cout << "Enter the base price of the flight" << endl;
        cin >> arr[i].basePrice;
        cout << "Is your ticket first class? Y(y) or N(n)" << endl;
        flag = false;
        while (flag != true)
        {
            cin >> answerTicketClass;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                break;
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

void showMinPricedFlights(const Flight arr[], const int& n) 
{
    Flight min = arr[0];
    string classType;
    int indexes[20];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].basePrice < min.basePrice)
        {
            min = arr[i];
            count = 0;
        }
        if (arr[i].basePrice == min.basePrice)
        {
            indexes[count++] = i;
        }
    }

    cout << "Here is the list with the lowest priced flights: " << endl;
    cout << "ID | DESTINATION | PILOT'S NAME | PASSENGER'S NAME | BASE PRICE | CLASS | DATE" << endl;
    for (int i = 0; i < count; i++)
    {
        classType = (arr[indexes[i]].firstClass == true) ? "First class" : "Second class";
        cout << arr[indexes[i]].id << " " << arr[indexes[i]].destination << " " << arr[indexes[i]].nameOfPilot << " " << arr[indexes[i]].nameOfPassenger
            << " " << arr[indexes[i]].basePrice << " " << classType << " " << arr[indexes[i]].date.day << "."
            << arr[indexes[i]].date.month << "." << arr[indexes[i]].date.year << endl;
    }
}

void showPilotFlights(const Flight arr[], const int& n)
{
    string name;
    string classType;
    bool flag = false;
    cout << "Enter a pilot's name:" << endl;
    getline(cin, name);
    
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "First class" : "Second class";
        if (arr[i].nameOfPilot == name)
        {
            cout << arr[i].id << " " << arr[i].destination << " " << arr[i].nameOfPilot << " " << arr[i].nameOfPassenger
                << " " << arr[i].basePrice << " " << classType << " " << arr[i].date.day << "."
                << arr[i].date.month << "." << arr[i].date.year << endl;
            flag = true;
        }
    }

    if (flag == false)
    {
        cout << "There are no connected flights to this pilot." << endl;
    }
}

bool menu(Flight arr[], const int& n)
{
    int choice = 0;
    string cathcer;
    while (choice != 4)
    {
        cout << "\tWelcome to my menu for flights.\nPlease select from the following choices:" << endl;
        cout << "1. Add flights" << endl;
        cout << "2. Show flights" << endl;
        cout << "3. Show the lowest priced flights" << endl;
        cout << "4. Search for a flight via a pilot's name. Show the flights with the lowest price." << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        cin.clear();
        switch (choice)
        {
        case 1:
            enterFlight(arr, n);
            break;
        case 2:
            showFlights(arr, n);
                break;
        case 3: 
            showMinPricedFlights(arr, n);
            break;
        case 4:
            getline(cin, cathcer);
            showPilotFlights(arr, n);
            break;
        case 5:
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
    /*cout << "Enter the number of flights you want to register. The maxium is 50." << endl;
    cin >> n;*/
    n = 5;
    for (int i = 0; i < n; i++)
    {
        arr[i] = exampleArr[i];
    }
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
