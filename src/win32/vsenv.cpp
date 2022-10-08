#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Windows.h>
#include "microsoft_craziness.h"

#define println(fmt, ...) printf(fmt "\n", __VA_ARGS__)
#define fprintln(stream, fmt, ...) fprintf(stream, fmt "\n", __VA_ARGS__)

int main()
{
    char buffer[2048];

    auto result = find_visual_studio_and_windows_sdk();
    defer { free_resources(&result); };

    println("%ls", result.windows_sdk_root);
    println("%ls", result.windows_sdk_ucrt_library_path);
    println("%ls", result.windows_sdk_um_library_path);

    println("%ls", result.vs_exe_path);
    println("%ls", result.vs_library_path);

    FILE *file = fopen("vsenv.bat", "w");
    defer { fclose(file); };

    fprintln(file, "@echo off");
    fprintln(file, "set CommandPromptType=Native");
    fprintln(file, "set DevEnvDir=C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Commmon7\\IDE\\");
    fprintln(file, "set ExtensionSdkDir=C:\\Program Files (x86)\\Microsoft SDKs\\Windows Kits\\10\\ExtensionSDKs");
    fprintln(file, "set Framework40Version=v4.0");
    fprintln(file, "set FrameworkDir=C:\\Windows\\Microsoft.NET\\Framework64\\");

/*@echo off
set FrameworkDir64=C:\Windows\Microsoft.NET\Framework64\
set FrameworkVersion=v4.0.30319
set FrameworkVersion64=v4.0.30319
set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\ATLMFC\include;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\include;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\ucrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\shared;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\winrt;
set LIB=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\lib\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.16299.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.16299.0\um\x64;
set LIBPATH=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\lib\x86\store\references;C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.16299.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.16299.0;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;
set Path=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\bin\HostX64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\VC\VCPackages;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\bin\Roslyn;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Team Tools\Performance Tools\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Team Tools\Performance Tools;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\\x64;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\;C:\Program Files (x86)\Windows Kits\10\bin\x64;C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\\MSBuild\15.0\bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\;%PATH%
set Platform=x64
set UCRTVersion=10.0.16299.0
set UniversalCRTSdkDir=C:\Program Files (x86)\Windows Kits\10\
set VCIDEInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\VC\
set VCINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\
set VCToolsInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\
set VCToolsRedistDir=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Redist\MSVC\14.12.25810\
set VCToolsVersion=14.12.25827
set VisualStudioVersion=15.0
set VS150COMNTOOLS=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\
set VSCMD_ARG_app_plat=Desktop
set VSCMD_ARG_HOST_ARCH=x64
set VSCMD_ARG_TGT_ARCH=x64
set VSCMD_VER=15.5.1
set VSINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\
set WindowsLibPath=C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.16299.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.16299.0
set WindowsSdkBinPath=C:\Program Files (x86)\Windows Kits\10\bin\
set WindowsSdkDir=C:\Program Files (x86)\Windows Kits\10\
set WindowsSDKLibVersion=10.0.16299.0\
set WindowsSdkVerBinPath=C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\
set WindowsSDKVersion=10.0.16299.0\
set __DOTNET_ADD_64BIT=1
set __DOTNET_PREFERRED_BITNESS=64 */
}