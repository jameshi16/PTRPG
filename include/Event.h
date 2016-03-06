#ifndef EVENT_H
#define EVENT_H

//Forward declaration
class Game;

//One should only use the event class by inheriting it
class Event
{
    public:
        Event();
        virtual int ExecuteEvent(Game*) = 0; //Use this to execute any event, ever.
        virtual bool canExecute(Game*) = 0; //Use this to check if an event is ready to execute
        virtual ~Event();
    protected:

    private:
};

#endif // EVENT_H
