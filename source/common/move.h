
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




task AutoMove()
{
	long nTicks = 0;
	while(true)
	{
		nMotorEncoder[backRightMotor] = 0;
		motor[backRightMotor] = 100;
		delay(1000);
		nTicks = nMotorEncoder[backRightMotor];
	}
}

int m1, m2, m3, m4;

void move(int x = 0, int y = 0, int r = 0)
{
	x /= 3;
	y /= 3;
	r /= 3;

	if((m1 = -y + x + r) < 30 && m1 > 0)m1 = 30;
	else if(m1 > -30 && m1 < 0)m1 = -30;

	if((m2 = -y - x - r) < 30 && m2 > 0)m2 = 30;
	else if(m2 > -30 && m2 < 0)m2 = -30;

	if((m3 = y + x - r) < 30 && m3 > 0)m3 = 30;
	else if(m3 > -30 && m3 < 0)m3 = -30;

	if((m4 = y - x + r) < 30 && m4 > 0)m4 = 30;
	else if(m4 > -30 && m4 < 0)m4 = -30;

	motor[frontRightMotor] = m1;
	motor[frontLeftMotor] = m2;
	motor[backRightMotor] = m3;
	motor[backLeftMotor] = m4;
}
