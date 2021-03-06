
#pragma once

#ifdef LARGE_BOT
	#define ROT_CONST 10
	#define RC_REDUCE *(vexRT[Btn8L] ? .75 : 1)
#else
	#define ROT_CONST 9
	#define RC_REDUCE /(vexRT[Btn8L] ? 2 : 1)
#endif

task RCMove()
{
	while(true){

		int Fore = vexRT[Ch3] / 3;
		int Side = vexRT[Ch4] / 3;
		int Rot = vexRT[Ch1] / 3;

		motor[frontRightMotor] = (-Fore + Side + Rot) RC_REDUCE;// (vexRT[Btn8L] ? 2 : 1);
		motor[frontLeftMotor] = (-Fore - Side - Rot) RC_REDUCE;// (vexRT[Btn8L] ? 2 : 1);
		motor[backRightMotor] = (Fore + Side - Rot) RC_REDUCE;// (vexRT[Btn8L] ? 2 : 1);
		motor[backLeftMotor] = (Fore - Side + Rot) RC_REDUCE;// (vexRT[Btn8L] ? 2 : 1);

	}

}


#define MIN_SPEED 25

void move(int x = 0, int y = 0, int r = 0)
{
	int m1, m2, m3, m4;

	if(!x && !y && !r)
	{
		motor[frontRightMotor] = motor[frontLeftMotor] = motor[backRightMotor] = motor[backLeftMotor] = 0;
	}

	x /= 3;
	y /= 3;
	r /= 3;

	if((m1 = -x + y + r) < MIN_SPEED && m1 > 0)m1 = MIN_SPEED;
	else if(m1 > -MIN_SPEED && m1 < 0)m1 = -MIN_SPEED;

	if((m2 = -x - y - r) < MIN_SPEED && m2 > 0)m2 = MIN_SPEED;
	else if(m2 > -MIN_SPEED && m2 < 0)m2 = -MIN_SPEED;

	if((m3 = x + y - r) < MIN_SPEED && m3 > 0)m3 = MIN_SPEED;
	else if(m3 > -MIN_SPEED && m3 < 0)m3 = -MIN_SPEED;

	if((m4 = x - y + r) < MIN_SPEED && m4 > 0)m4 = MIN_SPEED;
	else if(m4 > -MIN_SPEED && m4 < 0)m4 = -MIN_SPEED;

	motor[frontRightMotor] = m1;
	motor[frontLeftMotor] = m2;
	motor[backRightMotor] = m3;
	motor[backLeftMotor] = m4;
}

#define TICKS_PER_ROT 627.2
#define TICKS_PER_IN (TICKS_PER_ROT / 12) //49.9 /*52.26*/

void moveForward(int d)
{
	if(!d)
		return;

	nMotorEncoder[frontRightMotor] = 0;
	nMotorEncoder[frontLeftMotor] = 0;
	nMotorEncoder[backRightMotor] = 0;
	nMotorEncoder[backLeftMotor] = 0;

	int sign = (d < 0) ? -1 : 1;


	while((sign * nMotorEncoder[frontRightMotor]) < (sign * d * TICKS_PER_IN))
	{
		move(sign * 40,0,0);
	}

	move();
}

void moveRight(int d)
{
	if(!d)
		return;

	nMotorEncoder[frontRightMotor] = 0;
	nMotorEncoder[frontLeftMotor] = 0;
	nMotorEncoder[backRightMotor] = 0;
	nMotorEncoder[backLeftMotor] = 0;

	int sign = (d < 0) ? -1 : 1;


	while((sign * nMotorEncoder[frontRightMotor]) < (sign * d * TICKS_PER_IN))
	{
		move(0,sign * 60,0);
	}

	move();
}


void moveRotate(double a)
{
	if(!a)
		return;

	nMotorEncoder[frontRightMotor] = 0;
	nMotorEncoder[frontLeftMotor] = 0;
	nMotorEncoder[backRightMotor] = 0;
	nMotorEncoder[backLeftMotor] = 0;

	double sign = (a < 0) ? -1 : 1;

	while((sign * nMotorEncoder[frontRightMotor]) < (sign * a * (ROT_CONST + ((a > (PI / 2)) ? .2 : 0/*7.38*/)) * TICKS_PER_IN))
	{
		move(0, 0, sign * 40 * 2);
		//motor[backLeftMotor] = motor[frontLeftMotor] = sign * MIN_SPEED *2;
		//motor[backRightMotor] = motor[frontRightMotor] = sign * MIN_SPEED *2;
	}

	move();
}
