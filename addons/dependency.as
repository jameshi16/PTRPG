shared abstract class EventASScript
{
	EventASScript()
	{
		//Creates the C++ side of the proxy
		@m_obj = EventASScript_t();
	}
	
	int ExecuteEvent(Game @game) {m_obj.ExecuteEvent(game); return 1;}
	bool canExecute(Game @game) {m_obj.canExecute(game); return true;}
	
	void AddToGame() {m_obj.AddToGame();}

	bool Continuous
	{
		get {return m_obj.Continuous;}
		set {m_obj.Continuous = value;}
	}
	
	EventASScript_t @opImplCast() { return m_obj; }
	
	private EventASScript_t @m_obj;
}

shared abstract class ItemASScript
{
	ItemASScript()
	{
		//Creates the C++ side of the proxy
		@m_obj = ItemASScript_t();
	}
	
	int useItem(Game @game) {m_obj.useItem(game); return 1;}
	string setItemName(string s) {return m_obj.setItemName(s);}
	string getItemName() {return m_obj.getItemName();}
	
	void AddToGame() {m_obj.AddToGame();}
	
	ItemASScript_t @opImplCast() { return m_obj; }
	
	private ItemASScript_t @m_obj;
}

shared abstract class ASSkill
{
	ASSkill()
	{
		//Creates the C++ side of the proxy
		@m_obj = ASSkill_t();
	}

	int useItem(Game @game) {m_obj.useSkill(game); return 1;}

	void AddToGame() { m_obj.AddToGame(); }
	string setSkillName(string s) { return m_obj.setSkillName(s); }
	string getSkillName() { return m_obj.getSkillName();}

	ASSkill_t @opImplCast() { return m_obj; }

	private ASSkill_t @m_obj;
}

void jameshi16_dependency_90937917(Game @game)
{
	//I coded it in such a way that all the scripts need to have one master function
}