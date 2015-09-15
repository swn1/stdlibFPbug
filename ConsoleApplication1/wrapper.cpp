#include <intrin.h>
#include "stdafx.h"
#include <float.h>
#include <math.h>

// wrap exp to see assembler syntax for workaround construction;
// copied signature from math.h
extern "C" __declspec(noinline)
double  __cdecl my_exp(_In_ double _X)
{
	return 2 * exp(_X);
}