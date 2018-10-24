#pragma once

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Drive/DifferentialDrive.h>

class DriveTrain : public frc::Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand() override;
	void Drive(double inleft, double inright);
private:
	frc::Spark left{1};                                                                           //CHANGE
	frc::Spark right{0};
	frc::DifferentialDrive RobotDrive{left, right};
};

