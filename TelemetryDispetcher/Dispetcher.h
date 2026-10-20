#pragma once
#include "ILogger.h"
#include "ISensor.h"
#include <vector>
#include <memory>
class TelemetryDispetcher final{
private: 
	ILogger& logger_;
	std::vector<std::unique_ptr<ISensor>> sensors_;

public:
	explicit TelemetryDispetcher(ILogger& logger);
	void AddSensor(std::unique_ptr<ISensor> sensor);
	void DispatchAll();
};