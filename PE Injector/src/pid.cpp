#include "..\inc\main.hpp"



PortableExecutable::DWORD GetPid(LPCTSTR ProcessName) {
    pinfo.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(ProcessesShot, &pinfo)) { 
        do {
            if (!lstrcmpi(pinfo.szExeFile, ProcessName)) {
                CloseHandle(ProcessesShot);
                return pinfo.th32ProcessID;
            }
        } while (Process32Next(ProcessesShot, &pinfo));
    }
    CloseHandle(ProcessesShot); 
    return 0;
}




