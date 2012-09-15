/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string sobelSource =
    "uniform sampler2DRect tex;\n"
    "const vec3 sobelX0 = vec3(-1, 0, 1);\n"
    "const vec3 sobelX1 = vec3(-2, 0, 2);\n"
    "const vec3 sobelX2 = vec3(-1, 0, 1);\n"
    "const vec3 sobelY0 = vec3(1, 2, 1);\n"
    "const vec3 sobelY1 = vec3(0, 0, 0);\n"
    "const vec3 sobelY2 = vec3(-1, -2, -1);\n"
    "\n"
    "vec3 conv3x3(vec3 kernel0, vec3 kernel1, vec3 kernel2) {\n"
    "\n"
    "	vec3 sum = vec3(0.);\n"
    "\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, -1)).rgb * kernel0[0];\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, -1)).rgb * kernel0[1];\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, -1)).rgb * kernel0[2];\n"
    "\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, 0)).rgb * kernel1[0];\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy).rgb * kernel1[1];\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, 0)).rgb * kernel1[2];\n"
    "\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, 1)).rgb * kernel2[0];\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)).rgb * kernel2[1];\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, 1)).rgb * kernel2[2];\n"
    "\n"
    "	return sum;\n"
    "}\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec3 Gx = conv3x3(sobelX0, sobelX1, sobelX2);\n"
    "	vec3 Gy = conv3x3(sobelY0, sobelY1, sobelY2);\n"
    "	vec3 G = abs(Gx) + abs(Gy);\n"
    "\n"
    "	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;\n"
    "\n"
    "	gl_FragColor = vec4(G, alpha);\n"
    "}\n"
    "";
