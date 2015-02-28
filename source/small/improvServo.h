
#pragma once

int gDesServoAng = 0;

#define TICKS_PER_DEG ((TICKS_PER_ROT / 360) * (60 / 36))

int gTicks;

int gServoAng;

int gServoPwr;

task manageServo()
{
	int curServoAng;

	int servPower = 0;

	int vertAxis = 90;

	while(true)
	{
		gTicks = nMotorEncoder[impServ];

		//if(nMotorEncoder[impServ] < 0)
		//	nMotorEncoder[impServ] = 0;

		if(gDesServoAng < 0)
			gDesServoAng = 0;

		if(gDesServoAng > (180 + (gCurScissLvl * 13)))
			gDesServoAng = 180 + (gCurScissLvl * 13);


		gServoAng = curServoAng = nMotorEncoder[impServ] / TICKS_PER_DEG;


		if(curServoAng != gDesServoAng)//nMotorEncoder[impServ] > (gDesServoAng * TICKS_PER_DEG))
		{
			gServoPwr = servPower = (gDesServoAng * TICKS_PER_DEG) - nMotorEncoder[impServ];
			if(curServoAng < (gDesServoAng + 15) && curServoAng > (gDesServoAng - 15))
				servPower += 15 * ((curServoAng > gDesServoAng && gDesServoAng > (180 + (gCurScissLvl * 7.5))) ? -1 : 1);
		}
		else if(gDesServoAng == 0)
		{
			servPower = 0;
		}

		//if(servPower > 40)servPower = 40;

		motor[impServ] = servPower;
		//else if(curServoAng < gDesServoAng)
		//{
		//	servPower -= (gDesServoAng * TICKS_PER_DEG) - curServoAng;
		//}
	}
}

//
