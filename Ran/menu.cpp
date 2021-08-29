#include "menu.h"
#include "chucNang.h"

#define Enter 13

void menuBatDau()
{
    //Tọa độ giữa màn hình VGA 640 * 480
    int x_giua = 640 / 2, y_giua = 480 / 2;

    //Khung chọn
    setcolor(CYAN); //Màu CYAN mode XOR_PUT sẽ ra màu đỏ
    setfillstyle(DOTTED_LINE, LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    rectangle(x_giua - 125, y_giua - 110, x_giua + 125, y_giua - 50);

    //Lưu lại khung chọn
    int soByteCan = imagesize(x_giua - 125, y_giua - 110, x_giua + 125, y_giua - 50);
    char *khungChon = (char*)malloc(soByteCan);
    getimage(x_giua - 125, y_giua - 110, x_giua + 125, y_giua - 50, khungChon);

    //Xóa màn hình
    cleardevice();

    //Khung menu
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setbkcolor(LIGHTGRAY);
    setlinestyle(LINE_FILL, 0, THICK_WIDTH);
    rectangle(x_giua - 140, y_giua - 140, x_giua + 140, y_giua + 140);
    floodfill(x_giua, y_giua, GREEN);
    floodfill(0, 0, GREEN);

    //Tiêu đề menu
    setcolor(BLACK);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(x_giua, y_giua - 130, "SNAKE");

    //Chức năng 1: Start
    settextstyle(SMALL_FONT, HORIZ_DIR, 9);
    setcolor(GREEN);
    outtextxy(x_giua, y_giua - 70, "Start");

    //Chức năng 2: Help
    outtextxy(x_giua, y_giua, "Help");

    //Chức năng 3: High score
    outtextxy(x_giua, y_giua + 80, "High score");

    //Tip
    setcolor(RED);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    settextjustify(CENTER_TEXT, BOTTOM_TEXT);
    moveto(x_giua, y_giua + 160);
    outtext("Tip: Use 'W' or 'S' key to move up or down. Press Enter to choose!");
    outtextxy(x_giua, y_giua + 180, "Version: 4.53.28.08.21 (Use C++ language)");
    outtextxy(x_giua, y_giua + 200, "Written by Tran Quang Manh");
    outtextxy(x_giua, y_giua + 220, "4 : 53 PM   28 - 08 - 2021");

    //Tọa độ chức năng 1: x_giua - 125, y_giua - 110
    //Tọa độ chức năng 2: x_giua - 125, y_giua - 40
    //Tọa độ chức năng 3: x_giua - 125, y_giua + 40

    //Mảng lưu các giá trị độ lệch với vị trí giữa để tính toán vị trí khung chọn
    int doLechChucNang[3] = {-110, -40, 40};

    //Biến lưu chức năng mà người dùng chọn
    int chucNang(0); //Chức năng đã chọn = chucNang + 1

    //Đặt khung chọn tại vị trí chức năng 1
    putimage(x_giua - 125, y_giua + doLechChucNang[chucNang], khungChon, XOR_PUT);

    //Xử lí sự kiện bấm phím
    while(true)
    {
        if(kbhit())
        {
            char phim = getch(); //Bắt lấy phím vùa bấm

            if(phim == 's' && chucNang < 2)
            {
                //Xóa khung chọn ở vị trí hiện tại
                putimage(x_giua - 125, y_giua + doLechChucNang[chucNang], khungChon, XOR_PUT);

                //Tăng đến tọa độ tiếp theo
                ++chucNang;

                //Đưa khung chọn ra màn hình tại vị trí mới
                putimage(x_giua - 125, y_giua + doLechChucNang[chucNang], khungChon, XOR_PUT);
            }
            if(phim == 'w' && chucNang > 0)
            {
                //Xóa khung chọn ở vị trí hiện tại
                putimage(x_giua - 125, y_giua + doLechChucNang[chucNang], khungChon, XOR_PUT);

                //Giảm xuống tọa độ trước
                --chucNang;

                //Đưa khung chọn ra màn hình tại vị trí mới
                putimage(x_giua - 125, y_giua + doLechChucNang[chucNang], khungChon, XOR_PUT);
            }
            if(phim == Enter)
            {
                break;
            }
        }
    }

    switch(chucNang)
    {
    case 0:
        KhoiDong();
        Lap();
        break;

    case 1:
        cleardevice();
        outtextxy(100, 100, "HELP");
        break;

    case 2:
        cleardevice();
        outtextxy(100, 100, "HIGH SCORE");

    }
}
