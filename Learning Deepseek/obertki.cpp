#include <optional>
#include <tuple>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <variant>
/*// у меня стояли C++ 11, переключил на 20е, там есть и optional И erase_if
std::optional<int> FindIndex(const std::vector<int>& nums, int target)
{
	for (auto i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
		{
			return i;
		}
	}
	return std::nullopt;
}

std::tuple<int, int> GetMinMax(const std::vector<int>& v)
{
	int min = v[0];
	int max = v[0];
	for (const auto& x : v)
	{
		if (x <= min)
			min = x;
		if (x >= max)
			max = x;
	}
	return { min, max };
}

std::optional<int> ReadTemperature()
{
	return std::nullopt;
}


int main()
{
	//1
	std::vector<int> nums{ 2, 3, 5, 1, 7 };
	std::cout << "index: " << FindIndex(nums, 1).value() << '\n';
	//2
	auto [min, max] = GetMinMax(nums);
	std::cout << "min: " << min << " max: " << max << '\n';
	//3
	// отличие в том, тчо не нужно руками прописывать все ветки, если возвращаемое значение не нужно
	//4
	//логично, что вернется nullopt, value_or как раз наверно  и погасит эту ошибку, чтобы cout вернул нормальное "ничего"

	std::cout << "Read temperature: " << ReadTemperature().value_or(25) << '\n';
}

*/
/*
// контрольная:
//217
bool containsDuplicate(vector<int>& nums) {
	std::unordered_set<int> num_set;
	for (const auto& n : nums)
	{
		if (num_set.find(n) != num_set.end())
		{
			num_set.insert(n);
		}
		else
		{
			return true;
		}
	}
	return false;
}
// не проходит для случая, когда nums{1, 2, 3, 4}


//1

std::vector<int> sortedSquares(std::vector<int>& nums) {
	std::transform(nums.begin(), nums.end(), nums.begin(), [](int x) {
		x* x
		});
	std::sort(nums.begin(), nums.begin());
	return nums;
	
}*/


/*int main(void)
{
	//1 контейнер у нас будет vector. в начале я бы сделал resize(1024) раз размер заранее известен
	//2 как только дойдем до обращения к get_device_id ссылка будет не существовать на локальную переменную prefix. используем возврат поссылке, а не через string_view
	//3 
	std::vector<int> buffer = { 10, 50, 100, 20, 200 };
	std::erase_if(buffer, [](int x) {return x > 50;});
	//4
	if (std::holds_alternative<int>(result))
		std::cout << std::get<int>(resuilt) << '\n';



}*/