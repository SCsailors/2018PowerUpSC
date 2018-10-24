#pragma once

#include <Commands/Subsystem.h>
#include <AnalogGyro.h>

class MyGyro : public frc::Subsystem {
public:
	MyGyro();
	void InitDefaultCommand() override;
	void Reset();
	double GetAngle();

private:
	frc::AnalogGyro gyro{0};           //change
};

