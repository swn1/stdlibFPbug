#include "windows.h"
#include <math.h>

static double load_exp(_In_ double _X);
extern "C" double(*imp_exp)(double) = load_exp;

static double load_exp(_In_ double _X)
{
	imp_exp = (double(*)(double)) GetProcAddress(GetModuleHandle(TEXT("msvcr120.dll")), "exp");
	return imp_exp(_X);
}