#version 150

uniform mat4 modelViewProjectionMatrix;
uniform float uTime;

in vec4 position;
in vec2 texcoord;

out vec2 vTexCoord;

void main() {
    vTexCoord = texcoord;
    vec4 modPos = position;
    //modPos.x += sin(uTime* 6.) * 30.;
    gl_Position = modelViewProjectionMatrix * modPos;
}
