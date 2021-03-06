#pragma config(Motor,  port2,           leftWheel,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           rightWheel,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rearWheel,   tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Returns the greater of two numbers
float max(float Number1, float Number2) {
	if (Number1 > Number2) {
		return Number1;
	}
	return Number2;
}

// Returns the lesser of two numbers
float min(float Number1, float Number2) {
	if (Number1 < Number2) {
		return Number1;
	}
	return Number2;
}

task main()
{
	while (true) {
		// New formula to maximize power
		// Left wheels' motor power = Y position of joystick - X position of joystick
		// with a maximum of 127
		// Remember, left is a negative value
		// If the joystick is being held to the left, the left wheels' motor should
		// still be going at maximum power
		//motor[leftWheels] = min(vexRT[Ch2] + vexRT[Ch1], 127);
		motor[leftWheel] = min(vexRT[Ch2] + vexRT[Ch1], 127);
		// Right wheels' motor power = Y position of joystick + X position of joystick
		// with a maximum of 127
		// Remember, right is a positive vamin
		// If the joystick is being held to the right, the right wheels' motor should
		// still be going at maximum power
		//motor[rightWheels] = min(vexRT[Ch2] - vexRT[Ch1], 127);
		motor[rightWheel] = min(vexRT[Ch2] - vexRT[Ch1], 127);
		motor[rearWheel] = vexRT[Ch3];
	}
}
