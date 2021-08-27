#include <iostream>
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

    KhoiDong();
    Lap();



    while(getch() != ESC)
    {

    }

    closegraph();
    return 0;
}
