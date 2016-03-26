#include "stdafx.h"
typedef RPC_STATUS (__stdcall * pICFUNC)(UUID * Uuid);

//FixSCFdb3_MAC.00401000(guessed Arg1,Arg2,Arg3)
int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hModule = LoadLibraryA("RPCRT4.dll");

	if(!hModule)
	{
		printf("Error : Cannot load critical libraries\r\n");
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	FARPROC UuidCreateSequential2 = GetProcAddress((HMODULE)hModule, "UuidCreateSequential");
	//////////////////////////////////////////////////////////////////////////

	if(!UuidCreateSequential2)
	{
		printf("Error : Cannot load critical procedures\r\n");
		return 0;
	}

	UUID MacAddress;

	pICFUNC UuidCreateSequential3 = pICFUNC(UuidCreateSequential2);

	if( UuidCreateSequential3(&MacAddress) == RPC_S_UUID_NO_ADDRESS )
	{
		printf("Error : Cannot get internal adapter\r\n");
		return 0;
	}

 	FreeLibrary(hModule);
	
	printf("PLASMA32 productions...\r\n");
	Sleep(2000);

	printf("Returns to offer you...\r\n");
	Sleep(2000);

	printf("SCFdb3 cracked. Enjoy it!\r\n");
	Sleep(2000);

	char szMacAddress[12];
	sprintf(szMacAddress, "%02X-%02X-%02X-%02X-%02X-%02X", MacAddress.Data4[2], MacAddress.Data4[3], MacAddress.Data4[4], MacAddress.Data4[5], MacAddress.Data4[6], MacAddress.Data4[7]);

	HANDLE hFile = CreateFileA(".\\SCFdb3.exe", GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile == INVALID_HANDLE_VALUE)
	{
		printf("Error : Cannot open SCFdb3.exe\r\n");
		return 0;
	}

	Sleep(5000);

	unsigned int iFileSize = GetFileSize(hFile, NULL);
	char *Buffer = (char*)malloc(iFileSize);
	unsigned long dwBytesRead;

	if( !ReadFile(hFile, Buffer, iFileSize, &dwBytesRead, NULL) )
	{
		printf("Error : Cannot read SCFdb3.exe %d\r\n", GetLastError());
		return 0;
	}

	Sleep(5000);

	CloseHandle(hFile);

	//////////////////////////////////////////////////////////////////////////
	memcpy(Buffer+0x10C75, "CnB\000QuEr0__BCcFing1i3ld\0004y2tem4NEt", 34);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	HANDLE hFile2 = CreateFileA(".\\SCFdb3.exe", GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile2 == INVALID_HANDLE_VALUE)
	{
		printf("Error : Cannot open SCFdb3.exe\r\n");
		return 0;
	}

	if( !WriteFile(hFile2, Buffer, iFileSize, &dwBytesRead, NULL) )
	{
		printf("Error : Cannot write SCFdb3.exe\r\n");
		return 0;
	}

	Sleep(5000);

	free(Buffer);

	CloseHandle(hFile2);

	printf("SCFdb3.exe was patched successfully!!!\r\n");
	Sleep(9000);

	ExitProcess(0);
	
	return 0;
}

