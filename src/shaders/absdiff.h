/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string absdiffSource =
    "uniform sampler2DRect tex0;\n"
    "uniform sampler2DRect tex1;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 a = gl_Color * texture2DRect(tex0, gl_TexCoord[0].xy);\n"
    "	vec4 b = gl_Color * texture2DRect(tex1, gl_TexCoord[0].xy);\n"
    "	vec3 c = abs(a.rgb - b.rgb);\n"
    "	gl_FragColor = vec4(c, a.a);\n"
    "}\n"
    "";
