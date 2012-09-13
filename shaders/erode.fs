uniform sampler2DRect tex;

void main()
{
	vec3 a = texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, -1)).rgb;
	vec3 b = texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, 0)).rgb;
	vec3 c = texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)).rgb;
	vec3 d = texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)).rgb;
	vec3 color = min(min(a, b), min(c, d));
	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;
	gl_FragColor = vec4(color,alpha);
}
