local sdk_version = os.getWindowsRegistry( "HKLM:SOFTWARE\\Wow6432Node\\Microsoft\\Microsoft SDKs\\Windows\\v10.0\\ProductVersion" ) .. ".0"

-----------------------------------------------------------------------------------------------------------------------------------------------------	
workspace ("Asteroids")
	configurations { "Debug", "Release" }
	platforms { "x64" }
	location ( "../Generated/Projects" )
	targetdir ( "../Generated/Bin" )
	objdir ( "../Generated/Obj/%{prj.name}" )
	
	flags ("FatalWarnings")
		warnings ("Extra")
        
	filter ("configurations:Debug")
		defines { "_DEBUG" }
		symbols ("On")
		optimize ("Off")
		targetsuffix ("_d")
	
	filter ("configurations:Release")
		defines { "NDEBUG" }
		symbols ("Off")
		optimize ("On")
		
	filter ("platforms:x64")
		architecture ("x64")
		system ("Windows")
	
	filter {}

-----------------------------------------------------------------------------------------------------------------------------------------------------
	project ("Asteroids")
		kind ("WindowedApp")
		systemversion (sdk_version)
		language ("C++")
		characterset ("MBCS")
		
		defines
		{
			"SFML_STATIC",
			"ENGINE_STATIC",
			"_WINDOWS"
		}
		
		local SourceDir = "../Source";

		files
		{
			SourceDir .. "/**.h",
			SourceDir .. "/**.cpp",
		}
	   
		vpaths
		{
			["Engine/*"] = 
		    {
				SourceDir .. "/Engine/**.cpp",
				SourceDir .. "/Engine/**.h",
			},
			["Game/*"] = 
			{
				SourceDir .. "/Game/**.cpp",
				SourceDir .. "/Game**.h",
			},
		}
		
		postbuildcommands
		{
			'{COPY} "$(SFML_ROOT)/bin/openal32.dll" "%{cfg.targetdir}/*.*"',
			'{COPY} "%{wks.location}../' .. SourceDir .. '/Images" "%{cfg.targetdir}/Resources/*.*"',
		}
		
		includedirs
		{
			"$(SFML_ROOT)/include",
			SourceDir,
		}
		
		libdirs
		{
			"$(SFML_ROOT)/lib"
		}
		
		
		links
		{
			"opengl32.lib",
			"freetype.lib",
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