[EntityEditorProps(category: "GameScripted", description: "SHT Death Zone", color: "255 0 0 255")]
class SHT_DeathZoneEntityClass : GenericEntityClass
{
};

class SHT_DeathZoneEntity : GenericEntity
{
	[Attribute("12", desc: "Distance where warning starts")]
	protected float m_fWarnRadius;
	
	[Attribute("24", desc: "Distance where player dies")]
	protected float m_fZoneRadius;
	
	
	// --------------------------------------------------
	// Constructor
	// --------------------------------------------------
	void SHT_DeathZoneEntity(IEntitySource src, IEntity parent)
	{
		SetEventMask(EntityEvent.INIT);
	}
	
	
	// --------------------------------------------------
	// Called when entity starts
	// --------------------------------------------------
	override protected void EOnInit(IEntity owner)
	{
		super.EOnInit(owner);
		
		Print("SHT DEATH ZONE INITIALISED");
		
		if (m_fZoneRadius <= 0)
			m_fZoneRadius = 24;
		
		if (m_fWarnRadius > m_fZoneRadius)
			m_fWarnRadius = m_fZoneRadius;
		
		// Check players every 500 milliseconds
		GetGame().GetCallqueue().CallLater(CheckPlayers, 500, true);
	}
	
	
	// --------------------------------------------------
	// Check every connected player
	// --------------------------------------------------
	protected void CheckPlayers()
	{
		PlayerManager playerManager = GetGame().GetPlayerManager();
		
		if (!playerManager)
			return;
		
		array<int> playerIds = {};
		playerManager.GetPlayers(playerIds);
		
		vector zonePosition = GetOrigin();
		
		foreach (int playerId : playerIds)
		{
			IEntity player = playerManager.GetPlayerControlledEntity(playerId);
			
			if (!player)
				continue;
			
			vector playerPosition = player.GetOrigin();
			
			float distance = vector.Distance(zonePosition, playerPosition);
			
			Print("Distance from zone: " + distance);
			
			if (distance >= m_fZoneRadius)
			{
				Print("PLAYER OUTSIDE DEATH ZONE");
				KillPlayer(player);
			}
			else if (distance >= m_fWarnRadius)
			{
				Print("WARNING - RETURN TO AREA");
			}
		}
	}
	
	
	// --------------------------------------------------
	// Kill player
	// --------------------------------------------------
	protected void KillPlayer(IEntity player)
	{
		SCR_DamageManagerComponent damageManager;
		
		damageManager = SCR_DamageManagerComponent.GetDamageManager(player);
		
		if (!damageManager)
			return;
		
		damageManager.SetHealthScaled(0);
	}
	
	
	// --------------------------------------------------
	// Clean up our repeating function
	// --------------------------------------------------
	void ~SHT_DeathZoneEntity()
	{
		if (GetGame())
			GetGame().GetCallqueue().Remove(CheckPlayers);
	}
};