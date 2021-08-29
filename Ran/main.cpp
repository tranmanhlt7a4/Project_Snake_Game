#include <iostream>
#include "menu.h"
#include "chucNang.h"

using namespace std;

#define ESC 27

int main()
{
    if(khoiDongDoHoa() != 0)
    {
        cout << "Loi do hoa! " << grapherrormsg(khoiDongDoHoa()) << endl;
        exit(-1);
    }

    menuBatDau();

    while(getch() != ESC)
    {

    }

    closegraph();
    return 0;
}
