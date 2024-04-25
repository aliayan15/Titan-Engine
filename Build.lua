
workspace "TitanEngine"
   architecture "x64"
   configurations { "Debug", "Release"}
   startproject "Game"


OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "TitanEngine"
	include "TitanEngine/Build-Engine.lua"
group ""

include "Game/Build-Game.lua"