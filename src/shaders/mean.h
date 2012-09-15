/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string meanSource =
    "uniform sampler2DRect tex;\n"
    "uniform int radius;\n"
    "uniform float threshold;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec3 max = vec3(0.);\n"
    "	vec3 min = vec3(1.);\n"
    "\n"
    "	for(int y=-radius; y<=radius; y++) {\n"
    "		for(int x=-radius; x<=radius; x++) {\n"
    "			vec3 s = texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y)).rgb;\n"
    "			max = max(s, max);\n"
    "			min = min(s, min);\n"
    "		}\n"
    "	}\n"
    "	vec3 color = (max + min) * 0.5;\n"
    "	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;\n"
    "\n"
    "	gl_FragColor = vec4(color, alpha);\n"
    "}\n"
    "";
