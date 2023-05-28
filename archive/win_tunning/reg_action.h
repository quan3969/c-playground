/*******************************************************************************
*
* HKEY_CLASSES_ROOT
* HKEY_CURRENT_USER
* HKEY_LOCAL_MACHINE
* HKEY_USERS
* HKEY_CURRENT_CONFIG
* 
* Open Key
* Query/Set/Delete Key
* Close Key
*
*******************************************************************************/

// HKEY hKey;
// LPCTSTR lpSubKey = TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoplayHandlers");
// TCHAR achValue[MAX_VALUE_NAME]; 
// DWORD cchValue = MAX_VALUE_NAME; 
// DWORD cbData;
// DWORD dwRet;
// int lResult = RegOpenKeyEx(HKEY_CURRENT_USER,
//     lpSubKey,
//     0,
//     KEY_ALL_ACCESS | KEY_WOW64_64KEY,
//     &hKey);
// if( lResult != ERROR_SUCCESS )
// {
//     if ( lResult == ERROR_FILE_NOT_FOUND ) { printf("Key not found.\n"); }
//     else { printf("Error opeing key.\n"); }
//     system("pause");
//     return 1;
// }
// RegGetValue(hKey, NULL, 
//             TEXT("DisableAutoplay"),
//             RRF_RT_REG_DWORD,
//             NULL,
//             achValue,
//             &cchValue);
// DWORD dwdata = 1234;
// RegCreateKey(hKey, TEXT("sdfsdf"), NULL);
// /* Set Key */
// RegSetValue(hKey, TEXT(""), 
//             REG_SZ, TEXT("TEST"), 
//             sizeof("TEST"));
// /* Create Value */
// RegSetValueEx(hKey,
//             TEXT("SDFJL"), 
//             0,
//             REG_DWORD,
//             (LPBYTE)&dwdata,
//             sizeof(dwdata));
// /* Delete Key */
// RegDeleteKey(hKey, TEXT("sdfsdf"));
// /* Delete Key with Value */
// RegDelNode(hKey, TEXT(""));
// /* Delete Value */
// RegDeleteValue(hKey, TEXT("DisableAutoplay"));
// RegCloseKey(hKey);

#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <strsafe.h>
 
BOOL RegDelNode (HKEY hKeyRoot, LPCTSTR lpSubKey);