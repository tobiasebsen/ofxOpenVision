/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string luma709Source =
    "uniform sampler2DRect tex;\n"
    "const vec3 prim = vec3(0.2126, 0.7152, 0.0722);\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sample = texture2DRect(tex, gl_TexCoord[0].st);\n"
    "	float luma = dot(sample.rgb, prim);\n"
    "	gl_FragColor = vec4(luma, luma, luma, sample.a);\n"
    "}\n"
    "";
