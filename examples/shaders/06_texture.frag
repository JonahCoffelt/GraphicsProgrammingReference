#version 330 core

in vec2 uv;

out vec4 fragColor;

uniform sampler2D texture1;

void main() {
    fragColor = vec4(texture(texture1, uv).rgb, 1.0);
} 