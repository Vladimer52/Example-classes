#include "Dispetcher.h"
#include "ISensor.h"

TelemetryDispetcher::TelemetryDispetcher(ILogger& logger) : logger_(logger)
{
	//просто потому что хочу. представь, что заранее известно, что на девайсе 5 датчиков
	sensors_.reserve(5);
}

void TelemetryDispetcher::AddSensor(std::unique_ptr<ISensor> sensor)
{
	sensors_.push_back(std::move(sensor));
}

void TelemetryDispetcher::DispatchAll()
{
	for (const auto& sens : sensors_)
	{
		logger_.log( sens->getName(), sens->read());
	}
}