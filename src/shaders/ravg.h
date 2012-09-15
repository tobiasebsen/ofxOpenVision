/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string ravgSource =
    "uniform sampler2DRect tex0;\n"
    "uniform sampler2DRect tex1;\n"
    "uniform float alpha;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 a = gl_Color * texture2DRect(tex0, gl_TexCoord[0].xy);\n"
    "	vec4 b = gl_Color * texture2DRect(tex1, gl_TexCoord[0].xy);\n"
    "	vec3 c = a.rgb * (1.0-alpha) + b.rgb * alpha;\n"
    "	gl_FragColor = vec4(c, a.a);\n"
    "}\n"
    "";
