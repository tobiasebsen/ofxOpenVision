/*
 *  ofxOvSqrt.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/18/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/sqrt.h"

class ofxOvSqrt : public ofxOvBaseFilter {
public:
	void setup() {
		loadShaderSource(sqrtSource);
	}
	void draw() {
		tex0->draw(0, 0);
	}
};