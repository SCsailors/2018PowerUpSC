#include "Right.h"
#include "../../Robot.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>
#include "../DriveStraight.h"
#include "../ClawToggle.h"
#include "../MoveArm.h"
#include "../Turn.h"
#include <iostream>

Right::Right(bool scale, bool prioswitch) {
	Robot::gyro.Reset();
	if (Robot::scaleside=="R" && scale && (!prioswitch || (prioswitch && Robot::switchside!="R" ))){
		frc::SmartDashboard::PutString("AutoChosen","Right Scale");
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("First",0),.8,true));
		AddParallel(new MoveArm(frc::SmartDashboard::GetNumber("Second",0),.8,true));
		AddSequential(new Turn(-45));
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("Third",0),.8,true));
		AddSequential(new ClawToggle());
		AddSequential( new DriveStraight(frc::SmartDashboard::GetNumber("Fourth",0),0,true));
		AddSequential(new DriveStraight(frc::SmartDashboard::GetNumber("Fifth",0),-.8,true));

	}
	else if (Robot::switchside=="R"){
		frc::SmartDashboard::PutString("AutoChosen","Right Switch");
		AddSequential(new DriveStraight(2,.8,true));
		AddParallel(new MoveArm(.5,.8,true));
		AddSequential(new Turn(-90));
		AddSequential(new DriveStraight(.5,.8,true));
		AddSequential(new ClawToggle());
	}
	else{
		frc::SmartDashboard::PutString("AutoChosen","Right Default");
		AddSequential(new DriveStraight(2,.8,true));

	}
}
