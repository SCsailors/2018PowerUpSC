#include "Default.h"
#include <SmartDashBoard/SmartDashBoard.h>
#include "../DriveStraight.h"

Default::Default() {
	frc::SmartDashboard::PutString("AutoChosen","Default");
	AddSequential(new DriveStraight(2,.8,true));
}
