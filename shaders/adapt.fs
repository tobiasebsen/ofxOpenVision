uniform sampler2DRect tex;
uniform int radius;
uniform float threshold;

void main()
{
	float max = 0.;
	float min = 1.;

	for(int y=-radius; y<=radius; y++) {
		for(int x=-radius; x<=radius; x++) {
			vec3 s = texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y)).rgb;
			float l = dot(s, vec3(0.33333));
			if(l > max) max = l;
			if(l < min) min = l;
		}
	}
	float t = (max+min)*0.5;
	vec3 c = texture2DRect(tex, gl_TexCoord[0].xy).rgb;
	float l = dot(c, vec3(0.33333));
	float p = l > t + threshold ? 1. : 0.;

	gl_FragColor = vec4(vec3(p), 1.);
}
