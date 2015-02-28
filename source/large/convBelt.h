
#pragma once

#define MAX_CONV_LVL 3

#define TICKS_PER_CONV_LEVEL 1175//round(3/2 * TICKS_PER_ROT)//63 * TICKS_PER_ROT / 32)//TODO: Get # Ticks...


int gCurConvLvl = 0;

long gConvTicks = 0;

int peekPwr = 0;

void pickupBlock();
void dropBlock();

void prepConv()
{
	nMotorEncoder[convMot] = 0;

	while(nMotorEncoder[convMot] < (1 * TICKS_PER_ROT / 2))//7/12
	{
		gConvTicks = nMotorEncoder[convMot];
		motor[convMot] = 75;
	}

	motor[convMot] = 0;

	gConvTicks = nMotorEncoder[convMot] = 0;

//	pickupBlock();
//	dropBlock();
}

void pickupBlock()
{
	if(nMotorEncoder[convMot] < MAX_CONV_LVL * TICKS_PER_CONV_LEVEL && gCurConvLvl < MAX_CONV_LVL)
	{
		//gCurConvLvl = nMotorEncoder[convMot] / TICKS_PER_CONV_LEVEL;

		//int nLiftLvl = gCurConvLvl + 1;//Ticks = nMotorEncoder[scissorLeft] + TICKS_PER_LEVEL;
		gConvTicks += TICKS_PER_CONV_LEVEL - ((gCurConvLvl == 2) ? 200 : 0);

		while(nMotorEncoder[convMot] < gConvTicks)//gCurConvLvl < nLiftLvl)//nMotorEncoder[scissorLeft] < nLiftTicks)
		{
			//gConvTicks = nMotorEncoder[convMot];
			peekPwr = motor[convMot] = 75 / (vexRT[Btn8L] ? 2 : 1);
			//gCurConvLvl = nMotorEncoder[convMot] / TICKS_PER_CONV_LEVEL;
		}

		gCurConvLvl += 1;

		motor[convMot] = 0;
	}
}

void dropBlock()
{
	if(nMotorEncoder[convMot] > 0 && gCurConvLvl > 0)
	{


		//gCurConvLvl = nMotorEncoder[convMot] / TICKS_PER_CONV_LEVEL;

		//int nConvLvl = gCurConvLvl - 1;
		gConvTicks -= TICKS_PER_CONV_LEVEL - 60;

		while(nMotorEncoder[convMot] > gConvTicks)//gCurConvLvl > nConvLvl)//nMotorEncoder[scissorLeft] > nLiftTicks)
		{
			//gConvTicks = nMotorEncoder[convMot];
			motor[convMot] = (-50/* + (round(nMotorEncoder[convMot]) % round(TICKS_PER_CONV_LEVEL))*/) / (vexRT[Btn8L] ? 2 : 1);
			//gCurConvLvl = nMotorEncoder[convMot] / TICKS_PER_CONV_LEVEL;
		}

		gCurConvLvl -= 1;

		motor[convMot] = 0;
	}
}

task trackCurConvLvl()
{
	nMotorEncoder[convMot] = 0;

	while(true)
		gCurConvLvl = nMotorEncoder[convMot] / TICKS_PER_CONV_LEVEL;
}

//
