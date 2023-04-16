#ifndef EVENT
#define EVENT
using namespace std;
#include<iostream>





class Event{

    int day;
    string description;
    bool check;
    string weekDay;

public:
    Event();
    Event(int day,string description);
    Event(const Event& c);
    void setDescription(string);
    string getDescription();
    void setDay(int);
    int getDay();
    string getWeekDay();
    void setWeekDay(string);





};
#endif 