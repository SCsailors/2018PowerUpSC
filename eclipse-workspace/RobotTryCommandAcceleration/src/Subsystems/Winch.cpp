#include "Winch.h"
#include <SmartDashBoard/SmartDashBoard.h>

Winch::Winch() : Subsystem("Winch") {}

void Winch::InitDefaultCommand() {}

void Winch::MoveWinch(double input){
	frc::SmartDashboard::PutNumber("Winch",input);
	winch.Set(input);
}
