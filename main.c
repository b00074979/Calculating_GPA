/* Assignment 1*/

/* ------------------------------------------------------------

Programmer: Aleena Chaudhry

ID: B00074979

Date: 26th October 2014

Purpose: A programme that asks for :STUDENT ID, NAME,MODULE ID, MODULE CREDITS AND MODULE GRADE.
         Programme should display student data and calculate GPA aswell as level of qualification achieved.

------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct module{
              char moduleid[5];
              int credit;
              float grade;
};/*Variables for the struct module are declared*/

struct student{
               char id[10];
               char first_name[15];
               char last_name[15];
               struct module results[6];
};/*Variables for struct student are declared*/

int main()
{
    int i,j,n,m;
    int s=0,l=0,t=0,h=0,k=0;
    char G,C;
    float GPA;


    FILE* ifp;/*file declared as a pointer */
    ifp = fopen("Final_GPA.dat", "w");/* opening file in write mode -so that the file can be written into*/
    if (ifp == NULL)
    {
    printf("Error opening file!\n");
    exit(1);
    }

    printf("\n\nPLEASE ENTER TOTAL NUMBER OF STUDENTS:\n\n");
    scanf("%d",&n);

    printf("\n\n\nPLEASE ENTER NUMBER OF TOTAL MODULES:\n");
    scanf("%d",&m);

    struct student data[n];

    for(i=0; i<n; i++){

      printf("\n\n\nPLEASE ENTER STUDENT %d DATA:\n\n1. Student ID,\n2.First Name:\n3.Last Name:\n\n",i+1,t=t+1);
      scanf("%s%s%s",data[i].id,data[i].first_name,data[i].last_name);

        for(j=0; j<m; j++){/* nested loop to enter Module details 'm' amount of times*/

          printf("\nENTER MODULE %d DATA: \n\n1.Module ID:\n2.Credits earned:\n3.Grade:\n",j+1,l=l+1);
          scanf("%s%d%f",data[i].results[j].moduleid,&data[i].results[j].credit,&data[i].results[j].grade);


        }
    }

    for(i=0;i<n;i++) {/* these loops print out the data that we entered onto the screen*/

      printf("\t\t\t------------------------\t\t\t");
      printf("\n\t\t\tDATA ENTERED FOR STUDENT %d:\n\t\t\t",s=s+1);
      printf("\n\tID: %s\n\tName: %s %s\n\n\t",data[i].id,data[i].first_name,data[i].last_name);

        for(j=0; j<m; j++){

           printf("\n\n\t\t\t----------\t\t\t\n\n");
           printf("\n\tModule ID: %s\n\tCredits earned: %d\n\tGrade: %.2f\n\t",data[i].results[j].moduleid,data[i].results[j].credit,data[i].results[j].grade);
           fflush(stdin);

           fprintf(ifp,"\t\t\n\n----Student %d Data----\t\t\n\n",h=h+1);
           fprintf(ifp,"\n\nStudent ID:%s\n\n Student Name: %s%s\n\n",data[i].id,data[i].first_name,data[i].last_name);
           fprintf(ifp,"\t\t\n\n----Module %d Data----\t\t\n\n",k=k+1);
           fprintf(ifp,"\n\n Module ID:%s\n\n Credits Awarded:%d\n\n Percentage Grade:%f",data[i].results[j].moduleid,data[i].results[j].credit,data[i].results[j].grade);

                   /* fprintf statements print the contents into the stated file above*/

       if (data[i].results[j].grade<100.00&& data[i].results[j].grade  >80.00) {
        printf("\n\tGrade = A\n",G);
        printf("\tGPA awarded = 4.00\n",GPA);
        printf("\tCredits awarded: Yes\n",C);

  }

       else if (data[i].results[j].grade<79.99 &&data[i].results[j].grade > 70.00 ) {
          printf("\n\tGrade is B+\n",G);
          printf("\tGPA awarded = 3.50\n",GPA);
          printf("\tCredits awarded: Yes\n",C);
  }

       else if (data[i].results[j].grade<69.99 && data[i].results[j].grade > 60.00 ) {
          printf("\n\tGrade is B\n",G);
          printf("\tGPA awarded = 3.00\n",GPA);
          printf("\tCredits awarded: Yes\n",C);
  }

       else if (data[i].results[j].grade<59.99 && data[i].results[j].grade > 55.00) {
         printf("\n\tGrade is B-\n",G);
         printf("\tGPA awarded = 2.75\n",GPA);
         printf("\tCredits awarded: Yes\n",C);
  }

       else if (data[i].results[j].grade<54.99 && data[i].results[j].grade>50.00) {
         printf("\n\tGrade is C+\n",G);
         printf("\tGPA awarded = 2.50\n",GPA);
         printf("\tCredits awarded: Yes\n",C);
  }

      else if (data[i].results[j].grade<49.99 && data[i].results[j].grade>40.00  ) {
        printf("\n\tGrade is C\n",G);
        printf("\tGPA awarded = 2.00\n",GPA);
        printf("\tCredits awarded: Yes\n",C);
  }

      else if (data[i].results[j].grade< 39.99 && data[i].results[j].grade>35.99 ) {
        printf("\n\tGrade is D\n",G);
        printf("\tGPA awarded = 1.50\n",GPA);
        printf("\tCredits awarded: Yes\n",C);
  }

      else if ( data[i].results[j].grade < 35 ){
        printf("\n\tGrade is F\n",G);
        printf("\tGPA awarded = 0.00\n",GPA);
        printf("\tCredits awarded: No\n",C);
      }

      else if (data[i].results[j].grade>100){
        printf("\t\t\tValue entered is too high enter a grade between 0-100\n");
        printf("\tCredits awarded: No\n");
      }
     }
    }

    fclose(ifp);

 return 0;
}
