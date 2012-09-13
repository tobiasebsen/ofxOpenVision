uniform sampler2DRect tex0;
uniform sampler2DRect tex1;
uniform sampler2DRect mask;
uniform float alpha;
uniform float beta;

void main()
{
	vec4 a = gl_Color * texture2DRect(tex0, gl_TexCoord[0].xy);
	vec4 b = gl_Color * texture2DRect(tex1, gl_TexCoord[0].xy);
	vec4 m = gl_Color * texture2DRect(mask, gl_TexCoord[0].xy);

	if(m.rgb == vec3(0))
		gl_FragColor.rgb = a.rgb * (1.0-beta) + b.rgb * beta;
	else
		gl_FragColor.rgb = a.rgb * (1.0-alpha) + b.rgb * alpha;

	gl_FragColor.a = a.a;
}
