/*******************************************************************************
*
* Program: auto_play
*
* Description: To config AutoPlay action, default/noAction.
*
* Author: Jason Zheng quan3969@qq.com
*
*******************************************************************************/

/*******************************************************************************
* Default:
* HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer
*   \AutoplayHandlers
*      DisableAutoplay  *Delete*
*      \EventHandlersDefaultSelection
*         \StorageOnArrival
*            (Default)  REG_SZ  MSPromptEachTime
*         \CameraAlternate\ShowPicturesOnArrival
*            (Default)  REG_SZ  MSPromptEachTime
*      \UserChosenExecuteHandlers
*         \StorageOnArrival
*            (Default)  REG_SZ  MSPromptEachTime
*         \CameraAlternate\ShowPicturesOnArrival
*            (Default)  REG_SZ  MSPromptEachTime
*
* NoAction:
* HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer
*   \AutoplayHandlers
*      DisableAutoplay  REG_DWORD  1
*      \EventHandlersDefaultSelection
*         \StorageOnArrival
*            (Default)  REG_SZ  MSTakeNoAction
*         \CameraAlternate\ShowPicturesOnArrival
*            (Default)  REG_SZ  MSTakeNoAction
*      \UserChosenExecuteHandlers
*         \StorageOnArrival
*            (Default)  REG_SZ  MSTakeNoAction
*         \CameraAlternate\ShowPicturesOnArrival
*            (Default)  REG_SZ  MSTakeNoAction
* 
*******************************************************************************/

#include "auto_play.h"
#include "reg_action.h"

int set_default()
{
    HKEY hKey;
    LPCTSTR lpSubKey = TEXT(
        "Software\\Microsoft\\Windows\\CurrentVersion\\"
        "Explorer\\AutoplayHandlers"
        );
    DWORD value_to_set = 1;
    LPCTSTR key_value = TEXT("MSPromptEachTime");
    DWORD key_length = sizeof(L"MSPromptEachTime");

 
    int lResult = RegOpenKeyEx(HKEY_CURRENT_USER,
        lpSubKey,
        0,
        KEY_ALL_ACCESS | KEY_WOW64_64KEY,
        &hKey);

    if (lResult != ERROR_SUCCESS)
    {
        if (lResult == ERROR_FILE_NOT_FOUND) { printf("Key not found.\n"); }
        else { printf("Error opeing key.\n"); }
        return 1;
    }

    RegDeleteValue(hKey, TEXT("DisableAutoplay"));

    RegSetValue(
        hKey, 
        TEXT("EventHandlersDefaultSelection\\CameraAlternate"
        "\\ShowPicturesOnArrival"),
        REG_SZ, 
        key_value,
        key_length
        );
    
    RegSetValue(
        hKey, 
        TEXT("EventHandlersDefaultSelection\\StorageOnArrival"), 
        REG_SZ, 
        key_value,
        key_length
        );
    
    RegSetValue(
        hKey, 
        TEXT("UserChosenExecuteHandlers\\CameraAlternate"
        "\\ShowPicturesOnArrival"), 
        REG_SZ, 
        key_value,
        key_length
        );
    
    RegSetValue(
        hKey, 
        TEXT("UserChosenExecuteHandlers\\StorageOnArrival"), 
        REG_SZ, 
        key_value,
        key_length
        );

    RegCloseKey(hKey);
    return 0;
}

int set_no_action()
{
    HKEY hKey;
    LPCTSTR lpSubKey = TEXT(
        "Software\\Microsoft\\Windows\\CurrentVersion\\"
        "Explorer\\AutoplayHandlers"
        );
    DWORD value_to_set = 1;
    LPCTSTR key_value = TEXT("MSTakeNoAction");
    DWORD key_length = sizeof(L"MSTakeNoAction");

 
    int lResult = RegOpenKeyEx(HKEY_CURRENT_USER,
        lpSubKey,
        0,
        KEY_ALL_ACCESS | KEY_WOW64_64KEY,
        &hKey);

    if (lResult != ERROR_SUCCESS)
    {
        if (lResult == ERROR_FILE_NOT_FOUND) { printf("Key not found.\n"); }
        else { printf("Error opeing key.\n"); }
        return 1;
    }

    RegSetValueEx(hKey,
        TEXT("DisableAutoplay"), 
        0,
        REG_DWORD,
        (LPBYTE)&value_to_set,
        sizeof(value_to_set)
        );

    RegSetValue(
        hKey, 
        TEXT("EventHandlersDefaultSelection\\CameraAlternate"
        "\\ShowPicturesOnArrival"),
        REG_SZ, 
        key_value,
        key_length
        );
    
    RegSetValue(
        hKey, 
        TEXT("EventHandlersDefaultSelection\\StorageOnArrival"), 
        REG_SZ, 
        key_value,
        key_length
        );
    
    RegSetValue(
        hKey, 
        TEXT("UserChosenExecuteHandlers\\CameraAlternate"
        "\\ShowPicturesOnArrival"), 
        REG_SZ, 
        key_value,
        key_length
        );
    
    RegSetValue(
        hKey, 
        TEXT("UserChosenExecuteHandlers\\StorageOnArrival"), 
        REG_SZ, 
        key_value,
        key_length
        );

    RegCloseKey(hKey);
    return 0;
}

int setup_auto_play()
{
    int user_choise;
    printf("\n"
        "=====================================================\n"
        "AutoPlay:\n"
        "  1. Default\n"
        "  2. No action\n\n"
        "Set AutoPlay to? (1/2): "
        );

    scanf("%d", &user_choise);

    if (user_choise == 1)
    {
        if (set_default() ==0)
            printf("\n"
                "AutoPlay set to default.\n\n"
                );
        else 
            printf("\n"
                "Setup fail.\n\n");
    }
    else if (user_choise == 2)
    {
        if (set_no_action() ==0)
            printf("\n"
                "AutoPlay set to no action.\n\n"
                );
        else 
            printf("\n"
                "Setup fail.\n\n");
    }
    else
    {
        printf("\n"
                "Set cancel.\n\n"
                );
    }
}
