workspace "Game"
	configurations { "Debug", "Release" }
	platforms { "Win32", "Win64" }
	location ("Generated/Build")
	targetdir ("Generated/Bin/%{prj.name}_%{cfg.longname}")
	objdir ("Generated/Obj/%{prj.name}_%{cfg.longname}")
	
	flags "FatalWarnings"
		warnings "Extra"	
	
	filter "configurations:Debug"
		defines { "_DEBUG" }
		symbols "On"
		optimize "Off"
		targetsuffix "_d"
	
	filter "configurations:Release"
		defines { "NDEBUG" }
		symbols "Off"
		optimize "On"
		
	filter "platforms:Win32"
		architecture "x86"
		system "Windows"
		defines { "WIN32" }

	filter "platforms:Win64"
		architecture "x64"
		system "Windows"
	
	filter {}

dofile("asteroids_prj.lua")