#ifndef _MACRO_H_
#define _MACRO_H_

#define INV_MAX_15BIT 1.0f/32767.0f
#define MAX_15BIT 32767.0f

#define flp_INV_FFT_LEN 2.0f/1024.0f
#define ADD_WIN_START_OFFSET 512
#define FFT_LEN 1024

#define Actual_Len ((FFT_LEN>>1)+1)
#define INV_Actual_Len 1.0f/Actual_Len

#define THETA 3.162f

#define MAX_SNR 1000.0f
#define MIN_SNR_APRIORI 0.0025f

#define Precision_N 11

#define MIN_FLT 1.175494e-30F
#define MAX_FLT 3.402823466e+38F

#define max(a,b) ((a)>=(b) ? (a):(b))
#define min(a,b) ((a)<=(b) ? (a):(b))

#endif