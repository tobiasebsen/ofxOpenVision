/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string dilateSource =
    "uniform sampler2DRect tex;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec3 a = texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, -1)).rgb;\n"
    "	vec3 b = texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, 0)).rgb;\n"
    "	vec3 c = texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)).rgb;\n"
    "	vec3 d = texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)).rgb;\n"
    "	vec3 color = max(max(a, b), max(c, d));\n"
    "	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;\n"
    "	gl_FragColor = vec4(color,alpha);\n"
    "}\n"
    "";
