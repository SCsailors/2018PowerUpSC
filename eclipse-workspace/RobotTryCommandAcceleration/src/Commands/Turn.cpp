#include "Turn.h"
#include "../Robot.h"

Turn::Turn(double inchange) {
	Requires(&Robot::drivetrain);
	Requires(&Robot::gyro);
	change=inchange;
}

void Turn::Initialize() {
	initial=Robot::gyro.GetAngle();
}

void Turn::Execute() {
	if (change>0){
		Robot::drivetrain.Drive(-.8,.8);
	}
	else{
		Robot::drivetrain.Drive(.8,-.8);
	}

}

bool Turn::IsFinished() {
	if (change>0){
		if (Robot::gyro.GetAngle()<(initial+change)){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		if (Robot::gyro.GetAngle()>(initial+change)){
			return false;
		}
		else{
			return true;
		}
	}

}


void Turn::End() {
	Robot::drivetrain.Drive(0,0);
}


void Turn::Interrupted() {
	Robot::drivetrain.Drive(0,0);
}
