/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string boxglowSource =
    "uniform sampler2DRect tex;\n"
    "uniform int radius;\n"
    "\n"
    "float gray(vec3 rgb) {\n"
    "	return dot(rgb, vec3(0.333333));\n"
    "}\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sum = vec4(0.);\n"
    "\n"
    "	for(int y=-radius; y<=radius; y++) {\n"
    "		for(int x=-radius; x<=radius; x++) {\n"
    "			sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y));\n"
    "		}\n"
    "	}\n"
    "\n"
    "	int d = (radius*2+1);\n"
    "	int n = d * d;\n"
    "	float m = 1. / float(n);\n"
    "\n"
    "	if(radius > 0)\n"
    "		sum = sum * m;\n"
    "\n"
    "	vec4 sample = texture2DRect(tex, gl_TexCoord[0].xy);\n"
    "\n"
    "	gl_FragColor = gray(sum.rgb) > gray(sample.rgb) ? sum : sample;\n"
    "}\n"
    "";
