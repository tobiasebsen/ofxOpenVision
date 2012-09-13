uniform sampler2DRect tex;
uniform float threshold;

void main()
{
	vec4 sample = gl_Color * texture2DRect(tex, gl_TexCoord[0].xy);
	float i = sample.r * 0.333 + sample.g * 0.333 + sample.b * 0.333;
	gl_FragColor = i > threshold ? vec4(1) : vec4(0, 0, 0, 1);
}
