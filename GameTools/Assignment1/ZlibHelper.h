#pragma once

#include <string>
#include "zlib128-dll\include\zlib.h"

namespace ZLib
{
	void Compress(std::string buffer, const char* outputFileName, unsigned long& sizeDataCompressed)
	{
		int sizeDataOriginal = buffer.size();
		Byte * dataOriginal = (Byte*)malloc(sizeDataOriginal);
		strncpy((char*)dataOriginal, buffer.c_str(), sizeDataOriginal);

		sizeDataCompressed = (sizeDataOriginal  * 1.1) + 12;

		Byte * dataCompressed = (Byte*)malloc(sizeDataCompressed);

		int z_result = compress(

			dataCompressed,         // destination buffer,
									// must be at least
									// (1.01X + 12) bytes as large
									// as source.. we made it 1.1X + 12bytes

			&sizeDataCompressed,    // pointer to var containing
									// the current size of the
									// destination buffer.
									// WHEN this function completes,
									// this var will be updated to
									// contain the NEW size of the
									// compressed data in bytes.

			dataOriginal,           // source data for compression

			sizeDataOriginal);    // size of source data in bytes

		switch (z_result)
		{
		case Z_OK:
			printf("***** SUCCESS! *****\n");
			break;

		case Z_MEM_ERROR:
			printf("out of memory\n");
			exit(1);    // quit.
			break;

		case Z_BUF_ERROR:
			printf("output buffer wasn't large enough!\n");
			exit(1);    // quit.
			break;
		}

		FILE * out = fopen(outputFileName, "wb");
		fwrite(dataCompressed, sizeDataCompressed, 1, out);
		fclose(out);

		free(dataOriginal);
		free(dataCompressed);
	
	}

	void UnCompress(std::string& buffer, char* inputFile, int OriginalSize, int sizeDataCompressed)
	{
		FILE * readFile = fopen(inputFile, "rb");
		fseek(readFile, 0, SEEK_END);
		unsigned long fileLength = ftell(readFile);
		rewind(readFile);
		Byte * dataReadInCompressed = (Byte*)malloc(fileLength);
		fread(dataReadInCompressed, fileLength, 1, readFile);
		unsigned long sizeDataUncompressed = OriginalSize;
		Byte * dataUncompressed = (Byte*)malloc(sizeDataUncompressed);

		int z_result = uncompress(

			dataUncompressed,       // destination for the uncompressed
									// data.  This should be the size of
									// the original data, which you should
									// already know.

			&sizeDataUncompressed,  // length of destination (uncompressed)
									// buffer

			dataReadInCompressed,   // source buffer - the compressed data

			sizeDataCompressed);   // length of compressed data in bytes

		switch (z_result)
		{
		case Z_OK:
			printf("***** SUCCESS! *****\n");
			break;

		case Z_MEM_ERROR:
			printf("out of memory\n");
			exit(1);    // quit.
			break;

		case Z_BUF_ERROR:
			printf("output buffer wasn't large enough!\n");
			exit(1);    // quit.
			break;
		}

		char* data = new char[OriginalSize];
		strncpy(data, (char*)dataUncompressed, OriginalSize);

		buffer = data;

		free(data);
		free(dataReadInCompressed);
		free(dataUncompressed);
	}

}