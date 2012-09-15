/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string multiplySource =
    "uniform sampler2DRect tex0;\n"
    "uniform sampler2DRect tex1;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 a = texture2DRect(tex0, gl_TexCoord[0].xy);\n"
    "	vec4 b = texture2DRect(tex1, gl_TexCoord[0].xy);\n"
    "	gl_FragColor = a * b;\n"
    "}\n"
    "";
