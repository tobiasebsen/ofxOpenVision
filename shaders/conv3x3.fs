uniform sampler2DRect tex;
uniform vec3 kernel0;
uniform vec3 kernel1;
uniform vec3 kernel2;
uniform float bias;

void main()
{
	vec3 sum = vec3(0.);

	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, -1)).rgb * kernel0[0];
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, -1)).rgb * kernel0[1];
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, -1)).rgb * kernel0[2];

	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, 0)).rgb * kernel1[0];
	sum += texture2DRect(tex, gl_TexCoord[0].xy).rgb * kernel1[1];
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, 0)).rgb * kernel1[2];

	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(-1, 1)).rgb * kernel2[0];
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(0, 1)).rgb * kernel2[1];
	sum += texture2DRect(tex, gl_TexCoord[0].xy + vec2(1, 1)).rgb * kernel2[2];

	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;

	gl_FragColor = vec4(sum + bias, alpha);
}
