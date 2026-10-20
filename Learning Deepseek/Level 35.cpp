#include <iostream>


class IButton {
public:
	virtual ~IButton() = default;
	virtual bool isPressed() const = 0;

};

class HardwareButton : public IButton
{
public:
	bool isPressed() const override {
		return true;
	}
};

class App {
	IButton& button_;
public:
	App(IButton& button): button_(button){}
	void run()
	{
		if (button_.isPressed())
			std::cout << "Beep\n";
	}
	
};

class Isensor {
public:
	virtual ~Isensor() = default;
	virtual int read() = 0;
};

class DummySensor :public Isensor {
public:
	int read() override
	{
		return 42;
	}
};

class System {
	std::unique_ptr<Isensor> sensor_;
public:
	System(std::unique_ptr<Isensor> sensor) : sensor_(std::move(sensor))
	{

	}
};

int main(void)
{
	HardwareButton b1;
	App button(b1);
	button.run();

	auto my_sensor = std::make_unique<DummySensor>();
	System sys(std::move(my_sensor)); // нельзя копировать умный указатель, мы его просто передаем другому владельцу
}*/