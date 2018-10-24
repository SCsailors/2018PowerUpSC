#include <Commands/TankDrive.h>
#include "../Robot.h"

TankDrive::TankDrive(bool inacceleration) : frc::Command("TankDrive") {
	Requires(&Robot::drivetrain);
	acceleration=inacceleration;

}

void TankDrive::Execute() {
	double left=Robot::joysticks.GetLeft().GetY();       //auto& instead of double?
	double right=Robot::joysticks.GetRight().GetY();
	if (acceleration){
		if (left>0){
			left=left*left;
		}
		else{
			left=-left*left;
		};
		if (right>0){
			right=right*right;
		}
		else{
			right=-right*right;
		}



	};
	Robot::drivetrain.Drive(left,right);
}

bool TankDrive::IsFinished() {
	return false;
}


void TankDrive::End() {
	Robot::drivetrain.Drive(0, 0);
}
