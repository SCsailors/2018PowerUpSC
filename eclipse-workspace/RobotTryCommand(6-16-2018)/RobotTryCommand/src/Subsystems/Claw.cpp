#include "Claw.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>

MyClaw::MyClaw() : Subsystem("Claw") {}

void MyClaw::InitDefaultCommand(){}

void MyClaw::toggleClaw(){
	if (open){
		clawsol.Set(frc::DoubleSolenoid::Value::kForward);
		open=false;
	}
	else{
		clawsol.Set(frc::DoubleSolenoid::Value::kReverse);
		open=true;
	}
	frc::SmartDashboard::PutBoolean("Claw Open?",MyClaw::open);
}

bool MyClaw::clawOpen(){
	return open;
}


