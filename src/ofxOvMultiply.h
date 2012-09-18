/*
 *  ofxOvMultiply.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/18/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/multiply.h"

class ofxOvMultiply : public ofxOvBaseFilter {
public:
	void setup() {
		loadShaderSource(multiplySource);
	}
	void draw() {
		shader.setUniformTexture("tex1", *tex1, 1);
		tex0->draw(0, 0);
	}
};