varying float height;
varying vec4 color;

void main()
{
	gl_FragColor = (height+0.5) * color;
}