#include <stdio.h>
#include "hal_api.h"

size_t __write(int Handle, const unsigned char * Buf, size_t Bufsize)
{
 	int nChars = 0;
 	/* Check for stdout and stderr 
 	(only necessary if file descriptors are enabled.) */
 	if (Handle != 1 && Handle != 2)
 	{
 		return -1;
 	}
 	for (/*Empty */; Bufsize > 0; --Bufsize)
 	{
 		DiagPutChar(*Buf++);
 		++nChars;
 	}
 	return nChars;
}

size_t __read(int Handle, unsigned char * Buf, size_t Bufsize)
{
	int nChars = 0;
	/* Check for stdin
	(only necessary if FILE descriptors are enabled) */
	if (Handle != 0)
	{
		return -1;
	}
	for (/*Empty*/; Bufsize > 0; --Bufsize)
	{
		int c = DiagGetChar(_FALSE);
		if (c < 0)
			break;
		*(Buf++) = c;
		++nChars;
	}
	return nChars;	
}