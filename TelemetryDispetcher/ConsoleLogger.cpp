#include "ConsoleLogger.h"
#include <iostream>
void ConsoleLogger::log(const std::string& sensorName, float value)
{
	std::cout << "[LOG] " << sensorName << ": " << value << '\n';
}
