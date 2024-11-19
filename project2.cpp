#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Student 
{
    private:
        std::string first_name;
        std::string last_name;
        float gpa;
        int graduation_year;
        std::string graduation_semester;
        int enrolled_year;
        std::string enrolled_semester;
        std::string undergrad_grad;

    public:
        Student() : first_name(""), last_name(""), gpa(0.0), graduation_year(0),
                    graduation_semester(""), enrolled_year(0), enrolled_semester(""),
                    undergrad_grad("Undergrad") {}

        ~Student() {}

        void setName(const std::string& first, const std::string& last) 
        {
            first_name = first;
            last_name = last;
        }

        void setGPA(float g) { gpa = g; }
        void setGraduationYear(int year) { graduation_year = year; }
        void setGraduationSemester(const std::string& semester) { graduation_semester = semester; }
        void setEnrolledYear(int year) { enrolled_year = year; }
        void setEnrolledSemester(const std::string& semester) { enrolled_semester = semester; }
        void setGradType(const std::string& status) { undergrad_grad = status; }

        std::string getName() const { return first_name + " " + last_name; }
        float getGPA() { return gpa; }
        int getGraduationYear() { return graduation_year; }
        std::string getGraduationSemester() const { return graduation_semester; }
        int getEnrolledYear() { return enrolled_year; }
        std::string getEnrolledSemester() { return enrolled_semester; }
        std::string getGradType() { return undergrad_grad; }

        void writeToFile(std::ofstream& outfile) 
        const {
            outfile << getName() << ", " << gpa << ", " << graduation_year << ", "
                    << graduation_semester << ", " << enrolled_year << ", "
                    << enrolled_semester << ", " << undergrad_grad << std::endl;
        }
};

class Art_Student : public Student
{
    private:
        std::string art_emphasis;

    public:
        Art_Student() : Student(), art_emphasis("Art Studio") {}

        void setArtEmphasis(const std::string& emphasis) { art_emphasis = emphasis; }
        std::string getArtEmphasis() { return art_emphasis; }

        void writeToFile(std::ofstream& outfile) 
        const {
            Student::writeToFile(outfile);
            outfile << ", " << art_emphasis << std::endl;
        }
};

class Physics_Student : public Student 
{
    private:
        std::string concentration;

    public:
        Physics_Student() : Student(), concentration("Biophysics") {}

        void setConcentration(const std::string& concentrate) { concentration = concentrate; }
        std::string getConcentration() const { return concentration; }

        void writeToFile(std::ofstream& outfile) 
        const {
            Student::writeToFile(outfile);
            outfile << ", " << concentration << std::endl;
        }
};

int main()
{
    std::vector<Art_Student*> art_students;
    std::vector<Physics_Student*> physics_students;

    art_students.push_back(new Art_Student);
    art_students[0]->setName("John", "Doe");
    art_students[0]->setGPA(3.9);
    art_students[0]->setGraduationYear(2025);
    art_students[0]->setGraduationSemester("Spring");
    art_students[0]->setEnrolledYear(2021);
    art_students[0]->setEnrolledSemester("Fall");
    art_students[0]->setGradType("Undergrad");
    art_students[0]->setArtEmphasis("Art Studio");

    art_students.push_back(new Art_Student);
    art_students[1]->setName("Mike", "Ekim");
    art_students[1]->setGPA(2.0);
    art_students[1]->setGraduationYear(2027);
    art_students[1]->setGraduationSemester("Spring");
    art_students[1]->setEnrolledYear(2021);
    art_students[1]->setEnrolledSemester("Fall");
    art_students[1]->setGradType("Undergrad");
    art_students[1]->setArtEmphasis("Art Studio");

    art_students.push_back(new Art_Student);
    art_students[2]->setName("John", "John");
    art_students[2]->setGPA(3.9);
    art_students[2]->setGraduationYear(2026);
    art_students[2]->setGraduationSemester("Spring");
    art_students[2]->setEnrolledYear(2019);
    art_students[2]->setEnrolledSemester("Fall");
    art_students[2]->setGradType("Grad");
    art_students[2]->setArtEmphasis("Art Education");

    art_students.push_back(new Art_Student);
    art_students[3]->setName("Ryan", "Bryan");
    art_students[3]->setGPA(4.1);
    art_students[3]->setGraduationYear(2026);
    art_students[3]->setGraduationSemester("Spring");
    art_students[3]->setEnrolledYear(2021);
    art_students[3]->setEnrolledSemester("Fall");
    art_students[3]->setGradType("Undergrad");
    art_students[3]->setArtEmphasis("Art History");

    art_students.push_back(new Art_Student);
    art_students[4]->setName("Donald", "Harris");
    art_students[4]->setGPA(1.8);
    art_students[4]->setGraduationYear(2025);
    art_students[4]->setGraduationSemester("Fall");
    art_students[4]->setEnrolledYear(2021);
    art_students[4]->setEnrolledSemester("Fall");
    art_students[4]->setGradType("Undergrad");
    art_students[4]->setArtEmphasis("Art Education");

    physics_students.push_back(new Physics_Student);
    physics_students[0]->setName("Johnathon", "Hetfield");
    physics_students[0]->setGPA(3.8);
    physics_students[0]->setGraduationYear(2027);
    physics_students[0]->setGraduationSemester("Fall");
    physics_students[0]->setEnrolledYear(2021);
    physics_students[0]->setEnrolledSemester("Spring");
    physics_students[0]->setGradType("Undergrad");
    physics_students[0]->setConcentration("Earth and Planetary Sciences");

    physics_students.push_back(new Physics_Student);
    physics_students[1]->setName("Charles", "Smith");
    physics_students[1]->setGPA(2.9);
    physics_students[1]->setGraduationYear(2026);
    physics_students[1]->setGraduationSemester("Spring");
    physics_students[1]->setEnrolledYear(2021);
    physics_students[1]->setEnrolledSemester("Spring");
    physics_students[1]->setGradType("Grad");
    physics_students[1]->setConcentration("Biophysics");

    physics_students.push_back(new Physics_Student);
    physics_students[2]->setName("Walter", "White");
    physics_students[2]->setGPA(4.2);
    physics_students[2]->setGraduationYear(2024);
    physics_students[2]->setGraduationSemester("Fall");
    physics_students[2]->setEnrolledYear(2020);
    physics_students[2]->setEnrolledSemester("Spring");
    physics_students[2]->setGradType("Grad");
    physics_students[2]->setConcentration("Biophysics");

    physics_students.push_back(new Physics_Student);
    physics_students[3]->setName("Jennifer", "Mike");
    physics_students[3]->setGPA(3.4);
    physics_students[3]->setGraduationYear(2027);
    physics_students[3]->setGraduationSemester("Fall");
    physics_students[3]->setEnrolledYear(2021);
    physics_students[3]->setEnrolledSemester("Spring");
    physics_students[3]->setGradType("Undergrad");
    physics_students[3]->setConcentration("Earth and Planetary Sciences");

    physics_students.push_back(new Physics_Student);
    physics_students[4]->setName("Juanita", "Smith");
    physics_students[4]->setGPA(3.5);
    physics_students[4]->setGraduationYear(2045);
    physics_students[4]->setGraduationSemester("Fall");
    physics_students[4]->setEnrolledYear(2020);
    physics_students[4]->setEnrolledSemester("Spring");
    physics_students[4]->setGradType("Grad");
    physics_students[4]->setConcentration("Earth and Planetary Sciences");

    std::ofstream outfile;
    outfile.open("student_info.dat", std::ios::out);

    for (int i = 0; i < art_students.size(); i++) {
        art_students[i]->writeToFile(outfile);
    }

    for (int i = 0; i < physics_students.size(); i++) {
        physics_students[i]->writeToFile(outfile);
    }

    outfile.close();

    for (int i = 0; i < art_students.size(); i++) {
        delete art_students[i];
    }

    for (int i = 0; i < physics_students.size(); i++) {
        delete physics_students[i];
    }

    return 0;
}