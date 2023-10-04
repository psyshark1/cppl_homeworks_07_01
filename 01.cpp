#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator << (std::ostream& l, std::vector<std::pair<char, int>>& r)
{
	for (const auto& it : r)
	{
		l << it.first << ": " << it.second << std::endl;
	}
	return l;
}

int main()
{
	std::string s{ "Hello world!!"};

	std::vector<std::pair<char, int>> vec;
	bool chk = false;

	for (const auto& str_it : s)
	{
		chk = false;
		for (auto& vec_it : vec)
		{
			if (vec_it.first == str_it)
			{
				++vec_it.second;
				chk = true;
			}
		}
		if (!chk)
		{
			vec.push_back(std::pair<char, int>(str_it, 1));
		};
	}

	std::sort(vec.begin(), vec.end(), [](const std::pair<char, int>& lhs, const std::pair<char, int>& rhs) {return lhs.second > rhs.second; });

	std::cout << "[IN]: " << s << std::endl;

	std::cout << "[OUT]: " << std::endl << vec;

	return 0;
}
