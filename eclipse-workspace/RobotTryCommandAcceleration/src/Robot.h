#pragma once

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>
#include <SmartDashboard/SendableChooser.h>

#include "Subsystems/Gyro.h"
#include "Subsystems/Arm.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Claw.h"
#include "Subsystems/Winch.h"
#include "Joysticks.h"


class Robot : public frc::IterativeRobot {
public:
	static MyClaw claw;
	static DriveTrain drivetrain;
	static Joysticks joysticks;
	static Arm arm;
	static MyGyro gyro;
	static Winch winch;
	static std::string switchside;
	static std::string scaleside;

private:
	frc::Command* autonomous;
	frc::SendableChooser<int> autochoice;
	frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
	std::string gamedata;

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};
