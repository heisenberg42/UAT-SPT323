
#pragma once

int gDesServoAng = 0;

#define TICKS_PER_DEG (TICKS_PER_ROT / 360)

task manageServo()
{
	int curServoAng;

	int servPower = 0;

	int vertAxis = 90;

	while(true)
	{
		if(gDesServoAng < 0)
			gDesServoAng = 0;

		if(gDesServoAng > (180 + (gCurScissLvl * 7)))
			gDesServoAng = (180 + (gCurScissLvl * 7));


		curServoAng = nMotorEncoder[impServ] / TICKS_PER_DEG;

		if(curServoAng != gDesServoAng)//nMotorEncoder[impServ] > (gDesServoAng * TICKS_PER_DEG))
		{
			servPower = (gDesServoAng * TICKS_PER_DEG) - nMotorEncoder[impServ];
		}

		if(servPower > 40)servPower = 40;

		motor[impServ] = servPower;
		//else if(curServoAng < gDesServoAng)
		//{
		//	servPower -= (gDesServoAng * TICKS_PER_DEG) - curServoAng;
		//}
	}
}

//
