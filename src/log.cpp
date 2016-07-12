#include "Log.h"

//Log &nL = *(Log().getMainLoggingInstance()); //gets the first logging instance, I hope

Log::Log(std::string fileName)
{
    /*Here's to issue #2, my eternal friend*/
    boost::filesystem::path p_path(boost::filesystem::current_path().string() + "\\log\\"); //Gets the current path + log folder
    if (!boost::filesystem::exists(p_path)) //If the path does not exist
    {
        boost::filesystem::create_directory(p_path); //This should work. If it doesn't, we don't log at all
    }

    f_file->open(fileName, std::ios::out | std::ios::ate); //opens the file
}

/**
@brief I can write a brief for this? Really? Seriously?
*/
Log* Log::mainLoggingInstance = 0; //initialize is good

/**
@brief Writes a warning to the log with a message.
*/
Log* Log::w(std::string message)
{
    logMutex.lock();
    logWithMessageType(message, "[WARN]");
    logMutex.unlock();
    return this;
}

/**
@brief Writes a warning to the log with a message.
*/
Log* Log::e(std::string message)
{
    logMutex.lock();
    logWithMessageType(message, "[ERROR]");
    logMutex.unlock();
    return this;
}

/**
@brief Writes a normal to the log with a message.
*/
Log* Log::n(std::string message)
{
    logMutex.lock();
    logWithMessageType(message, "[OK]");
    logMutex.unlock();
    return this;
}

/**
@brief Writes a rip to the log with a message
*/
Log* Log::rip(std::string message)
{
    logMutex.lock();
    logWithMessageType(message, "[RIP]");
    logMutex.unlock();
    return this;
}

/**
@brief Writes a debug to the log with a message
*/
Log* Log::d(std::string message)
{
    logMutex.lock();
    if (DEBUGMODE == 1)
        logWithMessageType(message, "[DEBUG]");

    logMutex.unlock();
    return this;
}

/**
@brief Does the loggin' magic
*/
void Log::logWithMessageType(std::string message, std::string type)
{
    *f_file << type << " " << getTime() << ": " << message << std::endl;
}

std::string Log::getTime()
{
    std::stringstream ss;
    ss << boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());
    return ss.str();
}

Log::~Log()
{
    //dtor
}

namespace Loggers
{
    Log &nL = Log::logInstance();
    std::string its(int n_number)
    {
        std::stringstream ss;
        ss << n_number;
        return ss.str();
    }

    std::string its(std::uintptr_t n_number)
    {
        std::stringstream ss;
        ss << n_number;
        return ss.str();
    }
}
