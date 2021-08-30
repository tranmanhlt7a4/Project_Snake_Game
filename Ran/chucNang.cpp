#include "chucNang.h"
#include "menu.h"

#define X_MIN 60
#define Y_MIN 58
#define X_MAX 580
#define Y_MAX 409

#define MaxSize 50

extern int sizeRan;
extern int diem;
extern char *thanRan[2];
extern bool lanDau;
//Mảng chứa tọa độ khả dụng của mồi
extern int x_moi_kha_dung[37], y_moi_kha_dung[24];

//Các mảng toàn bộ lưu tọa độ của thân rắn
extern int x_tren_cu[MaxSize], y_tren_cu[MaxSize], x_duoi_cu[MaxSize], y_duoi_cu[MaxSize]; //Tọa độ cũ của thân rắn
extern int x_tren_moi[MaxSize], y_tren_moi[MaxSize], x_duoi_moi[MaxSize], y_duoi_moi[MaxSize]; //Tọa độ mới của thân rắn

extern char huong; //Lưu hướng hiện tại của rắn

extern int x_moi, y_moi; //Biến lưu tọa độ mồi

int diemCao;
bool isHighScore(false);
int thoiGianChoi;

int REFRESH_RATE(300);

void KhoiDong()
{
    cleardevice();

    //Đặt lại màu nền
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(10, 10, BLACK);

    //Đặt lại tọa độ
    for(int i = 0; i < MaxSize; i++)
    {
        x_tren_moi[i] = y_tren_moi[i] = x_duoi_moi[i] = y_duoi_moi[i] = 0;
        x_tren_cu[i] = y_tren_cu[i] = x_duoi_cu[i] = y_duoi_cu[i] = 0;
    }

    for(int i = 0; i < 37; i++)
    {
        x_moi_kha_dung[i] = 0;
    }

    for(int i = 0; i < 24; i++)
    {
        y_moi_kha_dung[i] = 0;
    }

    sizeRan = 5;
    huong = 'd';
    x_moi = y_moi = 0;
    lanDau = true;
    diem = 0;

    sizeRan = 5; //Đặt lại kích thước rắn
    taoRanLanDau(); //Tạo rắn lần đầu
    taoMoi(); // Tạo mồi
    TaoKhuVucChoi();
}

void Lap()
{
    static bool daTang = false;
    int batDau = time(0);

    while(conSong())
    {
        anMoi(); //Có ăn mồi không
        bamPhim(); //Điều khiển rắn
        CapNhatTrangThai(); //Cập nhật thông tin

        //nếu diem chia hết cho 5 thì tăng tốc rắn lên 30 milis
        if(diem % 5 == 0 && !daTang)
        {
            if(REFRESH_RATE > 100)
            {
                REFRESH_RATE -= 30;
            }
            daTang = true;
        }

        if(diem % 5 != 0 && daTang)
        {
            daTang = false;
        }

        delay(REFRESH_RATE);
    }
    int ketThuc = time(0);
    thoiGianChoi = ketThuc - batDau;
    if(diem > diemCao)
    {
        diemCao = diem;
        isHighScore = true;
    }
    else
    {
        isHighScore = false;
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
    outtextxy(0, 40, "Press any key to continue...");

    while(!kbhit())
    {

    }

    //Xóa hết phím còn tồn tại nếu có
    while(kbhit())
    {
        getch();
    }

    outtextxy(0, 25, "                         ");
    outtextxy(0, 40, "                                                                          ");
    return;
}
