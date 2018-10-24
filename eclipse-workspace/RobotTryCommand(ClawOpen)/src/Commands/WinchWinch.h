#pragma once

#include <Commands/Command.h>

class WinchWinch : public frc::Command {
public:
	WinchWinch(double inspeed);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double speed;
};

