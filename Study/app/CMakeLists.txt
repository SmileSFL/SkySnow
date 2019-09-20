cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions("-DGLM_FORCE_SIZE_T_LENGTH -DGLM_FORCE_RADIANS")

SET(Source_Code_Dir "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp")
SET(Common_Code_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../SourceCode")
SET(ThirdParty_Code_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../SourceCode/ThirdParty")


file(GLOB sourceCode    "${Source_Code_Dir}/*.cpp"
                        "${Common_Code_dir}/Application/*.cpp"
                        "${Common_Code_dir}/Common/*.cpp"
                        "${Common_Code_dir}/Sample/*.cpp"
                        "${Common_Code_dir}/Sample/DeferredRendering/*.cpp"
                        "${Common_Code_dir}/RunTime/*.cpp"
                        "${Common_Code_dir}/RunTime/IO/*.cpp"
                        "${Common_Code_dir}/RunTime/CoreShader/*.cpp"
                        "${Common_Code_dir}/RunTime/CoreTexture/*.cpp"
                        "${Common_Code_dir}/RunTime/CoreObject/*.cpp"
                        "${Common_Code_dir}/RunTime/CoreBuffer/*.cpp"
                        "${Common_Code_dir}/RunTime/CoreScene/*.cpp"
                        "${Common_Code_dir}/RunTime/Renderer/*.cpp"
                        "${Common_Code_dir}/RunTime/RHI/*.cpp"
                        "${Common_Code_dir}/RunTime/RHI/GLES3/*.cpp"
                        "${Common_Code_dir}/RunTime/RHI/Thread/*.cpp"
                        "${ThirdParty_Code_dir}/glm/*.cpp"
                        "${ThirdParty_Code_dir}/glm/detail/*.cpp"
                        "${ThirdParty_Code_dir}/glm/gtc/*.cpp"
                        "${ThirdParty_Code_dir}/glm/gtx/*.cpp"
                        "${ThirdParty_Code_dir}/stbImage/*.cpp"
    )

add_library(GLESRenderer SHARED ${sourceCode})

target_include_directories( GLESRenderer PRIVATE $<BUILD_INTERFACE:${Source_Code_Dir}/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/Application/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/Common/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/Sample/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/Sample/DeferredRendering/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/IO/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/CoreBuffer/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/CoreScene/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/CoreShader/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/CoreTexture/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/CoreObject/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/Renderer/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/RHI/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/RHI/GLES3/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/RunTime/RHI/Thread/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${Common_Code_dir}/Sample/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${ThirdParty_Code_dir}/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${ThirdParty_Code_dir}/glm/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${ThirdParty_Code_dir}/glm/gtc/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${ThirdParty_Code_dir}/glm/gtx/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${ThirdParty_Code_dir}/glm/detail/>
                            GLESRenderer PRIVATE $<BUILD_INTERFACE:${ThirdParty_Code_dir}/stbImage/>
                           )


target_link_libraries(   GLESRenderer
                         android
                         GLESv3
                         log
                      )