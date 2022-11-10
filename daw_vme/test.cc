#include <iostream>
#include <CAENVMElib.h>

int main()
{

CVErrorCodes ret ;
int32_t Handle ; 
ret = CAENVME_Init(cvA3818,0,0,&Handle);
std::cout << "CAENVME_Init : " << ret << std::endl; 

char Rel[100] ; 
CAENVME_DriverRelease(Handle,Rel);
std::cout << "DriverRelease : " << Rel << std::endl ; 

uint64_t Basic ;
// Here the baseaddress is 1111 (according to the board backend) and the 8140 is board info register
CAENVME_ReadCycle(Handle,0x11118140,&Basic,cvA32_U_DATA, cvD32);
std::cout << "Board information" << std::hex << Basic << std::endl ; 

uint64_t retry ;
// Retry with no baseaddress 
CAENVME_ReadCycle(Handle,0x8140,&retry,cvA32_U_DATA, cvD32);
std::cout << "Board information" << std::hex  <<retry << std::endl ; 

// Have a try at no actual address 
CAENVME_ReadCycle(Handle,0x11118141,&Basic,cvA32_U_DATA, cvD32);
std::cout << "Board information" << std::hex << Basic << std::endl ; 

ret = CAENVME_End(Handle);
std::cout << "CAENVME_End : " << ret << std::endl; 
return 0 ; 
}
