#include <fcntl.h>
#include <cmath>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "GPIO.h"

int degreeToOnDelay(int servoPos) { return (servoPos * 10) + 600; }
int toMicro(int bigSec) { return (bigSec * 1000000); }

int main() {
        int servoNum, start_position, end_position, rot_speed;
        double Angle;

        std::cout << "Enter the Servo Number: ";
        std::cin >> servoNum;
        std::cout << "Enter the Start Position (0 to 180 degrees): ";
        std::cin >> start_position;
	std::cout << "Enter the End Position (0 to 180 degrees): ";
	std::cin >> end_position;
	std::cout << "Enter the Rotational speed (deg/s): " ;
	std::cin >> rot_speed;

	//Allocate memory to new Servo object
        GPIO *servo = new GPIO(servoNum);

	/**
        if(Angle < 1 || Angle > 179) {
                std::cout << "The angle you've entered is out of range, entering 0 as Angle" << std::endl;
                Angle = 0;
        }
	*/

	int first_pulse = degreeToOnDelay(start_position);
	int last_pulse = degreeToOnDelay(end_position);
	
	double  time_d = toMicro(abs(start_position - end_position) / rot_speed );
	double  numPeriods = time_d/20000;
        std::cout << servoNum << std::endl;
        std::cout <<  first_pulse << std::endl;
	std::cout << last_pulse << std::endl;
        std::cout << numPeriods << std::endl;

        //20ms period with 400 iterations
        servo->GenerateVariablePWM (20000, first_pulse, last_pulse, (int)numPeriods);


}

