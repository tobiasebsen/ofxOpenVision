/*
 *  ofxOvSobel.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/15/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/sobel.h"

class ofxOvSobel : public ofxOvBaseFilter {
public:
	void setup() {
		loadShaderSource(sobelSource);
	}
	void draw() {
		getFirstTexture().draw(0, 0);
	}
};