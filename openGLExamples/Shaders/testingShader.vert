#version 400

in vec3 vertex_position;
in vec3 vertex_colour;

uniform mat4 matrix;

out vec3 colour;

void main() {
    gl_Position = matrix * vec4(vertex_position, 1.0);
    colour = vertex_colour;
}