//#include "WinchEncoder.h"
//
//WinchEncoder::WinchEncoder() : Subsystem("WinchEncoder") {
//	winchencoder.SetMaxPeriod(frc::SmartDashboard::GetNumber("MaxPeriod",.1));
//	winchencoder.SetMinRate(frc::SmartDashboard::GetNumber("MinRate",10));
//	winchencoder.SetDistancePerPulse(frc::SmartDashboard::GetNumber("DistancePerPulse",5));
//	winchencoder.SetSamplesToAverage(frc::SmartDashboard::GetNumber("SamplesPerAverage",7));
//}
//
//void WinchEncoder::InitDefaultCommand() {}
//
//double WinchEncoder::GetDistance(){
//	double distance=winchencoder.GetDistance();
//	frc::SmartDashboard::PutNumber("WinchEncoder",distance);
//	return distance;
//}
