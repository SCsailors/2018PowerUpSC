#include "JoyArm.h"
#include "../Robot.h"

JoyArm::JoyArm() {
	Requires(&Robot::arm);
	//Requires(&Robot::winchencoder);
}


void JoyArm::Execute() {
	double value=Robot::joysticks.GetGamepad().GetY();     //auto& instead of double?
	Robot::arm.Move(value);								//^CHANGE
	//Robot::winchencoder.GetDistance();
}


bool JoyArm::IsFinished() {
	return false;
}


void JoyArm::End() {
	Robot::arm.Move(0);
}


