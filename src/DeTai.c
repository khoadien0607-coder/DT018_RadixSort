#include "DeTai.h"

bool kiem_tra_dau_vao(const int a[], int n) {
    if (n < 0 || n > MAX_N) {
        printf("[Loi Validator] So phan tu n = %d khong hop le (yeu cau 0 <= n <= %d)\n", n, MAX_N);
        return false;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < MIN_VAL || a[i] > MAX_VAL) {
            printf("[Loi Validator] Phan tu a[%d] = %d vuot mien [%d, %d]\n", i, a[i], MIN_VAL, MAX_VAL);
            return false;
        }
    }
    return true;
}

void tach_hai_dau(const int a[], int n, int am[], int *n_am, int khong_am[], int *n_khong_am) {
    *n_am = 0;
    *n_khong_am = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            am[(*n_am)++] = a[i];
        } else {
            khong_am[(*n_khong_am)++] = a[i];
        }
    }
}

void radix_khong_am(int a[], int n) {
    if (n <= 1) return;

    // Tìm giá trị lớn nhất để xác định số chữ số
    int max_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    // Cấp phát mảng tạm b để chứa kết quả từng lượt phân phối
    int *b = (int *)malloc(n * sizeof(int));
    if (b == NULL) {
        fprintf(stderr, "[Loi] Khong du bo nho cap phat!\n");
        return;
    }

    // Duyệt qua từng chữ số exp = 1, 10, 100, 1000,...
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        int count[10] = {0};

        // 1. Đếm tần suất các chữ số tại hàng exp
        for (int i = 0; i < n; i++) {
            int chu_so = (a[i] / exp) % 10;
            count[chu_so]++;
        }

        // 2. Tính vị trí tích lũy (prefix sum)
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // 3. Phân phối ổn định từ phải sang trái vào mảng tạm b
        for (int i = n - 1; i >= 0; i--) {
            int chu_so = (a[i] / exp) % 10;
            b[count[chu_so] - 1] = a[i];
            count[chu_so]--;
        }

        // 4. Sao chép lại mảng b vào mảng a
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }

    free(b);
}

bool radix_co_am(int a[], int n, bool in_chi_tiet) {
    if (!kiem_tra_dau_vao(a, n)) {
        return false;
    }
    if (n <= 1) {
        return true;
    }

    // Cấp phát mảng chứa 2 nhóm
    int *am = (int *)malloc(n * sizeof(int));
    int *khong_am = (int *)malloc(n * sizeof(int));
    if (am == NULL || khong_am == NULL) {
        fprintf(stderr, "[Loi] Khong du bo nho cap phat!\n");
        if (am) free(am);
        if (khong_am) free(khong_am);
        return false;
    }

    int n_am = 0, n_khong_am = 0;
    tach_hai_dau(a, n, am, &n_am, khong_am, &n_khong_am);

    if (in_chi_tiet) {
        in_mang("  -> Nhom am ban dau", am, n_am);
        in_mang("  -> Nhom khong am ban dau", khong_am, n_khong_am);
    }

    // 1. Sắp xếp nhóm không âm
    if (n_khong_am > 1) {
        radix_khong_am(khong_am, n_khong_am);
    }

    // 2. Sắp xếp nhóm âm thông qua độ lớn
    if (n_am > 0) {
        int *do_lon = (int *)malloc(n_am * sizeof(int));
        for (int i = 0; i < n_am; i++) {
            do_lon[i] = -am[i]; // Lấy trị tuyệt đối
        }

        if (n_am > 1) {
            radix_khong_am(do_lon, n_am);
        }

        if (in_chi_tiet) {
            in_mang("  -> Do lon nhom am sau Radix", do_lon, n_am);
        }

        // Mấu chốt: Đảo ngược thứ tự độ lớn rồi đổi dấu âm
        // Số có độ lớn lớn nhất đứng đầu tiên
        for (int i = 0; i < n_am; i++) {
            am[i] = -do_lon[n_am - 1 - i];
        }

        if (in_chi_tiet) {
            in_mang("  -> Nhom am sau dao chieu va doi dau", am, n_am);
        }

        free(do_lon);
    }

    // 3. Ghép hai nhóm lại vào a
    for (int i = 0; i < n_am; i++) {
        a[i] = am[i];
    }
    for (int i = 0; i < n_khong_am; i++) {
        a[n_am + i] = khong_am[i];
    }

    free(am);
    free(khong_am);
    return true;
}

void in_mang(const char *tieu_de, const int a[], int n) {
    printf("%s (n = %d): [", tieu_de, n);
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}
