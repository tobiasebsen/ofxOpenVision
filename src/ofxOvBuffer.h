/*
 *  ofxOvPingPong.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/17/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

// http://www.comp.nus.edu/~ashwinna/docs/PingPong_FBO.pdf
// http://www.seas.upenn.edu/~cis565/fbo.htm#setupgl4

#pragma once

#include "ofMain.h"

class ofxOvBuffer {
public:

    void allocate(int width, int height, int internalformat = GL_RGBA){
		for (int i=0; i<2; i++)
			fbos[i].allocate(width, height, internalformat);
		index = 0;
		swap();
		clear();
    }
    
    void swap(){
		index++;
    }
    
    void clear(){
		for (int i=0; i<2; i++) {
			fbos[i].begin();
			glClear(0);
			fbos[i].end();
		}
    }
	
	ofFbo& getCurrent() {
		return fbos[(index)%2];
	}
	
	ofFbo& getCurrentAndSwap() {
		return fbos[(index++)%2];
	}

	ofTexture& getTextureReference() {
		return fbos[(index)%2].getTextureReference();
	}
	
	int getWidth() {
		return fbos[0].getWidth();
	}
	
	int getHeight() {
		return fbos[0].getHeight();
	}

private:
    ofFbo   fbos[2];    // Real addresses of ping/pong FBO´s  
    int     index;      // Integer for making a quick swap
};
