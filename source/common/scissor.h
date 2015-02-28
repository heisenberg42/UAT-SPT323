
#pragma once

#define MAX_SCISS_LVL 6

#define TICKS_PER_LEVEL 50//TODO: Get # Ticks...

int gCurScissLvl = 0;

void raiseLiftLvl()
{
	if(gCurScissLvl < MAX_SCISS_LVL)
	{
		gCurScissLvl = nMotorEncoder[scissorLeft] / TICKS_PER_LEVEL;

		int nLiftLvl = gCurScissLvl + 1;//Ticks = nMotorEncoder[scissorLeft] + TICKS_PER_LEVEL;

		while(gCurScissLvl < nLiftLvl)//nMotorEncoder[scissorLeft] < nLiftTicks)
		{
			gCurScissLvl = nMotorEncoder[scissorLeft] / TICKS_PER_LEVEL;
			motor[scissorRight] = 40;
			motor[scissorLeft] = 40;
		}

		motor[scissorRight] = motor[scissorLeft] = 0;
	}
}

void dropLiftLvl()
{
	if(gCurScissLvl)
	{
		gCurScissLvl = nMotorEncoder[scissorLeft] / TICKS_PER_LEVEL;

		int nLiftLvl = gCurScissLvl - 1;

		while(gCurScissLvl > nLiftLvl)//nMotorEncoder[scissorLeft] > nLiftTicks)
		{
			motor[scissorRight] = -35 + (nMotorEncoder[scissorLeft] % TICKS_PER_LEVEL);
			motor[scissorLeft] = -35 + (nMotorEncoder[scissorLeft] % TICKS_PER_LEVEL);
			gCurScissLvl = nMotorEncoder[scissorLeft] / TICKS_PER_LEVEL;
		}

		motor[scissorRight] = motor[scissorLeft] = 0;
	}
}

task trackCurLvl()
{
	gCurScissLvl = nMotorEncoder[scissorLeft] / TICKS_PER_LEVEL;
}

task scissorRC()
{
	while(1)
	{
		motor[scissorRight] = motor[scissorLeft] = -vexRT[Ch2] / (vexRT[Btn8L] ? 2 : 1);
		//if(vexRT[Btn5U])
		//{
		//	motor[scissorRight] = 40;
		//	motor[scissorLeft] = 40;
		//}
		//else if(vexRT[Btn5D])
		//{
		//	motor[scissorRight] = -35;
		//	motor[scissorLeft] = -35;
		//}
		//else
		//{
		//	motor[scissorRight] = motor[scissorLeft] = 0;
		//}
	}
}


//
