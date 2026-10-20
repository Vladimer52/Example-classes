#include "Sensors.h"
#include <string>

std::string TempSensor::getName() const
{
	return "Temperature";
}

float TempSensor::read()
{
	return 25.5f;
}

std::string PreasureSensor::getName() const
{
	return "Preasure";
}

float PreasureSensor::read()
{
	return 1013.2f;
}
