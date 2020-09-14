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
	kind "SharedLib"
	language "C++"
	staticruntime "Off"
	
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
		cppdialect "C++17"
		systemversion "latest"
	
		defines
		{
			"FLARE_FOR_WINDOWS",
			"FLARE_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"" .. CommonTargetDir .. "Sandbox/\"")
		}
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

		defines 
		{ 
			"FLARE_DEBUG",
		}
	
	filter "configurations:Release"
		defines "FLARE_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		defines "FLARE_DIST"
		runtime "Release"
		optimize "On"
	
	----- UTILITY -----
project "Utility"
	location "Utility"
	kind "StaticLib"
	language "C++"
	staticruntime "Off"
	
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
		cppdialect "C++17"
		systemversion "latest"
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		runtime "Release"
		optimize "On"
	
	
----- UNITTEST -----
project "UnitTest"
	location "UnitTest"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"
	
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
		cppdialect "C++17"
		systemversion "latest"
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		runtime "Release"
		optimize "On"
	
	
	----- SANDBOX -----
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"
	
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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"FLARE_FOR_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FLARE_DEBUG"
		runtime "Debug"
		symbols "On"
		
		filter "configurations:Release"
		defines "FLARE_RELEASE"
		runtime "Release"
		optimize "On"
		
		filter "configurations:Dist"
		defines "FLARE_DIST"
		runtime "Release"
		optimize "On"
