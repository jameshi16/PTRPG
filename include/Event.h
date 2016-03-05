#ifndef EVENT_H
#define EVENT_H

//One should only use the event class by inheriting it
class Event
{
    public:
        Event();
        virtual int ExecuteEvent(); //Use this to execute any event, ever.
        virtual ~Event();
    protected:

    private:
};

#endif // EVENT_H
