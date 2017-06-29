#include<iostream>
#include<thread>
using namespace std;

void hello(){
	cout<<"hello thread"<<endl;
}

int main()
{
	thread t(hello);
	//join a thread in program,and main function will finish after  this thread 
	t.join();
	//detach a thread in program,and main function will finish before this thread 
	t.detach();
	return 0;
}
