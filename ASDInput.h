#pragma once
#include "ASDString.h"
#include "fun_console.h"

namespace ASD {
	class Input
	{
		ASD::String mask;
		ASD::String str;
	public:
		Input(ASD::String m) { mask = m; }
		ASD::String get() { return str; }
		bool input(int, int);
	};
}

