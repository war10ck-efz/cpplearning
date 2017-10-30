#include <iostream>
#include <ctime>

using namespace std;

template <class T>
inline void swap_move(T& a, T& b)
{
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}


template <class T>
inline void swap_copy(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

int main()
{
	int a = 1, b = 2;
	int start = clock();
	for (int i = 0; i < 1000000; ++i)	std::swap(a, b);
	int end = clock();
	cout << "swap_move spent :" << end - start << "ms" << endl;

	start = clock();
	for (int i = 0; i < 1000000; ++i)	swap_copy(a, b);
	end = clock();
	cout << "swap_copy spent :" << end - start << "ms" << endl;
	return 0;
}
