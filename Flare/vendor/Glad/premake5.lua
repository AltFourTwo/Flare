----- GLAD -----
project "Glad"
    kind "StaticLib"
    language "C"

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
        staticruntime "On"
        systemversion "latest"

    filter { "system:windows", "configurations:Release" }
    buildoptions "/MT"