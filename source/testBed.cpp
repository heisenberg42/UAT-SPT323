#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  rightSonar,     sensorSONAR_mm)
#pragma config(Sensor, dgtl3,  midSonar,       sensorSONAR_mm)
#pragma config(Sensor, dgtl5,  leftSonar,      sensorSONAR_mm)
#pragma config(Sensor, dgtl7,  liftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  qEncBL,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  qEncBR,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  qEncFR,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  qEncFL,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  servoEnc,       sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_6,  wristEnc,       sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           wristMot,      tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_6)
#pragma config(Motor,  port2,           frontRightMotor, tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_3)
#pragma config(Motor,  port3,           frontLeftMotor, tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, I2C_4)
#pragma config(Motor,  port4,           backRightMotor, tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port5,           backLeftMotor, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port6,           scissorRight,  tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, dgtl7)
#pragma config(Motor,  port7,           scissorLeft,   tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, dgtl7)
#pragma config(Motor,  port8,           impServ,       tmotorVex393_MC29, openLoop, encoderPort, I2C_5)
#pragma config(Motor,  port10,          clawMot,       tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//#pragma config(Motor,  port8,           impServ,       tmotorVex393_MC29, openLoop, encoderPort, I2C_5)

//#pragma config(Motor,  port8,           convMot,       tmotorVex393_MC29, openLoop, encoderPort, I2C_5)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(I2C_Usage, I2C1, i2cSensors)
//#pragma config(Sensor, I2C_1,  qEncBL,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
//#pragma config(Sensor, I2C_2,  qEncBR,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
//#pragma config(Sensor, I2C_3,  qEncFR,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
//#pragma config(Sensor, I2C_4,  qEncFL,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
//#pragma config(Motor,  port2,           backLeftMotor, tmotorVex393_MC29, PIDControl, reversed, driveRight, encoderPort, I2C_2)
//#pragma config(Motor,  port3,           frontLeftMotor, tmotorVex393_MC29, PIDControl, reversed, driveLeft, encoderPort, I2C_3)
//#pragma config(Motor,  port4,           frontRightMotor, tmotorVex393_MC29, PIDControl, reversed, driveRight, encoderPort, I2C_4)
//#pragma config(Motor,  port5,           backRightMotor, tmotorVex393_MC29, PIDControl, reversed, driveLeft, encoderPort, I2C_1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//Robot B [Small]

//#define LARGE_BOT

#include "common\move.h"
#include "common\scissor.h"
#include "common\pingAlign.h"
//#include "large\convBelt.h"
#include "small\improvServo.h"
#include "small\clawArm.h"

#pragma platform(VEX)


task main()
{
	startTask(manageServo);
	startTask(manageClaw);

	nMotorEncoder[impServ] = nMotorEncoder[wristMot] = 0;

	//moveRight(12);
	gDesServoAng = 45;
	while(gServoAng < 35);

	gDesWristAng = 180;
	while(gWristAng < 175);

	clawState = 1;
	delay(750);

	gDesServoAng = 15;
	while(gServoAng > 15);

	gDesServoAng = 0;
	while(gServoAng > 0);

	clawState = 2;

	delay(750);

	for(int i = 0; i < 4 * 38; i++)
	{
		gDesServoAng += 1;//38;
		gDesWristAng -= 1;
		//while(gServoAng < gDesServoAng);
		delay(10);
	}

	gDesWristAng = 0;
	delay(250);

	clawState = 1;
	delay(500);

	//gDesServoAng = 90;
	//while(gServoAng < 80);
	//gDesServoAng = 180;


	for(int i = 0; i < 5; i++)
	{

	}
	while(1);
}


//task main()
//{
//	nMotorEncoder[impServ] = 0;
//	nMotorEncoder[clawMot] = 0;
//	startTask(RCMove);
//	startTask(manageServo);
//	startTask(scissorRC);
//	startTask(clawRC);

//	//for(int i = 12; i; i--)
//	//{
//	//	gDesServoAng += 15;
//	//	delay(3000);
//	//}
//	//for(int i = 12; i; i--)
//	//{
//	//	gDesServoAng -= 15;
//	//	delay(3000);
//	//}
//	//moveForward(12);

//	long lTime = 0;

//	while(true)
//	{
//		if((nSysTime - lTime) > 5)
//		{
//			if(vexRT[Btn6U])
//			{
//				gDesServoAng += 1;
//			}
//			if(vexRT[Btn6D])
//			{
//				gDesServoAng -= 1;
//			}


//			if(vexRT[Btn5U])
//			{
//				gDesWristAng += 1;
//			}
//			if(vexRT[Btn5D])
//			{
//				gDesWristAng -= 1;
//			}

//			lTime = nSysTime;
//		}
//	}
//}



//task main()
//{
//	////startTask(trackCurConvLvl);

//	startTask(RCMove);
//	startTask(scissorRC);
//	//startTask(trackCurConvLvl);

//	long lTime = 0;

//	prepConv();

//	while(1)
//	{
//		if(vexRT[Btn8D])// && (nSysTime - lTime) > 250)
//		{
//			pickupBlock();
//			//lTime = nSysTime;
//		}
//		else if(vexRT[Btn8R])// && (nSysTime - lTime) > 250)
//		{
//			dropBlock();
//			//lTime = nSysTime;
//		}
//	}

//}

//
