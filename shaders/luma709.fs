uniform sampler2DRect tex;
const vec3 prim = vec3(0.2126, 0.7152, 0.0722);

void main()
{
	vec4 sample = texture2DRect(tex, gl_TexCoord[0].st);
	float luma = dot(sample.rgb, prim);
	gl_FragColor = vec4(luma, luma, luma, sample.a);
}
