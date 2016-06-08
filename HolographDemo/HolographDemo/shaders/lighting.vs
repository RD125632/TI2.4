uniform float time;

varying float height;
varying vec4 color;

void main()
{
	height = 0.25 * sin(gl_Vertex.x + time*2.0) + 0.35 * sin(gl_Vertex.x) * sin(gl_Vertex.z*.5 + time*.25) + 0.025 * sin(gl_Vertex.z*15.0+gl_Vertex.x*75.0 + time*.15);
	vec4 offset = vec4(0, height,0,0);

	color = gl_Color;

	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * (gl_Vertex + offset);
}