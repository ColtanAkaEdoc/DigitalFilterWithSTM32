#ifndef _COEFFICIENTS_H_
#define _COEFFICIENTS_H_

// info:
// number of bands: 31
// contains coeffs for 31 sets of 3-section biquad 1/3rd octave filters
float iir_31[] = {
    // fs = 48000, fl = 18245.6057, fu = 22988.0227
    1,    0,    -1,    1.2094,    0.60865,
    1,    0,    -1,    1.8842,    0.90263,
    1,    0,    -1,    1.4369,    0.51428,
};
float iir_30[] = {
    // fs = 48000, fl = 14481.5469, fu = 18245.6057
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_29[] = {
    // fs = 48000, fl = 11494.0114, fu = 14481.5469
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_28[] = {
    // fs = 48000, fl = 9122.8029, fu = 11494.0114
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_27[] = {
    // fs = 24000, fl = 7240.7734, fu = 9122.8029
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_26[] = {
    // fs = 24000, fl = 5747.0057, fu = 7240.7734
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_25[] = {
    // fs = 24000, fl = 4561.4014, fu = 5747.0057
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_24[] = {
    // fs = 12000, fl = 3620.3867, fu = 4561.4014
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_23[] = {
    // fs = 12000, fl = 2873.5028, fu = 3620.3867
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_22[] = {
    // fs = 12000, fl = 2280.7007, fu = 2873.5028
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_21[] = {
    // fs = 6000, fl = 1810.1934, fu = 2280.7007
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_20[] = {
    // fs = 6000, fl = 1436.7514, fu = 1810.1934
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_19[] = {
    // fs = 6000, fl = 1140.3504, fu = 1436.7514
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_18[] = {
    // fs = 3000, fl = 905.0967, fu = 1140.3504
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_17[] = {
    // fs = 3000, fl = 718.3757, fu = 905.0967
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_16[] = {
    // fs = 3000, fl = 570.1752, fu = 718.3757
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_15[] = {
    // fs = 1500, fl = 452.5483, fu = 570.1752
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_14[] = {
    // fs = 1500, fl = 359.1879, fu = 452.5483
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_13[] = {
    // fs = 1500, fl = 285.0876, fu = 359.1879
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_12[] = {
    // fs = 750, fl = 226.2742, fu = 285.0876
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_11[] = {
    // fs = 750, fl = 179.5939, fu = 226.2742
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_10[] = {
    // fs = 750, fl = 142.5438, fu = 179.5939
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_9[] = {
    // fs = 375, fl = 113.1371, fu = 142.5438
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_8[] = {
    // fs = 375, fl = 89.797, fu = 113.1371
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_7[] = {
    // fs = 375, fl = 71.2719, fu = 89.797
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_6[] = {
    // fs = 187.5, fl = 56.5685, fu = 71.2719
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_5[] = {
    // fs = 187.5, fl = 44.8985, fu = 56.5685
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_4[] = {
    // fs = 187.5, fl = 35.6359, fu = 44.8985
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
float iir_3[] = {
    // fs = 93.75, fl = 28.2843, fu = 35.6359
    1,    0,    -1,    1.2913,    0.81359,
    1,    0,    -1,    0.61801,    0.75893,
    1,    0,    -1,    0.8909,    0.59813,
};
float iir_2[] = {
    // fs = 93.75, fl = 22.4492, fu = 28.2843
    1,    0,    -1,    0.54128,    0.82814,
    1,    0,    -1,    -0.074253,    0.82093,
    1,    0,    -1,    0.21943,    0.66936,
};
float iir_1[] = {
    // fs = 93.75, fl = 17.818, fu = 22.4492
    1,    0,    -1,    -0.65082,    0.86142,
    1,    0,    -1,    -0.16103,    0.85328,
    1,    0,    -1,    -0.38444,    0.72943,
};
#endif // coefficients.h