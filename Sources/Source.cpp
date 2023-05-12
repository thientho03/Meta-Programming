#include <iostream>

using namespace std;

template <int N>
class inc {
public:
	enum {
		value = inc<N - 1>::value + 1
	};
};

template <>
class inc<0>
{
public:
	enum {
		value = 0
	};
};

int main()
{
	 //inc<499>::value;
	inc<500>::value;

	return 0;
}

