#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

class SuperSingleton
{
	public:
		static SuperSingleton & GetInstance()
		{
			static SuperSingleton instance;
			return instance;
		}

		int count;
	private:

		SuperSingleton() {}
		SuperSingleton(const SuperSingleton &);
		SuperSingleton & operator = (const SuperSingleton &);
};

std::mutex mux;

void threadA()
{
	while (true)
	{
		// std::lock_guard<std::mutex> lock(mux);
		if (SuperSingleton::GetInstance().count > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			cout << SuperSingleton::GetInstance().count-- << endl;
		}
		else {
			break;
		}
	}
}

int main()
{
	SuperSingleton::GetInstance().count = 100;
	std::thread threads[5];
	for (int i = 0; i < 5; i++) {
		threads[i] = std::thread(threadA);
	}

	for (int i = 0; i < 5; i++) {
		threads[i].join();
	}

	cout << "in major thread" << endl;//在主线程
	return 0;
}
