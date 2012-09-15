/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string thresholdSource =
    "uniform sampler2DRect tex;\n"
    "uniform float threshold;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sample = gl_Color * texture2DRect(tex, gl_TexCoord[0].xy);\n"
    "	float i = sample.r * 0.333 + sample.g * 0.333 + sample.b * 0.333;\n"
    "	gl_FragColor = i > threshold ? vec4(1) : vec4(0, 0, 0, 1);\n"
    "}\n"
    "";
