
#pragma once

int clawState = 0;//1 == open, 2 = close, 0 = hold

task manageClaw()
{
	while(true)
	{
		if(clawState == 1)
		{
			motor[clawMot] = -75;
			delay(1000);
			clawState = 0;
		}
		else if(clawState == 2)
		{
			motor[clawMot] = 75;
			delay(1000);
			clawState = 0;
		}
		else
		{
			motor[clawMot] = 0;
		}
	}
}

task clawRC()
{
	while(true)
	{
		if(vexRT[Btn7D])
		{
			motor[clawMot] = 75;
		}
		else if(vexRT[Btn7R])
		{
			motor[clawMot] = -75;
		}
		else
		{
			motor[clawMot] = 0;
		}
	}
}

//
