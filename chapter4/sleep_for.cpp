bool flag;
mutex m;

void wait_for_flag()
{
	unique_ptr<mutex> lk(m);
	while(!flag)
	{
		lk.unlock();
		this_thread::sleep_for(chrono::milliseconds(100));
		lk.lock();
	}
}
