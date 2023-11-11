# FanControl_AVR32
#### The aim of this project is to design a temperature-controlled fan using ATmega32 microcontroller, in which the fan is automatically turned ON or OFF according to the temperature.

![](https://github.com/OmarMahmoudSalah/FanControl_AVR32/blob/main/Screens/Screen.jpg?raw=true)

The Project is  implemented based on the layered architecture model as follow
![](https://github.com/OmarMahmoudSalah/FanControl_AVR32/blob/main/Screens/LAM.jpg?raw=true)

------------



The microcontroller will continuously monitor the temperature and based on the
temperature value, the microcontroller will drive the fan like that:
-  If the temperature is less than 30C turn off the fan.
-  If the temperature is greater than or equal 30C turn on the fan with 25% of its
- maximum speed.
-  If the temperature is greater than or equal 60C turn on the fan with 50% of its
- maximum speed.
-  If the temperature is greater than or equal 90C turn on the fan with 75% of its
- maximum speed.

![](https://github.com/OmarMahmoudSalah/FanControl_AVR32/blob/main/Screens/Screen2.jpg?raw=true)



# Project Covers
- Shifting and bit masking
- Drivers Dynamic Configuration
- Pre Processor Directives
- Interrupts
- Timer (PWM)
- GPIO
- ADC
- LCD


