#ifndef _COEFF_H_
#define _COEFF_H_

#define N_IIR_FILTERS		30	// 30 1/3s octaves
#define N_BIQ				3 	// adds up to filters of order 2*3=6
#define N_COEFF_PER_BIQ		5	// ---> ask thomas for order
#define N_FIR_DECIMATORS	10	// 1 decimation every octave
#define N_COEFF_PER_FIR		5	// ---> ask thomas for order

/* 30 groups of 3 biquad-sets of 5 coefficients each
 *
 *
*/
float iir_coeff[N_IIR_FILTERS][N_COEFF_PER_BIQ] = {

};

/* 10 groups of FIR-decimators for more performance and anti-aliasing
 *
 * @[9] -> fs = 48kHz, 	fc = 20kHz, 	no filter? (check back with thomas)
 * @[8] -> fs = 24kHz, 	fc = 10kHz, 	TP
 * @[7] -> fs = 12kHz, 	fc = 5kHz, 		TP
 * @[6] -> fs = 6kHz, 	fc = 2.5kHz, 	TP
 * @[5] -> fs = 3kHz, 	fc = 1.25kHz, 	TP
 * @[4] -> fs = 1.5kHz, fc = 625Hz, 	TP
 * @[3] -> fs = 750Hz, 	fc = 312Hz, 	TP
 * @[2] -> fs = 375Hz, 	fc = 156Hz, 	TP
 * @[1] -> fs = 187Hz, 	fc = 78Hz, 		TP
 * @[0] -> fs = 93Hz, 	fc = 39Hz, 		TP
*/
float fir_decimator_coeff[N_FIR_DECIMATORS][N_COEFF_PER_FIR] = {

};


#endif
