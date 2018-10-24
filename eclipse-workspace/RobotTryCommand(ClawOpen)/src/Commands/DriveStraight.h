#pragma once

#include <Commands/Command.h>
#include <Timer.h>

class DriveStraight : public frc::Command {
public:
	DriveStraight(double insecondsdouble, double inspeedpercent,bool involtcontrol);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double initial=0;
	double speedpercent;
	double seconds;
	bool voltcontrol;
	frc::Timer timer;
};

