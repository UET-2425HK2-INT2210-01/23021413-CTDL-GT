#include <iostream>
using namespace std;
#define MAX_NAME_LENGTH 100
#define MAX_GRADE_LENGTH 30
class Student
{
public:
    int ID;
    char name[MAX_NAME_LENGTH];  // Mảng ký tự cho tên sinh viên
    char grade[MAX_GRADE_LENGTH];  // Mảng ký tự cho lớp học
    Student* next;
    // Constructor
    Student(int ID = 0, const char* name = "", const char* grade = "") : ID(ID), next(NULL)
    {
        // Sao chép tên và lớp học vào mảng
        int i = 0;
        while (name[i] != '\0' && i < MAX_NAME_LENGTH - 1)
        {
            this->name[i] = name[i];
            i++;
        }
        this->name[i] = '\0';  // Kết thúc chuỗi tên

        i = 0;
        while (grade[i] != '\0' && i < MAX_GRADE_LENGTH - 1)
        {
            this->grade[i] = grade[i];
            i++;
        }
        this->grade[i] = '\0';  // Kết thúc chuỗi lớp học
    }
    // Chèn sinh viên vào danh sách
    void Insert(Student*& List_Student, int ID, const char* name, const char* grade)
    {
        Student* newStudent = new Student(ID, name, grade);
        if (!List_Student)
        {
            List_Student = newStudent;
            return;
        }
        // Duyệt đến cuối danh sách để thêm phần tử mới
        Student* temp = List_Student;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    // Xóa sinh viên khỏi danh sách
    void Delete(Student*& List_Student, int ID)
    {
        if (!List_Student)
            return;
        // Nếu phần tử cần xóa là phần tử đầu
        if (List_Student->ID == ID)
        {
            Student* temp = List_Student;
            List_Student = List_Student->next;
            delete temp;
            return;
        }
        // Tìm và xóa phần tử có ID khớp
        Student* prev = List_Student;
        Student* curr = List_Student->next;
        while (curr)
        {
            if (curr->ID == ID)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    // Tìm thông tin sinh viên
    void Infor(Student* List_Student, int ID)
    {
        Student* temp = List_Student;
        while (temp)
        {
            if (temp->ID == ID)
            {
                cout << temp->name << "," << temp->grade << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "NA,NA" << endl;
    }
};

int main()
{
    Student* List_Student = NULL;
    Student s;

    char operation[20];
    while (true)
    {
        cin.getline(operation, 20);  // Đọc lệnh từ bàn phím
        if (operation[0] == 'I' && operation[1] == 'n' && operation[2] == 's' && operation[3] == 'e' && operation[4] == 'r' && operation[5] == 't')  // Thực hiện Insert
        {
            int ID;
            char name[MAX_NAME_LENGTH], grade[MAX_GRADE_LENGTH];
            sscanf(operation, "Insert(%d,%s,%s)", &ID, name, grade);  // Dùng sscanf để lấy thông tin từ lệnh
            s.Insert(List_Student, ID, name, grade);
        }
        else if (operation[0] == 'D' && operation[1] == 'e' && operation[2] == 'l' && operation[3] == 'e' && operation[4] == 't' && operation[5] == 'e')  // Thực hiện Delete
        {
            int ID;
            sscanf(operation, "Delete(%d)", &ID);
            s.Delete(List_Student, ID);
        }
        else if (operation[0] == 'I' && operation[1] == 'n' && operation[2] == 'f' && operation[3] == 'o' && operation[4] == 'r')  // Thực hiện Infor
        {
            int ID;
            sscanf(operation, "Infor(%d)", &ID);
            s.Infor(List_Student, ID);
        }
        else if (operation[0] == 'E' && operation[1] == 'X' && operation[2] == 'I' && operation[3] == 'T')  // Thoát
        {
            break;
        }
    }
    return 0;
}
