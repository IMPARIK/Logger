// Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Logger.h"
const string Logger::fileName = "Log.txt";
Logger* Logger::instance = nullptr;
std::mutex Logger::mu;
ofstream Logger::logfile;


Logger* Logger::getInstance()
{
	if (instance == nullptr) {
		lock_guard<mutex> lock(mu);
		if (instance == nullptr) {
			instance = new Logger();
			logfile.open(fileName.c_str(), ios::out | ios::app);
		}
	}
	return instance;
}

void Logger::LogError(const char* format, ...)
{	
	char * msg = Log(format);	
	logfile << HelpClass::CurrentDateTime() << ":\t";
	logfile << "[ERROR]:"<< msg << "\n";
}
void Logger::LogWarning(const char* format, ...)
{
	char* msg = Log(format);
	logfile << HelpClass::CurrentDateTime() << ":\t";
	logfile << "[WARNING]:" << msg << "\n";
}
void Logger::LogInfo(const char* format, ...)
{
	char* msg = Log(format);
	string msg1 = msg;
	logfile << HelpClass::CurrentDateTime() << ":\t";
	logfile << "[INFO]:" << msg << "\n";
	//print(msg1);
}
void Logger::LogErrorOnConsole(const char* format, ...)
{
	char* msg = Log(format);
	cout << HelpClass::CurrentDateTime() << "  " <<"[ERROR]:" << msg << endl;
}
void Logger::LogWarningOnConsole(const char* format, ...)
{
	char* msg = Log(format);
	cout << HelpClass::CurrentDateTime() << "  " << "[WARNING]:" << msg << endl;
}
void Logger::LogInfoOnConsole(const char* format, ...)
{
	char* msg = Log(format);
	cout << HelpClass::CurrentDateTime() << "  " << "[INFO]:" << msg << endl;
}
void Logger::LogErrorOnConsole(std::string& data)
{
	cout << HelpClass::CurrentDateTime() << "  " <<"[ERROR]:" << data << endl;
}
void Logger::LogWarningOnConsole(std::string& data)
{
	cout << HelpClass::CurrentDateTime() << "  " << "[WARNING]:"<<  data << endl;
}
void Logger::LogInfoOnConsole(std::string& data)
{
	cout << HelpClass::CurrentDateTime() << "  " << "[INFO]:" << data << endl;
}
void Logger::LogError(const string& sMessage)
{
	logfile << HelpClass::CurrentDateTime() << ":\t" << "[ERROR]:" << sMessage << endl;
}
void Logger::LogWarning(const string& sMessage)
{
	logfile << HelpClass::CurrentDateTime() << ":\t" << "[WARNING]:" << sMessage << endl;
}
void Logger::LogInfo(const string& sMessage)
{
	logfile << HelpClass::CurrentDateTime() << ":\t"  << "[INFO]:" << sMessage << endl;
}
char * Logger::Log(const char* format, ...)
{
	char* sMessage = NULL;
	va_list args;
	int nLength = 0;
	va_start(args, format);
	//  Return the number of characters in the string referenced the list of arguments.
	// _vscprintf doesn't count terminating '\0' (that's why +1)
	nLength = _vscprintf(format, args) + 1;
	sMessage = new char[nLength];
	vsprintf_s(sMessage, nLength, format, args);
	//vsprintf(sMessage, format, args);	
	va_end(args);
	return sMessage;
}
void Logger::Log(const string& sMessage)
{
	logfile << HelpClass::CurrentDateTime() << ":\t";
	logfile << sMessage << "\n";
}
Logger& Logger::operator<<(const string& sMessage)
{
	logfile << "\n" << HelpClass::CurrentDateTime() << ":\t";
	logfile << sMessage << "\n";
	return *this;
}
void Logger::count()
{
	EntryExit;//it will log entry exit from function count()

}
int main()
{
	string message1 = "logg message 1 ...";
	Logger::getInstance()->LogError("message to be logged");

	int    nNum = 10;
	Logger::getInstance()->LogErrorOnConsole("Parikshit");
	Logger::getInstance()->LogWarningOnConsole(message1);
	Logger::getInstance()->LogError("Num is = %d",nNum);
	Logger::getInstance()->LogError(message1);
	Logger::count();
	return 0;
}

