#include <graphics.h>
#include <stdio.h>
#include <conio.h>


/*
 * Hàm tạo menu bắt đầu
 * Menu gồm start, help, quit
 * Hàm trả về false cho biết người dùng chọn quit
*/
bool menuBatDau();

/*
 * Hàm tạo menu trợ giúp
 * Hướng dẫn chơi
 * Hàm không trả về giá trị
 * Bấm phím bất kì để trở về menu bắt đầu
*/
void menuTroGiup();

/*
 * Hàm tạo menu kết quả
 * Tổng hợp kết quả của người chơi
 * Hàm không trả về giá trị
 * Bấm phím bất kì để trở về menu bắt đầu
*/
void menuKetQua();
