#pragma once

#include <Commands/Subsystem.h>
#include <Spark.h>

class Winch : public frc::Subsystem {
public:
	Winch();
	void InitDefaultCommand() override;
	void MoveWinch(double input);
private:
	frc::Spark winch{3};
};

