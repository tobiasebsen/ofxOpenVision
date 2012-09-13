uniform sampler2DRect tex;

void main()
{
	vec4 sum = vec4(0.);

	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(4, 0)) * 0.05;
	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(3, 0)) * 0.09;
	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(2, 0)) * 0.12;
	sum += texture2DRect(tex, gl_TexCoord[0].xy - vec2(1, 0)) * 0.15;
	sum += texture2DRect(tex, gl_TexCoord[0].xy) * 0.16;
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, 0)) * 0.15;
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(2, 0)) * 0.12;
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(3, 0)) * 0.09;
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(4, 0)) * 0.05;

	gl_FragColor = sum;
}
