#ifndef EVENTCHANGEPLAYERNAME_H
#define EVENTCHANGEPLAYERNAME_H

#include "Event.h"

class EventChangePlayerName: public Event
{
    public:
        EventChangePlayerName();
        virtual int ExecuteEvent(Game*); //implement the execute event
        virtual bool canExecute(Game*); //implement the can execute
        virtual ~EventChangePlayerName();

    protected:

    private:
};

#endif // EVENTCHANGEPLAYERNAME_H
