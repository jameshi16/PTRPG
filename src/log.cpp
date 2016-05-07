#include "Log.h"

Log::Log(std::string fileName)
{
    f_file->open(fileName, std::ios::out); //opens the file
}

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
