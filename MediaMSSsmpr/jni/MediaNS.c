#include "com_ximalaya_mediamsssmpr_MediaNS.h"
#include "inc/buf_management.h"
#include "inc/noise_est.h"
#include "inc/ns_process.h"

#include <stdio.h>


short inFrm[10000]={0},outFrm[10000]={0};
short count = 0;

SpEnh_Scratch *spEnh_buf;
Noise_Est *noise_est_inst;
FILE *fidr,*fidw;
short i,frm_len,retLen;
int retVal;

void init(){

	SpEnh_Buf_Alloc(&spEnh_buf,&noise_est_inst);
	xmly_monoNS_SetGainThreshold(spEnh_buf,0.05f);
	xmly_monoNS_SetBandwidth(spEnh_buf, 204);
}

void release(){
	xmly_monoNS_Delete(spEnh_buf,noise_est_inst);

}

int ns(char* in,int in_len,char* out,short flag){
	return xmly_monoNS_Process(spEnh_buf,noise_est_inst,inFrm,frm_len,outFrm,1);
}

JNIEXPORT void JNICALL Java_com_ximalaya_mediamsssmpr_MediaNS_init
  (JNIEnv * env, jobject jobj)
{
	init();
}

JNIEXPORT void JNICALL Java_com_ximalaya_mediamsssmpr_MediaNS_release
  (JNIEnv * env, jobject jobj)
{
	release();
}

JNIEXPORT jint JNICALL Java_com_ximalaya_mediamsssmpr_MediaNS_ns
  (JNIEnv * env, jobject jobj, jbyteArray jin, jint jin_len, jbyteArray jout, jshort jflag)
{
	char* in = (char*)(*env)->GetByteArrayElements(env,jin,JNI_FALSE);
	char* out = (char*)(*env)->GetByteArrayElements(env,jout,JNI_FALSE);
	int result = ns(in,jin_len,out,jflag);
	(*env)->ReleaseByteArrayElements(env,jin,(jbyte*)in,0);
	(*env)->ReleaseByteArrayElements(env,jout,(jbyte*)out,0);
	return result;
}

JNIEXPORT jstring JNICALL Java_com_ximalaya_mediamsssmpr_MediaNS_test
  (JNIEnv * env, jobject jobj)
{
	return (*env)->NewStringUTF(env,"media ns ");
}

