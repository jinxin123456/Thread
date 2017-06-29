

void some_function();
viod some_other_function();
thread t1(some_function);
thread t2=move(t1);
t1=thread(some_other_function);
thread(t3);
t3=move(t2);
