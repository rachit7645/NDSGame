#ifndef MACROS_H
#define MACROS_H

#define NDS_INLINE inline
#define NDS_STATIC static

#define STRINGYFY_HELPER(x) #x
#define STRINGYFY(x) STRINGYFY_HELPER(x)

#define TEXT_FMT(row, col, text) "\x1b[" STRINGYFY(row) ";" STRINGYFY(col) "H" text

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

#endif