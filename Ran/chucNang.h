/*
 * Người tao: Trần Quang Mạnh
 * Ngày tạo: 3:36 PM 26-08-2021
*/

#include <stdio.h>
#include <conio.h>

#include "ran.h"

/*
 * Tiến hành các thiết đặt khởi đầu cho game như rắn, mồi,...
 * Được gọi lại khi bắt đầu màn chơi khác
 * Chỉ gọi 1 lần
 * Không trả về giá trị
*/
void KhoiDong();

/*
 * Lặp cho đến khi trò chơi kết thúc
 * Được gọi lại khi bắt đầu màn chơi khác
 * Chỉ gọi 1 lần
 * Không trả về giá trị
*/
void Lap();

/*
 * Hàm cập nhật các giá trị như điểm, chiều dài,...
 * Hàm không trả về giá trị
*/
void CapNhatTrangThai();

/*
 * Hàm tạo khu vực chơi kích thước xxx * xxx thân rắn
 * Không trả về giá trị
*/
void TaoKhuVucChoi();

/*
 * Hàm khởi động đồ họa
 * Không nhận vào giá trị
 * Hàm trả về kết quả của hàm graphresult()
*/
int khoiDongDoHoa();
