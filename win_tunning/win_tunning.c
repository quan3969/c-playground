/*******************************************************************************
*
* Program: WinTunning
*
* Description: A tool for optimizing your Windows.
*
* Author: Jason Zheng quan3969@qq.com
*
*******************************************************************************/

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


#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <strsafe.h>

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

//*************************************************************
//
//  RegDelNodeRecurse()
//
//  Purpose:    Deletes a registry key and all its subkeys / values.
//
//  Parameters: hKeyRoot    -   Root key
//              lpSubKey    -   SubKey to delete
//
//  Return:     TRUE if successful.
//              FALSE if an error occurs.
//
//*************************************************************

BOOL RegDelNodeRecurse (HKEY hKeyRoot, LPTSTR lpSubKey)
{
    LPTSTR lpEnd;
    LONG lResult;
    DWORD dwSize;
    TCHAR szName[MAX_PATH];
    HKEY hKey;
    FILETIME ftWrite;

    // First, see if we can delete the key without having
    // to recurse.

    lResult = RegDeleteKey(hKeyRoot, lpSubKey);

    if (lResult == ERROR_SUCCESS) 
        return TRUE;

    lResult = RegOpenKeyEx (hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

    if (lResult != ERROR_SUCCESS) 
    {
        if (lResult == ERROR_FILE_NOT_FOUND) {
            printf("Key not found.\n");
            return TRUE;
        } 
        else {
            printf("Error opening key.\n");
            return FALSE;
        }
    }

    // Check for an ending slash and add one if it is missing.

    lpEnd = lpSubKey + lstrlen(lpSubKey);

    if (*(lpEnd - 1) != TEXT('\\')) 
    {
        *lpEnd =  TEXT('\\');
        lpEnd++;
        *lpEnd =  TEXT('\0');
    }

    // Enumerate the keys

    dwSize = MAX_PATH;
    lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
                           NULL, NULL, &ftWrite);

    if (lResult == ERROR_SUCCESS) 
    {
        do {

            *lpEnd = TEXT('\0');
            StringCchCat(lpSubKey, MAX_PATH * 2, szName);

            if (!RegDelNodeRecurse(hKeyRoot, lpSubKey)) {
                break;
            }

            dwSize = MAX_PATH;

            lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
                                   NULL, NULL, &ftWrite);

        } while (lResult == ERROR_SUCCESS);
    }

    lpEnd--;
    *lpEnd = TEXT('\0');

    RegCloseKey (hKey);

    // Try again to delete the key.

    lResult = RegDeleteKey(hKeyRoot, lpSubKey);

    if (lResult == ERROR_SUCCESS) 
        return TRUE;

    return FALSE;
}

//*************************************************************
//
//  RegDelNode()
//
//  Purpose:    Deletes a registry key and all its subkeys / values.
//
//  Parameters: hKeyRoot    -   Root key
//              lpSubKey    -   SubKey to delete
//
//  Return:     TRUE if successful.
//              FALSE if an error occurs.
//
//*************************************************************

BOOL RegDelNode (HKEY hKeyRoot, LPCTSTR lpSubKey)
{
    TCHAR szDelKey[MAX_PATH*2];

    StringCchCopy (szDelKey, MAX_PATH*2, lpSubKey);
    return RegDelNodeRecurse(hKeyRoot, szDelKey);

}

int main()
{
    HKEY hKey;
    LPCTSTR lpSubKey = TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoplayHandlers");

    TCHAR achValue[MAX_VALUE_NAME]; 
    DWORD cchValue = MAX_VALUE_NAME; 
    DWORD cbData;
    DWORD dwRet;
 
    int lResult = RegOpenKeyEx(HKEY_CURRENT_USER,
        lpSubKey,
        0,
        KEY_ALL_ACCESS | KEY_WOW64_64KEY,
        &hKey);

    if( lResult != ERROR_SUCCESS )
    {
        if ( lResult == ERROR_FILE_NOT_FOUND ) { printf("Key not found.\n"); }
        else { printf("Error opeing key.\n"); }
        system("pause");
        return 1;
    }

/*     dwRet = RegQueryValueEx( HKEY_CURRENT_USER,
                             lpSubKey,
                             NULL,
                             NULL,
                             achValue,
                             &cchValue ); */

    RegGetValue(hKey,
                NULL,
                TEXT("DisableAutoplay"),
                RRF_RT_ANY,
                NULL,
                achValue,
                &cchValue);
    DWORD dwdata = 1234;

    RegCreateKey(hKey, TEXT("sdfsdf"), &hKey);
    RegSetValue(hKey, TEXT(""), REG_SZ, TEXT("MSTakeNoAction"), sizeof("MSTakeNoAction"));
    RegSetValueEx(hKey,
                TEXT("SDFJL"), 
                0,
                REG_DWORD,
                (LPBYTE)&dwdata,
                sizeof(dwdata));

    RegDeleteKey(hKey, TEXT("sdfsdf"));
    RegDelNode(hKey, TEXT(""));

    RegCloseKey(hKey);

    system("pause");
    return 0;
}
