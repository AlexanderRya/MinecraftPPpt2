#version 460 core
layout (location = 0) in vec3 ivtx;
layout (location = 1) in vec2 itx_coords;
layout (location = 2) in vec3 offsets;

out vec2 tx_coords;

uniform mat4 pv_mat;
uniform mat4 model;

void main() {
    gl_Position = pv_mat * model * vec4(ivtx + offsets, 1.0);
}
