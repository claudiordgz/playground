################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LoadShaders.cpp \
../src/main.cpp \
../src/opengl_methods.cpp 

OBJS += \
./src/LoadShaders.o \
./src/main.o \
./src/opengl_methods.o 

CPP_DEPS += \
./src/LoadShaders.d \
./src/main.d \
./src/opengl_methods.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/claudiordgz/workspace/oglpg-8th-edition/include" -I"/home/claudiordgz/workspace/playground/OpenGL/Nightmare/include" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


