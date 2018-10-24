#include "MoveArm.h"
#include "../Robot.h"
#include <Timer.h>

MoveArm::MoveArm(double inseconds, double inspeed, bool involtcontrol) {
	Requires(&Robot::arm);
	seconds=inseconds;
	speed=-inspeed;
	voltcontrol=involtcontrol;
}


void MoveArm::Initialize() {
	timer.Reset();
	timer.Start();
	double vf=1;
	if (voltcontrol){
		vf=12/DriverStation::GetInstance().GetBatteryVoltage();
	}
	Robot::arm.Move(speed*vf);
}


bool MoveArm::IsFinished() {
	if (timer.Get()>=seconds){
		return true;
	}
	else{
		return false;
	}
}


void MoveArm::End() {
	Robot::arm.Move(0);
}


void MoveArm::Interrupted() {
	Robot::arm.Move(0);
}
