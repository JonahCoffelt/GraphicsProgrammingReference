#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_uv;

uniform mat4 transform;

out vec2 uv;

void main() {
    uv = in_uv;
    gl_Position = transform * vec4(in_position, 1.0);
}