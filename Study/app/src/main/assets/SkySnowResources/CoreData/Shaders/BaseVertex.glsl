#version 300 es
in vec4 iPos;
in vec3 iNormal;
in vec2 iTexCoord;
uniform mat4 cMadel;
uniform mat4 cView;
uniform mat4 cViewProj;
out vec3 vNormal;
out vec2 vTexCoord;
void main()
{
    gl_Position = cViewProj * cView * cMadel * vec4(iPos.xyz,1.0);
    vTexCoord = iTexCoord;
    vNormal = vec3(1.0) * iNormal;
}//