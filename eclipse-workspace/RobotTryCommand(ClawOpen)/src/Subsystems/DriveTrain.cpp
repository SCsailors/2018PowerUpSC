#include "DriveTrain.h"
#include "../Robot.h"
#include "../Commands/TankDrive.h"
#include <SmartDashBoard/SmartDashBoard.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	left.SetInverted(true);
	right.SetInverted(true);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive());
}


void DriveTrain::Drive(double inleft, double inright){
	RobotDrive.TankDrive(inleft,inright);
	Robot::gyro.GetAngle();
	frc::SmartDashboard::PutNumber("LeftDrive",inleft);
	frc::SmartDashboard::PutNumber("RightDrive",inright);
}

