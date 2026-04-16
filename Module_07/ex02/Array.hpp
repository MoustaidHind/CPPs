#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>
class Array
{

private:
	T *arr;
	int len;

public:
	Array()	{
		len = 0;
		arr = NULL;
	};

	Array(unsigned int n) {
		len = n;
		arr = new T[len]();
	};

	Array(const Array& src)
	{
		this->len = src.len;
		this->arr = new T[src.len]();	
		for (int i = 0; i < src.len; i++)
		{
			this->arr[i] = src.arr[i];
		}
	};

	Array& operator=(const Array& src)
	{
		if(this == &src)
			return(*this);

		delete [] this->arr;

		this->len = src.len;
		this->arr = new T[src.len];	
		for (int i = 0; i < src.len; i++)
		{
			this->arr[i] = src.arr[i];
		}

		return(*this);
	}

	~Array() {delete [] this->arr;};

	T& operator[](int i)
	{
		if(i < 0 || i >= len)
			throw std::exception();
		return(arr[i]);
	}

	const T& operator[](int i) const
	{
		if(i < 0 || i >= len)
			throw std::exception();
		return(arr[i]);
	}

	size_t size() const { return len; }
};


#endif