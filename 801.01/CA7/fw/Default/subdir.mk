################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cJSON.c \
../fzd_stpmic1.c \
../main.c \
../zed_cpu_info.c \
../zed_gpio.c \
../zed_rflink.c \
../zed_serial_com.c \
../zed_spi.c \
../zed_timing.c \
../zed_uart.c \
../zed_uio.c 

C_DEPS += \
./cJSON.d \
./fzd_stpmic1.d \
./main.d \
./zed_cpu_info.d \
./zed_gpio.d \
./zed_rflink.d \
./zed_serial_com.d \
./zed_spi.d \
./zed_timing.d \
./zed_uart.d \
./zed_uio.d 

OBJS += \
./cJSON.o \
./fzd_stpmic1.o \
./main.o \
./zed_cpu_info.o \
./zed_gpio.o \
./zed_rflink.o \
./zed_serial_com.o \
./zed_spi.o \
./zed_timing.o \
./zed_uart.o \
./zed_uio.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MPU GCC Compiler'
	$(CC) "$<" -std=gnu11 -g3 -c -Ipthread -Ilibgpiod -Im -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./cJSON.d ./cJSON.o ./fzd_stpmic1.d ./fzd_stpmic1.o ./main.d ./main.o ./zed_cpu_info.d ./zed_cpu_info.o ./zed_gpio.d ./zed_gpio.o ./zed_rflink.d ./zed_rflink.o ./zed_serial_com.d ./zed_serial_com.o ./zed_spi.d ./zed_spi.o ./zed_timing.d ./zed_timing.o ./zed_uart.d ./zed_uart.o ./zed_uio.d ./zed_uio.o

.PHONY: clean--2e-

