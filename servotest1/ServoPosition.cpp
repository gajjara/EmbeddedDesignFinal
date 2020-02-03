#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "GPIO.h"


/*
void checkAngle(double Angle) {
	if(Angle < 1 || Angle > 179) {
		std::cout << "The angle you've entered is out of range, entering 0 as Angle" << std::endl;
		Angle = 0;	
	}
}
*/

/*
void getServoPos(int servoNum, double Angle) {
	std::cout << "Enter the Servo Number: ";
	std::cin >> servoNum;
	std::cout << "Enter the Servo Angle (0 to 180 degrees): ";
	std::cin >> Angle;
}
*/

double degreeToOnDelay(double servoPos) { return (servoPos * 10) + 600; }

/*
void setServoPos(int servoNum, double Angle) {
	GPIO *servo = new GPIO(servoNum);
	
	checkAngle(Angle);

	std::cout << servoNum << std::endl;
	std::cout << Angle << std::endl; 
	
	//20ms period with 400 iterations
	servo->GeneratePWM (20000, degreeToOnDelay(Angle), 400);
}
*/


int main() { 
	int servoNum;
	double Angle;

	std::cout << "Enter the Servo Number: ";
        std::cin >> servoNum;
        std::cout << "Enter the Servo Angle (0 to 180 degrees): ";
        std::cin >> Angle;

        GPIO *servo = new GPIO(servoNum);
       

	if(Angle < 1 || Angle > 179) {
                std::cout << "The angle you've entered is out of range, entering 0 as Angle" << std::endl;
                Angle = 0;
        }


        std::cout << servoNum << std::endl;
        std::cout << Angle << std::endl;
	std::cout << degreeToOnDelay(Angle) << std::endl;

        //20ms period with 400 iterations
        servo->GeneratePWM (20000, degreeToOnDelay(Angle), 400);
	

}

