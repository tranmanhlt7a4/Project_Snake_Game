#include "Ran.h"
#include "chucNang.h"

#define MaxSize 50
#define Enter 13

#define X_MIN 60
#define Y_MIN 58
#define X_MAX 580
#define Y_MAX 409

//Mảng chứa tọa độ khả dụng của mồi
int x_moi_kha_dung[37], y_moi_kha_dung[24];

//Các mảng toàn bộ lưu tọa độ của thân rắn
int x_tren_cu[MaxSize], y_tren_cu[MaxSize], x_duoi_cu[MaxSize], y_duoi_cu[MaxSize]; //Tọa độ cũ của thân rắn
int x_tren_moi[MaxSize], y_tren_moi[MaxSize], x_duoi_moi[MaxSize], y_duoi_moi[MaxSize]; //Tọa độ mới của thân rắn
int sizeRan(5); //Biến lưu kích thước rắn

//Vùng nhớ lưu ảnh
//Kích thước thân rắn là 12*12 bit + 1 bit khoảng cách giữa hai thân
char *thanRan[2]; //0 là đầu rắn, 1 là thân rắn

char huong('d'); //Lưu hướng hiện tại của rắn

int diem(0); //Điểm của người chơi

int x_moi, y_moi; //Biến lưu tọa độ mồi

bool conSong()
{
    static bool lanDau(true); //Kiểm tra xem có phải là lần đầu gọi hàm không
    //Lần đầu gọi hàm thì x_duoi_moi[0] == 0

    if(lanDau)
    {
        lanDau = false;
        return true;
    }


    if(x_duoi_moi[0] <= X_MIN || y_duoi_moi[0] <= Y_MIN + 13 || x_duoi_moi[0] >= X_MAX || y_duoi_moi[0] >= Y_MAX)
    {
        outtextxy(100, 100, "DIE 1");
        return false;
    }

    for(int i = 1; i < sizeRan; i++)
    {
        if(x_tren_moi[0] == x_tren_moi[i] && y_tren_moi[0] == y_tren_moi[i] && x_duoi_moi[0] == x_duoi_moi[i] && y_duoi_moi[0] == y_duoi_moi[i])
        {
            if(x_tren_moi[0] != 0 && y_tren_moi[0] != 0 && x_duoi_moi[0] != 0 && y_duoi_moi[0] != 0)
            {
                outtextxy(100, 100, "DIE 3");
                return false;
            }
        }
    }

    return true;
}

void taoMoi()
{
    static char *moi;

    if(x_moi == 0 && y_moi == 0) //Nếu là lần đầu
    {
        int i = 0;
        //Tạo tọa độ khả dụng cho mồi
        for(int y = Y_MIN + 13; y < Y_MAX - 13 * 2; y += 13)
        {
            y_moi_kha_dung[i] = y;
            i++;
        }

        i = 0;
        for(int x = X_MIN + 13; x < X_MAX - 13 * 2; x += 13)
        {
            x_moi_kha_dung[i] = x;
            i++;
        }

        //Chọn ngẫu nhiên vị trí mồi
        x_moi = rand() % 37;
        y_moi = rand() % 24;

        //Vẽ mồi tại vị trí trên
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        rectangle(x_moi_kha_dung[x_moi], y_moi_kha_dung[y_moi], x_moi_kha_dung[x_moi] + 13, y_moi_kha_dung[y_moi] + 13);
        floodfill(x_moi_kha_dung[x_moi] + 1, y_moi_kha_dung[y_moi] + 1, GREEN);

        //Lưu ảnh mồi
        int soByteCan = imagesize(x_moi_kha_dung[x_moi], y_moi_kha_dung[y_moi], x_moi_kha_dung[x_moi] + 13, y_moi_kha_dung[y_moi] + 13);
        moi = (char*)malloc(soByteCan);
        getimage(x_moi_kha_dung[x_moi], y_moi_kha_dung[y_moi], x_moi_kha_dung[x_moi] + 13, y_moi_kha_dung[y_moi] + 13, moi);
    }
    else //Các lần tiếp theo
    {
        //Xóa ảnh mồi cũ
        putimage(x_moi_kha_dung[x_moi], y_moi_kha_dung[y_moi], moi, XOR_PUT);

        //Lấy vị trí mồi mới
        while(true)
        {
            int x_moi_cu = x_moi, y_moi_cu = y_moi; //Lưu lại vị trí mồi cũ

            x_moi = rand() % 37;
            y_moi = rand() % 24;

            if(x_moi != x_moi_cu && y_moi != y_moi_cu) //Khi vị trí mồi mới khác vị trí cũ thì dừng lặp
            {
                break;
            }
        }

        //Đưa ảnh mồi ra vị trí mới
        putimage(x_moi_kha_dung[x_moi], y_moi_kha_dung[y_moi], moi, XOR_PUT);
    }
}

void anMoi()
{
    if(x_tren_moi[0] == x_moi_kha_dung[x_moi] && y_tren_moi[0] == y_moi_kha_dung[y_moi])
    {
        diem++;
        sizeRan++;
        taoMoi();
    }

    return;
}

void taoRanLanDau()
{
    int x_giua = getmaxx() / 2, y_giua = getmaxy() / 2; //toa do giua man hinh

    //tao dau ran
    setcolor(BLUE); //net ve xanh duong
    setfillstyle(SOLID_FILL, RED); //mau to do
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH); //be day net ve binh thuong

    x_tren_cu[0] = x_giua + 18; //toa do dau ran
    y_tren_cu[0] = y_giua - 6;
    x_duoi_cu[0] = x_giua + 30;
    y_duoi_cu[0] = y_giua + 6;

    rectangle(x_tren_cu[0], y_tren_cu[0], x_duoi_cu[0], y_duoi_cu[0]); //ve dau ran hinh vuong
    floodfill(x_giua + 24, y_giua, BLUE); //to mau dau ran bang mau do

    int soByteCan = imagesize(x_tren_cu[0], y_tren_cu[0], x_duoi_cu[0], y_duoi_cu[0]); //lay so byte can de luu anh dau ran
    thanRan[0] = (char*)malloc(soByteCan); //cap phat bo nho
    getimage(x_tren_cu[0], y_tren_cu[0], x_duoi_cu[0], y_duoi_cu[0], thanRan[0]); //luu hinh anh vao bo nho

    //toa do phan than dau tien
    setfillstyle(SOLID_FILL, YELLOW); //mau to vang;
    x_tren_cu[1] = x_tren_cu[0] - 12 * 1 - 1;
    y_tren_cu[1] = y_tren_cu[0];            //toa do cua phan than
    x_duoi_cu[1] = x_duoi_cu[0] - 12 * 1 - 1;
    y_duoi_cu[1] = y_duoi_cu[0];

    rectangle(x_tren_cu[1], y_tren_cu[1], x_duoi_cu[1], y_duoi_cu[1]); //ve phan than ran
    floodfill(x_tren_cu[1] + 1, y_tren_cu[1] + 1, BLUE);

    soByteCan = imagesize(x_tren_cu[1], y_tren_cu[1], x_duoi_cu[1], y_duoi_cu[1]); //lay so byte can de luu anh
    thanRan[1] = (char*)malloc(soByteCan); //cap phat bo nho
    getimage(x_tren_cu[1], y_tren_cu[1], x_duoi_cu[1], y_duoi_cu[1], thanRan[1]); //luu anh vao bo nho

    //ve than ran
    for(int i = 2; i < sizeRan; i++)
    {
        x_tren_cu[i] = x_tren_cu[0] - 12 * i - i;
        y_tren_cu[i] = y_tren_cu[0];            //toa do cua phan than
        x_duoi_cu[i] = x_duoi_cu[0] - 12 * i - i;
        y_duoi_cu[i] = y_duoi_cu[0];

        putimage(x_tren_cu[i], y_tren_cu[i], thanRan[1], XOR_PUT);
    }
}

void bamPhim()
{
    //Nếu có sự kiện bấm phím
    if(kbhit())
    {
        char phim = getch(); //Bắt lấy phím vừa bấm

        //Kiểm tra phím có hợp với hướng di chuyển không
        if(phim == 'a' && huong != 'd')
        {
            huong = phim;
        }
        else if(phim == 's' && huong != 'w')
        {
            huong = phim;
        }
        else if(phim == 'w' && huong != 's')
        {
            huong = phim;
        }
        else if(phim == 'd' && huong != 'a')
        {
            huong = phim;
        }
        else if(phim == Enter)
        {
            tamDung();
            return;
        }
    }

    diChuyen();
}


void diChuyen()
{
    for(int i = 0; i < sizeRan; i++)
    {
        if(i == 0) //Nếu là đầu rắn
        {
            putimage(x_tren_cu[i], y_tren_cu[i], thanRan[0], XOR_PUT); //Xóa ảnh đầu rắn

            switch(huong)
            {
            case 'a':
                x_tren_moi[0] = x_tren_cu[0] - 13;
                y_tren_moi[0] = y_tren_cu[0];
                x_duoi_moi[0] = x_duoi_cu[0] - 13;
                y_duoi_moi[0] = y_duoi_cu[0];
                break;
            case 's':
                x_tren_moi[0] = x_tren_cu[0];
                y_tren_moi[0] = y_tren_cu[0] + 13;
                x_duoi_moi[0] = x_duoi_cu[0];
                y_duoi_moi[0] = y_duoi_cu[0] + 13;
                break;
            case 'w':
                x_tren_moi[0] = x_tren_cu[0];
                y_tren_moi[0] = y_tren_cu[0] - 13;
                x_duoi_moi[0] = x_duoi_cu[0];
                y_duoi_moi[0] = y_duoi_cu[0] - 13;
                break;
            case 'd':
                x_tren_moi[0] = x_tren_cu[0] + 13;
                y_tren_moi[0] = y_tren_cu[0];
                x_duoi_moi[0] = x_duoi_cu[0] + 13;
                y_duoi_moi[0] = y_duoi_cu[0];
            }

            x_tren_moi[i + 1] = x_tren_cu[i];
            y_tren_moi[i + 1] = y_tren_cu[i];
            x_duoi_moi[i + 1] = x_duoi_cu[i];
            y_duoi_moi[i + 1] = y_duoi_cu[i];

            putimage(x_tren_moi[i], y_tren_moi[i], thanRan[0], XOR_PUT); //In ảnh rắn
            x_tren_cu[i] = x_tren_moi[i];
            y_tren_cu[i] = y_tren_moi[i];
            x_duoi_cu[i] = x_duoi_moi[i];
            y_duoi_cu[i] = y_duoi_moi[i];
        }
        else
        {
            putimage(x_tren_cu[i], y_tren_cu[i], thanRan[1], XOR_PUT); //Xóa ảnh rắn

            x_tren_moi[i + 1] = x_tren_cu[i];
            y_tren_moi[i + 1] = y_tren_cu[i];
            x_duoi_moi[i + 1] = x_duoi_cu[i];
            y_duoi_moi[i + 1] = y_duoi_cu[i];

            putimage(x_tren_moi[i], y_tren_moi[i], thanRan[1], XOR_PUT); //In ảnh rắn
            x_tren_cu[i] = x_tren_moi[i];
            y_tren_cu[i] = y_tren_moi[i];
            x_duoi_cu[i] = x_duoi_moi[i];
            y_duoi_cu[i] = y_duoi_moi[i];
        }

    }
}


