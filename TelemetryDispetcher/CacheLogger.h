#pragma once
#include <map>
#include "ILogger.h"
class CacheLogger final : public ILogger {
private: 
	std::map<std::string, float> cache_;
public:
	void log(const std::string& name, float value) override;
	void dump() const;
};