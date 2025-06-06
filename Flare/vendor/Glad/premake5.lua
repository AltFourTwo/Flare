----- GLAD -----
project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir ( CommonTargetDir .. "%{prj.name}" )
    objdir ( CommonObjDir .. "%{prj.name}" )
    
    files 
    {
        "include/glad/glad.h",
        "include/KHR/platform.h",
        "src/glad.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"