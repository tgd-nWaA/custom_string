
#include <iostream>

template <typename T>
void print(T val);

int main(void) {

	print(5);
	print("Hello templates");
	print(5.907);

	return 0;
};

template <typename T>
void print(T val) {

	std::cout << val << "\n";
};