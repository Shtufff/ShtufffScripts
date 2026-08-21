// Written by Shtufff, no Ai was used to make this script.
// My notes may not make sense to you, but it works for me.
// If I have misunderstood how something works, please let me know! 
// I mostly looked at how SCR_EditorRestrictionZoneEntity.c worked, and went from there.

// Huge shout out to "WillowSaysWhat?" on YouTube, and his modding course.

// Creates the class and assigns it a cataegory, and description. I am unsure what color does, but the base script had it.
[EntityEditorProps(category: "GameScripted", description: "SHT Stuff Cleaner", color: "255 0 0 255")]

// Creates my new class        Inherit from this class.
class SHT_CleanerEntityClass : GenericEntityClass
{
};

// Creates my new class   Inherit from this class.
class SHT_CleanerEntity : GenericEntity
{
	//Same as first line, but for the actual spawnable entity.
	[Attribute( defvalue: "20", desc:"Area in meters to delete dropped items", category: "Shtufffs Scripts")]
	protected float m_fCleanRadius;
	
	// ^ Creates variable of type float called m_fCleanRadius
	
	// Convention is to put the first letter of variable type at start.
	
	// v Creates variable of type boolean called m_bItemDetected 
	
	protected bool m_bItemDetected;
	
	
	//Creates  SHT_CleanerEntity, no idea what the brackets do, but all the other code had it.
	void SHT_CleanerEntity(IEntitySource src, IEntity parent)
	{
		//Same with this, I think it checks if SHT_CleanerEntity is initialised? The other code had it.
		SetEventMask(EntityEvent.INIT);
	}
	
	
	// Starts entity cleaner in the console log.
	// Learned to use override when changing functions of variables .
	// Use modded for classes.
	override protected void EOnInit(IEntity owner)
	{	
		// Super runs the original defenition of EOnInit?
		super.EOnInit(owner);
		
		PrintFormat("Cleanup in %1 meters of this point", m_fCleanRadius);
		
		if (m_fCleanRadius <= 0)
			Print("Cannot have a area of 0");
	}
	
	
	
	
	
	
	
	
}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

