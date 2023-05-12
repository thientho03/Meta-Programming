#pragma once
// primary template: yield second or third argument depending on first argument
template<bool C, typename Ta, typename Tb>
class IfThenElse;

// partial specialization: true yields second argument
template<typename Ta, typename Tb>
class IfThenElse<true, Ta, Tb> 
{
public:
	typedef Ta ResultT;
};

// partial specialization: false yields third argument
template<typename Ta, typename Tb>
class IfThenElse<false, Ta, Tb> 
{
public:
	typedef Tb ResultT;
};

 //primary template for main recursive step
template<int N, int LO = 1, int HI = N>
class sqrtIfThenElse {
public:
	// compute the midpoint, rounded up
	enum { mid = (LO + HI + 1) / 2 };

	// search a not too large value in a halved interval
	typedef typename IfThenElse<(N < mid * mid),
		sqrtIfThenElse<N, LO, mid - 1>,
		sqrtIfThenElse<N, mid, HI> >::ResultT
		SubT;

	enum { result = SubT::result };
};
