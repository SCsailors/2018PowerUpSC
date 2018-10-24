#include "ClawOpen.h"
#include "../Robot.h"

ClawOpen::ClawOpen() {
	Requires(&Robot::claw);
}

void ClawOpen::Initialize() {
	Robot::claw.toggleClaw();
}

bool ClawOpen::IsFinished() {
	return (Robot::claw.clawOpen()==true);
}

