/*
 *  ofxOvBaseFilter.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/14/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class ofxOvBaseFilter : public ofFbo {
public:
	
	ofxOvBaseFilter();
	
	virtual void setup() = 0;
	virtual void draw() = 0;
	
	ofTexture& apply(ofTexture& texture);
	ofTexture& apply(ofTexture& tex0, ofTexture& tex1);
	
	void loadShaderFile(string filename);
	void loadShaderSource(string source);
	
	void allocate(int width, int height, int internalFormat = GL_RGB, bool useArbTex = true);
	
	void clear();
	
	ofShader& getShader();
	
	ofTexture& getFirstTexture();
	ofTexture& getSecondTexture();
	
protected:
	
	ofShader shader;
	ofTexture* tex0;
	ofTexture* tex1;
};