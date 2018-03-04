-----------------------------------------------------------------------------------------------------------------------------------------------------
project "Asteroids"
	kind "WindowedApp"
	language "C++"
	characterset "MBCS"    
    defines { "SFML_STATIC" }
	
	local SourceDir = "../Source/";

	files
	{
		SourceDir .. "**.h",
		SourceDir .. "**.cpp",
	}
   
	vpaths
	{
	   ["Header Files/*"] = { SourceDir .. "**.h" },
	   ["Source Files/*"] = { SourceDir .. "**.cpp" },
	}
    
    postbuildcommands
    {
        "{COPY} %{wks.location}/../../../SFML/%{cfg.platform}/bin/openal32.dll %{cfg.targetdir}"
    }
    
	includedirs
	{
		SourceDir .. "/../SFML/%{cfg.platform}/include"
	}
	
	libdirs
	{
		SourceDir .. "/../SFML/%{cfg.platform}/lib"
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
    }
    
    filter { "configurations:Debug" }
        links
        {
            "sfml-window-s-d.lib",
            "sfml-system-s-d.lib",
            "sfml-graphics-s-d.lib",
            "sfml-audio-s-d.lib",
            "sfml-network-s-d.lib"
        }
        
    filter { "configurations:Release" }
        links
        {
            "sfml-window-s.lib",
            "sfml-system-s.lib",
            "sfml-graphics-s.lib",
            "sfml-audio-s.lib",
            "sfml-network-s.lib"
        }
-----------------------------------------------------------------------------------------------------------------------------------------------------