uniform sampler2DRect tex;
uniform float hue;
uniform float saturation;
uniform float lightness;

vec3 rgbToHsl(vec3 sample)
{
	float M = max(max(sample.r, sample.g), sample.b);
	float m = min(min(sample.r, sample.g), sample.b);
	float C = M - m;

	float h = 0.;
	if(C == 0.)
		h = 0.;
	else if(M == sample.r)
		h = mod((sample.g - sample.b) / C, 6.);
	else if(M == sample.g)
		h = (sample.b - sample.r) / C + 2.;
	else if(M == sample.b)
		h = (sample.r - sample.g) / C + 4.;
	float H = 60. * h;

	float L = (M + m) * 0.5;
	float S = (C == 0.) ? 0. : C / (1. - abs(2. * L - 1.));

	return vec3(H, S, L);
}

vec3 hslToRgb(vec3 sample)
{
	float H = sample[0];
	float S = sample[1];
	float L = sample[2];

	float C = (1. - abs(2. * L - 1.)) * S;
	
	float h = H / 60.;
	float X = C * (1. - abs(mod(h, 2.) - 1.));

	vec3 rgb;
	if(H == 0.)
		rgb = vec3(0.);
	else if(0. <= h && h < 1.)
		rgb = vec3(C, X, 0.);
	else if(1. <= h && h < 2.)
		rgb = vec3(X, C, 0.);
	else if(2. <= h && h < 3.)
		rgb = vec3(0., C, X);
	else if(3. <= h && h < 4.)
		rgb = vec3(0., X, C);
	else if(4. <= h && h < 5.)
		rgb = vec3(X, 0., C);
	else if(5. <= h && h < 6.)
		rgb = vec3(C, 0., X);

	float m = L - 0.5 * C;

	return clamp(rgb + m, 0., 1.);
}

void main()
{
	vec4 sample = texture2DRect(tex, gl_TexCoord[0].xy);

	vec3 hsl = rgbToHsl(sample.rgb);

	hsl[0] = mod(hsl[0] + hue * 360., 360.);
	hsl[1] = hsl[1] * saturation;
	hsl[2] = hsl[2] * lightness;

	vec3 rgb = hslToRgb(hsl);

	gl_FragColor = vec4(rgb,sample.a);
}
