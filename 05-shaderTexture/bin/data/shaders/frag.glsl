#version 150

uniform sampler2D tex0;
uniform vec2 uMousePos;
uniform vec2 uResolution;

in vec2 vTexCoord;
out vec4 outputColor;


void main(){
    vec4 finalColor;
    vec2 coord = vTexCoord;

    finalColor = texture(tex0, uv);
    outputColor = finalColor;
}
