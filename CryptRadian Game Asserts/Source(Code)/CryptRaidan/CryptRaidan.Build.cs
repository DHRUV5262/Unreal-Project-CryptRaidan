// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CryptRaidan : ModuleRules
{
	public CryptRaidan(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
