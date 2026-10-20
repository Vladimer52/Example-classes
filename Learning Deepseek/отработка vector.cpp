/*дан вектор values, в котором 2 значения.мы кладем в него 3е значение 30.
далее второе значение мы пытаемся скопировать, а не передать по ссылке, ничгео не поменяется, останется 20.
далее пробуем через кастование size в int поместить число 3 в конец, думаю все норм, сработает и будет {10, 20, 30, 3}. выводит именно то, что я указал, потому что явно преобразуем скорее всего size_t к int
далее цикл range, просто перебирает, лучше через const int& для чтения, сильно будет безопаснее. выдает через пробел числа
и выводим Size = 4. 
*/

#include <iostream>
#include <vector>
/*1
std::vector<int> get_even_numbers(const std::vector<int>& v)
{
	std::vector<int> out;
	for (const auto& element : v)
	{
		if (element % 2 == 0)
			out.push_back(element);
	}
	return out;
}

int main(void)
{
	std::vector<int> values{ -3, 8, 0, 5, 12, -4, 7, 2 };
	std::vector<int> even_values = get_even_numbers(values);

	for (const auto& v : values)
		std::cout << v << ' ';
	std::cout << '\n';
	for (const auto& v : even_values)
		std::cout << v << ' ';
}*/


//2
/*void remove_negative(std::vector<int>& v)
{
	for (auto i = 0; i < v.size(); i++)
	{
		if (v[i] < 0) {
			v.erase(v.begin() + i);
			i--;
		}
	}
}
int main(void)
{
	std::vector<int> values{ 5, -2, 8, -1, -7, 3, 0, 4 };
	remove_negative(values);
	for (const auto& v : values)
		std::cout << v << ' ';
	std::cout << '\n';
}*/

//3
/*void remove_dublicates(std::vector<int>& v)
{
	for (auto i = 0; i < v.size(); i++)
	{
		for (auto j = i + 1; j < v.size(); j++)
		{
			if (v[i] == v[j]) {
				v.erase(v.begin() + j);
				j--;
			}
		}
	}
}
int main(void)
{
	std::vector<int> values{ 4, 2, 4, 1, 2, 7, 1, 7, 9 };
	remove_dublicates(values);
	for (const auto& v : values)
		std::cout << v << ' ';
	std::cout << '\n';

}*/
//4
/*void move_zeros(std::vector<int>& v)
{
	int write = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			v[write] = v[i];
			write++;
		}
	}
	for (int i = write; i < v.size(); i++)
	{
		v[i] = 0;
	}

}
int main(void)
{
	std::vector<int> values{ 0, 1, 0, 3, 12, 0, 5 };
	move_zeros(values);
	for (const auto& v : values)
		std::cout << v << ' ';
	std::cout << '\n';
}*/

/*#include <map>
#include <unordered_map>
#include <set>

std::map<std::string, int> count_words(const std::vector<std::string>& words)
{
	std::map<std::string, int> words_count;
	for (const auto& word : words)
	{
		++words_count[word];
	}
	return words_count;
}

std::string most_popular_word(const std::vector<std::string>& words)
{
	std::map<std::string,int> c_words = count_words(words);
	int max = 0;

	if (c_words.empty()) return "";
	for (const auto& element : c_words)
	{
		if (element.second > max)
			max = element.second;
	}
	for (const auto& m : c_words)
	{
		if (m.second == max)
			return m.first;
	}
	
}

int main(void)
{
	//1
	std::map<std::string, int> m;
	m.emplace("temp", 20);
	m.insert({ "hum", 60 });
	m.emplace("press", 1013);
	std::cout << m.size() << '\n';
	auto it = m.find("hum");
	if(it != m.end())
	std::cout << it->second;// есть трудности как мне найти через find
	//std::cout << m.find("unknown");
	m.erase("press");
	for (const auto& kv : m)
	{
		std::cout << kv.first << '=' << kv.second << '\n';

	}
	//2
	m["non_exist"];
	std::cout << m.size() << '\n'; //ничего не изменилось. все так же 3 элемента внутри. 

	//3
	std::unordered_map<std::string, int> m1;
	m1.emplace("temp", 20);
	m1.insert({ "hum", 60 });
	m1.emplace("press", 1013);
	for (const auto& kv : m1)
	{
		std::cout << kv.first << '=' << kv.second << '\n';
	}
	//4 
	std::set<int> values = { 5, 1, 3, 1, 5, 2 };//он убрал все копии, удобно:) видимо только уникальные значения
	std::cout << values.size() << '\n';

	//5
	std::vector<std::string> words = { "temp", "hum", "temp", "press", "temp", "hum" };
	auto count = count_words(words);
	for (const auto& kv : count)
	{
		std::cout << kv.first << '=' << kv.second << '\n';

	}
	std::cout << "most popular word: " << most_popular_word(words) << '\n';
}*/


/*#include <vector>
#include <algorithm>
int main(void)
{
	//1
	std::vector<int> v{ 10, 20, 30, 40, 50 };
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << '\n';
	}
	for (auto it = v.cbegin(); it != v.cend(); ++it)
	{
		std::cout << *it << '\n';
	}
	//2
	std::cout << "third element: " << *(v.begin() + 2) << '\n';
	std::cout << "size to element: " << v.begin() + 2 - v.begin() << '\n';
	//3
	auto it = v.begin();
	v.push_back(100);// залили 100 нулей в вектор, it указывает на начало, а мы залили в конец. сместится v.end()

	//4
	std::vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8 };
	for (auto i = v1.begin(); i != v1.end();)
	{
		if (*i % 2 == 0)
			i = v1.erase(i);
		else ++i;
	}//где то тут падает
	for (const auto& element : v1)
		std::cout << element << '\n';
	//5
	auto element_40 = std::find(v.begin(), v.end(), 40);
	if (element_40 != v.end())
		std::cout << *element_40 << '\n';
	else
		std::cout << "Not found" << '\n';
}


*/

