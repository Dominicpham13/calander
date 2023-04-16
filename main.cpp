#include <iostream>
#include <time.h>
#include <chrono>
#include "Event.h"
#include <ctime>
#include <vector>
#include <string>
using namespace std;

void calendar(string month, int, vector<string>);
void displayMenu();
string findWeekday(int);
string findMonth(int month);
void printMenu();
int getOption();
void generateTime(vector<string>);
void addTask(vector<string> &);
void removeTask(vector<string> &events);

int main()
{
    // Vector declaratin to hold events.
    vector<string> events;
    for (int i = 0; i < 45; i++)
    {
        events.push_back("None");
    }
    // Real Time
    //  std::cout << "Real-time: " << std::ctime(&timestamp);
    int choice;
    bool run = true;
    do
    {
        generateTime(events);
        printMenu();
        choice = getOption();
        switch (choice)
        {
        case 1:
            addTask(events);

            break;
        case 2:
            removeTask(events);
            break;
        case 0:
            break;
        }

    } while (choice != 0);
    return 0;
}

// End of main ------------------------------------------------------------------------------

void calendar(string month, int year, vector<string> events)
{

    cout << "|---------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "\t\t\t\t\t\t" << month << "-" << year << endl;
    cout << "|---------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|\tM\t"
         << "|\tT\t"
         << "|\tW\t"
         << "|\tTh\t"
         << "|\tF\t"
         << "|\tS\t"
         << "|\tSu\t|" << endl;

    int j = 0;
    for (int i = 0; i <= 5; i++)
    {
        cout << "|---------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "|\t" << events.at(j) << "\t|\t" << events.at(j + 1) << "\t|\t" << events.at(j + 2) << "\t|\t" << events.at(j + 3) << "\t|\t" << events.at(j + 4) << "\t|\t" << events.at(j + 5) << "\t|\t" << events.at(j + 6) << "\t|" << endl;
        cout << "|\t\t"
             << "|\t\t"
             << "|\t\t"
             << "|\t\t"
             << "|\t\t"
             << "|\t\t"
             << "|\t\t|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------|" << endl;
        j += 7;
    }
}

string findWeekday(int weekday)
{
    switch (weekday)
    {
    case 0:
        return "Sunday";
        break;
    case 1:
        return "Monday";
        break;
    case 2:
        return "Tuesday";
        break;
    case 3:
        return "Wednesday";
        break;
    case 4:
        return "Thrusday";
        break;
    case 5:
        return "Friday";
        break;
    case 6:
        return "Saturday";
        break;
    }
    return " ";
}

string findMonth(int month)
{
    switch (month)
    {
    case 12:
        return "Dec";
        break;
    case 1:
        return "Jan";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Apr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "Aug";
        break;
    case 9:
        return "Sept";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    }
    return " ";
}

void printMenu()
{
    cout << "1. Add Task " << endl;
    cout << "2. Remove Task " << endl;
    cout << "0. Exit " << endl;
}
int getOption()
{
    int option;
    cin >> option;
    return option;
}

void generateTime(vector<string> events)
{
    std::time_t current = std::time(nullptr);
    std::tm *tm = std::localtime(&current);
    int weekdayNum = tm->tm_wday;
    int monthNum = tm->tm_mon + 1;
    string weekday = findWeekday(weekdayNum);
    string month = findMonth(monthNum);
    int year = tm->tm_year + 1900;
    calendar(month, year, events);

    std::tm date = {0, 0, 0, 1, monthNum - 1, year - 1900};
    while (date.tm_mon == monthNum - 1)
    {

        std::mktime(&date); // Ensure date.tm_wday is set correctly
        int weekday = date.tm_wday;
        string dayofWeek = findWeekday(weekday);
        // Print the date and weekday
        // Event day;
        // day.setWeekDay(dayofWeek);

        // std::cout << date.tm_mday << " " << weekday<< std::endl;

        // Increment the date to the next day
        date.tm_mday++;
    }
}
void addTask(vector<string> &events)
{
    int day;
    cout << "Select a day you have an event on." << endl;
    cin >> day;
    cout << "What would you like to schedule?" << endl;
    cin >> events[day];
}
void removeTask(vector<string> &events)
{
    int day;
    cout << "Select a day you have an event on." << endl;
    cin >> day;
    events[day] = "None";
}