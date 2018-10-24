#include "Arm.h"
#include "../Robot.h"
#include "../Commands/JoyArm.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>


Arm::Arm() : Subsystem("Arm") {}

void Arm::InitDefaultCommand() {
	SetDefaultCommand(new JoyArm());
}

void Arm::Move(double invalue){
	frc::SmartDashboard::PutBoolean("Switch",armswitch.Get());
	if (armswitch.Get()==true && invalue<0 && DriverStation::GetInstance().GetMatchTime()>35){
		invalue=0;
	}
	frc::SmartDashboard::PutNumber("Arm",invalue);
	marm.Set(invalue);
}
