/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string blurVSource =
    "uniform sampler2DRect tex;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sum = vec4(0.);\n"
    "\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(0, 4)) * 0.05;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(0, 3)) * 0.09;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(0, 2)) * 0.12;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(0, 1)) * 0.15;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy) * 0.16;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)) * 0.15;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 2)) * 0.12;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 3)) * 0.09;\n"
    "	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 4)) * 0.05;\n"
    "\n"
    "	gl_FragColor = sum;\n"
    "}\n"
    "";
