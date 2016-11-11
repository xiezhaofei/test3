#ifndef _FRAME_OPERATIONS_H_
#define _FRAME_OPERATIONS_H_

void xmly_Recordor_NS_InFrmUdp(volatile float *fft_array1,volatile float *fft_array2,short *raw_pcm,short *currpos);
void xmly_Recordor_NS_OvlpAdd(float *fft_array1,float *fft_array2,volatile float *flp_pcm,volatile float *last_half_frm);

#endif