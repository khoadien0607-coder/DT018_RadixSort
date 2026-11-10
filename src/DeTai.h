#ifndef DETAI_H
#define DETAI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 5000
#define MIN_VAL -999999
#define MAX_VAL 999999

/**
 * Kiểm tra hợp đồng đầu vào cho đề tài DT018:
 * - 0 <= n <= 5000
 * - -999999 <= a[i] <= 999999
 * Trả về true (1) nếu hợp lệ, false (0) nếu không hợp lệ.
 */
bool kiem_tra_dau_vao(const int a[], int n);

/**
 * Tách mảng a thành 2 nhóm:
 * - am: các phần tử < 0
 * - khong_am: các phần tử >= 0 (bao gồm cả số 0)
 */
void tach_hai_dau(const int a[], int n, int am[], int *n_am, int khong_am[], int *n_khong_am);

/**
 * Cài đặt giải thuật LSD Radix Sort cơ số 10 cho mảng số không âm (>= 0).
 * Sắp xếp tại chỗ (in-place) hoặc thông qua mảng tạm.
 */
void radix_khong_am(int a[], int n);

/**
 * Thuật toán Radix Sort mở rộng cho mảng có cả số âm và số dương:
 * 1. Tách nhóm âm và không âm
 * 2. Sắp xếp độ lớn nhóm âm bằng radix_khong_am
 * 3. ĐẢO NGƯỢC thứ tự độ lớn rồi mới đổi dấu âm
 * 4. Sắp xếp nhóm không âm bằng radix_khong_am
 * 5. Ghép hai nhóm lại thành mảng tăng dần
 * Trả về true nếu thành công, false nếu dữ liệu không hợp lệ.
 */
bool radix_co_am(int a[], int n, bool in_chi_tiet);

/**
 * In mảng số nguyên ra màn hình.
 */
void in_mang(const char *tieu_de, const int a[], int n);

#endif // DETAI_H
