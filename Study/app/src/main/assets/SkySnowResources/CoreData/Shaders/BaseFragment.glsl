#version 300 es
uniform sampler2D sDiffuseMap;
uniform vec4 cColor;
in vec2 vTexCoord;
in vec3 vNormal;
out vec4 fragColor;
void main()
{
    vec3 usenormal = vNormal;
    vec2 nTexCoor = vec2(1.0 - vTexCoord.x,1.0 - vTexCoord.y);
    vec4 color = texture(sDiffuseMap,nTexCoor);
    fragColor = color;//vec4(1.0,0.3,0.7,1.0);
}//