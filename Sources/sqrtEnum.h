#pragma once

template <int N, int LO = 1, int HI = N>
class sqrtEnum 
{
public:
	// compute the midpoint, rounded up
	enum { mid = (LO + HI + 1) / 2 };

	// search a not too large value in a halved interval
	enum {
		result = (N < mid * mid) ? sqrtEnum<N, LO, mid - 1>::result : sqrtEnum<N, mid, HI>::result
	};
};

// partial specialization for the case when LO equals HI
template<int N, int M>
class sqrtEnum<N, M, M> 
{
public:
	enum { result = M };
};


