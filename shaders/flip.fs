uniform sampler2D tex;
uniform vec2 dim;

void main()
{
	gl_FragColor = gl_Color * texture2D(tex, dim * gl_TexCoord[0].xy);
}
