#version 460 core

uniform sampler2D sampler;

in vec2 tx_coords;
out vec3 color;

void main() {
    color = vec3(1.0f);
}