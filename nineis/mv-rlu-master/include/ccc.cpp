
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo {
private:
	mutex m;
	condition_variable cv;
	bool b1;
	bool b2;
public:
	Foo() {
		b1 = false;
		b2 = false;
	}

	void first(function<void()> printFirst) {

		// printFirst() outputs "first". Do not change or remove this line.
		unique_lock<mutex> ul(m);
		printFirst();
		b1 = true;
		cv.notify_all();
	}

	void second(function<void()> printSecond) {

		// printSecond() outputs "second". Do not change or remove this line.
		unique_lock<mutex> ul(m);
		cv.wait(ul, [&]() {return b1; });
		printSecond();
		b2 = true;
		cv.notify_all();
	}

	void third(function<void()> printThird) {

		// printThird() outputs "third". Do not change or remove this line.
		unique_lock<mutex> ul(m);
		cv.wait(ul, [this]() {return b2; });
		printThird();
	}
};

int main() 
{
	function<void()> fun[3];
	fun[0] = []() {printf("1"); };
	fun[1] = []() {printf("2"); };
	fun[2] = []() {printf("3"); };

	vector<thread> vect;
	vector<int> vec{ 2,1,3 };

	Foo foo;

	using Func = void(Foo::*)(function<void()>);
	vector<Func> pmemfunc{ &Foo::first,&Foo::second,&Foo::third };

	for (auto i : vec)
	{
		vect.push_back(thread(pmemfunc[i-1],ref(foo),fun[i-1]));
	}

	for (auto& t : vect)
		t.join();

	system("pause");
	return 0;
}

