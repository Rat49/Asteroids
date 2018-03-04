-----------------------------------------------------------------------------------------------------------------------------------------------------
workspace "Game"
	configurations { "Debug", "Release" }
-----------------------------------------------------------------------------------------------------------------------------------------------------
project "Asteroids"
	kind "WindowedApp"
	language "C++"
	characterset "MBCS"
   
	filter { "platforms:Win32" }
		system "Windows"
		architecture "x86"
		defines { "WIN32" }

	filter { "platforms:Win64" }
		system "Windows"
		architecture "x64"
		
	local libPostfix = "";
	filter { "configurations:Debug" }
		libPostfix = "-d"
		
	local SourceDir = "Asteroids/Source/";

	files
	{
		SourceDir .. "**.h",
		SourceDir .. "**.cpp"
	}
   
	vpaths
	{
	   ["Header Files/*"] = { SourceDir .. "**.h" },
	   ["Source Files/*"] = { SourceDir .. "**.cpp" },
	}
	
	includedirs
	{
		SourceDir .. "/../SFML/%{cfg.longname}/include"
	}
	
	libdirs
	{
	}
	
	links
	{
		"opengl32.lib",
		"freetype.lib",
		"jpeg.lib",
		"ws2_32.lib",
		"winmm.lib",
		"openal32.lib",
		"gdi32.lib",
		"sfml-window-s" .. libPostfix .. ".lib",
		"sfml-system-s" .. libPostfix .. ".lib",
		"sfml-graphics-s" .. libPostfix .. ".lib",
		"sfml-audio-s" .. libPostfix .. ".lib",
		"sfml-network-s" .. libPostfix .. ".lib"
	}
-----------------------------------------------------------------------------------------------------------------------------------------------------