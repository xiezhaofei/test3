#ifndef _BUFFER_MANAGEMENT_H_
#define _BUFFER_MANAGEMENT_H_

#include "tools/fft_config.h"
#include "inc/macro.h"

//typedef struct _SpEnh_Scratch
//{
//	FFT_Config		*cfg;
//	float			fft_array1[FFT_LEN];//should be 1024
//	float			fft_array2[FFT_LEN];//1024
//	float			flp_pcm[FFT_LEN];//1024
//	float			last_half_frm[FFT_LEN>>1];//512
//	short			raw_pcm[FFT_LEN<<1];//512
//	short			out_pcm[FFT_LEN];//1024
//	float			ns_ps1[Actual_Len];//513
//	float			ns_ps2[Actual_Len];//513
//	float			sig_mag1[Actual_Len];//513
//	float			sig_mag2[Actual_Len];//513
//	int             pts_left;
//	short           offset;
//	short			first_frame;
//	short           currpos;
//}SpEnh_Scratch;

typedef struct _SpEnh_Scratch
{
	FFT_Config		*cfg;
	float			*fft_array1;//should be 1024
	float			*fft_array2;//1024
	float			*flp_pcm;//1024
	float			*last_half_frm;//512
	short			*raw_pcm;//512
	short			*out_pcm;//1024
	float			*ns_ps1;//513
	float			*ns_ps2;//513
	float			*sig_mag1;//513
	float			*sig_mag2;//513
	float			gainThres;//minimum gain threshold for each frame bin
	short           bandwidth;//1-512,BW  = fs/2/512*bandwidth, for 1024 points' FFT
	int             pts_left;
	short           offset;
	short			first_frame;
	short           currpos;

}SpEnh_Scratch;

#endif
