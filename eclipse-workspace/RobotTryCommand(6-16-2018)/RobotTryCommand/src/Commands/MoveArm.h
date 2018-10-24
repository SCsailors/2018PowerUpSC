#pragma once

#include <Commands/Command.h>
#include <Timer.h>

class MoveArm : public frc::Command {
public:
	MoveArm(double inseconds, double inspeed, bool involtcontrol);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double seconds;
	double speed;
	frc::Timer timer;
	bool voltcontrol;
};

