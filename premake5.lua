workspace "CDataStructs"
    architecture "x86"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--C Data Structures
project "CDataStructs"
    location "CDataStructs"
    kind "StaticLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/includes/**.h",
        "%{prj.name}/src/**.c",
    }

    includedirs
    {
        "CDataStructs/includes"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"
    
    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"

        --test bed for the structures
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

        files 
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.c",
        }
        
        includedirs
        {
            "CDataStructs/includes"
        }
        
        links
        {
            "CDataStructs"
        }
    
        filter "system:windows"
            staticruntime "On"
            systemversion "latest"
        
        filter "configurations:Debug"
            symbols "On"
        
        filter "configurations:Release"
            optimize "On"
        
        filter "configurations:Dist"
            optimize "On"