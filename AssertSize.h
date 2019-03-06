#pragma once

#define AssertSize(Size, Struct) \
	static_assert((Size) == sizeof(Struct), "Expected sizeof(" #Struct ") == " #Size)
