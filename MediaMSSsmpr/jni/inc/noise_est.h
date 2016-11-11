#ifndef _NOISE_ESTIMATION_H_
#define _NOISE_ESTIMATION_H_

typedef struct _nosie_estimation
{
	float ad;
	float ap;
	float beta;
	float gamma;
	float alpha;
	float *pk;
	float *delta;
	float *noise_ps;
	float *pxk;
	float *pnk;
	float *pxk_old;
	float *pnk_old;
	float *sig_prev;
	float *gain;
	float log_eng;
	float vad_floor;
	float eta;
	float eng_judge;
}Noise_Est;

short MCRA2_Noise_Init(Noise_Est * noise_est_inst);
void MCRA2_Noise_Estimation(Noise_Est * noise_est_inst,float *ns_ps);

#endif