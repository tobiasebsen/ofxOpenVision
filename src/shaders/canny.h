/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string cannySource =
    "uniform sampler2DRect tex;\n"
    "uniform float threshold;\n"
    "\n"
    "const vec3 sobelX0 = vec3(-1, 0, 1);\n"
    "const vec3 sobelX1 = vec3(-2, 0, 2);\n"
    "const vec3 sobelX2 = vec3(-1, 0, 1);\n"
    "const vec3 sobelY0 = vec3(1, 2, 1);\n"
    "const vec3 sobelY1 = vec3(0, 0, 0);\n"
    "const vec3 sobelY2 = vec3(-1, -2, -1);\n"
    "\n"
    "const float PI = 3.14159265358979323846264;\n"
    "\n"
    "vec3 conv3x3(vec2 coord, vec3 kernel0, vec3 kernel1, vec3 kernel2) {\n"
    "\n"
    "	vec3 sum = vec3(0.);\n"
    "\n"
    "	sum += texture2DRect(tex, coord + vec2(-1, -1)).rgb * kernel0[0];\n"
    "	sum += texture2DRect(tex, coord + vec2(0, -1)).rgb * kernel0[1];\n"
    "	sum += texture2DRect(tex, coord + vec2(1, -1)).rgb * kernel0[2];\n"
    "\n"
    "	sum += texture2DRect(tex, coord + vec2(-1, 0)).rgb * kernel1[0];\n"
    "	sum += texture2DRect(tex, coord).rgb * kernel1[1];\n"
    "	sum += texture2DRect(tex, coord + vec2(1, 0)).rgb * kernel1[2];\n"
    "\n"
    "	sum += texture2DRect(tex, coord + vec2(-1, 1)).rgb * kernel2[0];\n"
    "	sum += texture2DRect(tex, coord + vec2(0, 1)).rgb * kernel2[1];\n"
    "	sum += texture2DRect(tex, coord + vec2(1, 1)).rgb * kernel2[2];\n"
    "\n"
    "	return sum;\n"
    "}\n"
    "\n"
    "float atan2(float x, float y) {\n"
    "	if(x > 0.)\n"
    "		return atan(abs(y / x));\n"
    "	if(x < 0. && y >= 0.)\n"
    "		return atan(abs(y /x)) + PI;\n"
    "	if(x < 0. && y < 0.)\n"
    "		return atan(abs(y / x)) - PI;\n"
    "	if(x == 0. && y > 0.)\n"
    "		return PI / 2.;\n"
    "	if(x == 0. && y < 0.)\n"
    "		return -PI / 2.;\n"
    "	if(x == 0. && y == 0.)\n"
    "		return 0.;\n"
    "}\n"
    "\n"
    "float gray(vec3 color) {\n"
    "	return dot(color, vec3(0.3333333));\n"
    "}\n"
    "\n"
    "vec2 edge(vec2 coord) {\n"
    "	float x = gray(conv3x3(coord, sobelX0, sobelX1, sobelX2).rgb);\n"
    "	float y = gray(conv3x3(coord, sobelY0, sobelY1, sobelY2).rgb);\n"
    "	return vec2(x, y);\n"
    "}\n"
    "\n"
    "float mag(vec2 G) {\n"
    "	return sqrt(G.x * G.x + G.y * G.y);\n"
    "}\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec2 G = edge(gl_TexCoord[0].xy);\n"
    "	\n"
    "	float T = atan2(G.x, G.y);\n"
    "	int a = int(T * 4. / PI);\n"
    "	vec2 p;\n"
    "	if(a == 0 || a == 4 || a == -4)\n"
    "		p = vec2(1, 0);\n"
    "	if(a == 1 || a == -1)\n"
    "		p = vec2(1, 1);\n"
    "	if(a == 2 || a == -2)\n"
    "		p = vec2(0, 1);\n"
    "	if(a == 3 || a == -3)\n"
    "		p = vec2(1, -1);\n"
    "\n"
    "	float m0 = mag(G);\n"
    "	float m1 = mag(edge(gl_TexCoord[0].xy + p));\n"
    "	float m2 = mag(edge(gl_TexCoord[0].xy - p));\n"
    "	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;\n"
    "\n"
    "	if(m0 > m1 && m0 > m2 && m0 > threshold)\n"
    "		gl_FragColor = vec4(vec3(m0), alpha);\n"
    "	else\n"
    "		gl_FragColor = vec4(vec3(0.), alpha);\n"
    "}\n"
    "";
