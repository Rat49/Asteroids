workspace "Game"
	configurations { "Debug", "Release" }
	platforms { "Win32", "x64" }
	location ("Generated/Proj")
	targetdir ("Generated/Bin/%{prj.name}_%{cfg.platform}")
	objdir ("Generated/Obj/%{prj.name}")
	
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

	filter "platforms:x64"
		architecture "x64"
		system "Windows"
	
	filter {}

dofile("asteroids_prj.lua")