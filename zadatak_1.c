#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char Name[50];
    char Surname[50];
    int Points;
} Student;


int readNumberOfStudents(FILE* fp){
    
    if(fp == NULL){
        printf("Greška pri otvaranju datoteke");
        return -1;
    }

    int count = 0;
    char name[50], surname[50];
    int points;

    while(fscanf(fp, "%49s %49s %d", name, surname, &points) == 3) {
        count++;
    }

    
    return count;

}

Student* dynamicAllocation(int numberOfStudents){
    Student * students = (Student*) malloc(numberOfStudents* sizeof(Student));
    
    if(students == NULL){
        printf("Greška pri alkoaciji memorije");
        return NULL;
    }

    return students;    
}

void studentsInput(FILE* fp, Student* students, int numberOfStudents){
    
    for (int i = 0; i < numberOfStudents; i++) {
        fscanf(fp, "%49s %49s %d", students[i].Name, students[i].Surname, &students[i].Points);
    }
    
}




int maxPoints(Student* students, int numberOfStudents){

    int maxPoints = 0;
    for(int i=0;i<numberOfStudents; i++){
        if(students[i].Points> maxPoints){
            maxPoints = students[i].Points;
        }
    }

    return maxPoints;
}

double relativePoints(int points, int maxPoints){
    return ((double)points / maxPoints) * 100;
}


void studentsOutput(int numberOfStudents, Student* students){
    int i = 0;
    int maxPoint = maxPoints(students, numberOfStudents);

    for(int i=0; i<numberOfStudents; i++){

        printf("%s %s %.2f\n", students[i].Name, students[i].Surname, relativePoints(students[i].Points, maxPoint));
    }
}


int main(){

    FILE* fp;
    fp = fopen("datoteka.txt", "r");

    int numberOfStudents = readNumberOfStudents(fp);

    rewind(fp);

    Student* students = dynamicAllocation(numberOfStudents);
    if(students == NULL) return -1;

    studentsInput(fp, students, numberOfStudents);
    studentsOutput(numberOfStudents, students);

    free(students);
    fclose(fp);

    return 0;

}
