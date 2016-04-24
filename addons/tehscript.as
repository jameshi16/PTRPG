shared abstract class EventASScript
{
	EventASScript()
	{
		//Creates the C++ side of the proxy
		@m_obj = EventASScript_t();
	}
	
	int ExecuteEvent(Game @game) {m_obj.ExecuteEvent(game); return 1;}
	bool canExecute(Game @game) {m_obj.canExecute(game); return true;}
	
	EventASScript_t @opImplCast() { return m_obj; }
	
	private EventASScript_t @m_obj;
}

class MagicClass : EventASScript
{
	int ExecuteEvent (Game @game)
	{
		game.player.setPlayerName("Superman");
		return 1;
	}
	bool canExecute(Game @game)
	{
		return true;
	}
}

void main()
{
	MagicClass mc;
}