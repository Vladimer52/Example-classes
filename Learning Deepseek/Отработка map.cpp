#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
/*
void remove_single(std::unordered_map<int, int>& counts)
{
	auto it = counts.begin();
	while (it != counts.end())
	{
		if (it->second == 0)
			it = counts.erase(it);
		else
			++it;
	}
}

void remove_multiples_of_three(std::set<int>& values)
{
	auto it = values.begin();
	while (it != values.end())
	{
		if (*it % 3 == 0)
		{
			it = values.erase(it);
		}
		else
			++it;
	}
}

int main(void)
{
	std::vector<int> events{
	101, 102, 101, 105, 102, 101, 110, 105
	};
	std::vector<int> queries{
	101, 110, 999, 102
	};

	std::unordered_map<int, int> count_events;
	for (const auto& event: events)
	{
		++count_events[event];
	}
	for (const auto& kv : count_events)
	{
		std::cout << kv.first << '=' << kv.second << '\n';
	}
	std::cout << '\n';
	for (const auto& element : queries)
	{
		auto it = count_events.find(element);
		if (it != count_events.end())
			std::cout << it->first << '=' << it->second << '\n';
		else 
			std::cout << element << '=' << "not found\n";
	}
	std::cout << '\n2';
	//2
	std::unordered_map<int, int> counts{
	{101, 3},
	{102, 1},
	{105, 2},
	{110, 1},
	{115, 4}
	};
	remove_single(counts);
	for (const auto& element : counts)
		std::cout << element.first << '=' << element.second << '\n';
	//3
	std::set<int> values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


}*/