using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class dedicatedEditorServerTarget : TargetRules   
{
       public dedicatedEditorServerTarget(TargetInfo Target) : base(Target)  
       {
        Type = TargetType.Server;
        ExtraModuleNames.Add("dedicatedEditor");
       }
}