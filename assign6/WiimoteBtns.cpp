#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"
#include "RoboticArm.h"

WiimoteBtns::WiimoteBtns() {
	fieldid = open("/dev/input/event2", O_RDONLY | O_NONBLOCK);
	if (fieldid == -1) {
		std::cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
  accelid = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
  if(accelid == -1) {
    std::cerr << "Error: Could not open event file - forgot sudo?\n";
    exit(1);
  }
}

WiimoteBtns::~WiimoteBtns() {
	close(fieldid);
  close(accelid);
	exit(1);
}

int WiimoteBtns::checkAngle(int angle) {
    if(angle > 180) {
             return 180;
    }
    else if(angle < 0) {
             return 0;
    }
    else {
         return angle;
    }
}

/**
 * Function takes a code and value from a Wiimote 
 * button event as integer arguments and displays
 * a message on the screen reporting those values
 *
 * @param code		Is the code integer
 * @param value		Is the value integer
 * @return void
 */
void WiimoteBtns::ButtonEvent(RoboticArm *arm, int servo, int angle) {
	std::cout << "Writing to servo: " << servo << " With angle: " << angle << std::endl;

	//Write to servo
	arm->MoveServo(servo, angle, 10);
}

void WiimoteBtns::writeToAllServos(RoboticArm *arm, int ba, int bi, int el, int wr, int gr) {
	ButtonEvent(arm, 0, ba);
	ButtonEvent(arm, 1, bi);
	ButtonEvent(arm, 2, el);
	ButtonEvent(arm, 3, wr);
	ButtonEvent(arm, 4, gr);
}

/**
 * Function enters an infinite loop where a new event is read
 * And when an event is ready, the code and value fields of that
 * event are passed in an invocation to the ButtonEvent() function
 * 
 * @return void
 */
void WiimoteBtns::Listen() {
	int base_angle = 90, bicep_angle = 90, elbow_angle = 90, wrist_angle = 90, gripper_angle = 90;

  RoboticArm *arm = new RoboticArm();

	while (true) {
		//writeToAllServos(base_angle, bicep_angle, elbow_angle, wrist_angle, gripper_angle);

    //READ BUTTON EVENT
		int code, value;

		//Read a packet of 32 bytes from Wiimote
		char buffer[32];
		if (read(fieldid, buffer, 32) != 32) {
			//Do nothing
		}
		else {
			//Extract code (byte 10) and value(byte 12) from packet
			code = buffer[10];
			value = buffer[12];

			switch (code)	{
				case 105: { //Base Angle increment
					base_angle = base_angle + 5;
          base_angle = checkAngle(base_angle);
          break;
				}
				case 106: { //Base Angle decrement
					base_angle -= 5;
          base_angle = checkAngle(base_angle);
          break;
				}
				case 48: { //Bicep Angle increment
					bicep_angle = bicep_angle + 5;
          bicep_angle = checkAngle(bicep_angle);
          break;
				}
				case 49: { //Bicep Angle decrement
					bicep_angle -= 5;
          bicep_angle = checkAngle(bicep_angle);
          break;
				}
				case 151: { //Elbow Angle increment
					elbow_angle = elbow_angle + 5;
          elbow_angle = checkAngle(elbow_angle);
          break;
				}
				case 156: { //Elbow Angle decrement
					elbow_angle -= 5;
          elbow_angle = checkAngle(elbow_angle);
          break;
				}
				case 1: { //Wrist Angle increment
					wrist_angle = wrist_angle + 5;
          wrist_angle = checkAngle(wrist_angle);
          break;
				}
				case 2: { //Wrist Angle decrement
					wrist_angle -= 5;
          wrist_angle = checkAngle(wrist_angle);
          break;
				}
				case 103: { //Gripper Angle increment
					gripper_angle = gripper_angle + 5;
          gripper_angle = checkAngle(gripper_angle);
          break;
				}
				case 108: { //Gripper Angle decrement
					gripper_angle -= 5;
          gripper_angle = checkAngle(gripper_angle);
          break;
				}
				default: { //Do nothing 
          break;
				}
			}

		//writeToAllServos(base_angle, bicep_angle, elbow_angle, wrist_angle, gripper_angle);
		}
   
    //READ ACCELERATION EVENT
    int accel_code;
    short accel_val;
    
    char accelbuff[16];
    
    if(read(accelid, accelbuff, 16) != 16) {
      //Do nothing
    }
    else {
         accel_code = accelbuff[10];
         accel_val = *(short *)(accelbuff + 12);
         
	 std::cout << "code = " << accel_code << "val = " << accel_val << "\n";

         //Use Y axis acceleration to change base
         if(accel_code == 5) {
                      if(accel_val > 100) {accel_val = 100; }
                      if(accel_val < -100){accel_val = -100;}
                      
                      		if(accel_val >= -100 && accel_val <= -76)
                         			base_angle = 0;	
                        if(accel_val >= -75 && accel_val <= -51) 
		                    	base_angle= 22;	
                         if(accel_val >= -50 && accel_val <= -26)
			                   base_angle= 44;	
                         if(accel_val >= -25 && accel_val <= -1) 
			                   base_angle= 66;
		                    if(accel_val >= 0 && accel_val <= 24) 
			                  base_angle= 88;	
                        if(accel_val >= 25 && accel_val <= 49)
			                  base_angle= 110;	
                         if(accel_val >= 50 && accel_val <= 74)
			                   base_angle= 132;	
                         if(accel_val >= 75 && accel_val <= 100)
			                   base_angle= 154;
         }
    }
    
   
		writeToAllServos(arm, base_angle, bicep_angle, elbow_angle, wrist_angle, gripper_angle);
	}
}
