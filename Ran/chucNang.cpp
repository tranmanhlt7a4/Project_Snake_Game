#include "chucNang.h"

#define X_MIN 60
#define Y_MIN 58
#define X_MAX 580
#define Y_MAX 409

extern int sizeRan;
extern int diem;
extern char *thanRan[2];

int REFRESH_RATE(300);

void KhoiDong()
{
    cleardevice();

    //Đặt lại màu nền
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(10, 10, BLACK);

    sizeRan = 5; //Đặt lại kích thước rắn
    taoRanLanDau(); //Tạo rắn lần đầu
    taoMoi(); // Tạo mồi
    TaoKhuVucChoi();
}

void Lap()
{
    static bool daTang = false;
    while(conSong())
    {
        anMoi(); //Có ăn mồi không
        bamPhim(); //Điều khiển rắn
        CapNhatTrangThai(); //Cập nhật thông tin

        //nếu sizeRan tròn chục thì tăng tốc rắn lên 50 milis
        if(sizeRan % 5 == 0 && !daTang)
        {
            if(REFRESH_RATE > 50)
            {
                REFRESH_RATE -= 30;
            }
            daTang = true;
        }

        if(sizeRan % 5 != 0 && daTang)
        {
            daTang = false;
        }

        delay(REFRESH_RATE);
    }
}

void CapNhatTrangThai()
{
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    setcolor(WHITE);
    char status[50];
    sprintf(status, "Score: %d Length: %d Speed: %d", diem, sizeRan, 300 - REFRESH_RATE + 10);
    outtextxy(0, 10, status);
}

int khoiDongDoHoa()
{
    int mh = DETECT, mode = DETECT;
    initgraph(&mh, &mode, "D:\\BGI");

    return graphresult();
}

void TaoKhuVucChoi()
{
    for(int y = Y_MIN; y <= Y_MAX; y += 13)
    {
        putimage(60, y, thanRan[1], XOR_PUT);
        for(int x = X_MIN + 13; x <= X_MAX - 13; x += 13)
        {
            if(y == Y_MIN || y == Y_MAX)
            {
                putimage(x, y, thanRan[1], XOR_PUT);
            }
        }
        putimage(X_MAX, y, thanRan[1], XOR_PUT);
    }
}

void tamDung()
{
    //Xóa hết phím còn tồn tại nếu có
    while(kbhit())
    {
        getch();
    }

    outtextxy(0, 25, "Pause");
    outtextxy(0, 40, "Press any key (except Enter) to continue...");

    while(!kbhit())
    {

    }

    outtextxy(0, 25, "                         ");
    outtextxy(0, 40, "                                                                          ");
    return;
}
