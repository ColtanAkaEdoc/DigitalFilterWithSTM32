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

## Observations:

The knot in my head currently revolves around the ring-buffer, effectively acting as the better ring buffer than the actual one.

`joke break;`

The following code gives more insight into the timings of the STM32 by connecting probes to the DAC and a GPIO-pin:

```c
while(1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		dsp();
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	}
```

`dsp()` only acts as buffer swapper without any filterings as of now. Here the filtering would take place. This section is effectively entered as soon as a global flag `cplt` is set to one, indicating that half of a ADC-buffer is full and ready to be read.

![observation1](20211020_114540.jpg)

Here the toggle of the above stated function can be seen. It means that the dsp is not active, since the function exits on the `cplt == false` condition.

![observation2](20211020_114548.jpg)

*closeup*

![observation3](20211020_114630.jpg)

At some point (after half a buffer size) the dsp becomes active and the other buffer is sent out. Here a jump happens. The logic behind the implemented ringbuffer might be questionable. In theory, the dsp should work all of the time as well as the buffers without jumps.

![observation4](20211020_123105.jpg)

The start of a conversion appears to be very strange. Apparently the flag within `dsp()` gets set for a short time and then the out-pointer points to a new set of samples. It can be speculated that the interval of the switch is the time it takes for all values to be copied. That would be a good sign, since it's a lot faster than the output of a buffer. The absence of triggers after the switch is due to a programming error. 
>20.10.21