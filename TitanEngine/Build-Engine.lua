project "TitanEngine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"

   files { "Scr/**.h", "Scr/**.cpp" }

   
   targetdir ("../Bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Bin-Int/" .. OutputDir .. "/%{prj.name}")

   includedirs { "vendor/sfml/include" }

   libdirs { "vendor/sfml/lib" }
   links { "opengl32.lib", "freetype.lib", "winmm.lib", "gdi32.lib", "openal32.lib", 
    "flac.lib", "vorbisenc.lib", "vorbisfile.lib", "vorbis.lib", "ogg.lib", "ws2_32.lib" }

   filter "system:windows"
       systemversion "latest"
       defines {"SFML_STATIC" }

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

   