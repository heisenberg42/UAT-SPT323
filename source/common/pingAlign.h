
#pragma once

bool aligned = false;

void alignBot()
{
	bool running = true;

	long lSonar, mSonar, rSonar;

	int speedForw = 0;
	int speedRight = 0;
	int speedRot = 0;

	aligned = false;

	while(running)
	{
		lSonar = SensorValue[leftSonar];
		mSonar = SensorValue[midSonar];
		rSonar = SensorValue[rightSonar];

		speedRight = 0;

		if((lSonar <= mSonar) && (lSonar < rSonar))//Move left
		{
			speedRight = -25;
		}

		if((rSonar <= mSonar) && (rSonar < lSonar))//Move right
		{
			speedRight = 25;
		}

		if(lSonar < mSonar || rSonar < mSonar)
		{
			if(lSonar < rSonar)
			{
				if(lSonar > 12)
					speedForw = 5 * (lSonar - 8);
				else if(lSonar < 8)
					speedForw = 5 * (lSonar - 8);
				else
					speedForw = 0;
			}
			else if(rSonar > 12)
				speedForw = 5 * (rSonar - 8);
			else if(rSonar < 8)
				speedForw = 5 * (rSonar - 8);
			else
				speedForw = 0;
		}
		else if(mSonar > 12)
			speedForw = 5 * (mSonar - 8);
		else if(mSonar < 8)
			speedForw = 5 * (mSonar- 8);
		else
			speedForw = 0;

		if(speedForw < -150)
		{
			speedForw = -150;
		}
		else if(speedForw > 150)
		{
			speedForw = 150;
		}


		move(speedRight, speedForw, speedRot);


		for(int it = 2; it; it--)
		{
			if((mSonar < 11 && mSonar > 7) && (lSonar > (mSonar + 20) && rSonar > (mSonar + 20)))
			{
				if(it == 1)
				{
					move(0, 0, 0);
					running = false;
					aligned = true;
				}
			}
			else
				break;
		}
	}
}
