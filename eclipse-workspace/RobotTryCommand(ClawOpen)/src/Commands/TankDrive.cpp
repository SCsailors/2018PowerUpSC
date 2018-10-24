#include <Commands/TankDrive.h>
#include "../Robot.h"

TankDrive::TankDrive() : frc::Command("TankDrive") {
	Requires(&Robot::drivetrain);
}

void TankDrive::Execute() {
	double left=Robot::joysticks.GetLeft().GetY();       //auto& instead of double?
	double right=Robot::joysticks.GetRight().GetY();
	Robot::drivetrain.Drive(left,right);
}

bool TankDrive::IsFinished() {
	return false;
}


void TankDrive::End() {
	Robot::drivetrain.Drive(0, 0);
}
