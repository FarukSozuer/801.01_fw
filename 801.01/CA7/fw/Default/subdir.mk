################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON.c \
../fzd_cpu_info.c \
../fzd_gpio.c \
../fzd_rflink.c \
../fzd_serial_com.c \
../fzd_spi.c \
../fzd_stpmic1.c \
../fzd_timing.c \
../fzd_uart.c \
../main.c 

C_DEPS += \
./cJSON.d \
./fzd_cpu_info.d \
./fzd_gpio.d \
./fzd_rflink.d \
./fzd_serial_com.d \
./fzd_spi.d \
./fzd_stpmic1.d \
./fzd_timing.d \
./fzd_uart.d \
./main.d 

OBJS += \
./cJSON.o \
./fzd_cpu_info.o \
./fzd_gpio.o \
./fzd_rflink.o \
./fzd_serial_com.o \
./fzd_spi.o \
./fzd_stpmic1.o \
./fzd_timing.o \
./fzd_uart.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MPU GCC Compiler'
	$(CC) "$<" -std=gnu11 -g3 -c -Ipthread -Ilibgpiod -Im -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./cJSON.d ./cJSON.o ./fzd_cpu_info.d ./fzd_cpu_info.o ./fzd_gpio.d ./fzd_gpio.o ./fzd_rflink.d ./fzd_rflink.o ./fzd_serial_com.d ./fzd_serial_com.o ./fzd_spi.d ./fzd_spi.o ./fzd_stpmic1.d ./fzd_stpmic1.o ./fzd_timing.d ./fzd_timing.o ./fzd_uart.d ./fzd_uart.o ./main.d ./main.o

.PHONY: clean--2e-

