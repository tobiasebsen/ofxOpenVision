/* AUTO-GENERATED CODE BY shader.sh */

#pragma once

static string hslSource =
    "uniform sampler2DRect tex;\n"
    "uniform float hue;\n"
    "uniform float saturation;\n"
    "uniform float lightness;\n"
    "\n"
    "vec3 rgbToHsl(vec3 sample)\n"
    "{\n"
    "	float M = max(max(sample.r, sample.g), sample.b);\n"
    "	float m = min(min(sample.r, sample.g), sample.b);\n"
    "	float C = M - m;\n"
    "\n"
    "	float h = 0.;\n"
    "	if(C == 0.)\n"
    "		h = 0.;\n"
    "	else if(M == sample.r)\n"
    "		h = mod((sample.g - sample.b) / C, 6.);\n"
    "	else if(M == sample.g)\n"
    "		h = (sample.b - sample.r) / C + 2.;\n"
    "	else if(M == sample.b)\n"
    "		h = (sample.r - sample.g) / C + 4.;\n"
    "	float H = 60. * h;\n"
    "\n"
    "	float L = (M + m) * 0.5;\n"
    "	float S = (C == 0.) ? 0. : C / (1. - abs(2. * L - 1.));\n"
    "\n"
    "	return vec3(H, S, L);\n"
    "}\n"
    "\n"
    "vec3 hslToRgb(vec3 sample)\n"
    "{\n"
    "	float H = sample[0];\n"
    "	float S = sample[1];\n"
    "	float L = sample[2];\n"
    "\n"
    "	float C = (1. - abs(2. * L - 1.)) * S;\n"
    "	\n"
    "	float h = H / 60.;\n"
    "	float X = C * (1. - abs(mod(h, 2.) - 1.));\n"
    "\n"
    "	vec3 rgb;\n"
    "	if(H == 0.)\n"
    "		rgb = vec3(0.);\n"
    "	else if(0. <= h && h < 1.)\n"
    "		rgb = vec3(C, X, 0.);\n"
    "	else if(1. <= h && h < 2.)\n"
    "		rgb = vec3(X, C, 0.);\n"
    "	else if(2. <= h && h < 3.)\n"
    "		rgb = vec3(0., C, X);\n"
    "	else if(3. <= h && h < 4.)\n"
    "		rgb = vec3(0., X, C);\n"
    "	else if(4. <= h && h < 5.)\n"
    "		rgb = vec3(X, 0., C);\n"
    "	else if(5. <= h && h < 6.)\n"
    "		rgb = vec3(C, 0., X);\n"
    "\n"
    "	float m = L - 0.5 * C;\n"
    "\n"
    "	return clamp(rgb + m, 0., 1.);\n"
    "}\n"
    "\n"
    "void main()\n"
    "{\n"
    "	vec4 sample = texture2DRect(tex, gl_TexCoord[0].xy);\n"
    "\n"
    "	vec3 hsl = rgbToHsl(sample.rgb);\n"
    "\n"
    "	hsl[0] = mod(hsl[0] + hue * 360., 360.);\n"
    "	hsl[1] = hsl[1] * saturation;\n"
    "	hsl[2] = hsl[2] * lightness;\n"
    "\n"
    "	vec3 rgb = hslToRgb(hsl);\n"
    "\n"
    "	gl_FragColor = vec4(rgb,sample.a);\n"
    "}\n"
    "";
