#include <iostream>
#include <memory>
#include <mutex>
/*
class MutexGuard final
{
	std::mutex& mut_;
public:
	explicit MutexGuard(std::mutex& mut) : mut_(mut)
	{
		mut_.lock();
	}

	~MutexGuard()
	{
		mut_.unlock();

	}

};

//общий ресурс
std::mutex uart_mutex;

void do_work() {
	MutexGuard guard(uart_mutex); //создаем объект на стеке с захватом mutex
}

std::unique_ptr<int> create_buffer()
{
	auto out = std::make_unique<int>();
	*out = 42;
	return out;
}

extern "C" void disable_interrupts();
extern "C" void enable_interrupts();

class InterruptGuard final
{
public:
	InterruptGuard()
	{
		enable_interrupts();
	}
	~InterruptGuard()
	{
		disable_interrupts();
	}
};

int read_sensor_safe()
{
	InterruptGuard guard;
	int val = 10;
	if (val == 10) return -1;
	 return val;

}

int main(void)
{/*
	
	std::cout << "buffer: " << *create_buffer() << '\n';
	//3 создаем умный указатель на сенсор через make_unique. далее создаем указатель на указатель получается. освобождаем raw через delete. умный указатель после этого тоже должен будет освободиться. но он уже освбожден. будет UB
	//4 
	auto buffer = std::make_unique<uint8_t[]>(1024); // буффер на 1024 байта
}*/