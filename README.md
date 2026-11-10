# ĐỒ ÁN HỌC PHẦN CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 - NHÓM 03)
## ĐỀ TÀI DT018: RADIX SORT CHO MẢNG CÓ SỐ ÂM VÀ SỐ DƯƠNG

### 1. Thông tin sinh viên & Đề tài
- **Họ và tên:** Nguyễn Khoa Điền
- **Mã số sinh viên (MSSV):** N24DCDT014
- **Lớp:** D24CQDT01-N
- **Học viện Công nghệ Bưu chính Viễn thông - Cơ sở tại TP. Hồ Chí Minh**
- **Giảng viên hướng dẫn:** Hồ Nhựt Minh
- **Ngôn ngữ lập trình:** Ngôn ngữ C (chuẩn C99 / C11, trình biên dịch `gcc`)
- **Giáo trình căn cứ:** `Giao-trinh-Cau-truc-du-lieu-va-Giai-thuat-INT1306.pdf`, Chương 2, Mục 2.4; Mục 2.8 Bài 30; trang in 45–48, 62; trang PDF 57–60, 74.
- **URL GitHub cá nhân:** `[ĐIỀN_URL_REPO_GITHUB_CUA_DIEN]`
- **Commit SHA C:** `[ĐIỀN_SHA_COMMIT_C_40_KY_TU]`
- **Commit SHA S:** `[ĐIỀN_SHA_COMMIT_S_40_KY_TU]`

---

### 2. Cấu trúc thư mục mã nguồn

```
N24DCDT014_DT018_NguyenKhoaDien_MaNguon/
├── .gitignore
├── README.md                   # Hướng dẫn chi tiết biên dịch và chạy
├── demo.c                      # Chương trình demo chạy Ví dụ 1, Ví dụ 2 và nhập bàn phím
├── src/
│   ├── DeTai.h                 # Khai báo nguyên mẫu hàm, hằng số, validator
│   └── DeTai.c                 # Cài đặt thuật toán Radix Sort có âm, không âm và tách mảng
├── test/
│   └── runtests.c              # Bộ kiểm thử tự động với 14 ca kiểm độc lập
└── docs/
    └── anh_ket_qua/            # Chứa 11 ảnh chụp màn hình minh chứng gốc (A01 - A11)
```

---

### 3. Hướng dẫn biên dịch và chạy (Bằng trình biên dịch GCC)

Mở terminal (PowerShell, Command Prompt hoặc Git Bash) tại thư mục mã nguồn:

#### Bước 3.1. Biên dịch chương trình Demo và Bộ Test
```powershell
# Biên dịch demo.c thành demo.exe
gcc -Wall -Wextra -O2 src/DeTai.c demo.c -o demo.exe

# Biên dịch test/runtests.c thành test/runtests.exe
gcc -Wall -Wextra -O2 src/DeTai.c test/runtests.c -o test/runtests.exe
```

#### Bước 3.2. Chạy chương trình Demo
```powershell
./demo.exe
```
Chương trình sẽ tự động chạy:
- Ví dụ 1 trên phiếu: `[-5, 2, -10, 0, 2]` -> `[-10, -5, 0, 2, 2]`
- Ví dụ 2 trên phiếu: `[-3, -1, -2]` -> `[-3, -2, -1]`
- Ví dụ 3 hỗn hợp: `[100, -250, 45, -3, 0, -999, 12]`
- Tùy chọn nhập mảng bất kỳ từ bàn phím.

#### Bước 3.3. Chạy bộ kiểm thử tự động (14 ca độc lập)
```powershell
./test/runtests.exe
```
Kết quả hiển thị:
```
======================================================================
   KET QUA KIEM THU: 14 / 14 ca dat (PASS)
   DANH GIA: ALL TESTS PASSED! CHAT LUONG MA NGUON HOAN HAO!
======================================================================
```

---

### 4. Quy trình Git và Kiểm tra tính tái lập (Commit C và S)

#### Tạo Commit C (Code & Test đạt):
```powershell
git init
git add README.md .gitignore src demo.c test docs
git commit -m "Commit C: Hoan thanh thuat toan Radix Sort ngon ngu C va bo test"
git branch -M main
git remote add origin https://github.com/TEN_TAI_KHOAN/DT018_RadixSort.git
git push -u origin main
git rev-parse HEAD
```

#### Clone sang thư mục mới kiểm tra lại (Chụp ảnh A10):
```powershell
cd ..
git clone https://github.com/TEN_TAI_KHOAN/DT018_RadixSort.git kiem_tra_clone
cd kiem_tra_clone
gcc -Wall -Wextra -O2 src/DeTai.c demo.c -o demo.exe
./demo.exe
gcc -Wall -Wextra -O2 src/DeTai.c test/runtests.c -o test/runtests.exe
./test/runtests.exe
```

#### Tạo Commit S (Bổ sung 11 ảnh minh chứng):
Sau khi chụp 11 ảnh và lưu vào `docs/anh_ket_qua/`:
```powershell
git add docs/anh_ket_qua README.md
git commit -m "Commit S: Bo sung 11 anh minh chung va hoan tat ho so"
git push origin main
git rev-parse HEAD
```
*(Ghi SHA S vào file TXT nộp rời)*.
