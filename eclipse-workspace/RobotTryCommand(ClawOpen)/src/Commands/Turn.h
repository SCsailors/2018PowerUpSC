#pragma once

#include <Commands/Command.h>

class Turn : public frc::Command {
public:
	Turn(double inchange);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double change;
	double initial=0;
};

