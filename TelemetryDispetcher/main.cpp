
#include <iostream>
#include "ConsoleLogger.h"
#include "Dispetcher.h"
#include <memory>
#include "Sensors.h"
#include "CacheLogger.h"
int main()
{
    CacheLogger logger;
    TelemetryDispetcher dispatcher( logger);
    auto temp_sensor = std::make_unique<TempSensor>();
    auto preasue_sensor = std::make_unique<PreasureSensor>();
    dispatcher.AddSensor(std::move(temp_sensor));
    dispatcher.AddSensor(std::move(preasue_sensor));
    dispatcher.DispatchAll();
    logger.dump();
}
