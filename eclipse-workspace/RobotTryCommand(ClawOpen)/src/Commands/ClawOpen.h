#pragma once

#include <Commands/Command.h>

class ClawOpen : public frc::Command {
public:
	ClawOpen();
	void Initialize() override;
	bool IsFinished() override;
};

