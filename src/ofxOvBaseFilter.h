/*
 *  ofxOvBaseFilter.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/14/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxOvBuffer.h"

class ofxOvBaseFilter {
public:
	
	ofxOvBaseFilter();
	
	void init();
	
	virtual void setup() = 0;
	virtual void draw() = 0;
		
	ofTexture& applyTo(ofTexture& tex0, ofFbo& fbo);
	ofTexture& applyTo(ofTexture& tex0, ofTexture& tex1, ofFbo& fbo);
	
	void loadShaderFile(string filename);
	void loadShaderSource(string source);
		
	ofShader& getShader();
		
protected:
	ofShader shader;
	ofTexture* tex0;
	ofTexture* tex1;
};