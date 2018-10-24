#pragma once

#include <Commands/Command.h>


class ClawToggle : public frc::Command{
public:
	ClawToggle();
	void Initialize() override;
	bool IsFinished() override;
private:
	bool pstate=false;
};

