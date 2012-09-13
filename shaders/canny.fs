uniform sampler2DRect tex;
uniform float threshold;

const vec3 sobelX0 = vec3(-1, 0, 1);
const vec3 sobelX1 = vec3(-2, 0, 2);
const vec3 sobelX2 = vec3(-1, 0, 1);
const vec3 sobelY0 = vec3(1, 2, 1);
const vec3 sobelY1 = vec3(0, 0, 0);
const vec3 sobelY2 = vec3(-1, -2, -1);

const float PI = 3.14159265358979323846264;

vec3 conv3x3(vec2 coord, vec3 kernel0, vec3 kernel1, vec3 kernel2) {

	vec3 sum = vec3(0.);

	sum += texture2DRect(tex, coord + vec2(-1, -1)).rgb * kernel0[0];
	sum += texture2DRect(tex, coord + vec2(0, -1)).rgb * kernel0[1];
	sum += texture2DRect(tex, coord + vec2(1, -1)).rgb * kernel0[2];

	sum += texture2DRect(tex, coord + vec2(-1, 0)).rgb * kernel1[0];
	sum += texture2DRect(tex, coord).rgb * kernel1[1];
	sum += texture2DRect(tex, coord + vec2(1, 0)).rgb * kernel1[2];

	sum += texture2DRect(tex, coord + vec2(-1, 1)).rgb * kernel2[0];
	sum += texture2DRect(tex, coord + vec2(0, 1)).rgb * kernel2[1];
	sum += texture2DRect(tex, coord + vec2(1, 1)).rgb * kernel2[2];

	return sum;
}

float atan2(float x, float y) {
	if(x > 0.)
		return atan(abs(y / x));
	if(x < 0. && y >= 0.)
		return atan(abs(y /x)) + PI;
	if(x < 0. && y < 0.)
		return atan(abs(y / x)) - PI;
	if(x == 0. && y > 0.)
		return PI / 2.;
	if(x == 0. && y < 0.)
		return -PI / 2.;
	if(x == 0. && y == 0.)
		return 0.;
}

float gray(vec3 color) {
	return dot(color, vec3(0.3333333));
}

vec2 edge(vec2 coord) {
	float x = gray(conv3x3(coord, sobelX0, sobelX1, sobelX2).rgb);
	float y = gray(conv3x3(coord, sobelY0, sobelY1, sobelY2).rgb);
	return vec2(x, y);
}

float mag(vec2 G) {
	return sqrt(G.x * G.x + G.y * G.y);
}

void main()
{
	vec2 G = edge(gl_TexCoord[0].xy);
	
	float T = atan2(G.x, G.y);
	int a = int(T * 4. / PI);
	vec2 p;
	if(a == 0 || a == 4 || a == -4)
		p = vec2(1, 0);
	if(a == 1 || a == -1)
		p = vec2(1, 1);
	if(a == 2 || a == -2)
		p = vec2(0, 1);
	if(a == 3 || a == -3)
		p = vec2(1, -1);

	float m0 = mag(G);
	float m1 = mag(edge(gl_TexCoord[0].xy + p));
	float m2 = mag(edge(gl_TexCoord[0].xy - p));
	float alpha = texture2DRect(tex, gl_TexCoord[0].xy).a;

	if(m0 > m1 && m0 > m2 && m0 > threshold)
		gl_FragColor = vec4(vec3(m0), alpha);
	else
		gl_FragColor = vec4(vec3(0.), alpha);
}
