#include <stdlib.h>	
#include <fcntl.h>	
#include <unistd.h>
#include <iostream>	
#include "WiimoteBtns.h" 
#include "RoboticArm.h"

int main() {
	WiimoteBtns *wiibtns = new WiimoteBtns(); 
	wiibtns->Listen();
}
