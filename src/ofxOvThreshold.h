/*
 *  ofxOvThreshold.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/18/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/threshold.h"

class ofxOvThreshold : public ofxOvBaseFilter {
public:
	void setup() {
		threshold = 0.1;
		loadShaderSource(thresholdSource);
	}
	void draw() {
		shader.setUniform1f("threshold", threshold);
		tex0->draw(0, 0);
	}
	
	float threshold;
};