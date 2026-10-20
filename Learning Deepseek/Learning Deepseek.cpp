#include <vector>
#include <string>
#include <iostream>


class Sensor {
public:
    Sensor(std::string name, int value)
        : name_(std::move(name)), value_(value) {}

    const std::string& name() const { return name_; }
    const int value() const { return value_; }

    void add_value(int delta)
    {
        value_ += delta;
    }



    // 1. Добавь const-методы:
    //    const std::string& name() const;
    //    int value() const;

    // 2. Добавь не-const метод:
    //    void add_value(int delta);

private:
    std::string name_;
    int value_;
};

int total_value(const std::vector<Sensor>& sensors)
{
    int sum = 0;
    for (const auto& sensor : sensors)
    {
        sum += sensor.value();
    }
    return sum;
}

void bump_all(std::vector<Sensor>& sensors, int delta)
{
    for (auto& sensor : sensors)
    {
        sensor.add_value(delta);
    }
}

// 3. Напиши функцию, которая принимает const std::vector<Sensor>&
//    и возвращает суммарное value всех датчиков.
//    int total_value(const std::vector<Sensor>& sensors);

// 4. Напиши функцию, которая принимает std::vector<Sensor>&
//    и увеличивает value каждого датчика на delta.
//    void bump_all(std::vector<Sensor>& sensors, int delta);
/*
int main() {
    std::vector<Sensor> sensors;
    sensors.emplace_back("temp", 20);
    sensors.emplace_back("hum", 60);
    sensors.emplace_back("press", 1013);

    std::cout << "total value: " << total_value(sensors) << "\n";
    bump_all(sensors, 5);
    std::cout << "total value: " << total_value(sensors) << "\n";

    // 5. Выведи total_value(sensors).
    // 6. Вызови bump_all(sensors, 5).
    // 7. Снова выведи total_value(sensors).
}*/
/*
1. дан вектор, первый перебор копирует значения, изменяться не буедт. второй перебор берет поссылке, к каждому прибавится 1. третий перебор читает, потому используется const auto. выведет 2 3 4
2. возвращаем ссылку на объект, который уже не будет существовать, будет UB.
3. нет объявления у даннго геттера. int get() const { return value_; }
*/
/*

#include <cmath>
#include <string>
#include <iostream>
struct Point {
    int x;
    int y;
};

void print(const Point& p)
{
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}

void print(int x, int y)
{
    std::cout << "(" << x << ", " << y << ")\n";
}

void print(const std::string& label, const Point& p)
{
    std::cout << label << ": (" << p.x << ", " << p.y << ")\n";
}

double distance(const Point& p, const Point& origin = { 0, 0 })
{
    double dx = p.x - origin.x;
    double dy = p.y - origin.y;
    return sqrt(dx * dx + dy * dy);
}


int main()
{
    Point a{ 3, 4 };
    print(a);
    print(1, 2);
    print("point a", a);
    std::cout << distance(a) << '\n';
    std::cout << distance(a, { 0,0 }) << '\n';
}


*/

/*namespace sensors {
    struct Sensor {
        std::string name;
        int value;
    };
    void print(const Sensor& s) { std::cout << "[sensor] " << s.name << ": " << s.value << '\n'; }
}

namespace logging {
    void print(const std::string& msg) { std::cout << "[log] " << msg << '\n'; }
}

int main()
{
    sensors::Sensor s{ "temp", 20 };
    sensors::print(s);
    logging::print("started");
    using sensors::print;
    print(s);
    using logging::print;
    print(s);
}*/

enum class Colors:uint8_t { Red, Blue, Black, White};
Colors c = Colors::Red;
int x = static_cast<int>(c);

//1
void process(int* p)
{
    if (p != nullptr)
        std::cout << "value: <" << *p << ">\n";
    else
        std::cout << "empty\n";
    //какие перегрузки ты хочешь тут вызвать?!
}

//2
enum class State { Idle, Running, Error};

/*const char* to_string(State s)
{
    //return //не понятно чего ты тут хочешь:) формулируй задачку
}*/

/*3
  в структуре данные публичные, просто данные, нет инвариантности
  в классе у нас есть приватные поля, которые дают инвариантность
*/

/*struct Reading {
    int value;
    uint32_t timestamp;
};

class Sensor1
{
    std::string name_;
    int value_;

public:
    Sensor1(std::string name, int val)
        : name_(std::move(name)), value_(val) {}
    int get_value() const { return value_; }
    std::string& get_name() const { return name_; }
    void add_value(int val)
    {
        value_ += val;
    }
};


int main()
{
    int* p = nullptr;
    process(p);
    int a = 123;
    p = &a;
    process(p);
    Reading r{ 1, 123456 };
    Sensor1 s("temp", 123);
    std::cout << s.get_name() << ", " << s.get_value() << '\n';
    std::cout << r.timestamp << ", " << r.value << '\n';
}


1. первое сделает копирование, второй уже прибавит 1, 3й перебор просто чтение поэлементно. выведет 2, 3, 4, 5
2. ссылка на объект, который уже может не существовать. получим либо мусор, либо падение
3. class Timer {
public:
    Timer(int ms)
        : ms_(std::move(ms)){ }
    int get_ms() const { return ms_; } //get_ms не считаю проблемой, если так будет не принято, то будем переучиваться. я всю жизнь, что java код так писал, что в си. 
    void set_ms(int ms) { ms_ = ms; }
private:
    int ms_;
};

4. bool contains(const std::vector<std::string>&v, const::string & name)
{
    for (const auto& str : v)
        if (str == name)
            return true;
    return false;
}

5. void print(int a)
{
    std::cout << "str: " << a << '\n';
}

void print(const std::string& a)
{
    std::cout << "str: " << a << '\n';
}

void print(const std::vector<int>& a)
{
    std::cout << "vec: " << a.size() << '\n';
}
6. 
у нас не будет неявного преобразован int в enum объект.
можно указать enum class Mode: uint8_t {off, on, Auto};

7. int area(int width, int height = 0)
{
    if (height == 0) height = width;
    return width * height;
}

8. если данный простые, нет инвариантности, то выбираем структуру. по умолчанию поля публичны. иначе выбираем класс, по умолчанию поля приватны. для Point выбираем структуру, данные простые. для Sensor нужен класс.
9. используем namespace до момента, пока существет ее время жизни, т.е пока жив main(). просто вызовем 2 раза init().
10. void f() {
    int a = 42;
    int* p = &a;
    if (*p > 0)
        std::cout << *p;

}

*/

/*разминка:
1. вектор v. а по ссылке на первый элемент, b просто копирует. первый элемент станет 10. выведет: "10 10 20\n"
2. мы не можем приравнивать параметры, которые только объявили в функции. это все делается в теле

задачи:*/
#include <array>
struct Sensor2 { std::string name; int value; };
int main() {

    //1
    std::array<int, 5> a{ 1, 2,3, 4,5 };
    std::cout << "size: " << a.size() << "\nfront: " << a.front() << "\nback: " << a.back() << '\n';
    for (const auto& element : a)
        std::cout << element << '\n';
   //2
    std::vector<int> b;
    for (size_t i = 0; i < 10; i++)
    {
        b.push_back(i);
        std::cout << "size: " << b.size() << "\n capacity: " << b.capacity() << '\n';
        // памяти обычно выделялось чуть больше, чем количество элементов
    }
    //3
    std::vector<int> c;
    c.reserve(10);
    for (size_t i = 0; i < 10; i++)
    {
        c.push_back(i);
        std::cout << "size: " << c.size() << "\n capacity: " << c.capacity() << '\n';
        //capacity всегда 10 перевыделения не было.
    }
    //4
    std::vector<Sensor2> sensors;
    Sensor2 temp{ "temp", 1 };
    Sensor2 gas{ "gas", 123 };
    Sensor2 light{ "light", 2 };
    sensors.emplace_back(temp);
    sensors.emplace_back(gas);
    sensors.emplace_back(light);
    for (const auto& sensor : sensors)
    {
        std::cout << sensor.name << " " << sensor.value << '\n';
    }
    //5
    a.size = 3;
    b.size = 1 // потому что была инициализация одного элемента, а не выделения 3х
}

#include <string_view>
void print_c_str(const char* p)
{
    std::cout << p << '\n';
}

bool stars_with(std::string_view s, std::string_view prefix)
{
    return s.substr(0, prefix.size()) == prefix;
}

int main(){
std::string s = "sensor";
s += "_temp";
std::cout << s << ", " << s.size() << ", " << s[0] << ", " << s.back() << '\n';
print_c_str(s.c_str());

std::cout << stars_with("hello world", "hello") << '\n';
}
//4
//стринг вью уже не будет существовать внутри функции. 
//5 выделение памяти произойдет при вызове объекта типа string, а string_view даст только просмотр без выделения памяти