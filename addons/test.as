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

class StupidItem : ItemASScript
{

	StupidItem()
	{
		setItemName("jameshi16.dumbitem");
	}

	int useItem(Game @game)
	{
		game.player.setPlayerName("Yuki");
		return 1;
	}
}

void test(Game @game)
{
	//Declares new events and items
	TestEvent te;
	StupidItem si;

	//Add to game
	te.AddToGame();
	si.AddToGame();

	//game.player.addItem(si); //not sure if this will work
	game.player.addItem(game.findItemByName(0, "jameshi16.dumbitem")); //woops. Need to fix the C++ side for this
}