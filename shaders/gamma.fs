uniform sampler2DRect tex;
uniform float gamma;

void main()
{
	vec4 sample = texture2DRect(tex, gl_TexCoord[0].xy);
	vec3 color = pow(sample.rgb, vec3(gamma));
	gl_FragColor = vec4(color, sample.a);
}
