#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  char val[64]; // Mảng chứa kết quả trả về từ đĩa

  // Kiểm tra xem gõ đủ 3 chữ không (vd: getxattr README tacgia)
  if(argc != 3){
    fprintf(2, "Cach dung: getxattr <ten_file> <key>\n");
    exit(1);
  }

  // Gọi System Call lấy dữ liệu lên
  if(getxattr(argv[1], argv[2], val) < 0){
    fprintf(2, "Loi: Khong tim thay xattr hoac file khong ton tai!\n");
    exit(1);
  }

  // In kết quả ra màn hình Terminal
  printf("%s: %s\n", argv[2], val);
  exit(0);
}