#include <Windows.h>

#define WIN32_LEAN_AND_MEAN

int main() {
    
    
    const int targetG=219;
    const int x=700;
    const int y=500;

    HDC dng = GetDC(NULL); 
    int currentG;

    while (1) {
        Sleep(50);
        while(GetAsyncKeyState( VK_LSHIFT )) {
            COLORREF c = GetPixel(dng, x, y);

            currentG = GetGValue(c);

            if(currentG == targetG)
            {
                SetCursorPos(x,y);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
                mouse_event(MOUSEEVENTF_LEFTUP  , 0, 0, 0, 0 );
            }
        }

        if(GetAsyncKeyState( VK_DELETE )) {
            break;
        }
    }

    ReleaseDC(NULL, dng);
    Sleep(100);

    return EXIT_SUCCESS;
}
