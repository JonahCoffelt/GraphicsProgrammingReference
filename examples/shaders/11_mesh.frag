#version 330 core

uniform sampler2D texture1;

in vec2 uv;

out vec4 fragColor;

void main() {
    fragColor = vec4(texture(texture1, uv).rgb, 1.0);
} 