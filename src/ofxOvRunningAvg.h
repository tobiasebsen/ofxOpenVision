/*
 *  ofxOvRavg.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/18/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/ravg.h"

class ofxOvRunningAvg : public ofxOvBaseFilter {
public:
	void setup() {
		alpha = 0.01;
		loadShaderSource(ravgSource);
	}
	void draw() {
		shader.setUniformTexture("tex1", *tex1, 1);
		shader.setUniform1f("alpha", alpha);
		tex0->draw(0, 0);
	}	
	float alpha;
};