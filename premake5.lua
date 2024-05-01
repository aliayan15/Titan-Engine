
workspace "TitanEngine"
   architecture "x64"
   configurations { "Debug", "Release"}
   startproject "Game"


OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "TitanEngine"
	include "TitanEngine/Build-Engine.lua"
group ""

include "Game/Build-Game.lua"

newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries, and vs files.",
    execute = function()
        print("Removing binaries")
        os.remove("./bin/**.exe")
        os.remove("./bin/**.pdb")
        os.rmdir("./Bin/windows-x86_64/Debug/TitanEngine")
        os.rmdir("./Bin/windows-x86_64/Release/TitanEngine")
        print("Removing intermediate binaries")
        os.rmdir("./bin-int")
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
    }