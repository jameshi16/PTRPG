#include "dependency.as"

class TestEvent : EventASScript
{
   int ExecuteEvent(Game @game)
	{
     game.player.setPlayerName("It really works!");
	 return 1;
	}

	bool canExecute(Game @game)
	{
		if (game.player.getPlayerName() == "Yuki")
		{
		return true;
		}
		return false;
		}
}

void test()
{
  TestEvent te;
  te.AddToGame();
}