#pragma GCC diagnostic error "-std=c++11"  
#include <iostream>
#include <atomic>
#include <mutex>

// ps: delete this instance when process ends
class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if ( instance == NULL )
			instance = new Singleton();
		return instance;
	}
private:
	Singleton()	{}
	static Singleton *instance;
};

// ps: no delete
// 2016-11-9: it's thread-safe in c++11 or maybe you can try call_once
class BetterSingleton
{
public:
	static BetterSingleton& GetInstance()
	{
		static BetterSingleton instance;
		return instance;
	}
private:
	BetterSingleton() {}
};

// ps: prevent from copied instance
class SuperSingleton
{
public:
	static SuperSingleton & GetInstance()
	{
		static SuperSingleton instance;
		return instance;
	}
private:
	SuperSingleton() {}
	SuperSingleton( const SuperSingleton & );
	SuperSingleton & operator = ( const SuperSingleton & );
};

// thread safe version in c++11 with double check
// reference: http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
class Foo
{
public:
	static Foo* Instance()
	{
		if( pinstance == nullptr )
		{
			std::lock_guard<std::mutex> lock(m_);
			if( pinstance == nullptr )
			{
				pinstance = new Foo();
			}
		}
		return pinstance;
	}
private:
	Foo() {}
	static std::atomic<Foo*> pinstance;
	static std::mutex m_;
};

int main()
{
	return 0;
}
