#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct
{
    char Name[50];
    char Surname[50];
    int Points;
} Student;


int main(){

    FILE* fp;
    fp = fopen("datoteka.txt", "r");

    int numberOfStudents = readNumberOfStudents(fp);

    Student* students = dynamicAllocation(numberOfStudents);
    if(students == NULL) return -1;

    studentsInput(fp, students);
    studentsOutput(numberOfStudents, students);


}

int readNumberOfStudents(FILE* fp){
    
    if(fp == NULL){
        printf("Greška pri otvaranju datoteke");
        return -1;
    }

    int count;
    int currentChar;
    int lastChar;

    while((currentChar = fgetc(fp)) != EOF){

        if(isalpha(currentChar) && isdigit(lastChar)){
            count++;
        }

        lastChar = currentChar;
    }

    fp = fclose;
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

void studentsInput(FILE* fp, Student* students){
    
    int i;

    while(fscanf(fp, "%s %s %d", students[i].Name, students[i].Surname, &students[i].Points) == 3){
        i++;
    }
}

void studentsOutput(int numberOfStudents, Student* students){
    int i;
    int maxPoint = maxPoints(students, numberOfStudents);

    for(int i=0; i<numberOfStudents; i++){

        printf("%s %s %d", students[i].Name, students[i].Surname, relativePoints(&students[i].Points, maxPoint));
    }
}

double relativePoints(int points, int maxPoints){
    double relativePoints = (points/maxPoints)*100;
    return relativePoints;
}

int maxPoints(Student* students, int numberOfStudents){

    int maxPoints = 0;
    for(int i=0;i<numberOfStudents; i++){
        if(&students[i].Points> maxPoints){
            maxPoints = &students[i].Points;
        }
    }

    return maxPoints;
}

