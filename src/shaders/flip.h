/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string flipSource =
    "uniform sampler2D tex;\n"
    "uniform vec2 dim;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	gl_FragColor = gl_Color * texture2D(tex, dim * gl_TexCoord[0].xy);\n"
    "}\n"
    "";
