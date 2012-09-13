uniform sampler2DRect tex;
uniform int radius;

float gray(vec3 rgb) {
	return dot(rgb, vec3(0.333333));
}

void main()
{
	vec4 sum = vec4(0.);

	for(int y=-radius; y<=radius; y++) {
		for(int x=-radius; x<=radius; x++) {
			sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y));
		}
	}

	int d = (radius*2+1);
	int n = d * d;
	float m = 1. / float(n);

	if(radius > 0)
		sum = sum * m;

	vec4 sample = texture2DRect(tex, gl_TexCoord[0].xy);

	gl_FragColor = gray(sum.rgb) > gray(sample.rgb) ? sum : sample;
}
