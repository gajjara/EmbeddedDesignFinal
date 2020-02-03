
# WiimoteBtns program Makefile

main:	main.o WiimoteBtns.o RoboticArm.o
	g++ main.o WiimoteBtns.o RoboticArm.o -o main
main.o:	main.cpp WiimoteBtns.h RoboticArm.h
	g++ -g -c main.cpp
WiimoteBtns.o:	WiimoteBtns.cpp WiimoteBtns.h
	g++ -g -c WiimoteBtns.cpp
RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -g -c RoboticArm.cpp
clean:	
	rm main.o WiimoteBtns.o RoboticArm.o main


