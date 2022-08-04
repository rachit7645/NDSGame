#ifndef MACROS_H
#define MACROS_H

#define ARRAY_LENGTH(x) \
	do \
	{ \
		sizeof(x) / sizeof(x[0]) \
	} \
	while(0)

#endif