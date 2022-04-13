workspace "Dollop"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Dollop/src",
		"Dollop/vendor/spdlog/include"
	}

	links
	{
		"Dollop"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DP_PLATFORM_WINDOWS",
			"_MBCS"
		}

	filter "configurations:Debug"
		defines "DP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DP_DIST"
		optimize "On"

project "Dollop"
	location "Dollop"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DP_PLATFORM_WINDOWS",
			"DP_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DP_DIST"
		optimize "On"
