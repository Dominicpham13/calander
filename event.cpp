#include "Event.h"
Event::Event(){
    description = " ";
    day = -1;
}

Event::Event(int newDay,string newDescription){
    day = newDay;
    description = newDescription;
}
Event::Event(const Event& c){
    day = c.day;
    description = c.description;
}


void Event::setDescription(string newDescription){
    description = newDescription;
}
string Event::getDescription(){
    return description;
}
void Event::setDay(int newDay){
    day = newDay;
}
int Event::getDay(){
    return day;
}

string Event::getWeekDay(){
    return weekDay; 
}
void Event::setWeekDay(string newDayofWeek){
    weekDay = newDayofWeek;
}

