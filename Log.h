#include "Advanced2D.h"
#pragma once

namespace Freedom
{
	class Log
	{
	public:
		Log();
		~Log();

		bool SetupLogging();
		bool LogMsg(std::string msg, bool limitMsgs=true);
		bool LogErr(std::string msg);
		void EndLogging();

	private:
		std::ofstream logFile;
		int time_counter;

	}; // class

}; // namespace
