#include <string>
#include <iostream>

void SubstitudeSpace(std::string& str)
{
	size_t number = str.size();

	for (size_t n = number; n > 0; --n) {
		char letter = str[0];
		size_t c;
		for (c = 0; c < (number - 1); ++c) {
			str[c] = str[c + 1];
		}

		if (letter == ' ') {
			str.resize(str.size() + 2);
			number = number + 2;
			str[c] = '%'; 
			str[c + 1] = '2';
			str[c + 2] = '0';
		
		} else {
			str[c] = letter;
		}
	}
}

int main(int argc, char** argv)
{
	std::string s1("ab c d ef");
	std::string s2("abcd ef");
	std::string s3("abcdsdef");

	std::cout << s1 << " ";
	SubstitudeSpace(s1);
	std::cout << s1 << std::endl;

	std::cout << s2 << " ";
	SubstitudeSpace(s2);
	std::cout << s2 << std::endl;

	std::cout << s3 << " ";
	SubstitudeSpace(s3);
	std::cout << s3 << std::endl;
}

