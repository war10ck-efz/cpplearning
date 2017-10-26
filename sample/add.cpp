#include <iostream>
#include <cmath>
#include <typeinfo>
 
template<class T, class U>
auto add(T t, U u) -> decltype(t + u) // 返回类型是 operator+(T, U) 的类型
{
	return t + u;
}

// c++14
//template<class T, class U>
//auto add(T t, U u)
//{
//	return t + u;
//}
 
auto get_fun(int arg) -> double (*)(double) // 等同于： double (*get_fun(int))(double)
{
	switch (arg)
	{
		case 1: return std::fabs;
		case 2: return std::sin;
		default: return std::cos;
	}
}

int main()
{
	auto a = 1 + 2;
	std::cout << "type of a: " << typeid(a).name() << '\n';
	auto b = add(1, 1.2);
	std::cout << "type of b: " << typeid(b).name() << '\n';
	auto c = {1, 2};
	std::cout << "type of c: " << typeid(c).name() << '\n';
	auto d = new auto{3.f};
	std::cout << "type of d: " << typeid(d).name() << '\n';
	delete d;
										 
	auto my_lambda = [](int x) { return x + 3; };
	std::cout << "my_lambda: " << my_lambda(5) << '\n';
												 
	auto my_fun = get_fun(2);
	std::cout << "type of my_fun: " << typeid(my_fun).name() << '\n';
	std::cout << "my_fun: " << my_fun(3) << '\n';
	  													 
	//  auto int x; // C++11 开始错误："auto" 不再是存储类指定符
}
