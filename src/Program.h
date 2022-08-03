#ifndef PROGRAM_H
#define PROGRAM_H

#include <nds/ndstypes.h>

// Keys struct
// Equivalent to u32
typedef union _DSKeys
{
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
	u32 rawValue;
} DSKeys;

void Program_Run();
void Program_MainLoop();

#endif