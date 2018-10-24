################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Autonomous.cpp \
../src/Commands/ClawToggle.cpp \
../src/Commands/DriveStraight.cpp \
../src/Commands/JoyArm.cpp \
../src/Commands/MoveArm.cpp \
../src/Commands/TankDrive.cpp \
../src/Commands/Turn.cpp 

OBJS += \
./src/Commands/Autonomous.o \
./src/Commands/ClawToggle.o \
./src/Commands/DriveStraight.o \
./src/Commands/JoyArm.o \
./src/Commands/MoveArm.o \
./src/Commands/TankDrive.o \
./src/Commands/Turn.o 

CPP_DEPS += \
./src/Commands/Autonomous.d \
./src/Commands/ClawToggle.d \
./src/Commands/DriveStraight.d \
./src/Commands/JoyArm.d \
./src/Commands/MoveArm.d \
./src/Commands/TankDrive.d \
./src/Commands/Turn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\robot\eclipse-workspace\RobotTryCommand(6-6-2018)\RobotTryCommand/src" -IC:\Users\robot/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -Og -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


