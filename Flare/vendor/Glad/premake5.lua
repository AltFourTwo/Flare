----- GLAD -----
project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "Off"

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

    filter { "system:windows", "configurations:Release" }
        runtime "Release"