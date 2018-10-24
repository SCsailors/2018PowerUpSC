################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/Arm.cpp \
../src/Subsystems/Claw.cpp \
../src/Subsystems/DriveTrain.cpp \
../src/Subsystems/Gyro.cpp 

OBJS += \
./src/Subsystems/Arm.o \
./src/Subsystems/Claw.o \
./src/Subsystems/DriveTrain.o \
./src/Subsystems/Gyro.o 

CPP_DEPS += \
./src/Subsystems/Arm.d \
./src/Subsystems/Claw.d \
./src/Subsystems/DriveTrain.d \
./src/Subsystems/Gyro.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\robot\eclipse-workspace\RobotTryCommand(6-6-2018)\RobotTryCommand/src" -IC:\Users\robot/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -Og -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


