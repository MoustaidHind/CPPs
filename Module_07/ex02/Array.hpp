#ifndef ARRAY_HPP
#define ARRAY_HPP


template <class Array>
class Array
{
private:
	/* data */
public:
	Array() { Array arr[]; };
	Array(unsigned int n)
	{
		Array arr[n];
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = 0;
		}
	};

	~Array();
};






#endif