workspace "Ballz"
	configurations { "Debug", "Release" }

project "ballz"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	targetdir "bin/"

	files { "ballz/**.hpp", "ballz/**.cpp" }
	links { "SDL2" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

project "hello_ballz"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++20"
	targetdir "projects/"

	files { "hello_ballz/**.hpp", "hello_ballz/**.cpp" }
	links { "ballz", "SDL2" }
	includedirs { "ballz" }

