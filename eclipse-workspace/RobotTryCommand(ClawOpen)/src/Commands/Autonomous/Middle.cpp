#include "Middle.h"
#include "../../Robot.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>
#include "../DriveStraight.h"
#include "../ClawToggle.h"
#include "../ClawOpen.h"
#include "../MoveArm.h"
#include "../Turn.h"

Middle::Middle() {
	Robot::gyro.Reset();
	if (Robot::switchside=="R"){
		frc::SmartDashboard::PutString("AutoChosen","Middle Right Switch");
		AddSequential(new MoveArm(1.9,.6,true)); //1.9
		AddSequential(new DriveStraight(1.6,.8,true)); //1.6
		AddSequential(new ClawOpen());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawOpen());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawOpen());

	}
	else{
		frc::SmartDashboard::PutString("AutoChosen","Middle Left Switch");
		AddSequential(new DriveStraight(.8,.8,true)); //.8
		AddSequential(new Turn(-90));
		AddSequential(new DriveStraight(1.8,.8,true)); //1.8
		AddSequential(new Turn(90));
		AddSequential(new MoveArm(1.9,.6,true)); //1.9
		AddSequential(new DriveStraight(.9,.8,true)); //.9
		AddSequential(new ClawOpen());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawOpen());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawOpen());
	}
}
