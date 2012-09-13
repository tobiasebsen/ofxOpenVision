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

protected:

	void allocate(int width, int height, string shaderFile, int internalFormat = GL_RGB, bool useArbTex = true) {
		shader.load("", shaderFile);
		ofFbo::Settings settings;
		settings.width = width;
		settings.height = height;
		settings.internalformat = internalFormat;
		settings.textureTarget = useArbTex ? GL_TEXTURE_RECTANGLE_ARB : GL_TEXTURE_2D;
		ofFbo::allocate(settings);
		ofFbo::begin();
		ofClear(0, 0, 0, 255);
		ofFbo::end();
	}

	ofShader shader;
};