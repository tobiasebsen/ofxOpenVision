/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string ravg2Source =
    "uniform sampler2DRect tex0;\n"
    "uniform sampler2DRect tex1;\n"
    "uniform sampler2DRect mask;\n"
    "uniform float alpha;\n"
    "uniform float beta;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 a = gl_Color * texture2DRect(tex0, gl_TexCoord[0].xy);\n"
    "	vec4 b = gl_Color * texture2DRect(tex1, gl_TexCoord[0].xy);\n"
    "	vec4 m = gl_Color * texture2DRect(mask, gl_TexCoord[0].xy);\n"
    "\n"
    "	if(m.rgb == vec3(0))\n"
    "		gl_FragColor.rgb = a.rgb * (1.0-beta) + b.rgb * beta;\n"
    "	else\n"
    "		gl_FragColor.rgb = a.rgb * (1.0-alpha) + b.rgb * alpha;\n"
    "\n"
    "	gl_FragColor.a = a.a;\n"
    "}\n"
    "";
