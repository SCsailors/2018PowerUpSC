#include "Middle.h"
#include "../../Robot.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>
#include "../DriveStraight.h"
#include "../ClawToggle.h"
#include "../MoveArm.h"
#include "../Turn.h"

Middle::Middle() {
	Robot::gyro.Reset();
	if (Robot::switchside=="R"){
		frc::SmartDashboard::PutString("AutoChosen","Middle Right Switch");
		AddSequential(new MoveArm(frc::SmartDashboard::GetNumber("First",0),.8,true));
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("Second",0),.8,true));
		AddSequential(new ClawToggle());
	}
	else{
		frc::SmartDashboard::PutString("AutoChosen","Middle Left Switch");
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("First",0),.8,true));
		AddSequential(new Turn(-90));
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("Second",0),.8,true));
		AddSequential(new Turn(90));
		AddSequential(new MoveArm(frc::SmartDashboard::GetNumber("Third",0),.8,true));
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("Fourth",0),.8,true));
		AddSequential(new ClawToggle());
	}
}
