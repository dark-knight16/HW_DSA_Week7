#include <iostream>
using namespace std;

//* Tạo cấu trúc struct DanSo với hai giá trị là năm và số người sinh ra trong năm đó
typedef struct DanSo {
    int year;
    int people;
} Danso;

//* Hàm tìm số năm có số lượng người sinh ra lớn nhất và bé nhất
void find_year_min_max_people(Danso p[], int n) {
    int max_people = p[0].people;
    int min_people = p[0].people;

    //? Tìm số lượng người sinh ra lớn nhất và bé nhất
    for (int i = 0; i < n; i++) {
        if (p[i].people > max_people) max_people = p[i].people;
        if (p[i].people < min_people) min_people = p[i].people;
    }

    //? In các năm có số lượng người sinh ra bé nhất
    cout << "Cac nam co so luong nguoi sinh ra la be nhat: ";
    for (int i = 0; i < n; i++) {
        if (p[i].people == min_people) cout << p[i].year << ' ';
    }
    cout << endl;

    //? In các năm có số lượng người sinh ra lớn nhất
    cout << "Cac nam co so luong nguoi sinh ra la lon nhat: ";
    for (int i = 0; i < n; i++) {
        if (p[i].people == max_people) cout << p[i].year << ' ';
    }
    cout << endl;
}

//* Hàm tìm những năm có cùng số lượng người sinh ra
void find_year_have_same_people(DanSo p[], int n) {
    //? Mảng a chứa số lượng người sinh ra phân biệt
    Danso* a = new DanSo [n];

    //? Biến đếm số lượng phần tử của mảng a
    int m = 0; 
    for (int i = 0; i < n; i++) {
        bool found = false;
        //? Kiểm tra xem giá trị số lượng người sinh ra đã xuất hiện trong mảng a chưa
        //? Nếu chưa thì thêm giá trị vào mảng a
        for (int j = 0; j < m; j++) {
            if (p[i].people == a[j].people) {
                found = true;
                break;
            }
        }
        if (!found) {
            a[m].people = p[i].people;
            m++;
        }
    }

    //? In ra kết quả
    for (int i = 0; i < m; i++) {
        cout << "Nhung nam co cung " << a[i].people << " nguoi sinh ra la: ";
        for (int j = 0; j < n; j++) {
            if (p[j].people == a[i].people) cout << p[j].year << ' ';
        }
        cout << endl;
    }

    delete [] a;
}

int main() {
    //? Năm bắt đầu lấy số liệu
    int begin_year;
    cout << "Enter the begin year: ";
    cin >> begin_year;

    //? Năm kết thúc lấy số liệu
    int end_year;
    cout << "Enter the end year: ";
    cin >> end_year;

    //? Range(begin_year, end_year)
    int range = end_year - begin_year + 1;
    DanSo* p = new DanSo [range];
    for (int i = 0; i < range; i++) {
        p[i].year = begin_year;
        cout << p[i].year << "      ";
        cin >> p[i].people;
        begin_year++;
    }

    find_year_min_max_people(p, range);
    find_year_have_same_people(p, range);

    delete [] p;
}