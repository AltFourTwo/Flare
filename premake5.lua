workspace "Flare"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    defines
    {
        "FLARE_X64"
    }

CommonTargetDir = "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/"
CommonObjDir = "%{wks.location}/b-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/"

-- Include directories relative to root folder -> Solution Directory
IncludeDir = {}
IncludeDir["Utility"] = "Utility/src/"
IncludeDir["GoogleTest"] = "UnitTest/vendor/GoogleTest/googletest/include";
IncludeDir["GoogleMock"] = "UnitTest/vendor/GoogleTest/googlemock/include";
IncludeDir["GLFW"] = "Flare/vendor/GLFW/include"
IncludeDir["Glad"] = "Flare/vendor/Glad/include"
IncludeDir["GLM"] = "Flare/vendor/GLM/"
IncludeDir["ImGui"] = "Flare/vendor/imgui/"

include "UnitTest/vendor/GoogleTest"
include "Flare/vendor/GLFW"
include "Flare/vendor/Glad"
include "Flare/vendor/imgui"

----- FLARE -----
project "Flare"
    location "Flare"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ( CommonTargetDir .. "%{prj.name}/" )
    objdir ( CommonObjDir .. "%{prj.name}/" )
    
    pchheader "FlarePCH.h"
    pchsource "Flare/src/FlarePCH.cpp"
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/GLM/glm/**.hpp",
        "%{prj.name}/vendor/GLM/glm/**.inl"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.Utility}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.GLM}"
    }
    
    links
    {
        "Utility",
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }
    
    filter "system:windows"
        systemversion "latest"
    
        defines
        {
            "FLARE_FOR_WINDOWS",
            "FLARE_DLL",
            "GLFW_INCLUDE_NONE"
        }
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
        
        defines 
        { 
            "FLARE_DEBUG",
        }
    
    filter "configurations:Release"
        defines "FLARE_RELEASE"
        runtime "Release"
        optimize "on"
    
    filter "configurations:Dist"
        defines "FLARE_DIST"
        runtime "Release"
        optimize "on"


----- UTILITY -----
project "Utility"
    location "Utility"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ( CommonTargetDir .. "%{prj.name}" )
    objdir ( CommonObjDir .. "%{prj.name}" )
    
    pchheader "UtilityPCH.h"
    pchsource "Utility/src/UtilityPCH.cpp"
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.GLM}"
    }
    
    libdirs
    {
        "%{prj.name}/src"
    }
    
    filter "system:windows"
        systemversion "latest"
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        runtime "Release"
        optimize "on"
    
    filter "configurations:Dist"
        runtime "Release"
        optimize "on"


----- UNITTEST -----
project "UnitTest"
    location "UnitTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ( CommonTargetDir .. "%{prj.name}" )
    objdir ( CommonObjDir .. "%{prj.name}" )
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "Flare/src",
        "%{IncludeDir.Utility}",
        "%{IncludeDir.GoogleTest}",
        "%{IncludeDir.GoogleTest}/..",
        "%{IncludeDir.GoogleMock}",
        "%{IncludeDir.GoogleMock}/.."
    }
    
    links
    {
        "Flare",
        "Utility",
        "GoogleTest"
    }
    
    filter "system:windows"
        systemversion "latest"
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        runtime "Release"
        optimize "on"


----- SANDBOX -----
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ( CommonTargetDir .. "%{prj.name}" )
    objdir ( CommonObjDir .. "%{prj.name}" )
    
    pchheader "SandboxPCH.h"
    pchsource "Sandbox/src/SandboxPCH.cpp"
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "Flare/src",
        "Flare/vendor",
        "%{IncludeDir.Utility}",
        "%{IncludeDir.GLM}"
    }
    
    links
    {
        "Flare",
        "Utility"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "FLARE_FOR_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FLARE_DEBUG"
        runtime "Debug"
        symbols "on"
        
    filter "configurations:Release"
        defines "FLARE_RELEASE"
        runtime "Release"
        optimize "on"
        
    filter "configurations:Dist"
        defines "FLARE_DIST"
        runtime "Release"
        optimize "on"
