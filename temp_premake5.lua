----- UNITTEST -----
project "UnitTest"
	location "UnitTest"
	kind "StaticLib"
	language "C++"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
	objdir ( "b-int/" .. outputdir .. "/%{prj.name}" )

	pchheader "UnitTestPCH.h"
	pchsource "UnitTest/src/UnitTestPCH.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"SquareFlare/src",
		"%{IncludeDir.Utility}",
		"%{IncludeDir.GoogleTest}",
		"%{IncludeDir.GoogleMock}"
	}

	libdirs
	{
		"%{prj.name}/src"
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


----- GOOGLETEST -----
project "GoogleTest"
	location "UnitTest/vendor/GoogleTest"
	kind "ConsoleApp"
	language "C++"

	targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
	objdir ( "b-int/" .. outputdir .. "/%{prj.name}" )

	files 
	{
		"%{prj.location}/googletest/src/gtest-all.cc",
		"%{prj.location}/googlemock/src/gmock-all.cc"
	}

	includedirs
	{
		"%{prj.location}/googletest",
		"%{prj.location}/googlemock",
		"%{IncludeDir.GoogleTest}",
		"%{IncludeDir.GoogleMock}",
	}

	links 
	{
		"UnitTest"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "GTEST_ENABLE_CATCH_EXCEPTIONS_"
		buildoptions "/MDd /bigobj"
		symbols "On"

	filter "configurations:Release"
		buildoptions "/MD"
		optimize "On"
		
	filter "configurations:Dist"
		buildoptions "/MD"
		optimize "On"