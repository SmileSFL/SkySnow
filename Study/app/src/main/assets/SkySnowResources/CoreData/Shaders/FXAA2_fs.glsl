#version 300 es
uniform vec2 imageSize;
uniform sampler2D screenTexture;
in vec2 vTexCoord;
out vec4 FragColor;
void main()
{
    vec3 cFXAAParams = vec3(0.4,0.5,0.75);
    float FXAA_Reduce_Min = 1.0/128.0;
    float FXAA_Reduce_Mul = 1.0/8.0;
    float FXAA_Span_Max   = 8.0;

    vec2 posOffset = vec2(1.0/imageSize.x,1.0/imageSize.y) * cFXAAParams.x;

    vec3 rgbNW = texture(screenTexture,vTexCoord + vec2(-posOffset.x,-posOffset.y)).xyz;
    vec3 rgbNE = texture(screenTexture,vTexCoord + vec2(posOffset.x,-posOffset.y)).xyz;
    vec3 rgbSW = texture(screenTexture,vTexCoord + vec2(-posOffset.x,posOffset.y)).xyz;
    vec3 rgbSE = texture(screenTexture,vTexCoord + vec2(posOffset.x,posOffset.y)).xyz;
    vec3 rgbM  = texture(screenTexture,vTexCoord).xyz;

    vec3 luma = vec3(0.299,0.587,0.114);

    float lumaNW = dot(rgbNW,luma);
    float lumaNE = dot(rgbNE,luma);
    float lumaSW = dot(rgbSW,luma);
    float lumaSE = dot(rgbSE,luma);
    float lumaM  = dot(rgbM, luma);

    float lumaMin = min(lumaM,min(min(lumaNW,lumaNE),min(lumaSW,lumaSE)));
    float lumaMax = max(lumaM,max(max(lumaNW,lumaNE),max(lumaSW,lumaSE)));
    if(((lumaMax - lumaMin) / lumaMin) >= cFXAAParams.y)
    {
        vec2 dir;
        dir.x = -((lumaNW + lumaNE) - (lumaSW + lumaSE));
        dir.y = ((lumaNW + lumaSW) - (lumaNE + lumaSE));

        float dirReduce = max((lumaNW + lumaNE + lumaSW + lumaSE) * (0.25 * FXAA_Reduce_Mul),FXAA_Reduce_Min);

        float rcpDirmin = 1.0/(min(abs(dir.x),abs(dir.y) + dirReduce));
        dir = min(vec2(FXAA_Span_Max,FXAA_Span_Max),max(vec2(-FXAA_Span_Max,-FXAA_Span_Max),dir * rcpDirmin)) * (1.0/imageSize);
        dir *= cFXAAParams.z;

        vec3 rgbA = (1.0/2.0) * (texture(screenTexture,vTexCoord + dir * (1.0/3.0 - 0.5)).xyz +
                                 texture(screenTexture,vTexCoord + dir * (2.0/3.0 - 0.5)).xyz);
        vec3 rgbB = rgbA * (1.0/2.0) + (1.0/4.0) * (
                                                    texture(screenTexture,vTexCoord + dir * (0.0/3.0 - 0.5)).xyz +
                                                    texture(screenTexture,vTexCoord + dir * (3.0/3.0 - 0.5)).xyz);
        float lumaB = dot(rgbB,luma);
        vec3 rgbOut;
        if(lumaB < lumaMin || lumaB >lumaMax)
           rgbOut = rgbA;
        else
           rgbOut = rgbB;
        FragColor = vec4(rgbOut,1.0);
    }else{
        FragColor = vec4(rgbM,1.0);
    }
}
