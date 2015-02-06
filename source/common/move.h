
#pragma once

task RCMove()
{
	while(true){

		int Fore = vexRT[Ch3] / 3;
		int Side = vexRT[Ch4] / 3;
		int Rot = vexRT[Ch1] / 3;

		motor[frontRightMotor] = -Fore + Side + Rot;
		motor[frontLeftMotor] = -Fore - Side - Rot;
		motor[backRightMotor] = Fore + Side - Rot;
		motor[backLeftMotor] = Fore - Side + Rot;

	}

}

void move(int x, int y, int r)
{
	if(x)x /= 3;
	if(y)y /= 3;
	if(r)r /= 3;

	motor[frontRightMotor] = -y + x + r;
	motor[frontLeftMotor] = -y - x - r;
	motor[backRightMotor] = y + x - r;
	motor[backLeftMotor] = y - x + r;
}
