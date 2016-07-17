#include <cstdio>

void ReverseString(char* cstr)
{
	if (cstr == nullptr || *cstr == '\0')
		return;
	char* last = cstr;
	char* first = cstr;
	while (*(last + 1) != '\0') 
		last = last + 1;
	while (last != first) {
		char tmp = *first;
		*first = *last;
		*last = tmp;
		if ((last - 1) == first) {
			return;
		} else {
			last = last - 1;
			first = first + 1;
		}
	}
}

int main(int argc, char** argv) 
{
	char test1[5] = { 'a', 'b', 'c', 'd', '\0' };
	char test2[6] = { 'a', 'b', 'c', 'd', 'e', '\0' };

	std::printf("test1: %s \n", test1);
	std::printf("test2: %s \n", test2);

	ReverseString(test1);
	ReverseString(test2);

	std::printf("test1: %s \n", test1);
	std::printf("test2: %s \n", test2);

}
