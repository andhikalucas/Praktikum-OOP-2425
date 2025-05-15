import java.util.HashMap;
import java.util.HashSet;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        this.students = new HashMap<String, Student>();
        this.courses = new HashMap<String, Course>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        Student mapStudent = new Student(studentID, name);
        students.put(studentID, mapStudent);
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course mapCourse = new Course(courseID, courseName);
        courses.put(courseID, mapCourse);
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        if (!students.containsKey(studentID) || !courses.containsKey(courseID)) {
            System.out.println("Student atau course tidak ditemukan!");
            return;
        }

        Student s = students.get(studentID);
        s.enrollCourse(courseID);

        Course c = courses.get(courseID);
        c.addStudent(studentID);
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
        if (!students.containsKey(studentID)) {
            System.out.println("Student tidak ditemukan!");
            return;
        }

        Student s = students.get(studentID);
        HashSet<String> CourseList = s.getEnrolledCourses();
        System.out.println("Student " + s.getName() + " terdaftar di " + CourseList.size() + " course:");
        for (String x : CourseList) {
            System.out.println(x+ " "+ courses.get(x).getCourseName());
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
        if (!courses.containsKey(courseID)) {
            System.out.println("Course tidak ditemukan!");
            return;
        }

        Course c = courses.get(courseID);
        HashSet<String> StudentList = c.getEnrolledStudents();
        System.out.println("Course "+ c.getCourseName()+ " memiliki "+ StudentList.size()+ " student:");
        for (String x : StudentList) {
            System.out.println(x+ " "+ students.get(x).getName());
        }
    }
}
