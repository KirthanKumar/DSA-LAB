// Details of students using structure and array of structure.
#include <stdio.h>
#include <string.h>

struct student
{
    int rnumber;
    char name[20];
    int marks;
    char grade;
} stud[60];

void main()
{

    int n;
    float sum = 0, avg = 0;

    printf("Enter the number of students:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("\nEnter student %d details:", i);
        printf("\nRoll-Number : ");
        scanf("%d", &stud[i].rnumber);
        printf("\nName : ");
        scanf("%s", &stud[i].name);
        printf("\nMarks : ");
        scanf("%d", &stud[i].marks);
        fflush(stdin);
        printf("\nGrade : ");
        stud[i].grade=getchar();
        sum += stud[i].marks;
    }
    avg = sum / n;
    printf("\nAverage marks is:",avg);
    printf("\nDetails of the students is:\n");
    printf("\n Roll-Number\t\tName\t\tMarks\t\tGrade");
    for (int i = 1; i <= n; i++)
    {
        printf("\n%d\t\t\t%s\t\t\t%d\t\t\t%c", stud[i].rnumber, stud[i].name, stud[i].marks, stud[i].grade);
    }

    printf("\nDetails of the students who scored above average is:\n");
    printf("\n Roll-Number\t\tName\t\tMarks\t\tGrade");
    for (int i = 1; i <= n; i++)
    {
        if (stud[i].marks >= avg)
        {

            printf("\n%d\t\t\t%s\t\t\t%d\t\t\t%c", stud[i].rnumber, stud[i].name, stud[i].marks, stud[i].grade);
        }
    }

    printf("\nDetails of the students who scored below average is:\n");
    printf("\n Roll-Number\t\tName\t\tMarks\t\tGrade");
    for (int i = 1; i <= n; i++)
    {
        if (stud[i].marks < avg)
        {

            printf("\n%d\t\t\t%s\t\t\t%d\t\t\t%c", stud[i].rnumber, stud[i].name, stud[i].marks, stud[i].grade);
        }
    }
    getch();
}