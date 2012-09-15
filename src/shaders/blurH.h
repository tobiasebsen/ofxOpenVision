/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string blurHSource =
    "uniform sampler2DRect tex;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sum = vec4(0.);\n"
    "\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(4, 0)) * 0.05;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(3, 0)) * 0.09;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(2, 0)) * 0.12;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(1, 0)) * 0.15;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy) * 0.16;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, 0)) * 0.15;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(2, 0)) * 0.12;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(3, 0)) * 0.09;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(4, 0)) * 0.05;\n"
    "\n"
    "	gl_FragColor = sum;\n"
    "}\n"
    "";
