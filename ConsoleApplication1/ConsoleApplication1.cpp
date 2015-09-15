// compile in release x64, vs2013 update 5, full optimization, /fp:precise /fp:except,
// throws fp invalid op exception from instide the C++ runtime library due to what appears
// to be a vector instruction that should have been a scalar.  If you pass a number in
// the (totally irrelevant by-the-book) upper qword of xy, it does not crash.
//

#include <intrin.h>
#include "stdafx.h"
#include <float.h>
#include <math.h>

extern "C" __declspec(noinline)
double  __cdecl my_exp(_In_ double _X); // moved implementation to wrapper.cpp

__declspec(noinline)
double _vectorcall break_exp(__m128d xy)
{
	return my_exp(xy.m128d_f64[0])/2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	__m128d xy;
	_controlfp(0, _EM_INVALID);
	xy.m128d_f64[0] = 1.9;
	xy.m128d_f64[1] = nan("foo");
	return break_exp(xy) > 1;
}

