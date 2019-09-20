#version 300 es
layout(location = 0)in vec4 position;
layout(location = 1)in vec4 texCoord;
out vec2 vTexCoord;
void main()
{
    gl_Position = vec4(position.xy,0.0,1.0);
    vTexCoord = texCoord.xy;
}
