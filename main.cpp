
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

struct Student{ // student struct to store student info
    int id;
    string first;
    string last;
    int exam1;
    int exam2;
    int exam3;
    float mean;

};

void ComputeMean(Student myStudents[], int num){ // func that finds finalMean by getting average of all means.
    float finalMean = 0;
    for (int i = 0; i < num; i++){
        finalMean+= myStudents[i].mean;
    }
    finalMean = finalMean / num;
    cout << "The overall mean of exams is " << fixed << setprecision(2) <<finalMean << endl;

}

void MinMean(Student myStudents[], int num){ // sets minMean = to first value then compares to other students means
    float minMean = myStudents[0].mean;
    for (int i = 0; i < num; i++){
        if (myStudents[i].mean < minMean){
            minMean = myStudents[i].mean;
        }
    }
    cout << "Minimum of mean of the exams: " << minMean << endl;
}

void MaxMean(Student myStudents[], int num){ // sets maxMean = to first value then compares to other students means
    float maxMean = myStudents[0].mean;
    for (int i = 0; i < num; i++){
        if (myStudents[i].mean > maxMean){
            maxMean = myStudents[i].mean;
        }
    }
    cout << "Maximum of mean of the exams: " << maxMean << endl;
}

void AddStudent(Student students[], int num){  // inputs student information and calculates student mean
    cout << "Enter students' information" << endl;
    cout << "Id: ";
    cin >> students[num].id;
    cout << endl << "First name: ";
    cin >> students[num].first;
    cout << endl << "Last name: ";
    cin >> students[num].last;
    cout << endl << "Exam 1 score: ";
    cin >> students[num].exam1;
    cout << endl << "Exam 2 score: ";
    cin >> students[num].exam2;
    cout << endl << "Exam 3 score: ";
    cin >> students[num].exam3;
    students[num].mean = float(students[num].exam1 + students[num].exam2 + students[num].exam3) / 3.00; // adds 3 tests up and divides by 3
    cout << endl <<"New student with id " << students[num].id << " added." << endl << endl;
}

void UpdateStudent(Student students[], int num){
    bool isFound;
    int id;
    int i;
    cout << "Enter student id to update:";
    cin >> id;
    for (i = 0; i < num; i++){
        if(students[i].id == id){
            isFound = true;
            break;
        }
    }

    if (students[i].id != id){ // if can't find student id in array 
        cout << "Student not found" << endl;
        isFound = false;
    }

    if(isFound){
        cout << "Update students' information:" <<endl;
        cout << "First name: ";
        cin >> students[num].first;
        cout << endl << "Last name: ";
        cin >> students[num].last;
        cout << endl <<  "Exam 1 score: ";
        cin >> students[num].exam1;
        cout << endl <<  "Exam 2 score: ";
        cin >> students[num].exam2;
        cout << endl <<  "Exam 3 score: ";
        cin >> students[num].exam3;
        students[num].mean = (students[num].exam1 + students[num].exam2 + students[num].exam3) / 3;
        cout << "Students information with id " << id << " updated." << endl;

   } 
}

void PrintMyInfo(){ // function to print my student information
    cout << "+" << setfill('-') << setw(47) << "+" << endl << endl;
    cout << "|       Computer Science and Engineering       |" << endl << endl;
    cout << "|      CSCE 1040 - Computer Science II         |" << endl << endl;
    cout << "| Eric Parker  etp0040  ericparker3@my.unt.edu |" << endl << endl;
    cout << "+" << setfill('-') << setw(47) << "+" << endl << endl << endl;

}

void DisplayStudentInfo(Student students[], int num){
    cout << setw(23) << " " << "Students Information " << setw(23) << " " << endl;
    cout << "Id        First name    Last name        Exam1  Exam2  Exam3   Mean" << endl;
    cout << endl << setfill('_') << setw(68) << " " << endl << endl;
    for (int i = 0; i < num; i++){
        cout << setfill(' ') << setw(9) << left << students[i].id << " " << setw(9) << left << students[i].first
         << setw(5) << right << " " << setw(19) << left << students[i].last << setw(3) << right << students[i].exam1
        << setw(7) << students[i].exam2 << setw(7) << students[i].exam3 << setw(7)<< fixed << setprecision(2) << students[i].mean << endl << endl;
    }
}

void DisplayMenu(){
    cout << endl;
    cout << setfill('*') << setw(29) << " Menu " << setw(24) << " " <<  endl; 
    cout << "| 1. Display list of students' information         |" << endl << endl;
    cout << "| 2. Add new student                               |" << endl << endl;
    cout << "| 3. Update existing student                       |" << endl << endl;
    cout << "| 4. Compute mean of the exams                     |" << endl << endl;
    cout << "| 5. Compute minimum of the mean of the exams      |" << endl << endl;
    cout << "| 6. Compute maximum of the mean of the exams      |" << endl << endl;
    cout << "| 7. Exit program.                                 |" << endl << endl;
    cout << setw(53) << " " << endl << endl;
}

bool areStudents(int numStudents){ // checks if no students and doesnt allow execution if none
    if (numStudents == 0){
        cout << "Empty list of students." << endl << endl << endl;
        return false;
    }
    else{
        return true;
    }

}

int main(){
    int numStudents = 0;
    int userChoice;
    Student myStudents[20];
    PrintMyInfo();
    DisplayMenu();
    while (userChoice != 7){
        cin >> userChoice;
        if (userChoice > 7 || userChoice < 0){
            cout << "Please enter a number between 1-7" << endl;
            DisplayMenu();
        }
        switch (userChoice)
        {
        case 1:
            if(!areStudents(numStudents)){
                DisplayMenu();
                break;
            }
            DisplayStudentInfo(myStudents, numStudents);
            DisplayMenu();
            break;
       case 2:
            AddStudent(myStudents, numStudents);
            DisplayMenu();
            numStudents ++;
            break;
        case 3:
            if(!areStudents(numStudents)){
                break;
            }
            UpdateStudent(myStudents, numStudents);
            DisplayMenu();
            break;
        case 4:
            if(!areStudents(numStudents)){
                break;
            }
            ComputeMean(myStudents, numStudents);
            DisplayMenu();
            break;
        case 5:
            if(!areStudents(numStudents)){
                break;
            }
            MinMean(myStudents, numStudents);
            DisplayMenu();
            break;
        case 6:
            if(!areStudents(numStudents)){
                break;
            }
            MaxMean(myStudents, numStudents);
            DisplayMenu();
            break;

        default:
            break;
        }
        
    }
    cout << "Thank you for using this program. Goodbye!" << endl;

    return 0;
}
