#pragma once

#include <Commands/Command.h>

class TankDrive : public frc::Command {
public:
	TankDrive();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
};

