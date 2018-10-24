#include "Left.h"
#include "../../Robot.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include <DriverStation.h>
#include "../DriveStraight.h"
#include "../ClawToggle.h"
#include "../MoveArm.h"
#include "../Turn.h"

Left::Left(bool scale, bool prioswitch) {
	Robot::gyro.Reset();
	if (Robot::scaleside=="L" && scale && (!prioswitch || (prioswitch && Robot::switchside!="L" ))){
		frc::SmartDashboard::PutString("AutoChosen","Left Scale");
		AddSequential(new DriveStraight(2.1,.8,true)); //2.1 done
		AddParallel(new MoveArm(1.6,.8,true));  //1.6
		AddSequential(new DriveStraight(1.1,.8,true)); //1.1
		AddSequential(new Turn(15));
		AddSequential(new DriveStraight(.8,.8,true));  //.8
		AddSequential(new ClawToggle());
		AddSequential(new DriveStraight(1.5,0,true));  //1.5
		AddSequential(new DriveStraight(.8,-.8,true));

	}
	else if (Robot::switchside=="L"){
		frc::SmartDashboard::PutString("AutoChosen","Left Switch");
		AddSequential(new DriveStraight(2.0,.7,true));  //2.0 //done
		AddParallel(new MoveArm(1.3,.6,true));  //1.3
		AddSequential(new DriveStraight(1.0,.7,true)); //1.0
		AddSequential(new Turn(80));
		AddSequential(new DriveStraight(.7,.8,true));  //.7
		AddSequential(new ClawToggle());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawToggle());
		AddSequential(new DriveStraight(.5,0,true));
		AddSequential(new ClawToggle());
	}
	else{
		frc::SmartDashboard::PutString("AutoChosen","Left Default");
		AddSequential(new DriveStraight(2,.8,true));

	}
}
