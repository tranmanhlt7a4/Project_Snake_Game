#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <conio.h>

/*
 * Hàm khởi tạo tọa độ và hình rắn lần đầu
 * Hàm không trả về giá trị nào
*/
void taoRanLanDau();

/*
 * Hàm kiểm tra rắn còn sống hay đã chết (cắn vào người, đụng tường khu vực chơi xem như là đã chết)
 * Trả về true cho còn sống hoặc false cho đã chết
*/
bool conSong();

/*
 * Hàm xóa mồi ở vị trí cũ, tạo ngẫu nhiên vị trí mồi mới, rồi đưa mồi ra màn hình
 * Được gọi từ hàm anMoi()
 * Hàm không trả về giá trị nào
*/
void taoMoi();

/*
 * Hàm kiểm tra xem rắn có ăn mồi không (abs(x_duoi_ran[0] - x_moi) <= 2 && abs(y_duoi_ran[0] - y_moi) <= 2) được xem là đã ăn mồi
 * Hàm tăng điểm lên 1 đơn vị
 * Tạo thân mới
 * Hàm không trả về giá trị nào
*/
void anMoi();

/*
 * Hàm kiểm tra sự kiện bấm phím điều khiển của người chơi
 * Phím di chuyển gồm a, w, s, d cho di chuyển sang trái lên trên, xuống dưới, sang phải
 * Phím Enter mã 13 dùng để tạm dừng chương trình
*/

void bamPhim();


/*
 * Hàm thực hiện tạo hành động di chuyển của rắn
 * Cách hoạt động: Tọa độ phần thân sau là tọa độ cũ của phần thân trước
 * VD: Tọa độ thân rắn[i + 1] = Tọa độ cũ thân rắn[i];
*/

void diChuyen();
