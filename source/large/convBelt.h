
#pragma once

#define MAX_CONV_LVL 7

#define TICKS_PER_CONV_LEVEL 50//TODO: Get # Ticks...

int gCurConvLvl = 0;

void pickupBlock()
{
	if(gCurConvLvl < MAX_CONV_LVL)
	{
		int nLiftLvl = gCurConvLvl + 1;//Ticks = nMotorEncoder[scissorLeft] + TICKS_PER_LEVEL;

		while(gCurConvLvl < nLiftLvl)//nMotorEncoder[scissorLeft] < nLiftTicks)
		{
			motor[convMot] = 40;
		}

		motor[convMot] = 0;
	}
}

void dropBlock()
{
	if(gCurConvLvl)
	{
		int nConvLvl = gCurConvLvl - 1;

		while(gCurConvLvl > nConvLvl)//nMotorEncoder[scissorLeft] > nLiftTicks)
		{
			motor[convMot] = -35 + (nMotorEncoder[convMot] % TICKS_PER_CONV_LEVEL);
		}

		motor[convMot] = 0;
	}
}

task trackCurConvLvl()
{
	gCurConvLvl = nMotorEncoder[convMot] / TICKS_PER_CONV_LEVEL;
}

//
