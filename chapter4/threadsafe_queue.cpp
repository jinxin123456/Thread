#include<queue>
#include<mutex>
#include<condition_variable>

using namespace std;

template<typename T>
class threadsafe_queue{
private:
	mutex m;
	queue<T> data_queue;
	condition_variable data_cond;
public:
	void push(T new_value)
	{
		lock_guard<mutex> lk(m);
		data_queue.push(new_value);
		data_cond.notify_one();
	}
	void pop (T& value)
	{
		unique_lock<mutex> lk(m);
		data_cond.wait(lk,[this]{return !data_queue.empty();});
		value=data_queue.front();
		data_queue.pop();
	}
};
threadsafe_queue<data_chunk> data_queue;

void data_preparation_thread()
{
	while(more_data_to_prepare())
	{
		data_chunk const data=prepare_data();
		data_queue.push(data);
	}
}

void data_processing_thread()
{
	while(true)
	{
		data_chunk data;
		data_queue.wait_and_pop(data);
		priocess(data);
		if(is_last_chunk(data))
			break;
	}
}
