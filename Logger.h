#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
#include <mutex>
#include "HelpClass.h"
using namespace std;
//Singleton logger class
class Logger
{
	static Logger* instance;
	static ofstream logfile;
	static mutex mu;
	static const std::string fileName;
	Logger() = default;
public:
	
	static Logger* getInstance();

	void LogErrorOnConsole(const char* format, ...);
	void LogWarningOnConsole(const char* format, ...);
	void LogInfoOnConsole(const char* format, ...);
	void LogError(const char* format, ...);
	void LogWarning(const char* format, ...);
	void LogInfo(const char* format, ...);
	char* Log(const char* format, ...);

	void LogWarningOnConsole(std::string& data);
	void LogInfoOnConsole(std::string& data);
	void LogErrorOnConsole(std::string& data);
	void LogError(const std::string& data);
	void LogWarning(const std::string& data);
	void LogInfo(const std::string& data);
	void Log(const std::string& sMessage);
	
	Logger& operator<<(const string& sMessage);

	//deleted functions
	Logger (const Logger& obj) = delete;//copy cons
	Logger& operator=(const Logger& obj) = delete;//assignment

	static void count();
};
