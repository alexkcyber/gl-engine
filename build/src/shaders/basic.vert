#version 460 core

layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;

void main() {
	gl_Position = projection * view * model * vec4(vert, 1.0f);
	Normal = normal;
}
