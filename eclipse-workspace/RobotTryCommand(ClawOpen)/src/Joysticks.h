#pragma once

#include <Joystick.h>
#include <Buttons/JoystickButton.h>

class Joysticks{
public:
	Joysticks();
	frc::Joystick& GetLeft();
	frc::Joystick& GetRight();
	frc::Joystick& GetGamepad();

private:
	frc::Joystick left{1};																	    	//CHECK
	frc::Joystick right{0};
	frc::Joystick gamepad{2};

	frc::JoystickButton a{&gamepad,2};
	frc::JoystickButton b{&gamepad,3};
	frc::JoystickButton in_a{&gamepad,7};
	frc::JoystickButton in_b{&gamepad,8};
	frc::JoystickButton out_a{&gamepad,5};
	frc::JoystickButton out_b{&gamepad,6};
};

