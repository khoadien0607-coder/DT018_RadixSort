<div align="center">

# 🗂️ DT018 — Radix Sort cho mảng có số âm & số dương

**INT13185 Nhóm 03 · Học viện Công nghệ Bưu chính Viễn thông TP.HCM**

[![Tests](https://img.shields.io/badge/Tests-14%2F14%20PASS-brightgreen?style=flat-square&logo=checkmarx)](test/runtests.c)
[![Language](https://img.shields.io/badge/Language-C99%2FC11-blue?style=flat-square&logo=c)](src/DeTai.c)
[![Demo](https://img.shields.io/badge/🌐_Demo-Chạy_online-orange?style=flat-square)](https://khoadien0607-coder.github.io/DT018_RadixSort/)

🔗 **[Xem demo trực tuyến →](https://khoadien0607-coder.github.io/DT018_RadixSort/)**

</div>

---

## 👤 Thông tin

| | |
|---|---|
| **Sinh viên** | Nguyễn Khoa Điền — N24DCDT014 — D24CQDT01-N |
| **Giảng viên** | ThS. Hồ Nhựt Minh |
| **Môn học** | Cấu trúc Dữ liệu & Giải thuật — INT13185 Nhóm 03 |
| **Commit C** | [`dfc85b6`](https://github.com/khoadien0607-coder/DT018_RadixSort/commit/dfc85b683608d9952e7661dd10174df14350b23b) · mã nguồn hoàn chỉnh & 14/14 test PASS |
| **Commit S** | [`2fdc1fa`](https://github.com/khoadien0607-coder/DT018_RadixSort/commit/2fdc1fa6f8bc720baba3fcf7ea2367c800781a1c) · bổ sung 11 ảnh minh chứng |

---

## 🎯 Vấn đề & Giải pháp

**Vấn đề:** Radix Sort trong giáo trình chỉ sắp xếp được mảng **không âm**. Khi mảng có số âm, phép `% 10` cho kết quả âm → chỉ số mảng đếm âm → **Segmentation fault**.

**Ý tưởng mấu chốt:**

```
Với số âm: x < y < 0  ⟺  |x| > |y|
  → Sắp |âm| tăng dần  →  đảo chiều  →  đổi dấu  =  âm tăng dần ✓
```

**Ví dụ 1 (theo phiếu giao):**
```
Input:   [-5,  2, -10,  0,  2]
         ────────────────────
         Nhóm âm: [5, 10]  → Radix → [5,10] → đảo → [10,5] → đổi dấu → [-10,-5]
         Nhóm ≥0: [2, 0, 2] → Radix → [0, 2, 2]
         Ghép lại: [-10,-5]  +  [0,2,2]
Output:  [-10, -5,  0,  2,  2]  ✓
```

---

## ⚡ Chạy nhanh

```bash
git clone https://github.com/khoadien0607-coder/DT018_RadixSort.git
cd DT018_RadixSort

# Biên dịch
gcc -Wall -Wextra -O2 src/DeTai.c demo.c -o demo.exe
gcc -Wall -Wextra -O2 src/DeTai.c test/runtests.c -o test/runtests.exe

# Chạy demo (menu 1-8)
./demo.exe

# Chạy kiểm thử tự động
./test/runtests.exe
```

```
KET QUA KIEM THU: 14 / 14 ca dat (PASS)
DANH GIA: ALL TESTS PASSED! CHAT LUONG MA NGUON HOAN HAO!
```

---

## 📂 Cấu trúc

```
├── src/DeTai.h          ← Khai báo hàm & hằng (MAX_N=5000, miền ±999999)
├── src/DeTai.c          ← radix_co_am · radix_khong_am · tach_hai_dau · validator
├── demo.c               ← Demo tương tác 8 chế độ
├── test/runtests.c      ← 14 ca kiểm thử tự động (TC01–TC14)
└── docs/
    ├── index.html       ← 🌐 Demo web chạy thuật toán ngay trên trình duyệt
    └── anh_ket_qua/     ← 11 ảnh chụp màn hình A01–A11
```

---

## ✅ Bộ kiểm thử 14 ca

| Mã | Loại | Input | Kết quả |
|:--:|------|-------|:-------:|
| TC01 | Phiếu — VD01 | `[-5, 2, -10, 0, 2]` → `[-10,-5,0,2,2]` | ✅ |
| TC02 | Phiếu — VD02 | `[-3,-1,-2]` → `[-3,-2,-1]` | ✅ |
| TC03 | Tự thiết kế | `[-999,45,0,-3,100,-250,12]` | ✅ |
| TC04 | Tự thiết kế | `[-7,5,-7,0,5,-1,0,2]` (có trùng lặp) | ✅ |
| TC05 | Biên n=0 | `[]` → `[]` | ✅ |
| TC06 | Biên n=1 âm | `[-42]` → `[-42]` | ✅ |
| TC07 | Biên n=1 dương | `[7]` → `[7]` | ✅ |
| TC08 | Biên toàn 0 | `[0,0,0]` → `[0,0,0]` | ✅ |
| TC09 | Cực trị miền | `[999999,-999999,0]` | ✅ |
| TC10 | Đã sắp tăng | `[-10,-5,0,2,8]` | ✅ |
| TC11 | Giảm dần | `[8,2,0,-5,-10]` | ✅ |
| TC12 | Toàn dương | `[50,1,300,20]` | ✅ |
| TC13 | Validator | `a[2]=1000000 > 999999` → từ chối | ✅ |
| TC14 | Validator | `a[0]=-1000000 < -999999` → từ chối | ✅ |

---

## 📊 Độ phức tạp

| Pha | Thời gian | Không gian |
|-----|:---------:|:----------:|
| Tách nhóm | O(n) | O(n) |
| Radix Sort (d≤6, k=10) | O(d·n) | O(n) |
| Đảo chiều + đổi dấu | O(n) | O(1) |
| **Tổng** | **O(n)** | **O(n)** |

> Miền: `0 ≤ n ≤ 5000`, `-999999 ≤ a[i] ≤ 999999`

---

<div align="center">
<sub>Nguyễn Khoa Điền · N24DCDT014 · INT13185 Nhóm 03 · 11/2026</sub>
</div>
