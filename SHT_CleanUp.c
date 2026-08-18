[EntityEditorProps(category: "GameScripted", description: "SHT Stuff Cleaner", color: "255 0 0 255")]
class SHT_CleanerEntityClass : GenericEntityClass
{
};

class SHT_CleanerEntity : GenericEntity
{
	[Attribute(category: "Shtufff Scripts", desc: "Distance where warning starts", UIWidgets.EditBox, "Area in meters to delete dropped items")]
	protected float m_fCleanRadius;
	
	void SHT_CleanerEntity(IEntitySource src, IEntity parent)
	{
		SetEventMask(EntityEvent.INIT);
	}
	
	
	// starts entity in the console log.
	override protected void EOnInit(IEntity owner)
	{
		super.EOnInit(owner);
		
		PrintFormat("Cleanup in %1 meters of this point", m_fCleanRadius);
		
		if (m_fCleanRadius <= 0)
			Print("Cannot have a area of 0");	
	}
}