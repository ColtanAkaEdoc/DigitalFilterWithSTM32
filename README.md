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
