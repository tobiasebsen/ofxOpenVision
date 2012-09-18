/*
 *  ofxOvAbsDiff.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/18/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/absdiff.h"

class ofxOvAbsDiff : public ofxOvBaseFilter {
public:
	void setup() {
		loadShaderSource(absdiffSource);
	}
	void draw() {
		shader.setUniformTexture("tex1", *tex1, 1);
		tex0->draw(0, 0);
	}
};