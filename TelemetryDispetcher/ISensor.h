#pragma once
#include <string>

class ISensor {
	std::string name_;
public:
	virtual ~ISensor() = default;
	virtual std::string getName() const = 0;
	virtual float read() = 0;
};