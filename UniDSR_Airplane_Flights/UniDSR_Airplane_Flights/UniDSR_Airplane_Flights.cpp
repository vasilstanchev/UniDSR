// UniDSR_Airplane_Flights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int ARRSIZE_MAX = 50;

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
    {"2343", "Burgas", "Ivan Petrov", "Vasil Stanchev", 23.253, true, false, {2, 12, 2004}},
    {"2344", "Zagora", "Ivan Ivanov", "Vasil Stanimirov", 19.34, false, true, {3, 12, 2004}},
    {"2345", "Paris", "Ivan Cvetkov", "Petar Petrov", 25.3, false, true, {14, 10, 2015}},
    {"2346", "Londo", "Pesho Hacka", "Ivan Stanev", 42.55, true, false, {12,3,1991}},
    {"2347", "Tokyo", "Vasil Vasilev", "Petko Stankov", 19.34, true, false, {31, 12, 1999}}
};

void validateString(string& validated)
{
    cin.clear();
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    getline(cin, validated);

    while (cin.fail())
    {
        cout << "Invalid entry please enter a text";
        cin.clear();
        cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        getline(cin, validated);
    }
}

bool compareCharacters(char a, char b) {
    return tolower(a) < tolower(b);
}

void enterFlights(Flight arr[], int& n)
{
    char answerTicketClass;
    bool flag = false;
    int newElementsCount;
    cout << "Enter the number of flights you want to register" << endl;
    cin >> newElementsCount;
    cout << "Enter the list with the flights:" << endl;
    for (int i = n; i < n + newElementsCount; i++)
    {
        cout << "Enter a destination:" << endl;
        validateString(arr[i].destination);
        cout << "Enter a Id:" << endl;
        getline(cin, arr[i].id);
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
            cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

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
    n = n + newElementsCount;
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
    validateString(name);
    
    cout << "Here is the list with the given pilot's name flights:" << endl;
    cout << "ID | DESTINATION | PILOT'S NAME | PASSENGER'S NAME | BASE PRICE | CLASS | DATE" << endl;
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

void sortArr(Flight arr[], const int& n)
{
    bool swap;
    char first, second;
    for (int i = 0; i < n - i; i++)
    {
        swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            first = (char)arr[j].destination[0];
            second = (char)arr[j + 1].destination[0];
            if (compareCharacters(first, second))
            {
                Flight temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
                swap = true;
            }
        }

        if (swap == false)
            break;
    }
}

void showSortedAscendingPriceAndClass(Flight arr[], const int& n)
{
    Flight newArr[ARRSIZE_MAX];
    bool swap;
    for (int i = 0; i < n; i++)
    {
        newArr[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (newArr[j].basePrice > newArr[j + 1].basePrice)
            {
                Flight temp = newArr[j];
                newArr[j] = newArr[j + 1];
                newArr[j + 1] = temp;
                swap = true;
            }
        }
        if (swap == false)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((newArr[j].firstClass == false) && (newArr[j + 1].firstClass == true))
            {
                Flight temp = newArr[j];
                newArr[j] = newArr[j + 1];
                newArr[j + 1] = temp;
                swap = true;
            }
        }
        if (swap == false)
            break;
    }

    showFlights(newArr, n);
}

void showDateAndPilotFlights(Flight arr[], const int& n)
{
    Date searchedDate;
    string searchedDestination;
    bool flag = false;
    string classType;
    cout << "Enter a date:" << endl;
    cin >> searchedDate.day >> searchedDate.month >> searchedDate.year;
    cout << "Enter a destination" << endl;
    validateString(searchedDestination);

    cout << "Here's the list with the flights:" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "First class" : "Second class";
        if ((searchedDate.day == arr[i].date.day) && (searchedDate.month == arr[i].date.month) && (searchedDate.year == arr[i].date.year))
        {
            if (searchedDestination == arr[i].destination)
            {
                cout << arr[i].id << " " << arr[i].destination << " " << arr[i].nameOfPilot << " " << arr[i].nameOfPassenger
                     << " " << arr[i].basePrice << " " << classType << " " << arr[i].date.day << "."
                     << arr[i].date.month << "." << arr[i].date.year << endl;
                flag = true;
            }
        }
    }

    if (flag == false)
    {
        cout << "There are no connected flights to this date and destination" << endl;
    }
}

void calculateCurrentFlightPrice(Flight arr[], const int& n)
{
    Date departure;
    string classType;
    int departureDays = 0, flightDepartureDays = 0,difference;
    float currentPrice = 0;
    cout << "Enter a date:" << endl;
    cin >> departure.day >> departure.month >> departure.year;

    cout << "Here is the list with the base prices and the new ones:" << endl;
    cout << "ID | DESTINATION | PILOT'S NAME | PASSENGER'S NAME | BASE PRICE | NEW PRICE | CLASS | FLIGHT DATE | PASSENGER DEPARTURE DATE" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "First class" : "Second class";
        departureDays = departure.day + (departure.month * 30) + ((departure.year - 1) * 360);
        flightDepartureDays = arr[i].date.day + (arr[i].date.month * 30) + ((arr[i].date.year - 1) * 360);
        difference = flightDepartureDays - departureDays;

        if (difference > 20)
        {
            currentPrice = 0.5 * arr[i].basePrice;
        }
        else if (difference <= 20 && difference > 5)
        {
            currentPrice = 0.75 * arr[i].basePrice;
        }
        else if (difference <= 5 && difference > 1)
        {
            currentPrice = arr[i].basePrice;
        }
        else if (difference == 1)
        {
            currentPrice = (0.2 * arr[i].basePrice) + arr[i].basePrice;
        }
        else 
        {
            cout << "The flight is missed" << endl;
            continue;
        }

        cout << arr[i].id << " " << arr[i].destination << " " << arr[i].nameOfPilot << " " << arr[i].nameOfPassenger
            << " " << arr[i].basePrice << " " << currentPrice << " " << classType << " " << arr[i].date.day << "."
            << arr[i].date.month << "." << arr[i].date.year << " " << departure.day << "." << departure.month << "." 
            << departure.year << endl;

    }
}

void changePassengerClass(Flight arr[], const int& n)
{
    char choice;
    bool flag1 = false, flag2 = false;
    string searchedId, searchedName;
    cout << "Enter a name:" << endl;
    validateString(searchedName);
    cout << "Enter an Id:" << endl;
    getline(cin, searchedId);

    for (int i = 0; i < n; i++)
    {
        if (searchedId == arr[i].id && searchedName == arr[i].nameOfPassenger)
        {
            cout << "Do you want to change you ticket to a first class?" << endl;
            cout << "Answer Y(y)/N(n):" << endl;
            while (flag1 != true)
            {
                cin >> choice;
                cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

                switch (choice)
                {
                case 'Y':
                case 'y':
                    arr[i].firstClass = true;
                    flag1 = true;
                    break;
                case 'N':
                case 'n':
                    arr[i].secondClass = true;
                    flag1 = true;
                    break;
                default:cout << "Enter a valid answer!" << endl;
                    break;
                }
            }
            flag2 = true;
        }
    }

    if (flag2 == false)
        cout << "This passenger doesn't exist" << endl;
    else
        showFlights(arr, n);
}

void removeFlight(Flight arr[], int& n)
{
    string searchedId, searchedName;
    bool flag1 = false, flag2 = false;
    cout << "Enter a name:" << endl;
    validateString(searchedName);
    cout << "Enter an Id:" << endl;
    getline(cin, searchedId);
    cout << "Enter a date:" << endl;
    Date returnDate;
    cin >> returnDate.day >> returnDate.month >> returnDate.year;
    int returnDays = 0, flightDepartureDays = 0, difference;
    float returnMoney = 0;

    for (int i = 0; i < n; i++)
    {
        returnDays = returnDate.day + (returnDate.month * 30) + ((returnDate.year - 1) * 360);
        flightDepartureDays = arr[i].date.day + (arr[i].date.month * 30) + ((arr[i].date.year - 1) * 360);
        difference = flightDepartureDays - returnDays;
        if (searchedId == arr[i].id && searchedName == arr[i].nameOfPassenger)
        {
            if (difference > 20)
            {
                returnMoney = arr[i].basePrice;
                flag2 = true;
            }
            else if (difference <= 20 && difference > 5)
            {
                returnMoney = 0.75 * arr[i].basePrice;
                flag2 = true;
            }
            else if (difference < 5 && difference > 0)
            {
                returnMoney = 0.5 * arr[i].basePrice;
                flag2 = true;
            }
            n = n - 1;
            for (int j = i; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            flag1 = true;
            break;
        }
    }
    if (flag1 == false)
        cout << "This passenger doesn't exist" << endl;
    else if (flag1 == true && flag2 == false)
        cout << "The flight is missed" << endl;
    else
        cout << "Returned money: " << returnMoney << endl;
}

void writeInFile(Flight arr[], const int& n)
{
    ofstream outfile("myfile.bin", ios_base::binary);
    if (outfile.fail())
    {
        cout << "File could not be open" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int sizeId = arr[i].id.size();
            const char* strId = arr[i].id.c_str();
            int sizeDestination = arr[i].destination.size();
            const char* strDestination = arr[i].destination.c_str();
            int sizePilot = arr[i].nameOfPilot.size();
            const char* strPilot = arr[i].nameOfPilot.c_str();
            int sizePassenger = arr[i].nameOfPassenger.size();
            const char* strPassenger = arr[i].nameOfPassenger.c_str();

            outfile.write((char*)&sizeId, sizeof(int));
            outfile.write(strId, sizeId + 1);
            outfile.write((char*)&sizeDestination, sizeof(int));
            outfile.write(strDestination, sizeId + 1);
            outfile.write((char*)&sizePilot, sizeof(int));
            outfile.write(strPilot, sizeId + 1);
            outfile.write((char*)&sizePassenger, sizeof(int));
            outfile.write(strPassenger, sizeId + 1);
            outfile.write((char*)&arr[i].basePrice, sizeof(float));
            outfile.write((char*)&arr[i].firstClass, sizeof(bool));
            outfile.write((char*)&arr[i].secondClass, sizeof(bool));
            outfile.write((char*)&arr[i].date.day, sizeof(int));
            outfile.write((char*)&arr[i].date.month, sizeof(int));
            outfile.write((char*)&arr[i].date.year, sizeof(int));

            outfile.flush();
        }
    }
    outfile.close();
}

void openFromFile(Flight arr[], int& n)
{
    ifstream infile("myfile.bin", ios_base::binary | ios_base::beg);
    if (infile.fail())
    {
        cout << "File could not be open" << endl;
    }
    else
    {
        while (infile.peek() != EOF)
        {

        }
    }
}

bool menu(Flight arr[], int& n)
{
    int choice1 = 0, choice2 = 0;
    while (choice1 != 9)
    {
        cout << "\tWelcome to my menu for flights.\nPlease select from the following choices:" << endl;
        cout << "1. Add flights" << endl;
        cout << "2. Show flights" << endl;
        cout << "3. Show the lowest priced flights" << endl;
        cout << "4. Search for a flight via a pilot's name" << endl;
        cout << "5. Show additional choices" << endl;
        cout << "6. Show current prices via a departing date" << endl;
        cout << "7. Change class via flight's id and passenger name" << endl;
        cout << "8. Delete an flight and show return price" << endl;
        cout << "9. Exit the program" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice1;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            cin >> choice1;
        }
        cin.clear();
        switch (choice1)
        {
        case 1:
            enterFlights(arr, n);
            break;
        case 2:
            showFlights(arr, n);
                break;
        case 3: 
            showMinPricedFlights(arr, n);
            break;
        case 4:
            showPilotFlights(arr, n);
            break;
        case 5:
            while (choice2 != 3)
            {
                cout << "1. Show ascending sorted data thought price and class of the flights" << endl;
                cout << "2. Search for a flight via a date and deastination" << endl;
                cout << "3. Exit to the main menu" << endl;
                cout << "Enter your choice:" << endl;
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    showSortedAscendingPriceAndClass(arr, n);
                    break;
                case 2:
                    showDateAndPilotFlights(arr, n);
                    break;
                case 3:
                    break;
                default:
                    cout << "Enter a correct choice" << endl;
                    break;
                }
            }
            break;
        case 6:
            calculateCurrentFlightPrice(arr, n);
            break;
        case 7: 
            changePassengerClass(arr, n);
            break;
        case 8:
            removeFlight(arr, n);
            break;
        case 9:
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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    Flight arr[ARRSIZE_MAX];
    int n;
    n = 5;
    for (int i = 0; i < n; i++)
    {
        arr[i] = exampleArr[i];
    }
    sortArr(arr, n);
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
