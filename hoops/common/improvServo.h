
#pragma once

int gDesServoAng = 0;

int gDesWristAng = 0;


#define INVERT_ENCODERS *(1)

#define SERVO_MAX_ANGLE (180)
#define WRIST_SERVO_MAX_ANGLE (180)

#define SERVO_TICKS_PER_ROT 627.2
//or 633 | 632

#define TICKS_PER_DEG (SERVO_TICKS_PER_ROT / 360)
#define GEAR_RATIO 12 / 60

//int gTicks;

int gServoAng;
int gWristAng;

//int gServoPwr;

int servPower = 0;
int wristPower = 0;

task manageServo()
{
	nMotorEncoder[impServ] = 0;
	nMotorEncoder[wristMot] = 0;

	int curServoAng = 0;
	int curWristAng = 0;

	//int servPower = 0;
	//int wristPower = 0;

	//int vertAxis = 90;

	while(true)
	{
		//gTicks = nMotorEncoder[impServ];

		//if(nMotorEncoder[impServ] < 0)
		//	nMotorEncoder[impServ] = 0;

		if(gDesServoAng < 0)
			gDesServoAng = 0;
		if(gDesServoAng > SERVO_MAX_ANGLE)//(180 + 70))// + (gCurScissLvl * 13)))
			gDesServoAng = SERVO_MAX_ANGLE;//180 + 70;// + (gCurScissLvl * 13);

		if(gDesWristAng < 0)
			gDesWristAng = 0;
		if(gDesWristAng > WRIST_SERVO_MAX_ANGLE)//(180 + 70))// + (gCurScissLvl * 13)))
			gDesWristAng = WRIST_SERVO_MAX_ANGLE;//180 + 70;// + (gCurScissLvl * 13);


		gServoAng = curServoAng = nMotorEncoder[impServ] / TICKS_PER_DEG * GEAR_RATIO;// (TICKS_PER_ROT / 360 * 60 / 36);//TICKS_PER_DEG GEAR_RATIO;
		gWristAng = curWristAng = nMotorEncoder[wristMot] / TICKS_PER_DEG;

		//gWristAng *= -1;

		//if(curServoAng != gDesServoAng)//nMotorEncoder[impServ] > (gDesServoAng * TICKS_PER_DEG))
		//{
		//	/*gServoPwr = */servPower = (gDesServoAng * TICKS_PER_DEG * GEAR_RATIO) - nMotorEncoder[impServ];
		//	if(curServoAng < (gDesServoAng + 15) && curServoAng > (gDesServoAng - 15))
		//		servPower += 20 * ((curServoAng > gDesServoAng && gDesServoAng > (180/* + (gCurScissLvl * 7.5)*/)) ? -1 : 1);
		//}
		/*else if(gDesServoAng == 0)
		{
			servPower = 0;
		}*/

		if(curServoAng < gDesServoAng)
		{
			servPower = (gDesServoAng - curServoAng) * 5;
		}
		else if(curServoAng > gDesServoAng)
		{
			servPower = (curServoAng - gDesServoAng) * (-5);
		}
		else if(curServoAng == gDesServoAng)
		{
			servPower = 0;
		}

		if(curWristAng < gDesWristAng)
		{
			wristPower = (gDesWristAng - curWristAng) * 5;
		}
		else if(curWristAng > gDesWristAng)
		{
			wristPower = (curWristAng - gDesWristAng) * (-5);
		}
	  if(curWristAng == gDesWristAng)
		{
			wristPower = 0;
		}

		//if(curWristAng != gDesWristAng)//nMotorEncoder[impServ] > (gDesServoAng * TICKS_PER_DEG))
		//{
		//	wristPower = (gDesWristAng * 2) - (nMotorEncoder[wristMot] / TICKS_PER_DEG * 2);// * TICKS_PER_DEG) - (nMotorEncoder[wristMot]);
		//	if(gDesWristAng <
		//	//if(curWristAng < (gDesWristAng + 5) && curWristAng > (gDesWristAng - 5))
		//	//	wristPower += 15 * ((curWristAng > gDesWristAng && gDesWristAng > (180)) ? -1 : 1);
		//}
		///*else if(gDesWristAng == 0)
		//{
		//	wristPower = 0;
		//}*/

		//if(servPower > 40)servPower = 40;

		motor[impServ] = -servPower;
		motor[wristMot] = wristPower;

		//EndTimeSlice();

		//else if(curServoAng < gDesServoAng)
		//{
		//	servPower -= (gDesServoAng * TICKS_PER_DEG) - curServoAng;
		//}
	}
}

//
