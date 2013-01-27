#include "Advanced2D.h"

namespace Freedom
{
	Log::Log()
	{
	}

	Log::~Log()
	{
	}

	bool Log::SetupLogging()
	{
		// Open file for writing
		logFile.open("C:\\Logs\\paddle_battle.log");
		time_counter = 0;
		
		if (!logFile.is_open())
		{
			g_engine->message("Error opening Log file");
			return false;
		}
		else
		{
			// Test file writing with initial log message
			logFile << "Freedom Engine V1.0.0 Start Up\n";
		}

		return true;
	}

	bool Log::LogMsg(std::string msg, bool limitMsgs)
	{
		// Current date/time based on current system
		std::string datetime;
		time_t now = time(0);
		char* dt = ctime(&now);
		tm *ltm;
		ltm = localtime(&now);

		if (limitMsgs)
		{
			if (ltm->tm_sec > time_counter)
			{
				datetime = Advanced2D::rtrim(Advanced2D::ToString(dt));
				logFile << "LOG(" + Advanced2D::ToString(datetime) + "): " + msg + "\n";
			}
		}
		else
		{
			datetime = Advanced2D::rtrim(Advanced2D::ToString(dt));
			logFile << "LOG(" + Advanced2D::ToString(datetime) + "): " + msg + "\n";
		}

		time_counter = ltm->tm_sec;
		return true;
	}

	bool Log::LogErr(std::string msg)
	{
		// Current date/time based on current system
		std::string datetime;
		time_t now = time(0);
		char* dt = ctime(&now);

		datetime = Advanced2D::rtrim(Advanced2D::ToString(dt));
		logFile << "ERROR(: " + Advanced2D::ToString(datetime) + "): " + msg + "\n";
		return true;
	}

	void Log::EndLogging()
	{
		logFile.close();
	}
	
}
