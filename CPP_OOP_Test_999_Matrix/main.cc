#include <Windows.h>
#include <string.h>
 
//Код тут: https://www.youtube.com/watch?v=JV1bro7eK04
 
//API - Application Programming Interface - Интерфейс программирования приложений
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
//Параметры:
//hInstance - дескриптор экземпляра содержит метаданные для ОС
//hPrevInstance - не используеться. Использовался в 16 битных системах
//pCmdLine - аргументы командной строки
//nCmdShow - кол-во аргументов. Минимум 1
{
    LPSTR string = "Hello!"; //то же что и char*
    LPWSTR wString = NULL; //то же что и wchar_t*
    LPTSTR tString = NULL; //Шаблонная строка, зависит от того как компилируется проект
    LPCWSTR WSTRING = L"Constant string";
 
    //Типы(самые частоиспользуемые)
 
    CHAR ch = 0; // == char
    WCHAR wch = 0; // == wchar_t
    TCHAR tch = 0; //Зависит от типа компиляции
 
    BOOL bResult = 0; //Не _Bool !!! Нужен для получения кода ошибки, или 0 в случае успеха == int
    BOOLEAN bTrue = 0;//Более похож на _Bool. Имеет размер 1Б
 
    BYTE iValSmall = 0; //== unsigned char(В видео натупил с комментарием!)
    WORD iVal = 0; // == unsigned short
    INT iInt = 0; // == int
    UINT uiInt = 0; // == unsigned int
    DWORD iValBig = 0; // == unsigned long
 
    FLOAT fVal = 0; //== float
 
    LPVOID p0 = NULL; // == void*
    PVOID p1 = NULL; // == LPVOID && == void*
 
    HANDLE h = NULL; //Рассмотрим в будущем. Дескриптор. Используеться повсеместно в WINAPI. == void*
 
    //Примеры WINAPI функций. функции конвертации char* -> wchar_t* && wchar_t* -> char*
    //В ASCII. Работает только в Windows!!!
    /*
    int WideCharToMultiByte(
                     _In_      UINT    CodePage,
                     _In_      DWORD   dwFlags,
                     _In_      LPCWSTR lpWideCharStr,
                     _In_      int     cchWideChar,
                     _Out_opt_ LPSTR   lpMultiByteStr,
                     _In_      int     cbMultiByte,
                     _In_opt_  LPCSTR  lpDefaultChar,
                     _Out_opt_ LPBOOL  lpUsedDefaultChar
                     );
    */
 
    LPCWSTR LPWSTR_TMP = L"Test message!";
    DWORD iSizeStr = wcslen(LPWSTR_TMP) + 1;
    LPSTR lpStrTmp = (PCHAR)calloc(iSizeStr, sizeof(CHAR));
 
    DWORD iResult = WideCharToMultiByte(
        CP_ACP,
        WC_NO_BEST_FIT_CHARS,
        LPWSTR_TMP,
        INFINITE, //-1
        lpStrTmp,
        iSizeStr,
        NULL,
        NULL);
 
    //В Unicode. Работает только в Windows!!!
    /*
    int MultiByteToWideChar(
          _In_      UINT   CodePage,
          _In_      DWORD  dwFlags,
          _In_      LPCSTR lpMultiByteStr,
          _In_      int    cbMultiByte,
          _Out_opt_ LPWSTR lpWideCharStr,
          _In_      int    cchWideChar
        );
    */
 
    //LPCSTR LPSTR_TMP = "Test message!";
    //DWORD iSizeStr = strlen(LPSTR_TMP) + 1;
    //LPWSTR lpWstrTmp = (PWCHAR)calloc(iSizeStr, sizeof(WCHAR));
 
    //DWORD iResult = MultiByteToWideChar(
    //  CP_ACP,
    //  MB_PRECOMPOSED,
    //  LPSTR_TMP,
    //  INFINITE,
    //  lpWstrTmp,
    //  iSizeStr);
 
    system("pause");
    return 0;
}