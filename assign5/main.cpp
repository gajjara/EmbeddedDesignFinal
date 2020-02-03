#include "RoboticArm.h"
#include <unistd.h>
int main() {
	RoboticArm robotic_arm;

	while (true) {
		robotic_arm.MoveServo(0, 90, 10);
		robotic_arm.MoveServo(1, 90, 10);
		robotic_arm.MoveServo(2, 90, 10);
		robotic_arm.MoveServo(3, 90, 10);
		sleep(2);
		robotic_arm.MoveServo(1, 45, 10);
		robotic_arm.MoveServo(2, 45, 10);
		sleep(2);
		robotic_arm.MoveServo(4, 180, 10);
		sleep(1);
		robotic_arm.MoveServo(4, 0, 10);
		sleep(1);
		robotic_arm.MoveServo(1, 90, 10);
		robotic_arm.MoveServo(2, 90, 10);
		sleep(1);
		robotic_arm.MoveServo(1, 135, 10);
		robotic_arm.MoveServo(1, 135, 10);
		sleep(1);
		robotic_arm.MoveServo(1, 180, 10);
		robotic_arm.MoveServo(2, 180, 10);
		sleep(1);
		robotic_arm.MoveServo(4, 180, 10);
		sleep(5);


		//robotic_arm.MoveServo(0, 90, 10);
		//sleep(1);
		//robotic_arm.MoveServo(1, 90, 10);
		//sleep(1);
		//robotic_arm.MoveServo(2, 90, 10);
		//sleep(1);
		//robotic_arm.MoveServo(3, 90, 10);
		//sleep(1);
		//break;
		//robotic_arm.MoveServo(4, 90, 45);
		//robotic_arm.MoveServo(3, 90, 45);
		//sleep(1);
	}
}
