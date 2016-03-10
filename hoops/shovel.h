
#pragma once

#define ARM_MAX_ANGLE (180)
#define WRIST_MAX_ANGLE (180)

#define ARM_SENSITIVITY 60
#define WRIST_SENSITIVITY 2

#define UPDATE_WAIT_DURATION 10


task RCShovel()
{

	int armAng = 0;
	int wristAng = 0;

	unsigned long lUpdateTime = 0;

	while(true)
	{
		if(nSysTime - lUpdateTime >= UPDATE_WAIT_DURATION)
		{
			armAng += (vexRT[Ch2] / ARM_SENSITIVITY);

			if(vexRT[Btn6U])
			{
				wristAng -= WRIST_SENSITIVITY;
			}
			if(vexRT[Btn6D])
			{
				wristAng += WRIST_SENSITIVITY;
			}

			if(armAng < 0)
				armAng = 0;

			if(wristAng < 0)
				wristAng = 0;

			if(armAng > ARM_MAX_ANGLE)
				armAng = ARM_MAX_ANGLE;

			if(wristAng > WRIST_MAX_ANGLE)
				wristAng = WRIST_MAX_ANGLE;

			gDesServoAng = armAng;
			gDesWristAng = wristAng;

			lUpdateTime = nSysTime;
		}
	}
}

//
