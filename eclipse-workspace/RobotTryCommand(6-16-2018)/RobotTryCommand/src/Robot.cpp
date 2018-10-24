#include "Robot.h"
#include <CameraServer.h>
#include <Commands/Autonomous/Left.h>
#include <Commands/Autonomous/Right.h>
#include <Commands/Autonomous/Middle.h>
#include <Commands/Autonomous/Default.h>
#include <iostream>

MyClaw Robot::claw;
DriveTrain Robot::drivetrain;
Joysticks Robot::joysticks;
Arm Robot::arm;
MyGyro Robot::gyro;
Winch Robot::winch;
//WinchEncoder Robot::winchencoder;
std::string Robot::switchside;
std::string Robot::scaleside;

void Robot::RobotInit() {
	CameraServer::GetInstance()->StartAutomaticCapture();
	autochoice.AddObject("Left, Priority Scale", 1);
	autochoice.AddObject("Left, Priority Switch", 2);
	autochoice.AddObject("Left, No Scale", 3);
	autochoice.AddObject("Middle, Switch", 4);
	autochoice.AddObject("Right, Priority Scale",5);
	autochoice.AddObject("Right, Priority Switch", 6);
	autochoice.AddObject("Right, No Scale", 7);
	autochoice.AddDefault("Just Drive Forward", 8);
	frc::SmartDashboard::PutData("Which Autonomous?",&autochoice);
	frc::SmartDashboard::PutNumber("First",0);
	frc::SmartDashboard::PutNumber("Second",0);
	frc::SmartDashboard::PutNumber("Third",0);
	frc::SmartDashboard::PutNumber("Fourth",0);
	frc::SmartDashboard::PutNumber("Fifth",0);

}

void Robot::AutonomousInit(){
	gamedata=frc::DriverStation::GetInstance().GetGameSpecificMessage();
	frc::SmartDashboard::PutString("GameData",gamedata);
	switchside=gamedata[0];
	scaleside=gamedata[1];
	frc::SmartDashboard::PutBoolean(" ",(switchside=="R" && DriverStation::Alliance::kRed==(DriverStation::GetInstance().GetAlliance())) ||(switchside=="L" && DriverStation::Alliance::kBlue==(DriverStation::GetInstance().GetAlliance())));
	frc::SmartDashboard::PutBoolean("======-======",(switchside=="L" && DriverStation::Alliance::kRed==(DriverStation::GetInstance().GetAlliance())) ||(switchside=="R" && DriverStation::Alliance::kBlue==(DriverStation::GetInstance().GetAlliance())));
	frc::SmartDashboard::PutBoolean("   ",(scaleside=="R" && DriverStation::Alliance::kRed==(DriverStation::GetInstance().GetAlliance())) ||(scaleside=="L" && DriverStation::Alliance::kBlue==(DriverStation::GetInstance().GetAlliance())));
	frc::SmartDashboard::PutBoolean("=====-=======",(scaleside=="L" && DriverStation::Alliance::kRed==(DriverStation::GetInstance().GetAlliance())) ||(scaleside=="R" && DriverStation::Alliance::kBlue==(DriverStation::GetInstance().GetAlliance())));
	frc::SmartDashboard::PutBoolean("      ",(switchside=="R" && DriverStation::Alliance::kRed==(DriverStation::GetInstance().GetAlliance())) ||(switchside=="L" && DriverStation::Alliance::kBlue==(DriverStation::GetInstance().GetAlliance())));
	frc::SmartDashboard::PutBoolean("=======-=====",(switchside=="L" && DriverStation::Alliance::kRed==(DriverStation::GetInstance().GetAlliance())) ||(switchside=="R" && DriverStation::Alliance::kBlue==(DriverStation::GetInstance().GetAlliance())));

	int which=autochoice.GetSelected();
	if (which==1){
		autonomous=new Left(true,false);
	}
	else if (which==2){
		autonomous=new Left(true,true);
	}
	else if (which==3){
		autonomous=new Left(false,true);
	}
	else if (which==4){
		autonomous=new Middle();
	}
	else if (which==5){
		autonomous= new Right(true,false);
	}
	else if (which==6){
		autonomous=new Right(true,true);
	}
	else if (which==7){
		autonomous=new Right(false,true);
	}
	else if (which==8){
		autonomous=new Default();
	}
	else{
		autonomous=new Default();
	}

	if (autonomous!=NULL){
		autonomous->Start();
	}
	else{
		autonomous=new Default();
		autonomous->Start();
	}
}

void Robot::AutonomousPeriodic(){
	frc::Scheduler::GetInstance()->Run();
	frc::SmartDashboard::PutNumber("Time Remaining",DriverStation::GetInstance().GetMatchTime());
}

void Robot::TeleopInit(){
	if (autonomous!=NULL){
		autonomous->Cancel();
	}

}

void Robot::TeleopPeriodic(){
	frc::Scheduler::GetInstance()->Run();
	frc::SmartDashboard::PutNumber("Time Remaining",DriverStation::GetInstance().GetMatchTime());
}

void Robot::TestPeriodic(){}


START_ROBOT_CLASS(Robot)
