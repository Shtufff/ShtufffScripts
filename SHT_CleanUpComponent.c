// Written by Shtufff, no Ai was used to make this script.
// My notes may not make sense to you, but it works for me.
// If I have misunderstood how something works, please let me know! 
// I mostly looked at how SCR_EditorRestrictionZoneEntity.c worked, and went from there.

// Huge shout out to "WillowSaysWhat?" on YouTube, and his modding course.

// Same as the Entity creation but just fot a component class.
[ComponentEditorProps(category: "Shtufff Cleaner", description: "Component for cleaning, needs SHT_CleanerEntity")]
class SHT_CleanerComponentClass : ScriptComponentClass
{
}

// Creates new class         Inherit from this class.
class SHT_CleanerComponent : ScriptComponent
{
	override void OnPostInit(IEntity owner)
	{
		super.OnPostInit(owner);
		
		SetEventMask(owner, EntityEvent.INIT);
		
		Print("OwO my component is working");
	
	}
}

