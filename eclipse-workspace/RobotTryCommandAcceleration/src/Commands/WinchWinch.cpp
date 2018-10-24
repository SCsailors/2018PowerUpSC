#include "WinchWinch.h"
#include "../Robot.h"

WinchWinch::WinchWinch(double inspeed) {
	speed=inspeed;
	Requires(&Robot::winch);
}

void WinchWinch::Initialize() {
	Robot::winch.MoveWinch(speed);
}

bool WinchWinch::IsFinished() {
	return false;
}


void WinchWinch::End() {
	Robot::winch.MoveWinch(0);
}

void WinchWinch::Interrupted() {
	Robot::winch.MoveWinch(0);
}
