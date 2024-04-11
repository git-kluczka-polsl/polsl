#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <random>
#include <string>

int main()
{
	//zadanie 1
	std::vector<int> VEC1{ 1, 2, 3, 4, 5, 6 };
	std::ranges::sort(std::views::reverse(std::views::drop(VEC1, 3)));

	for (auto x : VEC1)
		std::cout << x << ' ';
	std::cout << std::endl;
	//zadanie 2
	std::vector VEC2{ 1, 2, 3, 4, 5, 6 };
	auto VIEW = VEC2
		| std::views::filter([](auto const i) { return i % 2 == 0; })
		| std::views::transform([](auto const i) { return i * i; });
	for (auto x : VIEW)
		std::cout << x << ' ';
	std::cout << std::endl;
	//zadanie 3
	auto kwadraty = VEC2
		| std::views::transform([](auto const i) {return i * i / 2; });
	auto kola = VEC2
		| std::views::transform([](auto const i) {return i * i * 3,14; });
	auto trojkaty = VEC2
		| std::views::transform([](auto const i) {return i * i * sqrt(3) / 4; });
	std::vector<int> combo;
	combo.assign_range(kwadraty);
	combo.append_range(kola);
	combo.append_range(trojkaty);
	const auto smieci = std::ranges::unique(combo);
	combo.erase(std::ranges::begin(smieci), std::ranges::end(smieci));
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::ranges::shuffle(combo, gen );
	for (auto x : combo)
		std::cout << x << ' ';
	std::cout << std::endl;
	//zadanie 4
	std::vector<std::pair<std::string, int>> ludzie = { {"Adam", 23},{"Daniel", 45}, {"Katarzyna", 72 } };
	auto mlodzi = ludzie
		| std::views::filter([](auto const i) { return i.second < 50; })
		| std::views::keys;

	for (auto x : mlodzi)
		std::cout << x << ' ';

}


