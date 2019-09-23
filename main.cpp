//Name : Alphonsa George
//Assignment :PROG1203 HW8 - Words

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "concordance.h"
#include "word.h"

const char k_continue_yes_small = 'y';
const char k_continue_yes_caps = 'Y';

int main()
{
	auto continue_input = k_continue_yes_small;

	while (continue_input == k_continue_yes_small || continue_input == k_continue_yes_caps)
	{
		std::cout << "Select a data file from the below list:\n"
			<< "Grimms\n"
			<< "Modest\n"
			<< "Odyssey\n"
			<< "War\n"
			<< "test\n"
			<< "test_two" << std::endl;

		std::cout << "File name is :";

		std::string file;
		std::cin >> file;

		std::string file_name = file + ".txt";

		std::map<std::string, std::vector<int>>unique_words;

		nwacc::concordance word;

		word.load_words(unique_words, file_name);

		word.write_to_file(unique_words, file);

		std::cout << "ENter the number of popular words to be displayed:";
		auto number = 0;
		std::cin >> number;

		word.load_popular_words(unique_words, number, file);

		std::cout << "Would you like to continue(y/n):";
		std::cin >> continue_input;
	}
	std::cout << "Bye!" << std::endl;;

	return 0;
}

