################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/svc_ctrl.c \
../src/svc_glob.c \
../src/svc_inst.c \
../src/svc_main.c \
../src/svc_start.c \
../src/svc_stop.c \
../src/svc_thrd.c \
../src/svc_uninst.c 

OBJS += \
./src/main.o \
./src/svc_ctrl.o \
./src/svc_glob.o \
./src/svc_inst.o \
./src/svc_main.o \
./src/svc_start.o \
./src/svc_stop.o \
./src/svc_thrd.o \
./src/svc_uninst.o 

C_DEPS += \
./src/main.d \
./src/svc_ctrl.d \
./src/svc_glob.d \
./src/svc_inst.d \
./src/svc_main.d \
./src/svc_start.d \
./src/svc_stop.d \
./src/svc_thrd.d \
./src/svc_uninst.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	i686-w64-mingw32-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


