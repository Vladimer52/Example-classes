#include <iostream>

/*class ILogger {
public: 
	virtual ~ILogger() = default;
	virtual void log(const std::string& msg) = 0;
};

class ConsoleLogger: public ILogger {
public:
	void log(const std::string& msg) override
	{
		std::cout << "[Console]: " << msg << '\n';
	}

};

class DummyLogger : public ILogger {
public: 
	void log(const std::string& msg) override
	{

	}
};

void do_work(ILogger& logger)
{
	logger.log("work started");
}

int main(void)
{
	ConsoleLogger clogger;
	DummyLogger dlogger;
	do_work(clogger);
	do_work(dlogger);
}*/

/*class UartTransmitter {
public:
	void sendBytes(const uint8_t* data, size_t len)
	{

	}
};

class TelemetrySender final {
	UartTransmitter transmitter;
public:

	void sendTemerature(int temp)
	{
		transmitter.sendBytes(reinterpret_cast<const uint8_t*>(&temp), sizeof(temp));
	}
	//4 делаем интерфейс IDummyTransmitter. в нем переопределяем sendBytes. при вызове тестов используем эту реализацию, а не настоящий Transmitter.
};

*/