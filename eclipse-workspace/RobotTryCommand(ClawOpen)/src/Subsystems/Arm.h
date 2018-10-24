#pragma once

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <DigitalInput.h>

class Arm : public frc::Subsystem {
public:
	Arm();
	void InitDefaultCommand() override;
	void Move(double invalue);
private:
	frc::Spark marm{2};
	frc::DigitalInput armswitch{0};
};

