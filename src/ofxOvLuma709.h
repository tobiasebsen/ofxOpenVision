/*
 *  ofxOvLuma709.h
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/18/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxOvBaseFilter.h"
#include "shaders/luma709.h"

class ofxOvLuma709 : public ofxOvBaseFilter {
public:
	void setup() {
		loadShaderSource(luma709Source);
	}
	void draw() {
		tex0->draw(0, 0);
	}
};