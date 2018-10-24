#pragma once

#include <Commands/Command.h>

class TankDrive : public frc::Command {
public:
	TankDrive(bool inacceleration);
	void Execute() override;
	bool IsFinished() override;
	void End() override;
private:
	bool acceleration;
};

