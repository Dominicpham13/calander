calender: main.o event.o
	g++ -o calender main.o event.o
main.o: event.h event.cpp
	g++ -c main.cpp event.cpp
event.o: event.h
	g++ -c event.cpp
clean:
	rm *.o calender