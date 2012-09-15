/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string sqrtSource =
    "uniform sampler2DRect tex;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 a = texture2DRect(tex, gl_TexCoord[0].xy);\n"
    "	gl_FragColor = sqrt(a);\n"
    "}\n"
    "";
