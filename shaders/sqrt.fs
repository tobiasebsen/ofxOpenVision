uniform sampler2DRect tex;

void main()
{
	vec4 a = texture2DRect(tex, gl_TexCoord[0].xy);
	gl_FragColor = sqrt(a);
}
