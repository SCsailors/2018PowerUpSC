#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <Spark.h>
#include <Timer.h>
#include <DriverStation.h>
#include <DoubleSolenoid.h>
#include <SmartDashBoard/SmartDashBoard.h>

class Robot : public frc::IterativeRobot {
public:
	Robot() {
		m_robotDrive.SetExpiration(0.1);
		m_timer.Start();
		m_left.SetInverted(true);
		m_right.SetInverted(true);
	}

	void AutonomousInit() override {
		m_timer.Reset();
		m_timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 1 seconds
		if (m_timer.Get() < 1.0) {
			// Drive forwards half speed
			m_robotDrive.ArcadeDrive(-0.5, 0.0);
		} else {
			// Stop robot
			m_robotDrive.ArcadeDrive(0.0, 0.0);
		}
	}

	void TeleopInit() override {}

	void TeleopPeriodic() override {
		m_robotDrive.TankDrive(left.GetY(),right.GetY());
		SmartDashboard::PutNumber("LeftDrive",left.GetY());
		SmartDashboard::PutNumber("RightDrive",right.GetY());

		m_arm.Set(gamepad.GetY()*.8);                                                                  //CHANGE
		SmartDashboard::PutNumber("Arm",gamepad.GetY()*.8);

		if (gamepad.GetRawButton(2)==true && clawClosed==false  && ppressed==false){																//CHANGE (41 & 45 & 50)
			claw.Set(frc::DoubleSolenoid::Value::kForward);
			clawClosed=true;
		}
		else if(gamepad.GetRawButton(2)==true && clawClosed==true && ppressed==false){													//Might have to change true and false (41 & 45)
			claw.Set(frc::DoubleSolenoid::Value::kReverse);
			clawClosed=false;
		}
		ppressed=gamepad.GetRawButton(2);
		SmartDashboard::PutBoolean("ClawClosed",clawClosed);
		SmartDashboard::PutBoolean("ppressed",ppressed);
		SmartDashboard::PutBoolean("A",gamepad.GetRawButton(1));

	}

	void TestPeriodic() override {}

private:
	// Robot drive system
	frc::Spark m_left{1};                                                                           //CHANGE
	frc::Spark m_right{0};        																	//CHANGE
	frc::Spark m_arm{2};  																			//CHANGE
	frc::DifferentialDrive m_robotDrive{m_left, m_right};
	frc::DoubleSolenoid claw {0, 1};																//CHANGE


	frc::Joystick left{1};																	    	//CHECK
	frc::Joystick right{0};																			//CHECK
	frc::Joystick gamepad{2};																		//CHECK
	frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
	frc::Timer m_timer;

	bool clawClosed=false;
	bool ppressed=false;
};

START_ROBOT_CLASS(Robot)
