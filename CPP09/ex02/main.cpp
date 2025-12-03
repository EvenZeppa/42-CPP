#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

typedef std::vector<unsigned int> vui;
typedef std::pair<unsigned int, unsigned int> p;
typedef std::vector<p> vpui;

void printVectorVui(const vui& v) {
	std::cout << "[";

	vui::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		std::cout << GREEN << *it << RESET << ", ";
	}

	std::cout << RESET << "]" << std::endl << std::endl;
}

void printVectorVpui(const vpui& v) {
	std::cout << "[";

	vpui::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		std::cout << RED << (*it).first << RESET << "<->" << GREEN << (*it).second << RED << ", ";
	}

	std::cout << "]" << std::endl << std::endl << RESET;
}

vui extractWinners(const vui& list) {	
	vui winners;

	vui::const_iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		int first = *it;
		++it;
		if (it == list.end()) {
			winners.push_back(first);
			break;
		}
		int second = *it;
		winners.push_back(first > second ? first : second);
	}
	return winners;
}

vpui extractloosers(const vui& list) {
	vpui loosers;
	if (list.size() == 0)
		return loosers;

	vui::const_iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		unsigned int first = *it;
		++it;
		if (it == list.end()) {
			return loosers;
		}
		unsigned int second = *it;
		p pair;
		pair.first = first > second ? second : first;
		pair.second = first > second ? first : second;
		loosers.push_back(pair);
	}
	return loosers;
}

unsigned int jacobsthal(unsigned int prev, unsigned int secondPrev) {
	return (prev + 2 * secondPrev);
}

void insertBackleft(vui& list, vui::iterator& it, unsigned int value) {
	while (value < *it && it != list.begin()) {
		// std::cout << "insertBackleft() :: START *it => " << *it << " -> " << value << std::endl;
		--it;
		// std::cout << "insertBackleft() :: END *it => " << *it << std::endl;
	}
	if (it != list.begin() && value < *it)
		++it;
	list.insert(it, value);
	// std::cout << "insertBackleft() :: list => ";
	// printVectorVui(list);
}

void insertLoosers(vui& winners, const vpui& loosers) {
	unsigned int jnPrev = 0;
	unsigned int jnCurrent = 1;
	unsigned int jnTemp = 0;

	while (jnCurrent <= loosers.size()) {
		jnCurrent = jacobsthal(jnCurrent, jnPrev);
		std::cout << "insertLoosers() :: START jnS => " << jnPrev << " -> " << jnCurrent << " -> " << jnTemp << std::endl;
		for (unsigned int j = jnCurrent; j > jnTemp; j--) {
			if (j > loosers.size())
				j = loosers.size();
			p pair = loosers.at(j - 1);
			std::cout << "insertLoosers() :: pair => " << pair.first << "<->" << pair.second << std::endl;

			// @TODO ERROR si je veux
			vui::iterator wit = std::find(winners.begin(), winners.end(), pair.second);
			insertBackleft(winners, wit, pair.first);
		// std::cout << "insertLoosers() :: END jnS => " << jnPrev << " -> " << jnCurrent << " -> " << jnTemp << std::endl;
		}
		jnPrev = jnTemp;
		jnTemp = jnCurrent;
	}
}

vui fordJohnson(const vui& list) {
	vui winners = extractWinners(list);
	// std::cout << "fordJohnson() :: winners => ";
	// printVectorVui(winners);
	vpui loosers = extractloosers(list);
	std::cout << "fordJohnson() :: loosers => ";
	printVectorVpui(loosers);
	if (winners.size() > 1) {
		winners = fordJohnson(winners);
		std::cout << "fordJohnson() :: SORTED winners => ";
		printVectorVui(winners);
	}
	insertLoosers(winners, loosers);
	return winners;
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cerr << "Need 2 args minimum" << std::endl;
		return 1;
	}
	// Build vector list with args
	vui list;
	for (int i = 1; i < argc; i++) {
		long n = atol(argv[i]);
		if (n == 0 && (argv[i][1] != '\0' || argv[i][0] != '0')) {
			std::cerr << "Argument invalid, only unsigned int" << std::endl;
			return 2;
		}
		list.push_back(static_cast<unsigned int>(n));
	}

	std::cout << "Unsorted list : " << std::endl;
	printVectorVui(list);
	
	// Recursive function to sorte given list
	list = fordJohnson(list);

	std::cout << "Sorted list : " << std::endl;
	printVectorVui(list);

	// vui::iterator it;
	// for (it = list.begin(); it < list.end(); ++it)
	// 	std::cout << *it << std::endl;

	return 0;
}