#pragma once

#include <thread>
#include <condition_variable>
#include <mutex>
#include <future>
#include <functional>
#include <sstream>

condition_variable s_cv;
mutex s_mtx;

class ThreadObj
{
public:
	void thread_task(ThreadObj* obj)
	{
		LOG_FUNCTION;
		cout << "param " << GetTickCount() << endl;
		//Sleep(1000);

		cout << "wait notify..." << endl;
		unique_lock<mutex> ulock_(s_mtx);
		s_cv.wait(ulock_);
		cout << "thread over " << GetTickCount() << endl;
	}

	void thread2(std::future<string>& fut) {
		cout << "value:" << fut.get() << endl;
	}

	void thread3(std::shared_future<string>& fut) {
		cout << "value:" << fut.get() << GetCurrentThreadId() << endl;
		ostringstream oss;
		oss << GetCurrentThreadId() << endl;
	}
	
public:
	//mutex mtx_;
	int i_ = 0;
};


class thread_class
{
public:
	
private:
};

void test_thread()
{
	LOG_FUNCTION;
	GetSington()->GetInstance2();

	int i = 0;

	ThreadObj to;
	std::thread t1(&ThreadObj::thread_task, to, &to);
	cout << "join thread" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	s_cv.notify_one();
	t1.join();
	cout << "test_thread over" << endl;

	std::promise<string> prom;
	std::future<string> fut = prom.get_future();
	std::shared_future<string> shared_fut = fut.share();// prom.get_future();
	
	ThreadObj obj2;
	
	//std::thread t2 = std::thread(&ThreadObj::thread2, obj2, std::ref(fut));

	const int thread_num = 5;
	std::thread threads[thread_num];
	for (int i = 0; i < thread_num; ++i) {
		threads[i] = std::thread(&ThreadObj::thread3, obj2, std::ref(shared_fut));
	}
	
	prom.set_value("hello future"); 
	//t2.join();
	
	for (auto &th : threads) {
		th.join();
	}

}
