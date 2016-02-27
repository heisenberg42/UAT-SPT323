
#pragma once

int gDesServoAng = 0;

int gDesWristAng = 0;

#define TICKS_PER_DEG (TICKS_PER_ROT / 360)
#define GEAR_RATIO * 60 / 36

//int gTicks;

int gServoAng;
int gWristAng;

//int gServoPwr;

int wristPower = 0;

task manageServo()
{
	nMotorEncoder[impServ] = 0;
	nMotorEncoder[wristMot] = 0;

	int curServoAng = 0;
	int curWristAng = 0;

	int servPower = 0;


	//int vertAxis = 90;

	while(true)
	{
		//gTicks = nMotorEncoder[impServ];

		//if(nMotorEncoder[impServ] < 0)
		//	nMotorEncoder[impServ] = 0;

		if(gDesServoAng < 0)
			gDesServoAng = 0;
		if(gDesServoAng > (180 + 90 + (gCurScissLvl * 13)))
			gDesServoAng = 180 + 90 + (gCurScissLvl * 13);

		if(gDesWristAng < 0)
			gDesWristAng = 0;
		if(gDesWristAng > (180 + 90 + (gCurScissLvl * 13)))
			gDesWristAng = 180 + 90 + (gCurScissLvl * 13);


		gServoAng = curServoAng = nMotorEncoder[impServ] / (TICKS_PER_ROT / 360 * 60 / 36);//TICKS_PER_DEG GEAR_RATIO;
		gWristAng = curWristAng = nMotorEncoder[wristMot] / -TICKS_PER_DEG;

		gWristAng *= -1;

		if(curServoAng != gDesServoAng)//nMotorEncoder[impServ] > (gDesServoAng * TICKS_PER_DEG))
		{
			/*gServoPwr = */servPower = (gDesServoAng * TICKS_PER_DEG GEAR_RATIO) - nMotorEncoder[impServ];
			if(curServoAng < (gDesServoAng + 15) && curServoAng > (gDesServoAng - 15))
				servPower += 20 * ((curServoAng > gDesServoAng && gDesServoAng > (180 + (gCurScissLvl * 7.5))) ? -1 : 1);
		}
		/*else if(gDesServoAng == 0)
		{
			servPower = 0;
		}*/

		if(curWristAng != gDesWristAng)//nMotorEncoder[impServ] > (gDesServoAng * TICKS_PER_DEG))
		{
			wristPower = (gDesWristAng * TICKS_PER_DEG) - nMotorEncoder[wristMot];
			//if(curWristAng < (gDesWristAng + 15) && curWristAng > (gDesWristAng - 15))
				//wristPower += 15 * ((curWristAng > gDesWristAng && gDesWristAng > (180 + (gCurScissLvl * 7.5))) ? -1 : 1);
		}
		/*else if(gDesWristAng == 0)
		{
			wristPower = 0;
		}*/

		//if(servPower > 40)servPower = 40;

		motor[impServ] = servPower;
		motor[wristMot] = wristPower;
		//else if(curServoAng < gDesServoAng)
		//{
		//	servPower -= (gDesServoAng * TICKS_PER_DEG) - curServoAng;
		//}
	}
}

//
