uniform sampler2DRect tex0;
uniform sampler2DRect tex1;

void main()
{
	vec4 a = texture2DRect(tex0, gl_TexCoord[0].xy);
	vec4 b = texture2DRect(tex1, gl_TexCoord[0].xy);
	gl_FragColor = a * b;
}
