/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string conv3x3Source =
    "uniform sampler2DRect tex;\n"
    "uniform vec3 kernel0;\n"
    "uniform vec3 kernel1;\n"
    "uniform vec3 kernel2;\n"
    "uniform float bias;\n"
    "\n"
    "void main()\n"
    "{\n"
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
    "	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;\n"
    "\n"
    "	gl_FragColor = vec4(sum + bias, alpha);\n"
    "}\n"
    "";
