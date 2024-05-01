project "Game"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Scr/**.h", "Scr/**.cpp" }

   targetdir ("../Bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Bin-Int/" .. OutputDir .. "/%{prj.name}")

   includedirs
   {
      "Scr",

	  -- Include Core
	  "../TitanEngine/Scr",
      "../TitanEngine/vendor/sfml/include"
   }


   libdirs 
   {    
       "../TitanEngine/vendor/sfml/lib",
       "../" 
   }

   links { "TitanEngine","opengl32.lib", "freetype.lib", "winmm.lib", "gdi32.lib", "openal32.lib", 
    "flac.lib", "vorbisenc.lib", "vorbisfile.lib", "vorbis.lib", "ogg.lib", "ws2_32.lib" }


   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS", "SFML_STATIC" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
       links { "sfml-audio-s-d.lib", "sfml-graphics-s-d.lib",
        "sfml-network-s-d.lib", "sfml-system-s-d.lib", "sfml-window-s-d.lib" }

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "Off"
       links { "sfml-audio-s.lib", "sfml-graphics-s.lib",
         "sfml-network-s.lib", "sfml-system-s.lib", "sfml-window-s.lib" }

   