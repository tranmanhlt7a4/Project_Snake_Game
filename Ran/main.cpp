#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "menu.h"
#include "chucNang.h"

using namespace std;

int main()
{
    if(khoiDongDoHoa() != 0)
    {
        cout << "Loi do hoa! " << grapherrormsg(khoiDongDoHoa()) << endl;
        exit(-1);
    }

    menuBatDau();

    return 0;
}
