//Name : Alphonsa George
//Assignment :PROG1203 HW8 - Words

#ifndef WORD_H_
#define WORD_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief Represents a class of words and methods to read and load from a file to determine the state of the word.

	Word class has words read from a file and it's respective line numbers. Words are stored to a container.
	This class contains methods to read from the file and load the container.

	*/
	class word
	{
	public:

		/*!
		\brief Represents the first English alphabet in capital, which is 'A'.
		*/
		static const char k_first_capital_alphabet;

		/*!
		\brief Represents the last english alphabet in capital, which is 'Z'
		*/
		static const char k_last_capital_alphabet;

		/*!
		\brief Represents the constant for punctuation mark, which is ','.
		*/
		static const char k_punctuation_mark;

		/*!
		\brief creates an instance of word.
		*/
		word();

		/*!
		\brief Creates an instance of word with specified word_input and line_number.

		\param word_input, word_input is the word read from the file.
		\param line_number is the line where the word_input is present.
		*/
		word(const std::string word_input,int line_number);

		/*!
		\brief Gets the word_input of this instance.

		\return returns the word_input of this instance.
		*/
		std::string get_word_input()const;

		/*!
		\brief Gets the line_number of this instance.

		\return returns the line_number of this instance.
		*/
		int get_line_number()const;

		/*!
		\brief Loads the map with words as keys and vector of line numbers as values.
		Loads the map with the words read from the file. Words are converted to lower case before
		adding them to the map.

		\param unique_words , map to be loaded.
		\param file_name, file from where the words are read.
		*/
		void load_words(std::map<std::string, std::vector<int>>& unique_words, std::string& file_name);

		/*!
		\breif Operator overoading of stream insertion operrator.

		\param out, ostream variable
		\param value, word variable.
		*/
		friend std::ostream& operator<<(std::ostream& out, const word& value);

		/*!
		\brief Operator overloading of stream extraction operator.

		\param in,  istream variable
		\param value, word variable.
		*/
		friend std::istream& operator>>(std::istream& in, word& value);

		/*!
		\brief Operator overloading of less than operator

		\param rhs, word variable to be compared. 
		*/
		bool  operator<(const word& rhs)const;

	private:

		/*!
		\brief Represents the word_input string
		word read from the file
		*/
		std::string word_input_;

		/*!
		\brief Represents the line_number integer
		respective line number of the word read from the file.
		*/
		int line_number_{};

	};


}

#endif