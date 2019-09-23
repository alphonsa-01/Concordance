//Name : Alphonsa George
//Assignment :PROG1203 HW8 - Words

#include "word.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
		\brief Represents the first English alphabet in capital, which is 'A'.
		*/
	const char word::k_first_capital_alphabet = 'A';

	/*!
		\brief Represents the last english alphabet in capital, which is 'Z'
		*/
	const char word::k_last_capital_alphabet = 'Z';

	/*!
		\brief Represents the constant for punctuation mark, which is ','.
		*/
	const char word::k_punctuation_mark = ',';

	/*!
		\brief creates an instance of word.
		*/
	word::word() {}

	/*!
		\brief Creates an instance of word with specified word_input and line_number.

		\param word_input, word_input is the word read from the file.
		\param line_number is the line where the word_input is present.
		*/
	word::word(const std::string word_input, int line_number)
	{
		this->word_input_ = word_input;
		this->line_number_ = line_number;
	}

	/*!
		\brief Gets the word_input of this instance.

		\return returns the word_input of this instance.
		*/
	std::string word::get_word_input()const
	{
		return this->word_input_;
	}

	/*!
		\brief Gets the line_number of this instance.

		\return returns the line_number of this instance.
		*/
	int word::get_line_number()const
	{
		return this->line_number_;
	}

	/*!
		\brief Loads the map with words as keys and vector of line numbers as values.
		Loads the map with the words read from the file. Words are converted to lower case before
		adding them to the map.

		\param unique_words , map to be loaded.
		\param file_name, file from where the words are read.
		*/
	void word::load_words(std::map<std::string, std::vector<int>>& unique_words, std::string& file_name)
	{
		unique_words.clear();
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
						if (letter == k_punctuation_mark)
						{
							word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
						}
						else if (letter > k_first_capital_alphabet || letter < k_last_capital_alphabet)
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
						unique_words[word].push_back(count);
						
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
					if (letter == k_punctuation_mark)
					{
						input_word.erase(std::remove_if(input_word.begin(), input_word.end(), ispunct), input_word.end());
					}
					else if (letter > k_first_capital_alphabet || letter < k_last_capital_alphabet)
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
					unique_words[input_word].push_back(count);
					
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
		\breif Operator overoading of stream insertion operrator.

		\param out, ostream variable
		\param value, word variable.
		*/
	std::ostream& operator<<(std::ostream& out, const word& value)
	{
		out << value.word_input_ << "- " << value.line_number_ << std::endl;

		return out;
	}

	/*!
		\brief Operator overloading of stream extraction operator.

		\param in,  istream variable
		\param value, word variable.
		*/
	std::istream& operator>>(std::istream& in, word& value)
	{
		in >> value.word_input_ >> value.line_number_;

		return in;
	}

	/*!
		\brief Operator overloading of less than operator

		\param rhs, word variable to be compared.
		*/
	bool word::operator<(const word& rhs)const
	{
		return this->word_input_ < rhs.word_input_;
	}
}

