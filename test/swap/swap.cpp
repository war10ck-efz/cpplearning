#include <iostream>
#include <ctime>
#include <utility>

using namespace std;

typedef long long LL;
const LL N = 1LL << 25;

template <class T>
inline void swap_move(T& a, T& b) noexcept
{
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}


template <class T>
inline void swap_copy(T& a, T& b) noexcept
{
	T tmp(a);
	a = b;
	b = tmp;
}

int main()
{
	int a = 1, b = 2;
	int start = clock();
	for (LL i = 0; i < N; ++i)	swap_copy(a, b);
	int end = clock();
	cout << "copy swap spent :" << end - start << "ms" << endl;

	start = clock();
	for (LL i = 0; i < N; ++i)	swap_move(a, b);
	end = clock();
	cout << "move swap spent :" << end - start << "ms" << endl;

	start = clock();
	for (LL i = 0; i < N; ++i)	std::swap(a, b);
	end = clock();
	cout << "std  swap spent :" << end - start << "ms" << endl;

	cout << endl;

	return 0;
}
