# RoboticArm Assign5 program makefile

main: RoboticArm.o main.cpp
	g++ main.cpp RoboticArm.o -o main
RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -c RoboticArm.cpp
clean:
	rm RoboticArm.o main
