/*
 *  ofxOpenVision.h
 *  openVision
 *
 *  Created by Tobias Ebsen on 6/1/12.
 *
 */

#pragma once

#include "ofMain.h"


class ovFilter : public ofFbo {
public:
	
	virtual void allocate(int width, int height) = 0;

	virtual ofTexture& apply(ofTexture& texture) = 0;
	
	ofShader& getShader() {
		return shader;
	}
	
	void loadShaderFile(string filename) {
	}
	
	void loadShaderSource(string source) {
	}

	void allocate(int width, int height, int internalFormat = GL_RGB, bool useArbTex = true) {
		
		// Allocate framebuffer object
		ofFbo::Settings settings;
		settings.width = width;
		settings.height = height;
		settings.internalformat = internalFormat;
		settings.textureTarget = useArbTex ? GL_TEXTURE_RECTANGLE_ARB : GL_TEXTURE_2D;
		ofFbo::allocate(settings);		
	}
	
	void clear() {
		
		// Clear the framebuffer object
		ofFbo::begin();
		ofClear(0, 0, 0, 255);
		ofFbo::end();
	}
	
protected:
	
	ofShader shader;
};