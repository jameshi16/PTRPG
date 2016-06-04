#ifndef LOG_H
#define LOG_H

#include <string>
#include <sstream>
#include <fstream>
#include <cstdint>

#include <boost/date_time.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

#define DEBUGMODE 1 //change this to 1 for debug

class Log
{
    public:

        ///Write a warning to the file. (I can still fix myself)
        Log* w(std::string);
        ///Write an error to the file. (I might still be able to proceed)
        Log* e(std::string);
        ///Write a Rest In Peace to the file. (I'm dead lol)
        Log* rip(std::string);
        ///Normal
        Log* n(std::string);

        ///Debug message
        Log* d(std::string);

        ///Logger class revamped
        static Log& logInstance()
        {
            if (!mainLoggingInstance)
                mainLoggingInstance = new Log((std::string)(boost::filesystem::current_path().string() +"\\log\\log" + boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time()) + ".log"));

            return *mainLoggingInstance;
        }

        Log& operator=(const Log&); //don't implement

    protected:
        Log(std::string);
        virtual ~Log();

    private:
        std::ofstream *f_file = new std::ofstream();
        std::string getTime();

        ///This is the first logging instance. A hack to solve issue #8
        static Log *mainLoggingInstance;
        boost::mutex logMutex;


        ///Was lazy
        void logWithMessageType(std::string, std::string);
};

namespace Loggers
{
    extern Log &nL;
    extern std::string its(int);
    extern std::string its(std::uintptr_t);
};



#endif // LOG_H
