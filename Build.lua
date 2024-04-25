
workspace "TitanEngine"
   architecture "x64"
   configurations { "Debug", "Release"}
   startproject "Game"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "TitanEngine"
	include "TitanEngine/Build-Engine.lua"
group ""

include "Game/Build-Game.lua"