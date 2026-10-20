#include "CacheLogger.h"
#include <iostream>
void CacheLogger::log(const std::string& name, float value)
{
	cache_[name] = value;
}

void CacheLogger::dump() const
{
	for (const auto& [name, value] : cache_)
	{
		std::cout << "[CACHE] " << name << " = " << value << '\n';
	}
}