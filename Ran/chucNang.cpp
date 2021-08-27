#include "chucNang.h"

extern int sizeRan;
extern int diem;
extern char *thanRan[2];

int speed(300);

void KhoiDong()
{
    sizeRan = 5; //Đặt lại kích thước rắn
    taoRanLanDau(); //Tạo rắn lần đầu
    taoMoi(); // Tạo mồi
    TaoKhuVucChoi();
}

void Lap()
{
    while(conSong())
    {
        anMoi(); //Có ăn mồi không
        bamPhim(); //Điều khiển rắn
        CapNhatTrangThai(); //Cập nhật thông tin

        //nếu sizeRan tròn chục thì tăng tốc rắn lên 50 milis
        if(sizeRan % 10 == 0)
        {
            if(speed > 50)
            {
                speed -= 50;
            }
        }

        delay(speed);
    }
}

void CapNhatTrangThai()
{
    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    setcolor(WHITE);
    char status[50];
    sprintf(status, "Score: %d Length: %d Speed: %d", diem, sizeRan, 300 - speed + 10);
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
    int j_ngoai;
    for(int i = 71; i <= 396; i += 13)
    {
        putimage(60, i, thanRan[1], XOR_PUT);
        for(int j = 60; j <= 580; j += 13)
        {
            if(i == 71 || i == 396)
            {
                putimage(j, i, thanRan[1], XOR_PUT);
            }
            j_ngoai = j;
        }
        putimage(j_ngoai, i, thanRan[1], XOR_PUT);
    }
}
