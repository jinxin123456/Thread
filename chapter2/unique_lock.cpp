#include<iostream>
#include<thread>

using namespace std;

class some_big_object;
void swap(some_big_object &lhs,some_big_object& rhs);

class X{
private:
	some_big_object some_detail;
	mutex m;
public:
	X(some_big_oject &sd):some_detail(sd){};
	friend void swap(X lsh,X rsh){
		if(lsh==rsh)
			return ;
		/*
		 * the use of unique_lock
		 *
		//ensure the mutex is unlock
		unique_lock<mutex> lock_a(lsh.m,defer_lock);
		unique_lock<mutex> lock_b(rsh.m.defer_lock);
		//lock the mutex
		lock(lock_a,lock_b);
		*/



		/*
		 *the use of lock_guard
		 * 
		//lock the mutex
		lock(lsh.m,rsh.m);
		//ensure the mutex is locked
		lock_guard<mutex> lock_a(lsh.m,adopt_lock);
		lock_guard<mutex> lock_b(rsh.m,adopt_lock);
		*/
		swap(lsh.somedetail,rsh.somedetail);
	}
};
