#include "JoyArm.h"
#include "../Robot.h"

JoyArm::JoyArm() {
	Requires(&Robot::arm);
}


void JoyArm::Execute() {
	double value=Robot::joysticks.GetGamepad().GetY();     //auto& instead of double?
	Robot::arm.Move(value);								//^CHANGE
}


bool JoyArm::IsFinished() {
	return false;
}


void JoyArm::End() {
	Robot::arm.Move(0);
}


