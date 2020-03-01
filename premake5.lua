workspace "SquareFlare"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	defines
	{
		"SQFL_X64"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder -> Solution Directory
IncludeDir = {}
IncludeDir["Utility"] = "Utility/src/"
--IncludeDir["GLFW"] = "SquareFlare/vendor/GLFW/include"

--include "SquareFlare/vendor/GLFW"

project "SquareFlare"
	location "SquareFlare"
	kind "SharedLib"
	language "C++"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
	objdir ( "b-int/" .. outputdir .. "/%{prj.name}" )
	
	pchheader "SquareFlarePCH.h"
	pchsource "SquareFlare/src/SquareFlarePCH.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.Utility}"
	}

	links
	{
		"Utility"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQFL_FOR_WINDOWS",
			"SQFL_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SQFL_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		
	filter "configurations:Release"
		defines "SQFL_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SQFL_DIST"
		buildoptions "/MD"
		optimize "On"


project "Utility"
	location "Utility"
	kind "StaticLib"
	language "C++"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
	objdir ( "b-int/" .. outputdir .. "/%{prj.name}" )
	
	pchheader "UtilityPCH.h"
	pchsource "Utility/src/UtilityPCH.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src"
	}

	libdirs
	{
		"%{prj.name}/src",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQFL_FOR_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SQFL_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		
	filter "configurations:Release"
		defines "SQFL_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SQFL_DIST"
		buildoptions "/MD"
		optimize "On"
	

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
	objdir ( "b-int/" .. outputdir .. "/%{prj.name}" )
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SquareFlare/src",
		"%{IncludeDir.Utility}"
	}

	links
	{
		"SquareFlare",
		"Utility"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQFL_FOR_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SQFL_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SQFL_RELEASE"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SQFL_DIST"
		buildoptions "/MD"
		optimize "On"
	
