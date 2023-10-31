#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}
};

class Student {
private:
    string last_name;
    string first_name;
    string middle_name;
    Date birth_date;
    string home_address;
    string phone_number;
    int* gradesMath;
    int* gradesPhysicalEducation;
    int* gradesChemistry;
    int maxGrades;

public:
    Student(string first, string last, int max) : first_name(first), last_name(last), maxGrades(max) 
    {
        gradesMath = new int[max]();
        gradesPhysicalEducation = new int[max]();
        gradesChemistry = new int[max]();
    }

    void SetBirthDate(const Date& date) {
        birth_date = date;
    }

    Date GetBirthDate() const {
        return birth_date;
    }

    void SetHomeAddress(const string& address) {
        home_address = address;
    }

    string GetHomeAddress() const {
        return home_address;
    }

    void SetPhoneNumber(const string& phone) {
        phone_number = phone;
    }

    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetLastName(const string& last) {
        last_name = last;
    }

    string GetLastName() const {
        return last_name;
    }

    void AddMathGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < maxGrades) {
            gradesMath[subject_index] = grade;
        }
    }

    int GetMathGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < maxGrades) {
            return gradesMath[subject_index];
        }
        return -1;
    }

    void AddPhysicalEducationGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < maxGrades) {
            gradesPhysicalEducation[subject_index] = grade;
        }
    }

    int GetPhysicalEducationGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < maxGrades) {
            return gradesPhysicalEducation[subject_index];
        }
        return -1;
    }

    void AddChemistryGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < maxGrades) {
            gradesChemistry[subject_index] = grade;
        }
    }

    int GetChemistryGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < maxGrades) {
            return gradesChemistry[subject_index];
        }
        return -1;
    }

    void ShowStudentInfo() const {
        cout << "Фамилия: " << last_name << endl;
        cout << "Имя: " << first_name << endl;
        cout << "Отчество: " << middle_name << endl;
        cout << "Дата рождения: " << birth_date << endl;
        cout << "Домашний адрес: " << home_address << endl;
        cout << "Телефонный номер: " << phone_number << endl;

        cout << "Оценки по математике: ";
        for (int i = 0; i < maxGrades; i++) {
            cout << gradesMath[i] << " ";
        }
        cout << endl;

        cout << "Оценки по физкультуре: ";
        for (int i = 0; i < maxGrades; i++) {
            cout << gradesPhysicalEducation[i] << " ";
        }
        cout << endl;

        cout << "Оценки по химии: ";
        for (int i = 0; i < maxGrades; i++) {
            cout << gradesChemistry[i] << " ";
        }
        cout << endl;
    }

   
    ~Student() {
        delete[] gradesMath;
        delete[] gradesPhysicalEducation;
        delete[] gradesChemistry;
    }
};

int main() {
    setlocale(LC_ALL, "");
    int maxGrades = 5;

    Student student("Антон", "Васильев", maxGrades);

    student.SetBirthDate(Date(2000, 1, 1));
    student.SetHomeAddress("ул. Добровольского, 123");
    student.SetPhoneNumber("+38(097)264-18-54");

    student.AddMathGrade(0, 95);
    student.AddMathGrade(1, 88);

    student.AddPhysicalEducationGrade(0, 85);
    student.AddPhysicalEducationGrade(1, 90);

    student.AddChemistryGrade(0, 75);
    student.AddChemistryGrade(1, 80);

    student.ShowStudentInfo();

    student.SetLastName("Петров");
    student.SetPhoneNumber("+38(097)234-13-24");

    cout << "Измененная фамилия: " << student.GetLastName() << endl;
    cout << "Измененный телефонный номер: " << student.GetPhoneNumber() << endl;

    return 0;
}
