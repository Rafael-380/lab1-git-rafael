#include <iostream>     // For std::cout, std::endl
#include <vector>       // For std::vector
#include <numeric>      // For std::accumulate
#include <string>       // For std::string


class Student{
public:

    Student(std::string n, std::string s) {  //Constructor
        name = n;
        surname = s;
    }


    void set_name(const std::string& n) {
        name = n;
    }

    std::string get_name() const {
        return name;
    }

    void set_surname(const std::string& s){
        surname = s;
    }

    std::string get_surname() const {
        return surname;
    }

    void set_album_number(int album_nr){
        if (album_nr >= 10000 && album_nr <= 999999){
            album_number = album_nr;
        }
        else{
            std::cout << "Invalid student number. Must have 5 or 6 digits" << std::endl;
        }
    }

    int get_album_number() const {
        return album_number;
    }

    void add_grade(float grade){
        if (grade >= 1 && grade <= 5){
            grades.push_back(grade);
        }
        else{
            std::cout << "Invalid grade number. Must be between 1 and 5" << std::endl;
        }
    }

    void list_grades() const {
        for (float g : grades)
            std::cout << g << " ";
        std::cout << std::endl;
    }


    float calculate_grade() const {
        if (grades.empty()) return 0.0f;
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    void display_student() const {
        std::cout << "Name: " << name << " " << surname << "\n";
        std::cout << "Student number: " << album_number << "\n";
        std::cout << "Grades: ";
        for (float grade : grades){
            std::cout << grade << " ";
        }
        std::cout << "\n" << "Student average: " << calculate_grade() << std::endl;
    }

    bool passed_semester() const {
        int negatives = 0;
        for (float grade : grades){
            if (grade <= 2){
                negatives = negatives + 1;
            }
        }
        return negatives <= 1;
    }


private:
    std::string name;
    std::string surname;
    int album_number;
    std::vector<float> grades;
};


int main(){
    // Create a vector to store multiple students
    std::vector<Student> students;

    // Adding students to the vector and adding grades
    students.push_back(Student("Jan", "Kowalski"));
    students[0].set_album_number(12345);
    students[0].add_grade(4.5);
    students[0].add_grade(3.0);
    students[0].add_grade(5.0);

    students.push_back(Student("Alice", "Smith"));
    students[1].set_album_number(54321);
    students[1].add_grade(3.5);
    students[1].add_grade(2.5);
    students[1].add_grade(4.0);

    students.push_back(Student("Jon", "Failure"));
    students[2].set_album_number(98765);
    students[2].add_grade(2.0);
    students[2].add_grade(4.0);
    students[2].add_grade(2.0);

    // Printing students' information and average grades
    for (const Student& student : students) {
        student.display_student();
        //std::cout << student.get_name() << " " << student.get_surname() << ": ";
        if (student.passed_semester()){
            std::cout << "The student passed the semester" << "\n" << std::endl;
        }
        else {
            std::cout << "The student failed the semester" << "\n" << std::endl;
        }
    }
    return 0;
}
