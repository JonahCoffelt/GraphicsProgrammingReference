#version 330 core

uniform sampler2DArray textureArray;
uniform int textureLayer;

in vec2 uv;
in vec3 normal;

out vec4 fragColor;

void main() {
    float light = (1 + dot(normalize(vec3(1, 3, 2)), normal)) / 2.0;
    fragColor = vec4(texture(textureArray, vec3(uv, textureLayer)).rgb * light, 1.0);
} 