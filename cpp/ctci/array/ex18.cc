#include <string>
#include <iostream>

bool IsRotation(std::string str, std::string of) 
{
	if (str.size() != of.size())
		return false;

	auto letter = of.begin();
	auto match = str.end();
	for (auto c = str.begin(); c != str.end(); ++c)
	{
			if (*c == *letter) {
				letter = letter + 1;
				if (match == str.end())
					match = c;
			} else {
				match = str.end();
			}
	}
	if (match != str.end() && 
			of.find(std::string(str.begin(), match)) != std::string::npos)
		return true;
	return false;
}

int main(int argc, char** argv)
{
	std::string of("stack");
	std::string s1("tacks");
	std::string s2("ackst");
	std::string s3("cksta");
	std::string s4("kstac");
	std::string s5("kstak");

	std::string of2("stackoverflow");
	std::string s6("overflowstack");
	std::string s7("flowstackover");
	std::string s8("flowoverstack");


	std::cout << s1 << " of " << of << std::endl;
	if (IsRotation(s1, of)) std::cout << "Yes" << std::endl;
	std::cout << s2 << " of " << of << std::endl;
	if (IsRotation(s2, of)) std::cout << "Yes" << std::endl;
	std::cout << s3 << " of " << of << std::endl;
	if (IsRotation(s3, of)) std::cout << "Yes" << std::endl;
	std::cout << s4 << " of " << of << std::endl;
	if (IsRotation(s4, of)) std::cout << "Yes" << std::endl;
	std::cout << s5 << " of " << of << std::endl;
	if (IsRotation(s5, of)) std::cout << "Yes" << std::endl;
	std::cout << of << " of " << of << std::endl;
	if (IsRotation(of, of)) std::cout << "Yes" << std::endl;
	std::cout << s6 << " of " << of2 << std::endl;
	if (IsRotation(s6, of2)) std::cout << "Yes" << std::endl;
	std::cout << s7 << " of " << of2 << std::endl;
	if (IsRotation(s7, of2)) std::cout << "Yes" << std::endl;
	std::cout << s8 << " of " << of2 << std::endl;
	if (IsRotation(s8, of2)) std::cout << "Yes" << std::endl;


}
