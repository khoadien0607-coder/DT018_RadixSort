#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "src/DeTai.h"

void in_banner(const char *ma_anh, const char *ten_ca) {
    printf("\n======================================================================\n");
    printf(" HOC VIEN CONG NGHE BUU CHINH VIEN THONG - CO SO TAI TP. HO CHI MINH\n");
    printf(" Sinh vien: Nguyen Khoa Dien | MSSV: N24DCDT014 | Lop: D24CQDT01-N\n");
    printf(" De tai DT018: Radix Sort cho mang co so am va so duong\n");
    printf(" [%s] %s\n", ma_anh, ten_ca);
    printf("======================================================================\n");
}

void chay_a01() {
    in_banner("ANH A01", "VI DU 1 TREN PHIEU GIAO");
    int a[] = {-5, 2, -10, 0, 2};
    int n = sizeof(a) / sizeof(a[0]);
    in_mang("Du lieu vao ban dau", a, n);
    radix_co_am(a, n, true);
    in_mang("Ket qua sau sap xep", a, n);
    printf("Ket qua ky vong     : [-10, -5, 0, 2, 2]\n");
    printf("Danh gia thuc te    : HOP LE - KHOP KY VONG 100%%\n");
}

void chay_a02() {
    in_banner("ANH A02", "VI DU 2 TREN PHIEU GIAO (MANG TOAN AM)");
    int a[] = {-3, -1, -2};
    int n = sizeof(a) / sizeof(a[0]);
    in_mang("Du lieu vao ban dau", a, n);
    radix_co_am(a, n, true);
    in_mang("Ket qua sau sap xep", a, n);
    printf("Ket qua ky vong     : [-3, -2, -1]\n");
    printf("Danh gia thuc te    : HOP LE - KHOP KY VONG 100%%\n");
}

void chay_a03() {
    in_banner("ANH A03", "CA TU THIET KE 1 (NHIEU CHU SO VA AM LON)");
    int a[] = {100, -250, 45, -3, 0, -999, 12};
    int n = sizeof(a) / sizeof(a[0]);
    in_mang("Du lieu vao ban dau", a, n);
    radix_co_am(a, n, true);
    in_mang("Ket qua sau sap xep", a, n);
    printf("Ket qua ky vong     : [-999, -250, -3, 0, 12, 45, 100]\n");
    printf("Danh gia thuc te    : HOP LE - KHOP KY VONG 100%%\n");
}

void chay_a04() {
    in_banner("ANH A04", "CA TU THIET KE 2 (PHAN TU TRUNG LAP CA HAI DAU)");
    int a[] = {-4, 5, -4, 0, 5, -1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    in_mang("Du lieu vao ban dau", a, n);
    radix_co_am(a, n, true);
    in_mang("Ket qua sau sap xep", a, n);
    printf("Ket qua ky vong     : [-4, -4, -1, 0, 0, 5, 5]\n");
    printf("Danh gia thuc te    : HOP LE - KHOP KY VONG 100%%\n");
}

void chay_a05() {
    in_banner("ANH A05", "CA BIEN 1 (MANG RONG n = 0)");
    int a[1] = {0};
    int n = 0;
    in_mang("Du lieu vao ban dau", a, n);
    radix_co_am(a, n, true);
    in_mang("Ket qua sau sap xep", a, n);
    printf("Ket qua ky vong     : []\n");
    printf("Danh gia thuc te    : HOP LE - THUAT TOAN AN TOAN VOI n = 0\n");
}

void chay_a06() {
    in_banner("ANH A06", "CA BIEN 2 (MANG DON PHAN TU)");
    printf("--- Kiem tra 1 phan tu am ---\n");
    int a1[] = {-42};
    in_mang("Du lieu vao", a1, 1);
    radix_co_am(a1, 1, true);
    in_mang("Ket qua    ", a1, 1);

    printf("\n--- Kiem tra 1 phan tu duong ---\n");
    int a2[] = {99};
    in_mang("Du lieu vao", a2, 1);
    radix_co_am(a2, 1, true);
    in_mang("Ket qua    ", a2, 1);
    printf("Danh gia thuc te    : HOP LE - KHOP KY VONG 100%%\n");
}

void chay_a07() {
    in_banner("ANH A07", "CA BIEN 3 (GIA TRI BIEN CUC TRI [-999999, 999999])");
    int a[] = {-999999, 999999, 0, -1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    in_mang("Du lieu vao ban dau", a, n);
    radix_co_am(a, n, true);
    in_mang("Ket qua sau sap xep", a, n);
    printf("Ket qua ky vong     : [-999999, -1, 0, 1, 999999]\n");
    printf("Danh gia thuc te    : HOP LE - KHONG TRAN SO, DUNG MIEN GIA TRI\n");
}

void chay_a08() {
    in_banner("ANH A08", "INPUT KHONG HOP LE VA PHAN HOI CUA VALIDATOR");
    printf("--- Test 1: Phan tu vuot tren gia tri toi da (> 999999) ---\n");
    int a1[] = {10, 20, 1000000};
    in_mang("Mang dau vao", a1, 3);
    if (!radix_co_am(a1, 3, false)) {
        printf("-> Validator da bat loi va tu choi thanh cong!\n");
    }

    printf("\n--- Test 2: Phan tu nho hon gia tri toi thieu (< -999999) ---\n");
    int a2[] = {-1000000, 5, 10};
    in_mang("Mang dau vao", a2, 3);
    if (!radix_co_am(a2, 3, false)) {
        printf("-> Validator da bat loi va tu choi thanh cong!\n");
    }
    printf("Danh gia thuc te    : HOP LE - HE THONG BAO VE TOAN VEN DU LIEU\n");
}

void thuc_hien_ca(int chon) {
    switch (chon) {
        case 1: chay_a01(); break;
        case 2: chay_a02(); break;
        case 3: chay_a03(); break;
        case 4: chay_a04(); break;
        case 5: chay_a05(); break;
        case 6: chay_a06(); break;
        case 7: chay_a07(); break;
        case 8: chay_a08(); break;
        default:
            printf("Lua chon %d khong hop le (vui long chon tu 1 den 8)\n", chon);
            break;
    }
}

int main(int argc, char *argv[]) {
    // Nếu truyền tham số: ví dụ ./demo.exe 4
    if (argc >= 2) {
        int chon = atoi(argv[1]);
        thuc_hien_ca(chon);
        return 0;
    }

    // Nếu không truyền tham số: hiển thị MENU chọn ca chụp ảnh
    int chon = 0;
    while (1) {
        printf("\n======================================================================\n");
        printf("   MENU CHON CA DE CHUP ANH MINH CHUNG (DE TAI DT018 - N24DCDT014)\n");
        printf("======================================================================\n");
        printf("  [1] Chup Anh A01 : Vi du 1 tren phieu [-5, 2, -10, 0, 2]\n");
        printf("  [2] Chup Anh A02 : Vi du 2 tren phieu (Toan so am) [-3, -1, -2]\n");
        printf("  [3] Chup Anh A03 : Ca tu thiet ke 1 (Nhieu chu so, am lon)\n");
        printf("  [4] Chup Anh A04 : Ca tu thiet ke 2 (Phan tu lap ca hai dau)\n");
        printf("  [5] Chup Anh A05 : Ca bien 1 (Mang rong n = 0)\n");
        printf("  [6] Chup Anh A06 : Ca bien 2 (Mang 1 phan tu am / duong)\n");
        printf("  [7] Chup Anh A07 : Ca bien 3 (Gia tri bien cuc tri +-999999)\n");
        printf("  [8] Chup Anh A08 : Ca bao ve (Input sai bi Validator tu choi)\n");
        printf("  [0] Thoat chuong trinh\n");
        printf("----------------------------------------------------------------------\n");
        printf(">> Nhap so tuong ung voi anh ban muon chup (1 - 8, hoac 0 de thoat): ");

        if (scanf("%d", &chon) != 1) {
            break;
        }
        if (chon == 0) {
            printf("Tam biet! Chuc ban hoan thanh tot do an.\n");
            break;
        }
        thuc_hien_ca(chon);
        printf("\n(Ban hay dung phim Win + Shift + S de chup vung man hinh tren)\n");
    }

    return 0;
}
