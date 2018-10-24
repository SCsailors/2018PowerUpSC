#include "DriveStraight.h"
#include "../Robot.h"
#include <DriverStation.h>

DriveStraight::DriveStraight(double inseconds, double inspeedpercent,bool involtcontrol) {
	Requires(&Robot::drivetrain);
	Requires(&Robot::gyro);
	speedpercent=-inspeedpercent;
	seconds=inseconds;
	voltcontrol=involtcontrol;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	initial=Robot::gyro.GetAngle();
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	double vf=1;
	if (voltcontrol){
		vf=12/DriverStation::GetInstance().GetBatteryVoltage();
	}
	double angle=Robot::gyro.GetAngle();
	if (angle>(initial+5)){														//CHANGE all values
		Robot::drivetrain.Drive(.8*speedpercent*vf,1*speedpercent*vf);
	}
	else if (angle<(initial-5)){
		Robot::drivetrain.Drive(1*speedpercent*vf,.8*speedpercent*vf);
	}
	else{
		Robot::drivetrain.Drive(1*speedpercent*vf,1*speedpercent*vf);
	}
	Wait(.02);															//Change
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	if (timer.Get()>=seconds){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void DriveStraight::End() {
	Robot::drivetrain.Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	Robot::drivetrain.Drive(0,0);
}
