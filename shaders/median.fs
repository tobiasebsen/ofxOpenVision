uniform sampler2DRect tex;
uniform int radius;

const vec3 on = vec3(1);

void main()
{
	int sum = 0;

	for(int y=-radius; y<radius; y++) {
		for(int x=-radius; x<radius; x++) {
			sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(x, y)).rgb == on ? 1 : 0;
		}
	}

	gl_FragColor = sum > (radius*radius) / 2 ? vec4(1) : vec4(0,0,0,1);
}
