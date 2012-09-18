/*
 *  ofxOvBaseFilter.cpp
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/14/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#include "ofxOvBaseFilter.h"

//////////////////////////////////////////////////
ofxOvBaseFilter::ofxOvBaseFilter() {
	tex0 = NULL;
	tex1 = NULL;
}
//////////////////////////////////////////////////
void ofxOvBaseFilter::init() {
	setup();
	shader.linkProgram();
}
//////////////////////////////////////////////////
ofTexture& ofxOvBaseFilter::applyTo(ofTexture& tex0, ofFbo& fbo) {
	return applyTo(tex0, tex0, fbo);
}
//////////////////////////////////////////////////
ofTexture& ofxOvBaseFilter::applyTo(ofTexture& tex0, ofTexture& tex1, ofFbo& fbo) {
	this->tex0 = &tex0;
	this->tex1 = &tex1;
	
	fbo.begin();
	shader.begin();
	draw();
	shader.end();
	fbo.end();
	
	return fbo.getTextureReference();
}
//////////////////////////////////////////////////
void ofxOvBaseFilter::loadShaderFile(string filename) {
	shader.setupShaderFromFile(GL_FRAGMENT_SHADER, filename);
}
//////////////////////////////////////////////////
void ofxOvBaseFilter::loadShaderSource(string source) {
	shader.setupShaderFromSource(GL_FRAGMENT_SHADER, source);
}
//////////////////////////////////////////////////
ofShader& ofxOvBaseFilter::getShader() {
	return shader;
}
