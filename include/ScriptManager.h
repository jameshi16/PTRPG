#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H
#include <angelscript.h>
/*
This class will not be used as of yet, until I manage to grasp AngelScript's C++ interface
I have no idea why I'm pushing it to the master branch, but ya' know
*/

class ScriptManager
{
    public:
        ScriptManager();

        void WrapGame(asIScriptEngine);
        void WrapItem(asIScriptEngine);
        void WrapEvent(asIScriptEngine);

        static void MessageCallback(const asSMessageInfo*, void*); //Apparently it's good to have a MessageCallback function to check if there are errors
        static void scriptTest(); //tests if the script can contact ScriptManager, and vice-versa

        void loadScripts(vector<string>);

        virtual ~ScriptManager();

    protected:

    private:
};

#endif // SCRIPTMANAGER_H
