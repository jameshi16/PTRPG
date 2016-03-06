#ifndef EVENTCHANGEPLAYERNAME_H
#define EVENTCHANGEPLAYERNAME_H

#include "Event.h"

class EventChangePlayerName: public Event
{
    public:
        EventChangePlayerName();
        virtual int ExecuteEvent(); //implement the execute event
        virtual bool canExecute(); //implement the can execute
        virtual ~EventChangePlayerName();

    protected:

    private:
};

#endif // EVENTCHANGEPLAYERNAME_H
