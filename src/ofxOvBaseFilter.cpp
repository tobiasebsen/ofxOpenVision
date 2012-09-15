/*
 *  ofxOvBaseFilter.cpp
 *  openVisionTest
 *
 *  Created by Tobias Ebsen on 9/14/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxOvBaseFilter.h"

//////////////////////////////////////////////////
ofxOvBaseFilter::ofxOvBaseFilter() {
	tex0 = NULL;
	tex1 = NULL;
}
//////////////////////////////////////////////////
ofTexture& ofxOvBaseFilter::apply(ofTexture& texture) {
	tex0 = &texture;
	tex1 = &texture;
	ofFbo::begin();
	shader.begin();
	draw();
	shader.end();
	ofFbo::end();
	return ofFbo::getTextureReference();
}
//////////////////////////////////////////////////
ofTexture& ofxOvBaseFilter::apply(ofTexture& tex0, ofTexture& tex1) {
	this->tex0 = &tex0;
	this->tex1 = &tex1;
	ofFbo::begin();
	shader.begin();
	draw();
	shader.begin();
	ofFbo::end();
	return ofFbo::getTextureReference();
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
void ofxOvBaseFilter::allocate(int width, int height, int internalFormat, bool useArbTex) {
	
	// Allocate framebuffer object
	ofFbo::Settings settings;
	settings.width = width;
	settings.height = height;
	settings.internalformat = internalFormat;
	settings.textureTarget = useArbTex ? GL_TEXTURE_RECTANGLE_ARB : GL_TEXTURE_2D;
	ofFbo::allocate(settings);
	
	clear();
	
	setup();
	
	shader.linkProgram();
}
//////////////////////////////////////////////////
void ofxOvBaseFilter::clear() {
	
	// Clear the framebuffer object
	ofFbo::begin();
	ofClear(0, 0, 0, 255);
	ofFbo::end();
}
//////////////////////////////////////////////////
ofShader& ofxOvBaseFilter::getShader() {
	return shader;
}
//////////////////////////////////////////////////
ofTexture& ofxOvBaseFilter::getFirstTexture() {
	return *tex0;
}
//////////////////////////////////////////////////
ofTexture& ofxOvBaseFilter::getSecondTexture() {
	return *tex1;
}
