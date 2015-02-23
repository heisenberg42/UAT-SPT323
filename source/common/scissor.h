
#pragma once


task scissorRC()
{
	while(1)
	{
		if(vexRT[Btn6U])
		{
			motor[scissorRightA] = 40;
			motor[scissorRightB] = 40;
		}
		else if(vexRT[Btn6D])
		{
			motor[scissorRightA] = -35;
			motor[scissorRightB] = -35;
		}
		else
		{
			motor[scissorRightA] = motor[scissorRightB] = 0;
		}
	}
}


//
