#version 330 core

uniform sampler2D uTexture;

in vec2 uv;
in vec3 normal;

out vec4 fragColor;

void main() {
    fragColor = vec4(texture(uTexture, uv).rgb * normal, 1.0);
} 