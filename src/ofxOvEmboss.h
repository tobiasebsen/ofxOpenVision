/*
 *  ofxOvEmboss.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/14/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/emboss.h"

class ofxOvEmboss : public ofxOvBaseFilter {
public:
	void setup() {
		loadShaderSource(embossSource);
	}
	void draw() {
		getFirstTexture().draw(0, 0);
	}
};