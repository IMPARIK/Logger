#include <iostream>
#include <string>
#include <time.h>
#define Trace EntryExit obj ## __LINE__ (__FUNCTION__);
#include<iostream>

struct EntryExit {
	EntryExit(const char* f) : f_(f) { std::cout << "++" << f_ << std::endl; }
	~EntryExit() { std::cout << "--" << f_ << std::endl; }
	const char* f_;
};


namespace HelpClass
{
	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
	const std::string CurrentDateTime()
	{
		time_t     now = time(NULL);
		struct tm  tstruct;
		char       buf[80];
		localtime_s(&tstruct, &now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X:%S", &tstruct);
		return buf;
	}
}
