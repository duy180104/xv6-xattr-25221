#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[]) {
    char val[64];
    int fd;

    printf("=== KHOI DONG HE THONG AUTOMATED TEST XATTR ===\n");
    printf("Do an HDH - Nhom 25221\n\n");

    // 1. Tao mot file rong de test
    fd = open("testauto.txt", O_CREATE | O_RDWR);
    if(fd >= 0) close(fd);

    // ----------------------------------------------------
    // TEST CASE 1: Ghi va Doc hop le (Key < 4, Val < 8)
    // ----------------------------------------------------
    printf("[Test 1] Kiem tra ghi/doc du lieu hop le (tac - Duy)...\n");
    if(setxattr("testauto.txt", "tac", "Duy") < 0){
        printf("  -> [FAIL] Khong the ghi du lieu hop le!\n");
    } else {
        if(getxattr("testauto.txt", "tac", val) < 0){
             printf("  -> [FAIL] Khong the doc du lieu da ghi!\n");
        } else {
             printf("  -> [PASS] Thanh cong! Da doc duoc: %s\n", val);
        }
    }

    // ----------------------------------------------------
    // TEST CASE 2: Kiem thu chan Buffer Overflow (Key >= 4 hoac Val >= 8)
    // ----------------------------------------------------
    printf("\n[Test 2] Kiem tra chan loi Tran bo nho (Buffer Overflow)...\n");
    printf("  (He thong phai tu choi luong du lieu nay)\n");
    
    // Co tinh truyen key = "tacgia" (6 ky tu >= 4)
    if(setxattr("testauto.txt", "tacgia", "Duy") < 0){
        printf("  -> [PASS] He thong da chan thanh cong du lieu doc hai!\n");
    } else {
        printf("  -> [FAIL] Nguy hiem: He thong da cho phep du lieu tran o dia!\n");
    }

    printf("\n=== HOAN THANH QUA TRINH TEST ===\n");
    exit(0);
}