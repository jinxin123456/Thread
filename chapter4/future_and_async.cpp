#include<future>
#include<iostream>

using namespace std;

int find_the_answer_to_ltuae();
void do_other_stuff();
int main()
{
	future<int> the_answer=async(find_the_answer_to_ituae);
	do_other_stuff();
	cout<<"the answer is "<<the_answer.get()<<endl;
}
