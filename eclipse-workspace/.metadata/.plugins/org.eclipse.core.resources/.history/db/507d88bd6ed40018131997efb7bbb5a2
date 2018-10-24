#pragma once

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include <SmartDashBoard/SmartDashBoard.h>
#include "Subsystems/Claw.h"

class MyClaw : public frc::Subsystem {
public:
	MyClaw();
	void InitDefaultCommand() override;
	void toggleClaw();
	bool clawOpen();
private:
	frc::DoubleSolenoid clawsol {0, 1};																//CHANGE
	bool open=false;
};

