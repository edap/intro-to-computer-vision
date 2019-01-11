#version 150

out vec4 fragColor;
uniform float uTime;
uniform sampler2D tex0;
uniform sampler2D tex1;
uniform sampler2D tex2;
uniform vec2 resolution;

in vec2 vTexCoord;

void main(){
    vec2 coord = vTexCoord;
    // flip the coordinate system vertically
    // try to comment out this line to see what happens
    coord = vec2(coord.x, 1.0 - coord.y);

    vec4 colCam = texture(tex0, coord);
    vec4 colVideo = texture(tex1, coord);
    vec4 mask = texture(tex2, coord);

    vec4 mixed;
    mixed.r = mix(colCam.r, colVideo.r, mask.r);
    mixed.g = mix(colCam.g, colVideo.g, mask.g);
    mixed.b = mix(colCam.b, colVideo.b, mask.b);
    mixed.a = 1;
    fragColor = mixed;
}

