// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Practies001 : ModuleRules
{
	public Practies001(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore" ,
			"NavigationSystem",
			"AIModule"
		});

		PublicIncludePaths.Add(ModuleDirectory);


	}
}
