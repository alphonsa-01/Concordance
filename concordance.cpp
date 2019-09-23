//Name : Alphonsa George
//Assignment :PROG1203 HW8 - Words

#include "concordance.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
		\brief creates an instance of concordance.
		*/
	concordance::concordance() {}

	/*!
		\brief Loads the map with words as keys and vector of line numbers as values.
		Loads the map with the words read from the file. Words are converted to lower case before
		adding them to the map.

		\param unique_words , map to be loaded.
		\param file_name, file from where the words are read.
		*/
	void concordance::load_words(std::map<std::string, std::vector<int>>& unique_words, std::string& file_name)
	{
		std::ifstream fin;
		fin.open(file_name);

		if (fin)
		{
			std::string input_word;
			auto count = 1;
			while (getline(fin, input_word))
			{
				auto start = 0U;
				auto last = input_word.find_first_of(" ");

				std::string word;
				
				while (last != std::string::npos)
				{
					word = input_word.substr(start, last - start);
					for (char letter : word)
					{
						if (letter == word::k_punctuation_mark)
						{
							word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
						}
						else if (letter > word::k_first_capital_alphabet || letter < word::k_last_capital_alphabet)
						{
							std::transform(word.begin(), word.end(), word.begin(), [](unsigned char letter) {return tolower(letter); });
						}
						else
						{
							word += letter;
						}
					}

					auto search = unique_words.find(word);
					std::vector<int>line_numbers;

					if (search == unique_words.end())
					{
						line_numbers.push_back(count);
						unique_words[word] = line_numbers;

					}
					else
					{
						line_numbers.push_back(count);
						unique_words[word] = line_numbers;
					}
					input_word.erase(start, (last + 1) - start);
					last = input_word.find_first_of(" ");
				}

				for (char letter : input_word)
				{
					if (letter == word::k_punctuation_mark)
					{
						input_word.erase(std::remove_if(input_word.begin(), input_word.end(), ispunct), input_word.end());
					}
					else if (letter > word::k_first_capital_alphabet || letter < word::k_last_capital_alphabet)
					{
						std::transform(input_word.begin(), input_word.end(), input_word.begin(), [](unsigned char letter) {return tolower(letter); });
					}
					else
					{
						input_word += letter;
					}
				}
				auto search = unique_words.find(input_word);
				std::vector<int>line_numbers;

				if (search == unique_words.end())
				{
					line_numbers.push_back(count);
					unique_words[input_word] = line_numbers;

				}
				else
				{
					line_numbers.push_back(count);
					unique_words[input_word] = line_numbers;
				}

				count++;

			}
			fin.close();

		}//else, file didnt open, do_nothing();

	}

	/*!
		\brief the loaded map is being written to a file

		\param unique_words, map which contains the unique_words and it's line numbers.
		\param file_name, file from which the words are being read.
		*/
	void concordance::write_to_file(std::map<std::string, std::vector<int>>& unique_words, std::string& file_name)
	{
		std::ofstream fout;

		std::string file_name_new = file_name + "_concordance" + ".txt";

		fout.open(file_name_new);

		for (const auto& word : unique_words)
		{
			fout << word.first << " appears " << word.second.size() << "  times on lines ";
			for (const auto& number : word.second)
			{
				fout << number << ' ';
			}
			fout << std::endl;
		}

	}


	/*!
		\breif Writing to a file all the popular words, based on the input chosen from the use.

		\param unique_words, map which contains the unique_words and it's line numbers.
		\param number, number of popular words to be displayed chosen by the user
		\param file_name,  file from which the words are being read
		 */
	void concordance::load_popular_words(std::map<std::string, std::vector<int>>& unique_words,int number,std::string& file_name)
	{
		std::string file_name_new = file_name + "_popular_" + std::to_string(number) + ".txt";

		std::ofstream fout;
		fout.open(file_name_new);

		for (const auto& word : unique_words)
		{
		
			fout << word.first << " appears " << word.second.size() << "  times on lines ";
			for (const auto& number : word.second)
			{
				fout << number << ' ';
			}
			fout << std::endl;

		}
		

	}

	/*!
		\breif Operator overoading of stream insertion operrator.

		\param out, ostream variable
		\param value, concordance variable
		*/
	std::ostream& operator<<(std::ostream& out, const concordance& value)
	{
		out << value.word_ << "- " << value.word_ << std::endl;

		return out;
	}

	/*!
		\brief Operator overloading of stream extraction operator.

		\param in,  istream variable
		\param value, concordance variable.
		*/
	std::istream& operator>>(std::istream& in, concordance& value)
	{
		in >> value.word_ >> value.word_;

		return in;
	}

}