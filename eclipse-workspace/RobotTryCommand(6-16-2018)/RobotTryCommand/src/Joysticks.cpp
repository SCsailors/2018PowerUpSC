#include "Joysticks.h"

#include <SmartDashboard/SmartDashboard.h>

#include "Commands/ClawToggle.h"
#include "Commands/WinchWinch.h"

Joysticks::Joysticks(){
	a.WhenPressed(new ClawToggle());
	in_a.WhileHeld(new WinchWinch(-1));
	out_a.WhileHeld(new WinchWinch(1));
}

frc::Joystick& Joysticks::GetLeft() {
	return left;
}

frc::Joystick& Joysticks::GetRight() {
	return right;
}

frc::Joystick& Joysticks::GetGamepad() {
	return gamepad;
}
