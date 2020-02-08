workspace "SquareFlare"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "SquareFlare"
	location "SquareFlare"
	kind "SharedLib"
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
		"SquareFlare/src"
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
		symbols "On"

		
	filter "configurations:Release"
		defines "SQFL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SQFL_DIST"
		optimize "On"

--	filter { "system:windows", "configurations:Release" }
--		buildoptions "/MT"

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
		"SquareFlare/src"
	}

	links
	{
		"SquareFlare"
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
		symbols "On"

		
	filter "configurations:Release"
		defines "SQFL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SQFL_DIST"
		optimize "On"
	