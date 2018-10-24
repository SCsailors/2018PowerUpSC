#include "Gyro.h"
#include "../Robot.h"
#include <SmartDashBoard/SmartDashBoard.h>

MyGyro::MyGyro() : Subsystem("Gyro") {}

void MyGyro::InitDefaultCommand() {
}

void MyGyro::Reset(){
	gyro.Reset();
}

double MyGyro::GetAngle(){
	double angle=gyro.GetAngle();
	frc::SmartDashboard::PutNumber("Gyro (When Called)",angle);
	return angle;
}
