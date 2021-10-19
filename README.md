# DigitalFilterWithSTM32
2021-10-10
Attempt to get a digital filter (HP 25kHz, TP 250kHz) up and running with an STM32L476G-DISCO

Theory/Guide:

https://www.youtube.com/watch?v=QRMe02kzVkA - IIR Filters - Theory and Implementation (STM32) - Phil's Lab

https://micromodeler.com/dsp/ - Online Filter Generator

https://deepbluembedded.com/stm32-dac-tutorial-example-hal-code-analog-signal-genreation/ - DAC (with triggers) tutorial

Order of operation:
1. Get the ADC up and running with the Board HAL and the HAL documentation
2. Get the DAC up and ...
3. Copy a filter with code from the internet and check its behaviour with a spectrum analyzer

Estimated Filter-"Power"
![IMG_5075](https://user-images.githubusercontent.com/62153964/137503139-60a9f56b-82b1-4710-ada8-158d6b80bb3d.jpg)

Samling Rate [Msps - Mega samples per secound)
5.44 Msps @ 12 Bits (S.177 https://github.com/ColtanAkaEdoc/DigitalFilterWithSTM32/blob/main/Documents/Datasheet_Chip-stm32l476vg.pdf)

ENOB - Effective nuber of bits - https://www.itwissen.info/ENOB-effective-number-of-bits.html
STM32LF76xx -> 10.4 Bits (S.181 https://github.com/ColtanAkaEdoc/DigitalFilterWithSTM32/blob/main/Documents/Datasheet_Chip-stm32l476vg.pdf)

Anti-Alias Filter - Dependent on sample rate (f_s) and ENOB
Required attenuation reffered to gain within pass range at f_s: 6dB x ENOB
