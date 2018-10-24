#include "ClawToggle.h"
#include "../Robot.h"

ClawToggle::ClawToggle(){
	Requires(&Robot::claw);
}

void ClawToggle::Initialize() {
	pstate=Robot::claw.clawOpen();
	Robot::claw.toggleClaw();
}

bool ClawToggle::IsFinished() {
	return (pstate!=Robot::claw.clawOpen());
}

