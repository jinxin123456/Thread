#include<iostream>
#include<mutex>

using namespace std;

unique_lock<mutex> get_lock()
{
	extern mutex x;
	unique<mutex> lk(x);
	prepare_data();
	return lk;
}
void process_data()
{
	unique_lock<mutex> lk(get_lock);
	do_something();
}
