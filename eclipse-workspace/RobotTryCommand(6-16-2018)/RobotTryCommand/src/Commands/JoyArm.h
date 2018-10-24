#pragma once

#include <Commands/Command.h>

class JoyArm : public frc::Command {
public:
	JoyArm();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
};

