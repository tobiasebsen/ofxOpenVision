uniform sampler2DRect tex;
const vec3 sobelX0 = vec3(-1, 0, 1);
const vec3 sobelX1 = vec3(-1, 0, 1);
const vec3 sobelX2 = vec3(-1, 0, 1);
const vec3 sobelY0 = vec3(1, 1, 1);
const vec3 sobelY1 = vec3(0, 0, 0);
const vec3 sobelY2 = vec3(-1, -1, -1);

vec3 conv3x3(vec3 kernel0, vec3 kernel1, vec3 kernel2) {

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

	return sum;
}

void main()
{
	vec3 Gx = conv3x3(sobelX0, sobelX1, sobelX2);
	vec3 Gy = conv3x3(sobelY0, sobelY1, sobelY2);
	vec3 G = abs(Gx) + abs(Gy);

	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;

	gl_FragColor = vec4(G, alpha);
}
