#ifndef EVENT_H
#define EVENT_H

//One should only use the event class by inheriting it
class Event
{
    public:
        Event();
        virtual int ExecuteEvent() = 0; //Use this to execute any event, ever.
        virtual bool canExecute() = 0; //Use this to check if an event is ready to execute
        virtual ~Event();
    protected:

    private:
};

#endif // EVENT_H
