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
		AddSequential(new DriveStraight(1.8,.8,true)); //1.8
		AddParallel(new MoveArm(1.6,.8,true));  //1.8
		AddSequential(new DriveStraight(1.1,.8,true)); //1.1
		AddSequential(new Turn(-25));
		AddSequential(new DriveStraight(.9,.8,true));  //.9
		AddSequential(new ClawToggle());
		AddSequential(new DriveStraight(1.5,0,true));  //1.5
		AddSequential(new DriveStraight(.8,-.8,true));


	}
	else if (Robot::switchside=="R"){
		frc::SmartDashboard::PutString("AutoChosen","Right Switch");
		AddSequential(new DriveStraight(2.0,.7,true));  //2.0
		AddParallel(new MoveArm(1.4,.6,true));  //1.4
		AddSequential(new DriveStraight(1.0,.7,true)); //1.0
		AddSequential(new Turn(-80));
		AddSequential(new DriveStraight(.7,.8,true));  //.7
		AddSequential(new ClawToggle());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawToggle());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawToggle());
	}
	else{
		frc::SmartDashboard::PutString("AutoChosen","Right Default");
		AddSequential(new DriveStraight(2,.8,true));

	}
}
