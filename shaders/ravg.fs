uniform sampler2DRect tex0;
uniform sampler2DRect tex1;
uniform float alpha;

void main()
{
	vec4 a = gl_Color * texture2DRect(tex0, gl_TexCoord[0].xy);
	vec4 b = gl_Color * texture2DRect(tex1, gl_TexCoord[0].xy);
	vec3 c = a.rgb * (1.0-alpha) + b.rgb * alpha;
	gl_FragColor = vec4(c, a.a);
}
