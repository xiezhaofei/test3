#ifndef _NOISE_REDUCTION_PROCESS_H_
#define _NOISE_REDUCTION_PROCESS_H_

short SpEnh_Buf_Alloc(SpEnh_Scratch** spEnh_buf,Noise_Est **noise_est_inst);
short xmly_monoNS_SetGainThreshold(SpEnh_Scratch *spEnh_Inst, float val);
short xmly_monoNS_SetBandwidth(SpEnh_Scratch *spEnh_Inst, short val);
int xmly_monoNS_Process(SpEnh_Scratch* spEnh_buf,Noise_Est *noise_est_inst,
						void *src_addr,unsigned int src_len,void *dst_addr,short ns_status);
void xmly_monoNS_Delete(SpEnh_Scratch* spEnh_buf,Noise_Est *noise_est_inst);

#endif
