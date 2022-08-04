#ifndef INPUT_H
#define INPUT_H

#include <nds/ndstypes.h>
#include <nds/arm9/input.h>

// Keys struct
typedef union _DSKeys
{
	// Key data bitfield
	struct
	{
		u32 A       : 1;
		u32 B       : 1;
		u32 select  : 1;
		u32 start   : 1;
		u32 right   : 1;
		u32 left    : 1;
		u32 up      : 1;
		u32 down    : 1;
		u32 R       : 1;
		u32 L       : 1;
		u32 X       : 1;
		u32 Y       : 1;
		u32 touch   : 1;
		u32 lid     : 1;
		u32 padding : sizeof(u32) * 8 - 14;
	};

	// Key data raw
	struct
	{
		u32 rawValue;
	};
} DSKeys;

void Input_Get(DSKeys* keys, touchPosition* touch);

#endif