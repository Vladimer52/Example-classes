#pragma once
#include "ISensor.h"
class TempSensor final: public ISensor {
public:
	std::string getName() const override;
	float read() override;
};

class PreasureSensor final: public ISensor {
public:
	 std::string getName() const override;
	 float read() override;
};