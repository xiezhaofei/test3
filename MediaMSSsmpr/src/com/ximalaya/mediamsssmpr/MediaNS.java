package com.ximalaya.mediamsssmpr;

public class MediaNS {

	static{
		System.loadLibrary("media_ns");
	}
	
	public native void init();
	
	public native void release();
	
	public native int ns(byte[] in,int in_len,byte[] out,short state);
	
	public native String test();

}
