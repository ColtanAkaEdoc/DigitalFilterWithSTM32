# Jakob's implementation of the IIR-filter on NUCLEO L476RG

In addition to getting this to run, this folder also expands on the idea of filters and tries to create rolling filters which then return a 30 bin spectrum for later noise classification with neural networks.

## Important:
> calculate the right timer-trigger for a lossless conversion!

### Formula:

```
    (1/ADC_CLK * CONV_CYCLES) / (1/TIM_CLK)
```

## Further notes:
This [video](https://www.youtube.com/watch?v=ThFfI-JSv2Y) explains a basic workflow (also implemented by Julius). HOWEVER, the loss of data even occurs in this video but is not adressed. Qustion still stands.

### Comments on the issue:

>"The explanation is excellent, thank you very much! I have a question, for the processing function, shouldn't you have a flag to stop processing until the other half is ready? Otherwise you process over and over the same buffer until the pointers are swapped. Perhaps after the processing function ends the core could be put to sleep until the next interrupt to save some energy. Just a thought, great tutorial."
 ~ user Federico Coppede

>"I was thinking the same. A flag may be set by the ADC-DMA callbacks and reset by the processing function, which is entered only if such flag is true. In this way, the MCU avoids looping on the same slice of buffer more than once. I suspect the almost invisible glitches and spikes that one can observe from the DAC capture are caused by the missing "synchronization" mechanism."
 ~ user Giovanni Scotti

>"why did you put the signal processing function into the main loop without any if statement? Wouldn't it mean that it could be executed multiple times per cycle? How do you know it will be executed just once?"
 ~ user babotvoj
