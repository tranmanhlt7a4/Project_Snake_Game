#include "menu.h"
#include "chucNang.h"

#define Enter 13

void menuBatDau()
{
start: //Nhãn để tạo lại menu khi thoát khỏi menu High Score và Help

    cleardevice();//Xóa màn hình
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
        menuHelp();
        goto start;

    case 2:
        break;
    }
}

void menuHelp()
{
    cleardevice();
    int x_giua = 640 / 2, y_giua = 480 / 2;

    setcolor(RED);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(x_giua, y_giua - 200, "HELP");


    setcolor(BLUE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    outtextxy(x_giua - 190, y_giua - 150, "You use:");
    setcolor(GREEN);
    outtextxy(x_giua - 190, y_giua - 120, "        w to move up");
    outtextxy(x_giua - 190, y_giua - 100, "       a to turn left");
    outtextxy(x_giua - 190, y_giua - 80,  "             s to move down");
    outtextxy(x_giua - 190, y_giua - 60,  "         d to turn right");
    setcolor(BROWN);
    outtextxy(x_giua - 10, y_giua - 30,  "You eat bait to increase your score and your ");
    outtextxy(x_giua - 200, y_giua - 10, "snake's length");
    outtextxy(x_giua - 10, y_giua + 20, "Your snake's speed will increase after each 5");
    outtextxy(x_giua - 250, y_giua + 40, "scores");

    setcolor(RED);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);

    //Tạo chữ nhấp nháy
    while(!kbhit())
    {
        outtextxy(x_giua, y_giua + 200, "Tip: Press any key to return main menu.");
        outtextxy(x_giua, y_giua + 200, "                                                                           ");
        if(kbhit())
        {
            //Xóa hết bộ đệm
            while(kbhit())
            {
                getch();
            }
            break;
        }
    }

    //Đặt lại màu nền
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(10, 10, BLACK);
}

