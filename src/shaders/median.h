/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string medianSource =
    "uniform sampler2DRect tex;\n"
    "uniform int radius;\n"
    "\n"
    "const vec3 on = vec3(1);\n"
    "\n"
    "void main()\n"
    "{\n"
    "	int sum = 0;\n"
    "\n"
    "	for(int y=-radius; y<radius; y++) {\n"
    "		for(int x=-radius; x<radius; x++) {\n"
    "			sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y)).rgb == on ? 1 : 0;\n"
    "		}\n"
    "	}\n"
    "\n"
    "	gl_FragColor = sum > (radius*radius) / 2 ? vec4(1) : vec4(0,0,0,1);\n"
    "}\n"
    "";
