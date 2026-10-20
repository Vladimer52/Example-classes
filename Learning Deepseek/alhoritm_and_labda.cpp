#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
/*—интаксис: [захват](параметры) -> тип_возврата { тело }.

[=] Ч захват всех внешних переменных по значению.

[&] Ч захват по ссылке.

[x, &y] Ч x по значению, y по ссылке.*/


/*std::find_if Ч найти первый элемент, дл€ которого л€мбда вернула true.

std::count_if Ч посчитать, сколько элементов вернули true.

std::sort Ч сортировка (быстрее qsort за счет инлайнинга).

std::transform Ч аналог map из других €зыков: берет элемент, что-то с ним делает в л€мбде и кладет результат в другой (или тот же) контейнер.

std::accumulate Ч пройтись по массиву и накопить результат (например, сумму).

std::erase_if (из C++20) Ч удалить из вектора все элементы, дл€ которых л€мбда вернула true (решает проблему с инвалидацией итераторов, о которой мы говорили!).*/
/*
int main(void)
{
	const std::vector<int> v{1, 2, 5, 10, 29, 31, 34, 109};
	int threshold = 10;
	auto it = std::find_if(v.begin(), v.end(), [threshold](int x) {
		return x > threshold;
		});
	//1
	std::vector<std::string> words = {"apple", "banana", "cat", "dog", "elephant"};
	auto it = std::find_if(words.begin(), words.end(), [](std::string& word) {
		return word.size() > 4;
		});
	if(it != words.end())
		std::cout << "word upper 4 symb: " << *it << '\n';
	//2
	std::vector<int> nums{ -5, 3, 0, 12, -8, 7 };
	int count_positive = std::count_if(nums.begin(), nums.end(), [](int x) {
		return x > 0;
		});
	std::cout << "count of positive: " << count_positive << '\n';
	//3
	std::vector<int> v2 = { 1, 2, 3, 4 };
	std::transform(v2.begin(), v2.end(), v2.begin(), [](int x) {
		return x * x;
		});
	for (const auto& x : v2)
		std::cout << x << ' ';
	//4
	std::vector<int> sensors{ 12,45,8,33,50 };
	int limit = 30;
	sensors.erase(std::remove_if(sensors.begin(), sensors.end(), [limit](int x) {
		return x < limit;
		}));
	//std::erase_if(v.begin(), v.end(), [limit](int x)
	//{
	// return x > limit;
	//}); // нет такой функции у мен€ в visual studio, возможно не та верси€ C++
	//5
	//ошибка в том, что к моменту выхода из анонимной функции threshold уже может не существовать. по ссылке его передавать нельз€. 
}*/