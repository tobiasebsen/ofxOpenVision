/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string gammaSource =
    "uniform sampler2DRect tex;\n"
    "uniform float gamma;\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sample = texture2DRect(tex, gl_TexCoord[0].xy);\n"
    "	vec3 color = pow(sample.rgb, vec3(gamma));\n"
    "	gl_FragColor = vec4(color, sample.a);\n"
    "}\n"
    "";
