#include <cstdio>

void RemoveDuplicates(char* cstr)
{
	if (cstr == nullptr || *cstr == '\0' || *(cstr + 1) == '\0')
		return;

	char* curr = cstr;
	char* next = cstr + 1;

	char letter = *cstr;
	char last = letter;
	do {
		while (*next != '\0') {
			if (*next != letter) {
				*curr = *next;
				curr = curr + 1;
			}
			next = next + 1;
		}
		*curr = letter;
		*(curr + 1) = '\0';
		curr = cstr;
		next = cstr + 1;
		letter = *cstr;
	} while (letter != last);
}

int main(int argc, char** argv)
{	
	char test1[8] = { 'a', 'b', 'c', 'd', 'a', 'e', 'f', '\0' };
	char test2[7] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0' };
	char test3[8] = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', '\0' };
	char test4[8] = { 'a', 'b', 'a', 'c', 'a', 'a', 'a', '\0' };
	char test5[8] = { 'a', 'b', 'a', 'b', 'a', 'f', 'a', '\0' };

	std::printf("test1: %s \n", test1);
	RemoveDuplicates(test1);
	std::printf("test1: %s \n", test1);

	std::printf("test2: %s \n", test2);
	RemoveDuplicates(test2);
	std::printf("test2: %s \n", test2);

	std::printf("test3: %s \n", test3);
	RemoveDuplicates(test3);
	std::printf("test3: %s \n", test3);

	std::printf("test4: %s \n", test4);
	RemoveDuplicates(test4);
	std::printf("test4: %s \n", test4);

	std::printf("test5: %s \n", test5);
	RemoveDuplicates(test5);
	std::printf("test5: %s \n", test5);
}
