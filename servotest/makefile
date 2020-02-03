#Assignment 2 Makefile

#main1: main.cpp GPIO.o
#	g++ main.cpp GPIO.o -o main1
main3: ServoSpeed.cpp GPIO.o
	g++ ServoSpeed.cpp GPIO.o -o main3
GPIO.o: GPIO.cpp GPIO.h
	g++ -c GPIO.cpp
clean:
	rm GPIO.o main3

