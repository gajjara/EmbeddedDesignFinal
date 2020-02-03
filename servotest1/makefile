#Assignment 2 Makefile

#main1: main.cpp GPIO.o
#	g++ main.cpp GPIO.o -o main1
main3: ServoPosition.cpp GPIO.o
	g++ ServoPosition.cpp GPIO.o -o main3
GPIO.o: GPIO.cpp GPIO.h
	g++ -c GPIO.cpp
clean:
	rm GPIO.o main3

