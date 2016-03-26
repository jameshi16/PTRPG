#ifndef LOG_H
#define LOG_H

#include <string>
#include <sstream>
#include <fstream>

#include <boost/date_time.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread/mutex.hpp>

#define DEBUGMODE 1 //change this to 1 for debug

class Log
{
    public:
        Log(std::string);

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

        virtual ~Log();

    protected:

    private:
        std::ofstream *f_file = new std::ofstream();
        std::string getTime();

        boost::mutex logMutex;

        ///Was lazy
        void logWithMessageType(std::string, std::string);
};

namespace Loggers
{
    static Log normalLogger(boost::filesystem::current_path().string() +"\\log" + boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time()) + ".log");
};



#endif // LOG_H
