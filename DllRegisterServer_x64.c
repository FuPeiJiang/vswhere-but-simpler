#include <stdio.h>
#include <windows.h>
#include <olectl.h>

#pragma comment(lib, "Ole32.lib")

int main() {
    CoInitialize(0);

    HMODULE hModule = LoadLibraryA("C:\\ProgramData\\Microsoft\\VisualStudio\\Setup\\x64\\Microsoft.VisualStudio.Setup.Configuration.Native.dll");
    typeof(DllRegisterServer) *myDllRegisterServer = (typeof(DllRegisterServer)*)GetProcAddress(hModule, "DllRegisterServer");

    HRESULT hResult = myDllRegisterServer();
    printf("%08lX\n",hResult);
}