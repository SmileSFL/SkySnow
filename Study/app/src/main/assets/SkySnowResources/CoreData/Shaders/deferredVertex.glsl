#version 300 es
layout(location = 0)in vec4 position;
layout(location = 1)in vec4 normal;
layout(location = 2)in vec4 texCoord;
uniform mat4 uMVPMatix;
uniform mat4 uModelMatix;
out vec2 vTexCoord;
out vec3 vNormal;
out vec3 vPosition;
void main()
{
    gl_Position = uMVPMatix * vec4(position.xyz,1.0);
    vNormal =(uModelMatix * vec4(normal.xyz,1.0)).xyz;
    vPosition = (uModelMatix * vec4(position.xyz,1.0)).xyz;
    vTexCoord = texCoord.xy;
}//