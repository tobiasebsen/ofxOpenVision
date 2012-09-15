/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string adaptSource =
    "uniform sampler2DRect tex;\n"
    "uniform int radius;\n"
    "uniform float threshold;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	float max = 0.;\n"
    "	float min = 1.;\n"
    "\n"
    "	for(int y=-radius; y<=radius; y++) {\n"
    "		for(int x=-radius; x<=radius; x++) {\n"
    "			vec3 s = texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y)).rgb;\n"
    "			float l = dot(s, vec3(0.33333));\n"
    "			if(l > max) max = l;\n"
    "			if(l < min) min = l;\n"
    "		}\n"
    "	}\n"
    "	float t = (max+min)*0.5;\n"
    "	vec3 c = texture2DRect(tex, gl_TexCoord[0].xy).rgb;\n"
    "	float l = dot(c, vec3(0.33333));\n"
    "	float p = l > t + threshold ? 1. : 0.;\n"
    "\n"
    "	gl_FragColor = vec4(vec3(p), 1.);\n"
    "}\n"
    "";
