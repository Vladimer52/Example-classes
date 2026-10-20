#pragma once
#include "ILogger.h"
class ConsoleLogger final: public ILogger {
public:
	void log(const std::string& sensorName, float value) override;
};