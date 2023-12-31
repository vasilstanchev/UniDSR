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
    {"2346", "London", "Petar Georgiev", "Ivan Stanev", 42.55, true, false, {12,3,1991}},
    {"2347", "Tokyo", "Vasil Vasilev", "Petko Stankov", 19.34, true, false, {31, 12, 1999}}
};

void validateString(string& validated)
{
    cin.clear();
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    getline(cin, validated);

    while (cin.fail())
    {
        cout << "Невалиден вход, вкарайте текст";
        cin.clear();
        cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        getline(cin, validated);
    }
}

void validateDate(Date& date)
{
    bool flag = false;
    while (flag != true)
    {
        cin >> date.day >> date.month >> date.year;
        if ((date.day > 0 && date.day < 31) && (date.month > 0 && date.month < 13) && date.year > 1900)
        {
            flag = true;
        }
        else
            cout << "Въведете правилна дата" << endl;
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
    cout << "Вкарайте броя полети, които искате да вкарате:" << endl;
    cin >> newElementsCount;
    cout << "Вкарайте полетата във полетите:" << endl;
    for (int i = n; i < n + newElementsCount; i++)
    {
        cout << "Вкарайте дестинация:" << endl;
        validateString(arr[i].destination);
        cout << "Вкарайте номер на полета:" << endl;
        getline(cin, arr[i].id);
        cout << "Вкарайте име на пилот:" << endl;
        getline(cin, arr[i].nameOfPilot);
        cout << "Вкарайте име на пътник:" << endl;
        getline(cin, arr[i].nameOfPassenger);
        cout << "Вкарайте основна цена на полета" << endl;
        cin >> arr[i].basePrice;
        cout << "Вашия билет първа класа ли е? Да или не / Y(y) или N(n)" << endl;
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
            default:cout << "Вкарайте валиден вход" << endl;
                break;
            }
        }
        cout << "Вкарайте дата на полета: ден, месец и година:" << endl;
        validateDate(arr[i].date);
    }
    n = n + newElementsCount;
}

void showFlights(const Flight arr[], const int& n)
{
    string classType;
    cout << "Лист с полети: " << endl;
    cout << "НОМЕР НА ПОЛЕТА | ДЕСТИНАЦИЯ | ПИЛОТ | ПЪТНИК | ОСНОВНА ЦЕНА | КЛАСА | ДАТА" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "Първа класа" : "Втора класа";
        cout << arr[i].id << " | " << arr[i].destination << " | " << arr[i].nameOfPilot << " | " << arr[i].nameOfPassenger
            << " | " << arr[i].basePrice << " | " << classType << " | " << arr[i].date.day << "."
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

    cout << "Лист с полети: " << endl;
    cout << "НОМЕР НА ПОЛЕТА | ДЕСТИНАЦИЯ | ПИЛОТ | ПЪТНИК | ОСНОВНА ЦЕНА | КЛАСА | ДАТА" << endl;
    for (int i = 0; i < count; i++)
    {
        classType = (arr[indexes[i]].firstClass == true) ? "Първа класа" : "Втора класа";
        cout << arr[indexes[i]].id << " | " << arr[indexes[i]].destination << " | " << arr[indexes[i]].nameOfPilot << " | " << arr[indexes[i]].nameOfPassenger
            << " | " << arr[indexes[i]].basePrice << " | " << classType << " | " << arr[indexes[i]].date.day << "."
            << arr[indexes[i]].date.month << "." << arr[indexes[i]].date.year << endl;
    }
}

void showPilotFlights(const Flight arr[], const int& n)
{
    string name;
    string classType;
    bool flag = false;
    cout << "Вкарайте име на пилот:" << endl;
    validateString(name);
    
    cout << "Лист с полети свързан с даденото име на пилота: " << endl;
    cout << "НОМЕР НА ПОЛЕТА | ДЕСТИНАЦИЯ | ПИЛОТ | ПЪТНИК | ОСНОВНА ЦЕНА | КЛАСА | ДАТА" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "Първа класа" : "Втора класа";
        if (arr[i].nameOfPilot == name)
        {
            cout << arr[i].id << " | " << arr[i].destination << " | " << arr[i].nameOfPilot << " | " << arr[i].nameOfPassenger
                << " | " << arr[i].basePrice << " | " << classType << " | " << arr[i].date.day << "."
                << arr[i].date.month << "." << arr[i].date.year << endl;
            flag = true;
        }
    }

    if (flag == false)
    {
        cout << "Няма свързани полети с дадения пилот" << endl;
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
    cout << "Вкарайте дата: ден, месец и дата" << endl;
    validateDate(searchedDate);
    cout << "Вкарайте дестинация" << endl;
    validateString(searchedDestination);

    cout << "Лист с полетите на съответната дата и дестинация:" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "Първа класа" : "Втора класа";
        if ((searchedDate.day == arr[i].date.day) && (searchedDate.month == arr[i].date.month) && (searchedDate.year == arr[i].date.year))
        {
            if (searchedDestination == arr[i].destination)
            {
                cout << arr[i].id << " | " << arr[i].destination << " | " << arr[i].nameOfPilot << " | " << arr[i].nameOfPassenger
                     << " | " << arr[i].basePrice << " | " << classType << " | " << arr[i].date.day << "."
                     << arr[i].date.month << "." << arr[i].date.year << endl;
                flag = true;
            }
        }
    }

    if (flag == false)
    {
        cout << "Няма свързани полети на съответната дата и дестинация" << endl;
    }
}

void calculateCurrentFlightPrice(Flight arr[], const int& n)
{
    Date departure;
    string classType;
    int departureDays = 0, flightDepartureDays = 0,difference;
    float currentPrice = 0;
    cout << "Вкарайте дата: ден, месец и година" << endl;
    validateDate(departure);

    cout << "Лист с полети с основната цена и новата спрямо посочената дата:" << endl;
    cout << "НОМЕР НА ПОЛЕТА | ДЕСТИНАЦИЯ | ПИЛОТ | ПЪТНИК | ОСНОВНА ЦЕНА | НОВА ЦЕНА | КЛАСА | ДАТА НА ПОЛЕТА | ДАТА НА ПЪТНИКА" << endl;
    for (int i = 0; i < n; i++)
    {
        classType = (arr[i].firstClass == true) ? "Първа класа" : "Втора класа";
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
            cout << "Полета е пропуснат" << endl;
            continue;
        }

        cout << arr[i].id << " | " << arr[i].destination << " | " << arr[i].nameOfPilot << " | " << arr[i].nameOfPassenger
            << " | " << arr[i].basePrice << " | " << currentPrice << " | " << classType << " | " << arr[i].date.day << "."
            << arr[i].date.month << "." << arr[i].date.year << " | " << departure.day << "." << departure.month << "." 
            << departure.year << endl;

    }
}

void changePassengerClass(Flight arr[], const int& n)
{
    char choice;
    bool flag1 = false, flag2 = false;
    string searchedId, searchedName;
    cout << "Вкарайте име на пътника:" << endl;
    validateString(searchedName);
    cout << "Вкарайте номер на полета:" << endl;
    getline(cin, searchedId);

    for (int i = 0; i < n; i++)
    {
        if (searchedId == arr[i].id && searchedName == arr[i].nameOfPassenger)
        {
            cout << "Искате ли да промените билета си на първа класа?" << endl;
            cout << "Отговор Да/Не / Y(y)/N(n):" << endl;
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
                default:cout << "Въведете валиден вход" << endl;
                    break;
                }
            }
            flag2 = true;
        }
    }

    if (flag2 == false)
        cout << "Данните не съответстват" << endl;
    else
        showFlights(arr, n);
}

void removeFlight(Flight arr[], int& n)
{
    string searchedId, searchedName;
    bool flag1 = false, flag2 = false;
    cout << "Вкарайте име на пътника:" << endl;
    validateString(searchedName);
    cout << "Вкарайте номер на полета:" << endl;
    getline(cin, searchedId);
    cout << "Вкарайте дата: ден, месец и година" << endl;
    Date returnDate;
    validateDate(returnDate);
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
        cout << "Данните не съответстват" << endl;
    else if (flag1 == true && flag2 == false)
        cout << "Полетът е пропуснат" << endl;
    else
        cout << "Сума за връщане: " << returnMoney << endl;
}

void writeInFile(Flight arr[], const int& n)
{
    ofstream outfile("myfile.bin", ios_base::binary|ios_base::beg);
    if (outfile.fail())
    {
        cout << "Файлът не може да бъде отворен" << endl;
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
            outfile.write(strDestination, sizeDestination + 1);
            outfile.write((char*)&sizePilot, sizeof(int));
            outfile.write(strPilot, sizePilot + 1);
            outfile.write((char*)&sizePassenger, sizeof(int));
            outfile.write(strPassenger, sizePassenger + 1);
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
        cout << "Файлът не може да бъде отворен" << endl;
    }
    else
    {
        int sizeId, sizeDestination, sizePilot, sizePassenger;
        char* id;
        char* destination;
        char* namePilot;
        char* namePassenger;
        while (infile.peek() != EOF)
        {
            /*sizeId = 0;
            sizeDestination = 0;
            sizePilot = 0;
            sizePassenger = 0;*/

            infile.read((char*)&sizeId, sizeof(int));
            id = (char*)calloc(sizeId + 1, 1);
            infile.read(id, sizeId + 1);
            arr[n].id = id;

            infile.read((char*)&sizeDestination, sizeof(int));
            destination = (char*)calloc(sizeDestination + 1, 1);
            infile.read(destination, sizeDestination + 1);
            arr[n].destination = destination;

            infile.read((char*)&sizePilot, sizeof(int));
            namePilot = (char*)calloc(sizePilot + 1, 1);
            infile.read(namePilot, sizePilot + 1);
            arr[n].nameOfPilot = namePilot;

            infile.read((char*)&sizePassenger, sizeof(int));
            namePassenger = (char*)calloc(sizePassenger + 1, 1);
            infile.read(namePassenger, sizePassenger + 1);
            arr[n].nameOfPassenger = namePassenger;

            infile.read((char*)&arr[n].basePrice, sizeof(float));

            infile.read((char*)&arr[n].firstClass, sizeof(bool));
            infile.read((char*)&arr[n].secondClass, sizeof(bool));

            infile.read((char*)&arr[n].date.day, sizeof(int));
            infile.read((char*)&arr[n].date.month, sizeof(int));
            infile.read((char*)&arr[n].date.year, sizeof(int));

            n++;
        }
    }
    infile.close();
}

bool menu(Flight arr[], int& n)
{
    int choice1 = 0, choice2 = 0;
    while (choice1 != 10)
    {
        cout << "\tТова е система за полети.\nИзберете от следните възможности:" << endl;
        cout << "1. Добавяне на полети" << endl;
        cout << "2. Показване на полети" << endl;
        cout << "3. Показване на полетите със най-ниска основна цена" << endl;
        cout << "4. Търсене на определен полет спрямо име на пилот" << endl;
        cout << "5. Показване на допълнителни възможности" << endl;
        cout << "6. Показване на текуща цена спрямо дата на заминаване" << endl;
        cout << "7. Промяна на класа на полета спрямо номер на полета и име на пътника" << endl;
        cout << "8. Изтриване на полет и показване на сума за връщане" << endl;
        cout << "9. Запис във файл" << endl;
        cout << "10. Изход от програма" << endl;
        cout << "Вкарване на избор:" << endl;
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
            sortArr(arr, n);
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
                cout << "1. Показване на сортираните полети спрямо цена и клас" << endl;
                cout << "2. Търсене на полет спрямо дата и дестинация" << endl;
                cout << "3. Връщане обратно във главното меню" << endl;
                cout << "Вкарване на избор:" << endl;
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
                    cout << "Въведете правилен избор" << endl;
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
            writeInFile(arr, n);
            cout << "Записано във файл!"<<endl;
            break;
        case 10:
            cout << "Довиждане!" << endl;
            return false;
            break;
        default:
            cout << "Въведете правилен избор" << endl;
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
    n = 0;
    openFromFile(arr, n);
    sortArr(arr, n);
    menu(arr, n);
    writeInFile(arr, n);
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
