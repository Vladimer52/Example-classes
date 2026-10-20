template <typename T> T clamp(T value, T min, T max)
{
	if (value < min) return min;
	else if (value > max) return max;
	else return value;
}

template <typename T, size_t Capacity>
class RingBuffer {
private:
	T buffer_[Capacity];
	size_t count_ = 0;
public:
	void push(const T& item)
	{
		if (count_ < Capacity)
		{
			buffer_[count_++] = item;
		}
	}
	size_t size() const {
		return count_;
	}
};

int main(void)
{
	RingBuffer<float, 5> buffer;
	buffer.push(4.2);
	buffer.push(3.7);
	//3 весь шаблон должен быть реализован в одном файле, как я помню, в хидере. партишал класс не допускается в этом случае
}