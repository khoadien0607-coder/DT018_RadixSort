#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/DeTai.h"

static int total_tests = 0;
static int passed_tests = 0;

static bool mang_bang_nhau(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

static void chay_test(const char *test_id, const char *mo_ta, int a[], int n, const int expected[], int n_expected) {
    total_tests++;
    printf("[%s] %s ... ", test_id, mo_ta);
    
    bool ok = radix_co_am(a, n, false);
    if (ok && n == n_expected && mang_bang_nhau(a, expected, n)) {
        printf("PASS\n");
        passed_tests++;
    } else {
        printf("FAIL!\n");
        printf("   Actual:   ");
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n   Expected: ");
        for (int i = 0; i < n_expected; i++) printf("%d ", expected[i]);
        printf("\n");
    }
}

static void chay_test_validator(const char *test_id, const char *mo_ta, int a[], int n) {
    total_tests++;
    printf("[%s] %s ... ", test_id, mo_ta);
    bool ok = radix_co_am(a, n, false);
    if (!ok) {
        printf("PASS (Bi tu choi dung nhu ky vong)\n");
        passed_tests++;
    } else {
        printf("FAIL! (Validator khong phat hien ra loi)\n");
    }
}

int main() {
    printf("======================================================================\n");
    printf("   BO KIEM THU TU DONG - DE TAI DT018 (NGUYEN KHOA DIEN - N24DCDT014)\n");
    printf("======================================================================\n\n");

    // --- NHÓM 1: HAI VÍ DỤ TRÊN PHIẾU GIAO ĐỀ TÀI ---
    {
        int a[] = {-5, 2, -10, 0, 2};
        int exp[] = {-10, -5, 0, 2, 2};
        chay_test("TC01", "Vi du 1 tren phieu giao", a, 5, exp, 5);
    }
    {
        int a[] = {-3, -1, -2};
        int exp[] = {-3, -2, -1};
        chay_test("TC02", "Vi du 2 tren phieu giao (Toan so am)", a, 3, exp, 3);
    }

    // --- NHÓM 2: CÁC CA SINH VIÊN TỰ THIẾT KẾ ---
    {
        int a[] = {100, -250, 45, -3, 0, -999, 12};
        int exp[] = {-999, -250, -3, 0, 12, 45, 100};
        chay_test("TC03", "Mang hon hop nhieu chu so va am lon", a, 7, exp, 7);
    }
    {
        int a[] = {-4, 5, -4, 0, 5, -1, 0};
        int exp[] = {-4, -4, -1, 0, 0, 5, 5};
        chay_test("TC04", "Mang co nhieu phan tu trung lap ca hai dau", a, 7, exp, 7);
    }

    // --- NHÓM 3: CÁC CA BIÊN HỢP LỆ THEO PHIẾU ---
    {
        int a[1] = {0};
        int exp[1] = {0};
        chay_test("TC05", "Mang rong (n = 0)", a, 0, exp, 0);
    }
    {
        int a[] = {-42};
        int exp[] = {-42};
        chay_test("TC06", "Mang chi co 1 phan tu am", a, 1, exp, 1);
    }
    {
        int a[] = {99};
        int exp[] = {99};
        chay_test("TC07", "Mang chi co 1 phan tu duong", a, 1, exp, 1);
    }
    {
        int a[] = {0, 0, 0};
        int exp[] = {0, 0, 0};
        chay_test("TC08", "Mang toan so 0 (bao toan du cac so 0)", a, 3, exp, 3);
    }
    {
        int a[] = {-999999, 999999, 0, -1, 1};
        int exp[] = {-999999, -1, 0, 1, 999999};
        chay_test("TC09", "Gia tri bien cuc tri [-999999, 999999]", a, 5, exp, 5);
    }
    {
        int a[] = {-20, -10, 0, 5, 15};
        int exp[] = {-20, -10, 0, 5, 15};
        chay_test("TC10", "Mang da duoc sap tang san", a, 5, exp, 5);
    }
    {
        int a[] = {15, 5, 0, -10, -20};
        int exp[] = {-20, -10, 0, 5, 15};
        chay_test("TC11", "Mang giam dan hoan toan", a, 5, exp, 5);
    }
    {
        int a[] = {543, 12, 9, 87, 102};
        int exp[] = {9, 12, 87, 102, 543};
        chay_test("TC12", "Mang toan so duong (khong co so am)", a, 5, exp, 5);
    }

    // --- NHÓM 4: CÁC CA VALIDATOR TỪ CHỐI DỮ LIỆU SAI ---
    {
        int a[] = {1, 2, 1000000};
        chay_test_validator("TC13", "Validator tu choi phan tu > 999999", a, 3);
    }
    {
        int a[] = {-1000000, 5, 10};
        chay_test_validator("TC14", "Validator tu choi phan tu < -999999", a, 3);
    }

    // --- TỔNG KẾT ---
    printf("\n======================================================================\n");
    printf("   KET QUA KIEM THU: %d / %d ca dat (PASS)\n", passed_tests, total_tests);
    if (passed_tests == total_tests) {
        printf("   DANH GIA: ALL TESTS PASSED! CHAT LUONG MA NGUON HOAN HAO!\n");
    } else {
        printf("   DANH GIA: CO CA TEST CHUA DAT, CAN KIEM TRA LAI!\n");
    }
    printf("======================================================================\n");

    return (passed_tests == total_tests) ? 0 : 1;
}
