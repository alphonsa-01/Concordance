//Name : Alphonsa George
//Assignment :PROG1203 HW8 - Words

#ifndef CONCORDANCE_H_
#define CONCORDANCE_H_

#include "word.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc 
{
	/*!
	\brief Represents a class of words and methods to read and load from a file to determine the state of the concordance class.

	 Words read from the file are stored to a container and it writes to a new file.

	*/
	class concordance
	{
	public:

		/*!
		\brief creates an instance of concordance.
		*/
		concordance();

		/*!
		\brief Represents the map of unique words from the word object.
		*/
		std::map<std::string, std::vector<int>>unique_words;

		/*!
		\brief Loads the map with words as keys and vector of line numbers as values.
		Loads the map with the words read from the file. Words are converted to lower case before
		adding them to the map.

		\param unique_words , map to be loaded.
		\param file_name, file from where the words are read.
		*/
		void load_words(std::map<std::string, std::vector<int>>& unique_words, std::string& file_name);

		/*!
		\brief the loaded map is being written to a file

		\param unique_words, map which contains the unique_words and it's line numbers.
		\param file_name, file from which the words are being read.
		*/
		void write_to_file(std::map<std::string, std::vector<int>>& unique_words,std::string& file_name);

		/*!
		\breif Writing to a file all the popular words, based on the input chosen from the use.

		\param unique_words, map which contains the unique_words and it's line numbers.
		\param number, number of popular words to be displayed chosen by the user
		\param file_name,  file from which the words are being read
	     */
		void load_popular_words(std::map<std::string, std::vector<int>>& unique_words, int number,std::string& file_name);

		/*!
		\breif Operator overoading of stream insertion operrator.

		\param out, ostream variable
		\param value, concordance variable
		*/
		friend std::ostream& operator<<(std::ostream& out, const concordance& value);

		/*!
		\brief Operator overloading of stream extraction operator.

		\param in,  istream variable
		\param value, concordance variable.
		*/
		friend std::istream& operator>>(std::istream& in, concordance& value);

	private:

		/*!
		\brief represents an attribute of type word.
		*/
		word word_;

	};

}

#endif
