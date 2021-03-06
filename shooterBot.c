#pragma config(Sensor, dgtl2,  touchSensor,    sensorTouch)
#pragma config(Motor,  port1,           leftOne,       tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port3,           Shooter,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightOne,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bStopTasksBetweenModes = true;


}

task autonomous()
{
motor[leftOne] = 100;
motor[rightOne] = 100;

wait1Msec(3000);

motor[leftOne] = 0;
motor[rightOne] = 0;

motor[Shooter] = 127;

wait1Msec(2000);

motor[Shooter] = 0;
AutonomousCodePlaceholderForTesting();
}

task usercontrol()
{

	while (true)
	{
		//Stuff
		int leftJoystick = vexRT[Ch3] * 0.78;
		motor[leftOne] = leftJoystick;

		int rightJoystick = vexRT[Ch2] * 0.78;
		motor[rightOne] = rightJoystick;

		if(SensorValue(touchSensor) == 0)
		{
			if(vexRT[Btn6U] == 1 && vexRT[Btn5U] == 0)
			{
				motor[Shooter] = 127;
			}
			else if(vexRT[Btn5U] == 1 && vexRT[Btn6U] == 0)
			{
				motor[Shooter] = -127;
			}
			else
			{
				motor[Shooter] = 0;
			}
		}
		else if(SensorValue(touchSensor) == 1 && vexRT[Btn6D] == 0)
		{
			motor[Shooter] = 50;
		}
		else if(SensorValue(touchSensor) == 1 && vexRT[Btn6D] == 1)
		{
			motor[Shooter] = 127;
		}
		else
		{
			motor[Shooter] = 0;
		}
		UserControlCodePlaceholderForTesting();
	}
}
