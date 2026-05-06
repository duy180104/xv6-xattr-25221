#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  // Kiểm tra xem người dùng có gõ đủ 4 chữ không (vd: setxattr README tacgia Duy)
  if(argc != 4){
    fprintf(2, "Cach dung: setxattr <ten_file> <key> <value>\n");
    exit(1);
  }

  // Gọi System Call truyền dữ liệu xuống Kernel
  if(setxattr(argv[1], argv[2], argv[3]) < 0){
    fprintf(2, "Loi: Khong the ghi xattr!\n");
    exit(1);
  }
  
  printf("Thanh cong! Da ghi [%s = %s] vao file %s\n", argv[2], argv[3], argv[1]);
  exit(0);
}