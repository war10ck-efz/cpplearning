#include <iostream>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>


void print(const std::string & s)
{
	// Thread safe?
	static std::mutex mtx;
	std::unique_lock<std::mutex> lock(mtx);
	std::cout << s << std::endl;	
}

int main()
{
	std::thread([&]() { for (int i = 0; i < 10; ++i) print("a" + std::to_string(i)); }).detach();
	std::thread([&]() { for (int i = 0; i < 10; ++i) print("b" + std::to_string(i)); }).detach();
	std::thread([&]() { for (int i = 0; i < 10; ++i) print("c" + std::to_string(i)); }).detach();
	std::thread([&]() { for (int i = 0; i < 10; ++i) print("d" + std::to_string(i)); }).detach();
	std::thread([&]() { for (int i = 0; i < 10; ++i) print("e" + std::to_string(i)); }).detach();

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
