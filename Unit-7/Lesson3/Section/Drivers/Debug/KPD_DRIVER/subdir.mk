################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KPD_DRIVER/keypad.c 

OBJS += \
./KPD_DRIVER/keypad.o 

C_DEPS += \
./KPD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
KPD_DRIVER/keypad.o: ../KPD_DRIVER/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master_Embedded_Diploma/1-Important/Unit-7/Sections/Videos/Drivers/Stm32_F103C6_Drivers/Includes" -I"D:/Master_Embedded_Diploma/1-Important/Unit-7/Sections/Videos/Drivers/KPD_DRIVER" -I"D:/Master_Embedded_Diploma/1-Important/Unit-7/Sections/Videos/Drivers/LCD_DRIVER" -I"D:/Master_Embedded_Diploma/1-Important/Unit-7/Sections/Videos/Drivers/Stm32_F103C6_Drivers/Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"KPD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
