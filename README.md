<div align="center">

# ⚡ DT018 — RADIX SORT CHO MẢNG CÓ SỐ ÂM VÀ SỐ DƯƠNG
### ĐỒ ÁN MÔN HỌC CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (INT13185 · NHÓM 03)
**HỌC VIỆN CÔNG NGHỆ BƯU CHÍNH VIỄN THÔNG — CƠ SỞ TP. HỒ CHÍ MINH**

<br/>

[![Language: C](https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C?style=for-the-badge&logo=c&logoColor=white)](src/DeTai.c)
[![Compiler: GCC](https://img.shields.io/badge/Compiler-GCC%2016.1.0-FF7043?style=for-the-badge&logo=gnu&logoColor=white)](test/runtests.c)
[![Automated Tests](https://img.shields.io/badge/Test_Suite-14%20%2F%2014%20PASS%20(100%25)-10B981?style=for-the-badge&logo=checkmarx&logoColor=white)](test/runtests.c)
[![Complexity](https://img.shields.io/badge/Time_Complexity-O(n)%20Linear-6366F1?style=for-the-badge&logo=speedtest&logoColor=white)](README.md#phân-tích-độ-phức-tạp)
[![Live Demo](https://img.shields.io/badge/🌐_Interactive_Demo-Online-F59E0B?style=for-the-badge&logo=googlechrome&logoColor=white)](https://khoadien0607-coder.github.io/DT018_RadixSort/)

<br/>

👉 **[TRẢI NGHIỆM WEB DEMO TRỰC TUYẾN TẠI ĐÂY 🚀](https://khoadien0607-coder.github.io/DT018_RadixSort/)** 👈

</div>

---

## 📑 MỤC LỤC
1. [Thông tin sinh viên & Học phần](#-thông-tin-sinh-viên--học-phần)
2. [Bối cảnh bài toán & Nguyên lý toán học](#-bối-cảnh-bài-toán--nguyên-lý-toán-học)
3. [Lưu đồ hoạt động & Kiến trúc xử lý](#-lưu-đồ-hoạt-động--kiến-trúc-xử-lý)
4. [Trải nghiệm Web Demo & Chương trình Console](#-trải-nghiệm-web-demo--chương-trình-console)
5. [Hướng dẫn biên dịch & Thực thi](#-hướng-dẫn-biên-dịch--thực-thi)
6. [Bộ kiểm thử tự động 14/14 ca (Test Suite)](#-bộ-kiểm-thử-tự-động-1414-ca-test-suite)
7. [Phân tích độ phức tạp thời gian & Bộ nhớ](#-phân-tích-độ-phức-tạp-thời-gian--bộ-nhớ)
8. [Cấu trúc mã nguồn đề tài](#-cấu-trúc-mã-nguồn-đề-tài)
9. [Thông tin nộp bài & Đối chiếu Git](#-thông-tin-nộp-bài--đối-chiếu-git)
10. [Tài liệu tham khảo](#-tài-liệu-tham-khảo)

---

## 👤 1. Thông tin sinh viên & Học phần

| Thông tin | Chi tiết sinh viên |
|:---|:---|
| **Họ và tên sinh viên** | **Nguyễn Khoa Điền** |
| **Mã số sinh viên (MSSV)** | **N24DCDT014** |
| **Lớp sinh hoạt** | **D24CQDT01-N** (Ngành Kỹ thuật Điện tử - Viễn thông) |
| **Học phần** | Cấu trúc dữ liệu và giải thuật (INT13185 · Nhóm 03) |
| **Giảng viên hướng dẫn** | **ThS. Hồ Nhựt Minh** |
| **Mã đề tài** | **DT018** |
| **Tên đề tài** | **Radix Sort cho mảng có số âm và số dương** |
| **Giáo trình căn cứ** | Giáo trình CTDL & GT (INT1306), Mục 2.4; Mục 2.8 Bài 30; Trang 45–48, 62. |

---

## 🎯 2. Bối cảnh bài toán & Nguyên lý toán học

### ⚠️ Giới hạn của Radix Sort chuẩn trong sách:
Thuật toán sắp xếp cơ số (Radix Sort LSD) dựa trên thuật toán sắp xếp đếm phân phối (Counting Sort) sử dụng từng chữ số từ $0 \dots 9$ làm chỉ số truy cập mảng đếm `count[]`. 
* Khi mảng chứa **số nguyên âm**, các phép chia lấy dư `(a[i] / exp) % 10` sẽ sinh ra **chỉ số âm**, dẫn đến lỗi tràn bộ nhớ nghiêm trọng (**Segmentation Fault / Out-of-bounds array access**).

### 💡 Giải pháp cốt lõi của đề tài DT018:
Để khắc phục hoàn toàn nhược điểm trên, đề tài áp dụng định lý toán học đối với số âm:

$$\forall x, y < 0: \quad x < y \iff |x| > |y|$$

> **Quy luật:** Đối với các số âm, số nào có **độ lớn tuyệt đối càng lớn** thì giá trị đại số của nó lại **càng nhỏ**.

#### Quy trình 4 bước giải quyết:
1. **Phân tách hai nhóm dấu (`tach_hai_dau`):** Lọc mảng thành nhóm âm `am[]` (lấy độ lớn dương $|a[i]|$) và nhóm không âm `duong[]`.
2. **Sắp xếp theo độ lớn (`radix_khong_am`):** Dùng Radix Sort LSD cơ số 10 sắp xếp cả 2 nhóm độc lập.
3. **Đảo chiều & Khôi phục dấu:** Đảo ngược thứ tự nhóm âm (`reverse`) để đưa phần tử có độ lớn tuyệt đối lớn nhất lên vị trí đầu tiên, sau đó nhân $-1$ để khôi phục giá trị âm tăng dần.
4. **Ghép nối mảng (`merge`):** Nối nhóm âm đứng trước nhóm không âm, thu được mảng tăng dần hoàn toàn.

---

## 🔄 3. Lưu đồ hoạt động & Kiến trúc xử lý

```
  ĐẦU VÀO: a = [-5, 2, -10, 0, 2] (n = 5)
                     │
                     ▼
  [1. KIỂM TRA ĐẦU VÀO (Validator: 0 <= n <= 5000, |a[i]| <= 999999)]
                     │
                     ▼
  [2. PHÂN TÁCH HAI NHÓM DẤU (tach_hai_dau)]
        ├── Nhóm âm:     am    = [5, 10]  (Lưu độ lớn tuyệt đối)
        └── Nhóm không âm: duong = [2, 0, 2]
                     │
                     ▼
  [3. RADIX SORT LSD CƠ SỐ 10 TRÊN TỪNG NHÓM (radix_khong_am)]
        ├── am    sau sắp: [5, 10]  (Độ lớn tăng dần)
        └── duong sau sắp: [0, 2, 2]
                     │
                     ▼
  [4. ĐẢO CHIỀU & ĐỔI DẤU NHÓM ÂM (reverse & negate)]
        ├── Đảo ngược độ lớn: [10, 5] (Độ lớn giảm dần)
        └── Khôi phục dấu âm: [-10, -5] (Giá trị đại số tăng dần: -10 < -5)
                     │
                     ▼
  [5. GHÉP NỐI HAI NHÓM (merge)]
        └── a = [-10, -5] + [0, 2, 2] ➔ a = [-10, -5, 0, 2, 2] (ĐÚNG 100%)
```

---

## 🌐 4. Trải nghiệm Web Demo & Chương trình Console

### 1. Trải nghiệm Web Simulator trực tuyến:
Mã nguồn tích hợp một giao diện Web Simulator chuẩn chuyên nghiệp:
* **Địa chỉ trực tuyến:** [https://khoadien0607-coder.github.io/DT018_RadixSort/](https://khoadien0607-coder.github.io/DT018_RadixSort/)
* **Chạy Offline nội bộ:** Click mở trực tiếp tệp [`docs/index.html`](docs/index.html) bằng bất kỳ trình duyệt nào.
* **Tính năng:**
  * Mô phỏng trực quan từng bước chuyển động mảng (Tách nhóm ➔ Radix ➔ Đảo chiều ➔ Ghép nối).
  * Chế độ tự sinh ngẫu nhiên số liệu kiểm thử và đo đạc.
  * Bộ điều khiển chạy tự động và chấm điểm trực tiếp 14 ca test.

### 2. Chương trình tương tác Console (`demo.c`):
Chương trình dòng lệnh hỗ trợ 8 chế độ chuyên sâu:
```text
======================================================================
     CHUONG TRINH DEMO RADIX SORT CHO MANG CO SO AM VA SO DUONG
======================================================================
1. Chay Vi du 1 tren phieu giao: [-5, 2, -10, 0, 2]
2. Chay Vi du 2 tren phieu giao: [-3, -1, -2] (Toan so am)
3. Chay ca tu thiet ke 1 (Hon hop nhieu chu so)
4. Chay ca tu thiet ke 2 (Trung lap ca 2 nhom dau)
5. Chay ca bien 1: Mang rong (n = 0)
6. Chay ca bien 2: Mang 1 phan tu am (n = 1)
7. Chay ca bien 3: Mang toan so 0
8. Chay ca du lieu khong hop le (Kiem tra Validator)
9. Nhap mang bat ky tu ban phim
0. Thoat chuong trinh
======================================================================
```

---

## ⚡ 5. Hướng dẫn biên dịch & Thực thi

### Yêu cầu hệ thống:
* **Hệ điều hành:** Windows 10/11, Linux (Ubuntu/Debian) hoặc macOS.
* **Trình biên dịch:** `gcc` (hỗ trợ C99 hoặc C11).

### Các bước biên dịch bằng GCC:

```powershell
# 1. Di chuyển vào thư mục mã nguồn
cd "DT018_RadixSort"

# 2. Biên dịch chương trình Demo tương tác
gcc -Wall -Wextra -O2 src/DeTai.c demo.c -o demo.exe

# 3. Biên dịch bộ kiểm thử tự động
gcc -Wall -Wextra -O2 src/DeTai.c test/runtests.c -o test/runtests.exe

# 4. Chạy chương trình Demo
./demo.exe

# 5. Chạy bộ kiểm thử tự động
./test/runtests.exe
```

---

## 🧪 6. Bộ kiểm thử tự động 14/14 ca (Test Suite)

Bộ kiểm thử độc lập [`test/runtests.c`](test/runtests.c) bao phủ 100% các tình huống biên, ca trên phiếu, ca cực trị và ca dữ liệu sai quy cách:

| Mã Ca | Nhóm phân loại | Dữ liệu đầu vào (Input) | Kết quả mong đợi (Expected) | Trạng thái |
|:---:|:---|:---|:---|:---:|
| **TC01** | Phiếu giao VD01 | `a = [-5, 2, -10, 0, 2]` | `[-10, -5, 0, 2, 2]` | ✅ **PASS** |
| **TC02** | Phiếu giao VD02 | `a = [-3, -1, -2]` (Toàn âm) | `[-3, -2, -1]` | ✅ **PASS** |
| **TC03** | Tự thiết kế TK01 | `[-999, 45, 0, -3, 100, -250, 12]` | `[-999, -250, -3, 0, 12, 45, 100]` | ✅ **PASS** |
| **TC04** | Tự thiết kế TK02 | `[-7, 5, -7, 0, 5, -1, 0, 2]` | `[-7, -7, -1, 0, 0, 2, 5, 5]` | ✅ **PASS** |
| **TC05** | Biên BIEN01 | `a = []` (n = 0, mảng rỗng) | `[]` (Kết thúc an toàn) | ✅ **PASS** |
| **TC06** | Biên BIEN02 | `a = [-42]` (n = 1 số âm) | `[-42]` (Giữ nguyên) | ✅ **PASS** |
| **TC07** | Biên BIEN03 | `a = [7]` (n = 1 số dương) | `[7]` (Giữ nguyên) | ✅ **PASS** |
| **TC08** | Biên BIEN04 | `a = [0, 0, 0]` (Mảng toàn số 0) | `[0, 0, 0]` (Bảo toàn số 0) | ✅ **PASS** |
| **TC09** | Cực trị KT09 | `[999999, -999999, 0]` (Biên miền) | `[-999999, 0, 999999]` | ✅ **PASS** |
| **TC10** | Dãy KT10 | `[-10, -5, 0, 2, 8]` (Đã sắp tăng) | `[-10, -5, 0, 2, 8]` | ✅ **PASS** |
| **TC11** | Dãy KT11 | `[8, 2, 0, -5, -10]` (Giảm dần) | `[-10, -5, 0, 2, 8]` | ✅ **PASS** |
| **TC12** | Dãy KT12 | `[50, 1, 300, 20]` (Toàn số dương) | `[1, 20, 50, 300]` | ✅ **PASS** |
| **TC13** | Validator LOI01 | `a = [1, 2, 1000000]` (> 999999) | `[Loi Validator] Tu choi xu ly` | ✅ **PASS** |
| **TC14** | Validator LOI02 | `a = [-1000000, 0]` (< -999999) | `[Loi Validator] Tu choi xu ly` | ✅ **PASS** |

---

## 📈 7. Phân tích độ phức tạp thời gian & Bộ nhớ

| Pha xử lý thuật toán | Phép toán chủ đạo | Thời gian thực thi | Không gian bộ nhớ phụ |
|:---|:---|:---:|:---:|
| **1. Kiểm tra đầu vào** | $n$ phép so sánh kiểm tra biên giá trị | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **2. Tách nhóm âm/dương** | $n$ phép kiểm tra $a[i] < 0$ và phép gán mảng | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **3. Radix Sort 2 nhóm** | $d$ vòng lặp Counting Sort cơ số $k = 10$ | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(n + k)$ |
| **4. Đảo chiều & Đổi dấu** | $n_{am}/2$ hoán vị, $n_{am}$ phép nhân $-1$ | $\mathcal{O}(n_{am}) \le \mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **5. Ghép mảng kết quả** | $n$ phép gán sao chép nối tiếp | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ |
| **TỔNG THỂ TOÀN THUẬT TOÁN** | **Tuyến tính theo kích thước mảng** | **$\mathcal{O}(n)$** | **$\mathcal{O}(n)$** |

> **Nhận xét:** Vì số chữ số tối đa $d \le 6$ (do miền $[-999999, 999999]$) và cơ số $k = 10$ là các hằng số độc lập với $n$, độ phức tạp tổng thể đạt $\mathcal{O}(n)$, nhanh vượt trội so với các thuật toán so sánh $\mathcal{O}(n \log n)$ như QuickSort hay MergeSort khi $n$ lớn.

---

## 📁 8. Cấu trúc mã nguồn đề tài

```
N24DCDT014_DT018_NguyenKhoaDien_MaNguon/
├── .gitignore                      # Danh sách bỏ qua file nhị phân & tạm
├── README.md                       # Tài liệu thuyết minh dự án GitHub
├── index.html                      # Trang web demo trực quan (Root GitHub Pages)
├── demo.c                          # Giao diện menu tương tác console 8 chế độ
├── src/
│   ├── DeTai.h                     # Khai báo nguyên mẫu hàm, cấu trúc & hằng số
│   └── DeTai.c                     # Cài đặt chi tiết các hàm thuật toán cốt lõi
├── test/
│   └── runtests.c                  # Bộ kiểm thử tự động 14 ca độc lập
└── docs/
    ├── index.html                  # Bản sao web demo phục vụ thư mục /docs
    └── anh_ket_qua/                # 11 ảnh chụp màn hình minh chứng cá nhân (A01 - A11)
        ├── 01_vi_du_1.png
        ├── 02_vi_du_2.png
        ├── 03_tu_thiet_ke_1.png
        ├── 04_tu_thiet_ke_2.png
        ├── 05_bien_1.png
        ├── 06_bien_2.png
        ├── 07_bien_3.png
        ├── 08_input_khong_hop_le.png
        ├── 09_tong_ket_kiem_thu.png
        ├── 10_clone_sach_chay_lai.png
        └── 11_github_repo_commit.png
```

---

## 📑 9. Thông tin nộp bài & Đối chiếu Git

| Tiêu chí đối chiếu | Thông tin chính thức |
|:---|:---|
| **Kho mã nguồn GitHub (Public)** | [https://github.com/khoadien0607-coder/DT018_RadixSort](https://github.com/khoadien0607-coder/DT018_RadixSort) |
| **Commit C (Mã nguồn & Test đạt)** | `dfc85b683608d9952e7661dd10174df14350b23b` |
| **Commit S (Bản nộp cuối đầy đủ)** | `88dc75b27d65e23362a4ad91b9f1c8bc25b63203` |
| **Permalink Hàm chính tại C** | [src/DeTai.c@dfc85b6](https://github.com/khoadien0607-coder/DT018_RadixSort/blob/dfc85b683608d9952e7661dd10174df14350b23b/src/DeTai.c) |
| **Permalink Bộ test tại C** | [test/runtests.c@dfc85b6](https://github.com/khoadien0607-coder/DT018_RadixSort/blob/dfc85b683608d9952e7661dd10174df14350b23b/test/runtests.c) |
| **Trạng thái tái lập (Reproducibility)** | Đã clone sạch sang thư mục độc lập, biên dịch lại và đạt 14/14 PASS 100%. |

---

## 📚 10. Tài liệu tham khảo

1. Học viện Công nghệ Bưu chính Viễn thông, *Giáo trình Cấu trúc dữ liệu và Giải thuật (INT1306)*, Chương 2: Thuật toán sắp xếp, Mục 2.4 (Radix Sort), trang in 45–48, 62; trang PDF 57–60, 74.
2. Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein, *Introduction to Algorithms (Third Edition)*, MIT Press, Chapter 8: Sorting in Linear Time (Section 8.3: Radix Sort).

---

<div align="center">
<sub>Đồ án học phần CTDL & GT · Sinh viên thực hiện: Nguyễn Khoa Điền (N24DCDT014 · D24CQDT01-N) · 11/2026</sub>
</div>
