#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENTS_INITIAL_FILE "Students.csv"
#define USERS_INITIAL_FILE "Users.csv"
#define INSTRUCTORS_INITIAL_FILE "Instructors.csv"
#define COURSES_INITIAL_FILE "Courses.csv"
#define INSTRUCTORCOURSES_INITIAL_FILE "InstructorCourses.csv"
#define STUDENTSCOURSES_INITIAL_FILE "StudentCoursesss.csv"
#define TEMP_FILE_USERS "TempUpdateUsers.csv"
#define TEMP_FILE_COURSES "TempUpdateCourses.csv"

#define STUDENTS_INITIAL_BINFILE "Students.bin"
#define USERS_INITIAL_BINFILE "Users.bin"
#define INSTRUCTORS_INITIAL_BINFILE "Instructors.bin"
#define COURSES_INITIAL_BINFILE "Courses.bin"
#define INSTRUCTORCOURSES_INITIAL_BINFILE "InstructorCourses.bin"
#define STUDENTSCOURSES_INITIAL_BINFILE "StudentCourses.bin"

#define MAX_ID_SIZE 11
#define MAX_TC_SIZE 11
#define MAX_COURSE_SIZE 6
#define MAX_SIZE 500
#define MAX_STUDENTNO_SIZE 9
#define MAX_YEAR_SIZE 4
#define STUDENT_TYPE "S"
#define INSTRUCTOR_TYPE "I"
#define SYSTEM_TYPE "A"
#define YES 'Y'
#define NO 'N'
#define COMMA ','
#define TRUE 1
#define FALSE 0
#define EMPTY_STRING "  "
typedef  struct{
	char ID[MAX_ID_SIZE];  		  			/*TC of Users*/
	char userType[MAX_SIZE];							/*type of the user*/
	char userName[MAX_SIZE]; 			 	/*username of the user*/
	char password[MAX_SIZE];	 			/*password of the user*/				
}users_t;

typedef  struct{
	char TC[MAX_TC_SIZE];					/*TC of Student*/
	char Name[MAX_SIZE]; 	 				/*name of the Student*/
	char surName[MAX_SIZE]; 			 	/*surname of the user*/
	char studentNo[MAX_STUDENTNO_SIZE]; 	/*number of user(student)*/
	char startYear[MAX_SIZE]; 						/*user(student) to the course start year*/
	int Term;								/*term of user(student)*/
}students_t;

typedef  struct{
	char TC[MAX_TC_SIZE];  		  			/*TC of Instructor */
	char Name[MAX_SIZE]; 	 				/*name of the Instructor*/
	char surName[MAX_SIZE]; 		 		/*surname of Instructor */
}instructors_t;								/*Struct of Instructor*/

typedef  struct{
	char courseCode[MAX_COURSE_SIZE];		/* name of the Course */
	char courseName[MAX_SIZE];				/*name of the Course*/
	char instructorName[MAX_SIZE];			/*name of the Instructor*/
	char instructorSurName[MAX_SIZE];		/*surname of Instructor */
	int term;					       		/*term of user(student)*/
	int passingGrade;						/*passingGrade of Course*/
	int checkAddRemove;						/*Add-Remove mode of Course */
	int checkOpenClose;		 	      		/*Open-Close mode of Course */
	char prerequisiteCourse[MAX_SIZE]; 	    /*prerequisite of Courses*/
}courses_t;									/*Struct of Courses*/

typedef  struct{
	char TC[MAX_TC_SIZE];					/*TC of Instructor */
	char studentNo[MAX_STUDENTNO_SIZE]; 	/*number of user(student)*/
	char studentName[MAX_SIZE];				/*name of the Student*/
	char studentSurName[MAX_SIZE];			/*name of the Student*/
	char courseCode[MAX_COURSE_SIZE];		/* code of the Course */
	char courseName[MAX_SIZE];				/*Name of Course*/
	int Grade;								/* grade of Course to pass*/
	int checkActivePasive;					/*checking active-pasive of Course*/
}studentsCourses_t;							/*Struct of StudentCourses*/

typedef  struct{
	char courseCode[MAX_COURSE_SIZE];		/* name of the Course */
	char TC[MAX_TC_SIZE];					/*TC of Instructor */
	char courseName[MAX_SIZE]; 			 	/*name of the Course*/
	char instructorName[MAX_SIZE];			/*name of the Instructor*/
	char instructorSurName[MAX_SIZE]; 		/*surname of Instructor */
	int term;				       			/*term of user(student)*/
	int passingGrade;			       		/*passingGrade of Course*/
	int checkAddRemove;		      			/*Add-Remove mode of Course */
	int checkOpenClose;		       			/*Open-Close mode of Course */
}instructorsCourses_t;						/*Struct of InstructorCourses*/

typedef struct {
	char ID[MAX_ID_SIZE];					/*TC of system user*/
	char userName[MAX_SIZE];				/*username of system user*/
	char password[MAX_SIZE];				/*password of system user*/
}systemUser_t;
void createSystemUser(FILE *inoutpUsers,systemUser_t *systemUser);

void systemFunction(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

int readBinaryFiles(char fileName[]);

int TCquestioning(char x[30]);

int studentNoQuestioning(char studentNo[MAX_SIZE]);

int startYearQuestioning(char startYear[MAX_YEAR_SIZE]);

int system_EXIT(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

int loginFunction(FILE *inoutpUsers, FILE *inoutpStudents, FILE *inoutpInstructors,users_t *user,students_t *student , instructors_t *instructor ,systemUser_t *systemUser);

int loginArgumentFunction( char const *argv[],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void addUser(FILE *inoutpUsers,FILE *inoutpInstructors, FILE *inoutpStudents ,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,FILE *inoutpCourses, users_t *user, students_t *student, instructors_t *instructor,courses_t *course ,systemUser_t *systemUser,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse);

void removeUser(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void modifyUser(FILE *inoutpUsers, FILE *inoutpStudents, FILE *inoutpInstructors,FILE *inoutpCourses, FILE *inoutpStudentCourses, FILE *inoutpInstructorCourses, users_t *user, students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void createCourse(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void removeSystemCourse(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void removeStudentCourse(int lineOfFile,char tempStudentTC[MAX_TC_SIZE],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void createTranscript(int lineOfFile,char tempStudentTC[MAX_SIZE], int tempStudentTerm,char tempStudentNo[MAX_STUDENTNO_SIZE],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);

void modifyCourse(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void userTypeFunctionControl(int lineOfFile, FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser);

void clear(void);
void listCourse(char tempStudentNo[MAX_STUDENTNO_SIZE],char tempStudentTC[MAX_TC_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void listOpenCourse(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE] ,int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
char getCharFromUser();
int EXIT();
void addCourse(int lineOfFile, int tempStudentTerm,char tempStudentTC[MAX_TC_SIZE],char tempStudentNo[MAX_STUDENTNO_SIZE],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);

void studentFunction(int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void instructorFunction(int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void openCourse(char tempTC[MAX_TC_SIZE], int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void finalizeCourse(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void editGrades(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE] ,int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void assignGrades(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
void listGrades(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser);
int main(int argc, char const *argv[])
 {
 	FILE *inoutpUsers;
 	FILE *inoutpCourses;
 	FILE *inoutpStudents;
 	FILE *inoutpInstructors;
 	FILE *inoutpInstructorCourses;
 	FILE *inoutpStudentCourses;

 	users_t *user;
 	students_t *student;
 	instructors_t *instructor;
 	courses_t *course;
 	instructorsCourses_t *instructorCourse;
 	studentsCourses_t *studentCourse; 
 	systemUser_t *systemUser;
	
	char fileName[MAX_SIZE];
	int size_of_users = 0;
	int size_of_students = 0;
	int size_of_instructors = 0;
 	int lineOfFile;
 	user=(users_t*)malloc(sizeof(users_t)*(100) );
 	student=(students_t*)malloc(sizeof(students_t)*(100) );
 	instructor=(instructors_t*)malloc(sizeof(instructors_t)*(100) );
 	course=(courses_t*)malloc(sizeof(courses_t)*(100) );
 	instructorCourse=(instructorsCourses_t*)malloc(sizeof(instructorsCourses_t)*(100) );
 	studentCourse=(studentsCourses_t*)malloc(sizeof(studentsCourses_t)*(100) );
 	systemUser=(systemUser_t*)malloc(sizeof(systemUser_t)*(100) );
 
 	inoutpUsers =fopen(USERS_INITIAL_FILE,"r");

	if(fopen(USERS_INITIAL_BINFILE,"rb")  == NULL){/*if Users.bin is not there*/
 	printf("LOADING BINARY FILE...\n");
 	printf("There is not found %s in the Directory\n\n",USERS_INITIAL_BINFILE);
 	printf("PLEASE WAIT SEARCHING\n");
		if(inoutpUsers == NULL){/*if User.csv is not there*/
		printf("LOADING .csv FILE...\n");
 		printf("There is not found %s in the Directory\n\n",USERS_INITIAL_FILE);
			if (argc == 1)/*Ex. ./run*/
			{
				printf("System is not first opened\n");
				createSystemUser(inoutpUsers,systemUser);
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
			}
			else if(argc == 3){ /*Ex. ./run İbrahimC passsword*/
				printf("Welcome to automation system %s \n",argv[1]);
				lineOfFile= loginArgumentFunction(argv,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,instructorCourse,studentCourse,course,systemUser );
				userTypeFunctionControl(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
			}
			else{
				printf("Incorrect Data!!!\n");
				printf("There is not found argument\n");
				createSystemUser(inoutpUsers,systemUser);
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
			}
		}
		else{/*if user.csv is there*/
			if(argc == 1){/*Ex. ./run*/
				loginFunction(inoutpUsers,inoutpStudents,inoutpInstructors,user,student,instructor,systemUser);
			}
			else if( argc == 3){/*Ex. ./run  BuseG busemre*/
				lineOfFile= loginArgumentFunction(argv,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,instructorCourse,studentCourse,course,systemUser );
				userTypeFunctionControl(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
			}
			else{
				printf("Incorrect Data!!!\n");
				printf("There is not found argument\n");
				system_EXIT (inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
			}
		}
	}
	else /*if Users.bin is there*/
	{
		readBinaryFiles(fileName);
	}

 	return 0;
}
int loginArgumentFunction( char const *argv[],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){
		
	inoutpUsers = fopen(USERS_INITIAL_FILE,"w");
	
	printf("Please enter the ID:\n"); 
	scanf("%s",systemUser[0].ID);	
	fprintf(inoutpUsers,"%s,%s,%s,%s\n",systemUser[0].ID,SYSTEM_TYPE,argv[1],argv[2]);
	fclose(inoutpUsers);
	return 0;
		
}
int loginFunction(FILE *inoutpUsers, FILE *inoutpStudents, FILE *inoutpInstructors,users_t *user,students_t *student , instructors_t *instructor ,systemUser_t *systemUser){
	
	char tempUserName[MAX_SIZE];
	char tempUserPassword[MAX_SIZE];
	int i = 0;
	char temp;
	int status=0;
	int check=FALSE;

	while(check==FALSE){
		i=0;
		printf("Please enter the userName of User:\n");
		scanf("%s",tempUserName);
		printf("Please enter the password of User:\n");
		scanf("%s",tempUserPassword);

		inoutpUsers=fopen(USERS_INITIAL_FILE,"r");

		status = fscanf(inoutpUsers,"%s,%s,%s,%s",user[i].ID,user[i].userType,user[i].userName,user[i].password);
		
			while( status != EOF ){

				strtok( user[i].ID,&user[i].ID[11]);
				strcpy( user[i].userType , strtok(NULL,",") );
				strcpy( user[i].userName, strtok(NULL,",") );
				strcpy( user[i].password, strtok(NULL,",") );

				if (  i>0   && strcmp(tempUserName,user[i].userName) == 0 && strcmp(tempUserPassword,user[i].password) ==  0  ){
				
					printf("Modunuza yönlendriliyorsunuz..\n ");
					return i;
				}
				else if (   i == 0 && strcmp(tempUserName,user[i].userName) == 0 && strcmp(tempUserPassword,user[i].password) == 0  )
				{
					printf("System kullanıcısı hosgeldın\n");
					return i;
				}	
				else{
					check=FALSE;
					i++;
				}
					
				status = fscanf(inoutpUsers,"%s,%s,%s,%s",user[i].ID,user[i].userType,user[i].userName,user[i].password);			
			}

	}

	fclose(inoutpUsers);	

}
void createSystemUser(FILE *inoutpUsers,systemUser_t *systemUser){
	
	int check = FALSE;
	
	printf("Since the system is first opened you as a user of the system will create\n");
	
	while(check == FALSE){
	    printf("Please enter the TC of system user:\n");
	    scanf("%s",systemUser[0].ID);
		    if (TCquestioning( systemUser[0].ID ) == 0){
			    printf("Please try again!!!\n");
			    printf("Please enter the 11 digit number and you do not use character!\n");
			    check = FALSE;
		    }else if ( TCquestioning( systemUser[0].ID ) == 1   ){		
			    check = TRUE;
		    }
	}	
	
	inoutpUsers = fopen(USERS_INITIAL_FILE,"w");
	fprintf(inoutpUsers," %s,%s,",systemUser[0].ID,SYSTEM_TYPE);
	fclose(inoutpUsers);

	printf("Please enter the system user name:\n"); 
	scanf("%s",systemUser[0].userName);
	printf("Please enter the system password:\n");
	scanf("%s",systemUser[0].password);
	
	inoutpUsers = fopen(USERS_INITIAL_FILE,"a");
	fprintf(inoutpUsers,"%s,%s\n",systemUser[0].userName,systemUser[0].password);
	fclose(inoutpUsers);
}

int EXIT(){
	printf("###############################################################\n");
	printf("#                                                             #\n");
	printf("#   -------Thank you for using AUTOMATION PROGRAM-------      #\n");
	printf("#                                                             #\n");
	printf("#                   << END OF PROGRAM >>                      #\n");
	printf("#                                                             #\n");
	printf("#                   İbrahim Ç. &  Buse G.                     #\n");
	printf("#                     CopyRight @ 2014                        #\n");
	printf("#                                                             #\n");
	printf("###############################################################\n");

    return 0;
}

int system_EXIT(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){
	
	int choice;
	int lineOfFile;

	do{
		printf("Sistemi komple kapatmak için -1, çıkış yapmak için 1'e basınız:\n");
		scanf("%d",&choice);

		if ( choice == -1 )
		{
			return 0;

		}
		else if( choice == 1 )
		{
			printf("İşleminiz gerçekleşmiştir. \n");
			printf("-------------LOG IN------------\n");
			lineOfFile= loginFunction(inoutpUsers,inoutpStudents,inoutpInstructors,user,student,instructor,systemUser);	
			userTypeFunctionControl(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
		}
		else
			printf("Invalid number.Please try again !!! \n");
		
	}while( !(choice == -1 || choice == 1) );

	
}

void systemFunction(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){
	
	int choice;
	int size_of_course;
	int size_of_instructorCourse;
	int size_of_studentCourse;
	int size_of_users;
	int size_of_students;
	choice = systemMenuFunction();

	switch(choice){
		case 1:
				addUser(inoutpUsers,inoutpInstructors,inoutpStudents ,inoutpInstructorCourses,inoutpStudentCourses,inoutpCourses,user,student,instructor,course,systemUser,instructorCourse,studentCourse);
		break;
		case 2: 
				removeUser(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);	
			
		break;
		case 3:

				modifyUser(inoutpUsers,inoutpStudents,inoutpInstructors,inoutpCourses,inoutpStudentCourses,inoutpInstructorCourses,user,student,instructor,instructorCourse,studentCourse,course,systemUser);

		break;
		case 4:	
				createCourse(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
		break;
		case 5:
				removeSystemCourse(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
		
		break;
		case 6:	
				modifyCourse(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
						
		break;
		case 7:
				system_EXIT(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
		break;
	}
	
}

int readBinaryFiles(char fileName[]){
	return TRUE;
}

int  systemMenuFunction(){
	int choice;

	printf("SYSTEM MENU FUNCTION\n");
	printf("1-) Add user \n");
	printf("2-) Remove a user\n");
	printf("      > Removing a Student    \n");
	printf("      > Removing an Instructor    \n");
	printf("3-) Modify a user \n");
	printf("4-) Create a course\n");
	printf("5-) Remove a course \n");
	printf("6-) Modify a course\n");
	printf("7-) system EXIT \n");
	
	printf("Please enter the choice\n");
	scanf("%d",&choice);
	
	while (choice < 1 || choice > 7){        /* Validate choice input. */          
        printf("You entered an invalid number. Choose 1,2,3, or 7 only.\n");
        printf("Enter a choice 1-7: ");
        scanf("%d",&choice);			
	}	
	return choice;
}

int  instructorMenuFunction(){
	int choice;

	printf("INSTRUCTOR MENU FUNCTION\n");
	printf("1-) Open a course \n");
	printf("2-) Finalize a course\n");
	printf("3-) Assign grades \n");
	printf("4-) Edit grades\n");
	printf("5-) List open courses \n");
	printf("6-) List grades\n");
	printf("7-) EXIT\n");
	
	printf("Please enter the choice \n");
	scanf("%d",&choice);
	
	while (choice < 1 || choice > 7){      /* Validate choice input. */   
        printf("You entered an invalid number. Choose 1,2,3, or 7 only.\n");
        printf("Enter a choice 1-7: ");
        scanf("%d",&choice);			
	}	
	return choice;
}

int studentMenuFunction(){
	int choice;
	
	printf("STUDENT MENU FUNCTION\n");
	printf("1-) Add a course\n");
	printf("2-) Remove a course\n");
	printf("3-) List courses \n");
	printf("4-) Create transcript\n");
	printf("5-) EXIT\n");
	
	printf("Please enter the choice \n");
	scanf("%d",&choice);
	
	while (choice < 1 || choice > 5){       /* Validate choice input. */   
        printf("You entered an invalid number. Choose 1,2,3, or 5 only.\n");
        printf("Enter a choice 1-5: ");
        scanf("%d",&choice);			
	}	
	return choice;
}

void addUser(FILE *inoutpUsers,FILE *inoutpInstructors, FILE *inoutpStudents ,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,FILE *inoutpCourses, users_t *user, students_t *student, instructors_t *instructor,courses_t *course ,systemUser_t *systemUser,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse){

	int check = TRUE;
	char checkK;
	int size;
	char charCheck;
	int  i = -1;
	int j = 0;
	int k;
	int a;
	char temp;
	char str[4];
	char ch;
	char strr[9];
	

	strtok( systemUser[0].ID,&systemUser[0].ID[11]);

	while(check !=  FALSE){
		i++;
		while(check == TRUE){
			printf("Please enter the new user TC:\n");
			scanf("%s",user[i].ID);

			if (TCquestioning( user[i].ID ) == 0){
				printf("Please try again!!!\n");
				printf("Please enter the 11 digit numbeer and you do not use character!\n");
				check = TRUE;
			}	
			else if ( strcmp( user[i].ID,systemUser[0].ID ) == 0){
				check = TRUE;
				printf("Try again!!!\n ID of user is equal to ID of system "); /*burda kontorlllllll*/
			}
			else if( i>0 ){

				for (j = 0; j < i; j++)
				{
					if( strcmp( user[i].ID,user[j].ID ) == 0 ){
						printf("Başk bir userın tc sini gırdın defol \n");
						check=TRUE;
						break;
					}
					check=FALSE;
				}
				j=0;
			}
			else {

				check = FALSE;
			}

		}
		check = TRUE;
		
		while(check == TRUE){ /*Add user compare system user*/
			printf("Please enter the new userName:\n");
			scanf("%s",user[i].userName);
			
			if ( strcmp( user[i].userName,(*systemUser).userName) == 0 ){
				check = TRUE; 
				printf("Try again!!!\n Username of user is equal to username of system ");  /*burda kontorlllllll*/
			}
			else{
				check = FALSE;
			}
		}
		check = TRUE;
		
		printf("Please enter the new password:\n");
		scanf("%s",user[i].password);

		inoutpUsers = fopen(USERS_INITIAL_FILE,"a");
		strtok( user[i].ID,&user[i].ID[11]);
		fprintf(inoutpUsers, "%s,",user[i].ID);
		fclose(inoutpUsers);
		
		/*USER TYPE*/
		printf("Please enter the usertype of User\n");
		printf("    >>>(I  -> Instructor)\n");
		printf("    >>>>(S  -> Student)\n");			

		/*CHARI STRİNGE ÇEVİRDİM*/

		ch=getCharFromUser();
		sprintf(user[i].userType,"%c",ch);
		inoutpUsers = fopen(USERS_INITIAL_FILE,"a");
		fprintf(inoutpUsers, "%s,%s,%s\n",user[i].userType,user[i].userName,user[i].password );
		fclose(inoutpUsers);

		if (  toupper(ch)== 'S')
		{
			printf("Please enter the name of Student\n");
			scanf("%s",student[i].Name);
			printf("Please enter the surname of Student\n");
			scanf("%s",student[i].surName);
			
			
			while(check == TRUE){
		        printf("Please enter the Student No:\n");
			    scanf("%s",student[i].studentNo);
		        if (studentNoQuestioning( student[i].studentNo ) == 0){
			        printf("Please try again!!!\n");
			        printf("Please enter the 9 digit numbeer and you do not use character!\n");
			        check = TRUE;
		        }
		   		else
		   			check=FALSE;
	        }

	        inoutpStudents = fopen(STUDENTS_INITIAL_FILE,"a");
			user[i].ID[11]='\0';		
			fprintf(inoutpStudents, "%s,%s,%s,%s,",user[i].ID,student[i].Name,student[i].surName,student[i].studentNo );
			fclose(inoutpStudents);
        	check=TRUE;
        	
		    while(check == TRUE){
		        printf("Please enter the Start Year:\n");
			    scanf("%s",student[i].startYear);
		        if (startYearQuestioning(student[i].startYear) == 0){
			        printf("Please try again!!!\n");
			        printf("Please enter the 4 digit numbeer and you do not use character!\n");
			        check = TRUE;
		        }
		   		else
		   			check=FALSE;
	        }								

	        inoutpStudents = fopen(STUDENTS_INITIAL_FILE,"a");
			fprintf(inoutpStudents, "%s,",student[i].startYear );
			fclose(inoutpStudents);
	       
			printf("Please enter the term of student\n");
		    scanf("%d",&student[i].Term);		
		    
			while(student[i].Term < 1 || student[i].Term > 8){
			    printf("Please try again!!!\n");
			    printf("You entered an invalid number. Choose 1,2,3, or 8 only.\n");
			    scanf("%d",&student[i].Term);			    
			}

			check=FALSE;

			inoutpStudents = fopen(STUDENTS_INITIAL_FILE,"a");
			fprintf(inoutpStudents, "%d\n",student[i].Term );
			fclose(inoutpStudents);
            
		}
		else if (  toupper(ch) == 'I'  )
		{
			printf("Please enter the name of Instructor\n");
			scanf("%s",instructor[i].Name);
			printf("Please enter the surname of Instructor\n");
			scanf("%s",instructor[i].surName);

			inoutpInstructors = fopen(INSTRUCTORS_INITIAL_FILE,"a");
			strtok( user[i].ID,&user[i].ID[11]);
			fprintf(inoutpInstructors," %s,%s,%s\n",user[i].ID,instructor[i].Name,instructor[i].surName );
			fclose(inoutpInstructors);

		}

		check=FALSE;

		do{
			printf("Do you want to go back  the menu of system(Y-y,N-n):\n");
			scanf(" %c",&charCheck);
			
			if ( toupper( charCheck ) == YES){
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
				check = FALSE;
			}
			else if( toupper( charCheck ) == NO) {		
				check = TRUE;
			}
			else{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck ==  YES || charCheck == NO || charCheck=='y' || charCheck=='n')  );
			
	}
		
}

void removeUser(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){
	char removeChoice;
	char charCheck;
	int check;
	int checkControl;
	char removeStudentTC[11];
	char tempStudentN[MAX_SIZE];
	char tempStudentNo[MAX_STUDENTNO_SIZE];
	char tempStudentSName[MAX_SIZE];
	char tempReInstName[MAX_SIZE];
	char removeStud[MAX_SIZE][MAX_SIZE];
	char removeInst[MAX_SIZE][MAX_SIZE];
	char removeInstructorTC[11];
	char removeUser[MAX_SIZE][MAX_SIZE];
	char tempTC[MAX_TC_SIZE];
	char tempStudentTC[MAX_TC_SIZE];
	char tempStartYear[MAX_YEAR_SIZE];
	char tempUName[MAX_SIZE];
	char tempUType[MAX_SIZE];
	char tempUPassword[MAX_SIZE];
	int i = 0;
	int m = 0;
	int k = 0;
	int j = 0;
	int a = 0;
	int l = 0;
	char temp;

	do{
	printf("Do you want to delete the category in which");
	printf("\n\n>>> Student(S or s)\n>>> Instructor(I or i)\n");
	printf("Please enter the choice of Remove :(s,S,i,I) \n");
	scanf(" %c",&removeChoice);
	}while( !(removeChoice== 'S' || removeChoice=='s' || removeChoice=='I' || removeChoice=='i'));

	switch(removeChoice){
	case 'S':
	case 's':
		check =TRUE;
		while(check == TRUE){
			printf("Silinecek öğrencinin TC Kimlik Numarasini giriniz: ");
			scanf("%s",removeStudentTC);
			printf("removeStudentTC %s\n",removeStudentTC );
			inoutpStudents=fopen(STUDENTS_INITIAL_FILE,"r");
			
			if (inoutpStudents == NULL)
			{
				printf("There is not found file or users!\n");
			}
			else
			{
				printf("\n\t\t\t\t UYE KAYDI SILME\n");
				/*Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.*/
				while(fscanf(inoutpStudents, "%s,%s,%s,%s,%s,%d", student[i].TC,student[i].Name,student[i].surName,student[i].studentNo,student[i].startYear,&student[i].Term) != EOF){
					strtok( student[i].TC,",");
					student[i].TC[MAX_TC_SIZE] = '\0';
					strcpy(tempStudentTC,student[i].TC);
					printf("tempStudentTC %s\n",tempStudentTC );
					strcpy(student[i].Name ,strtok(NULL,",") );
					strcpy(tempStudentN,student[i].Name );
					printf("studentName %s\n",student[i].Name );

					strcpy(student[i].surName ,strtok(NULL,",") );
					strcpy(tempStudentSName,student[i].surName );
					printf("studentSurName %s\n",student[i].surName );

					strcpy(student[i].studentNo ,strtok(NULL,",") );
					strcpy(tempStudentNo,student[i].studentNo );

					printf("studentNo %s\n",student[i].studentNo );

					strcpy(student[i].startYear ,strtok(NULL,",") );
					strcpy(tempStartYear,student[i].startYear);
					printf("studentYear %s\n",student[i].startYear );
		

					strcpy(student[i].startYear ,strtok(NULL,",") );
					student[i].Term = atoi(student[i].startYear );
					printf("student term%d\n",student[i].Term );

					strcpy( tempTC,student[i].TC);
					strtok( student[i].TC,",");
					printf("student TC %s eşit %s removeStudentTC\n",student[i].TC,removeStudentTC );
					student[i].TC[11]='\0';
					if(strcmp( student[i].TC,removeStudentTC )==0)
					{	
						
						i++;
						printf("Kullanıcı silinmiştir-\n");
						checkControl==TRUE;
					}	
					else{
						tempStudentTC[MAX_TC_SIZE] = '\0';
						tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
						tempStartYear[MAX_YEAR_SIZE] = '\0';
						sprintf(removeStud[m],"%s,%s,%s,%s,%s,%d",student[i].TC,tempStudentN,tempStudentSName,tempStudentNo,tempStartYear,student[i].Term);
						printf("removeStud[%d]-------------%s\n",m,removeStud[m]);
						
						i++;
						m++;
						/*if(checkControl==FALSE)
						{
						printf("Böyle bir user yoktur !! \n");
						}*/
					}
				}
			}
			fclose(inoutpStudents);
			inoutpStudents=fopen(STUDENTS_INITIAL_FILE,"w");
			printf("for dakiler \n");
			for (k = 0; k < m; ++k)
			{

				printf("removeStud[%d]-------------%s\n",k,removeStud[k]);
				fprintf(inoutpStudents,"%s\n",removeStud[k] );
			}
			fclose(inoutpStudents);


			inoutpUsers=fopen(USERS_INITIAL_FILE,"r");
			if (inoutpUsers == NULL)
			{
				printf("There is not found file or users!\n");
			}
			else{
				while(fscanf(inoutpUsers, "%s,%s,%s,%s", user[j].ID,user[j].userType,user[j].userName,user[j].password) != EOF){
					strtok( user[j].ID,",");
					strcpy(user[j].userType ,strtok(NULL,",") );
					strcpy(tempUType,user[j].userType);
					strcpy(user[j].userName ,strtok(NULL,",") );
					strcpy(tempUName,user[j].userName);
					strcpy(user[j].password ,strtok(NULL,",") );
					strcpy(tempUPassword,user[j].password);
					user[j].ID[11]='\0';
					printf("user TC %s eşit %s removeStudentTC\n",user[j].ID,removeStudentTC);
					if( strcmp( user[j].ID,removeStudentTC ) == 0 ){
						printf("Users dosyasından kullanıcı silinmiştir\n");
						j++;
					}
					else{
						sprintf(removeUser[a],"%s,%s,%s,%s", user[j].ID,tempUType,user[j].userName,user[j].password);
						j++;
						a++;
					}
				}
			}
			fclose(inoutpUsers);
			inoutpUsers=fopen(USERS_INITIAL_FILE,"w");
			for (l = 0; l < a; ++l)
			{
				printf("removeUser[%d]-------------%s\n",l,removeUser[l]);
				fprintf(inoutpUsers,"%s\n",removeUser[l] );
			}
			fclose(inoutpUsers);

			do{
				printf("Do you want to go back  the menu of system(Y-y/N-n):\n");
				scanf(" %c",&charCheck);
						
				if ( toupper( charCheck ) == YES){
					systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
						instructor,instructorCourse,studentCourse,course,systemUser);
					check = FALSE;
				}
				else if ( toupper( charCheck ) == NO){
					i = 0;
					m = 0;
					k = 0;
					j = 0;
					a = 0;
					l = 0;
					check = TRUE;
				}
				else{
					printf("Invalid character !! Try again:\n");
				}
			}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
		}

	break;
	case 'I':
	case 'i':
	check =TRUE;
	i = 0;
	m = 0;
	k = 0;
	j = 0;
	a = 0;
	l = 0;
		while(check == TRUE){
			printf("Silinecek öğretmenin TC Kimlik Numarasini giriniz: ");
			scanf("%s",removeInstructorTC);
			
			inoutpInstructors=fopen(INSTRUCTORS_INITIAL_FILE,"r+");
			
			if (inoutpInstructors == NULL)
			{
				printf("There is not found file or users!\n");
			}
			else
			{
				printf("\n\t\t\t\t UYE KAYDI SILME\n");
				/*Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.*/
				while(fscanf(inoutpInstructors, "%s,%s,%s", instructor[i].TC,instructor[i].Name,instructor[i].surName) != EOF ){

				strtok( instructor[i].TC,",");
				strcpy(instructor[i].Name,strtok(NULL,",") );
				strcpy(tempReInstName,instructor[i].Name);
				strcpy(instructor[i].surName,strtok(NULL,","));
				instructor[i].TC[11]='\0';
				printf("inst TC %s eşit %s removeInstructorTC\n",instructor[i].TC,removeInstructorTC );
					if(strcmp( instructor[i].TC,removeInstructorTC )==0)
					{	
						i++;
						printf("Kullanıcı silinmiştir-\n");
						checkControl==TRUE;
					}	
					else{
					
						sprintf(removeInst[m],"%s,%s,%s", instructor[i].TC,tempReInstName,instructor[i].surName);
						printf("removeInst[%d]-------------%s\n",m,removeInst[m]);
						
						i++;
						m++;
					}
				}
			}
			fclose(inoutpInstructors);
			inoutpInstructors=fopen(INSTRUCTORS_INITIAL_FILE,"w");
			printf("for dakiler \n");
			for (k = 0; k < m; ++k)
			{

				printf("removeInst[%d]-------------%s\n",k,removeInst[k]);
				fprintf(inoutpInstructors,"%s\n",removeInst[k] );
			}
			fclose(inoutpInstructors);

			inoutpUsers=fopen(USERS_INITIAL_FILE,"r");
			if (inoutpUsers == NULL)
			{
				printf("There is not found file or users!\n");
			}
			else{
				while(fscanf(inoutpUsers, "%s,%s,%s,%s", user[j].ID,user[j].userType,user[j].userName,user[j].password) != EOF){
					strtok( user[j].ID,",");
					strcpy(user[j].userType ,strtok(NULL,",") );
					strcpy(tempUType,user[j].userType);
					strcpy(user[j].userName ,strtok(NULL,",") );
					strcpy(tempUName,user[j].userName);
					strcpy(user[j].password ,strtok(NULL,",") );
					strcpy(tempUPassword,user[j].password);
					user[j].ID[11]='\0';
					printf("user TC %s eşit %s removeStudentTC\n",user[j].ID,removeStudentTC);
					if( strcmp( user[j].ID,removeInstructorTC ) == 0 ){
						printf("Users dosyasından kullanıcı silinmiştir\n");
						j++;
					}
					else{
						sprintf(removeUser[a],"%s,%s,%s,%s", user[j].ID,tempUType,user[j].userName,user[j].password);
						j++;
						a++;
					}
				}
			}
			fclose(inoutpUsers);
			inoutpUsers=fopen(USERS_INITIAL_FILE,"w");
			for (l = 0; l < a; ++l)
			{
				printf("removeUser[%d]-------------%s\n",l,removeUser[l]);
				fprintf(inoutpUsers,"%s\n",removeUser[l] );
			}
			fclose(inoutpUsers);


			do{
				printf("Do you want to go back  the menu of system(Y-y/N-n):\n");
				scanf(" %c",&charCheck);
						
				if ( toupper( charCheck ) == YES){
					systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
						instructor,instructorCourse,studentCourse,course,systemUser);
					check = FALSE;
				}
				else if ( toupper( charCheck ) == NO){
					int i = 0;
					int m = 0;
					int k = 0;
					int j = 0;
					int a = 0;
					int l = 0;
					check = TRUE;
				}
				else{
					printf("Invalid character !! Try again:\n");
				}
			}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
		}
	break;
	}

}

void modifyUser(FILE *inoutpUsers, FILE *inoutpStudents, FILE *inoutpInstructors,FILE *inoutpCourses, FILE *inoutpStudentCourses, FILE *inoutpInstructorCourses, users_t *user, students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){
	
	int x;
	char charCheck;
	char tempInstructorTC[11];
	char tempStudentTC[11];
	char tempTC[11];
	char tempName[MAX_SIZE];
	char tempIName[MAX_SIZE];
	char tempSName[MAX_SIZE];
	char tempSurname[MAX_SIZE];
	char tempStudentYear[MAX_SIZE];
	char tempStudentNo[MAX_SIZE];
	char tempNo[MAX_SIZE];
	char studentStr[MAX_SIZE][MAX_SIZE];	
	char instructorStr[MAX_SIZE][MAX_SIZE];
	char tempStartYear[MAX_SIZE];

	int choice;
	int tempTerm;
	int i=0;
	int k=0;
	int m=0;
	int check=TRUE;
	int checking=TRUE;

	FILE* inoutpTEMP_Users;

	while(check==TRUE){
		printf("Hangi bölümde modify of User?");
		do{
			printf("\n1) Student\n2) Instructor\n");
			printf("Seciminiz : ");
			scanf("%d",&choice);
		}while( !(choice==1 || choice==2) );
		
		if (choice == 1)
		{		
			inoutpStudents = fopen(STUDENTS_INITIAL_FILE, "r");
			for(;;)
			{
				printf("\nGuncellenicek öğrencinin TC Kimlik numarasini giriniz:");
				scanf("%s",tempStudentTC);
				x=TCquestioning(tempStudentTC);

				if (x==0)
				{
					printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				}
				if (x==1)
				{	
					break;
				}
			}
			

			if (inoutpStudents == NULL)
			{
				printf("Dosya veya sunucu bulunamadi!\n");
			}
			else
			{
				printf("********************************************************************************************************");
				printf("\n\t\t\t\t  Modify USErs STUDENTS\n");
				printf("********************************************************************************************************\n\n");
				while(fscanf(inoutpStudents, "%s,%s,%s,%s,%s,%d", student[i].TC,student[i].Name,student[i].surName,student[i].studentNo,student[i].startYear,&student[i].Term) != EOF){
					printf("%s\n",student[i].TC );
					strtok(student[i].TC,",") ;
					strcpy(tempTC,student[i].TC);
					strcpy(student[i].Name ,strtok(NULL,",") );
					strcpy(student[i].surName ,strtok(NULL,",") );
					strcpy(student[i].studentNo,strtok(NULL,",") );
					strcpy(tempNo,student[i].studentNo);
					strcpy(student[i].startYear,strtok(NULL,",") );
					strcpy(tempStartYear,student[i].startYear);
					strcpy(student[i].startYear,strtok(NULL,",") );
					student[i].Term = atoi(student[i].startYear);

					printf("%s,%s,%s,%s,%s,%d\n", tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);
					if ( strcmp(tempTC, tempStudentTC)==0 )
					{	
						printf("adını değiştirmek istiyormusunuz:[ Yes-> Y-y  ~ No-> random character ]\n");
						scanf(" %c",&charCheck);
						if ( toupper(charCheck) == YES )
						{	
							
							printf("Please enter the neww name of student\n");
							scanf("%s",tempName);
							strcpy(student[i].Name,tempName);
							printf("%s\n",student[i].Name );
							sprintf(studentStr[m],"%s,%s,%s,%s,%s,%d",tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);
							printf("%d--------------%s\n",m,studentStr[m]);
						}
						/*else{
						fprintf(inoutpTEMP_Users, "%s,",student[i].Name );
						}*/
						printf("soyadnı değiştirmek istiyormusunuz:\n");
						scanf(" %c",&charCheck);
						if (toupper(charCheck) == YES)
						{	
							printf("Please enter the new surname of student\n");
							scanf("%s",tempSurname);
							strcpy(student[i].surName,tempSurname);
							sprintf(studentStr[m],"%s,%s,%s,%s,%s,%d",tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);
							printf("%d--------------%s\n",m,studentStr[m] );
							
						}
						printf("student No değiştirmek istiyormusunuz:\n");
						scanf(" %c",&charCheck);
						if (toupper(charCheck) == YES)
						{	
							/*strcpy(student[i].studentNo,strtok(NULL,","));*/
							while(checking == TRUE){
								printf("Please enter the neww student No  of student\n");
								scanf("%s",tempStudentNo);
								strcpy(tempNo,tempStudentNo);
								if (studentNoQuestioning( tempNo ) == 0){
							        printf("Please try again!!!\n");
							        printf("Please enter the 9 digit numbeer and you do not use character!\n");
							        checking = TRUE;
					        	}
					   			else
					   				checking=FALSE;
				       		 }	
				
						sprintf(studentStr[m],"%s,%s,%s,%s,%s,%d",tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);
						printf("%d--------------%s\n",m,studentStr[m] );
							
						}					
						printf("startYear değiştirmek istiyormusunuz:\n");
						scanf(" %c",&charCheck);
						if (toupper(charCheck) == YES)
						{	
						printf("%s\n", student[i].startYear);
							while(checking == FALSE){
								printf("Please enter the neww student year  of student\n");
								scanf("%s",tempStudentYear);
								strcpy(tempStartYear,tempStudentYear);
								if (startYearQuestioning(tempStartYear) == 0){
						        printf("Please try again!!!\n");
						        printf("Please enter the 4 digit numbeer and you do not use character!\n");
						        checking = FALSE;
						        }
						   		else
					   			checking =TRUE;
		   					}
						sprintf(studentStr[m],"%s,%s,%s,%s,%s,%d",tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);
						printf("%d--------------%s\n",m,studentStr[m] );
						}
						printf("term değiştirmek istiyormusunuz:\n");
						scanf(" %c",&charCheck);
						if (toupper(charCheck) == YES)
						{
							printf("Please enter the neww term  of student\n");
							scanf("%d",&tempTerm);
							student[i].Term = tempTerm;	
								while(student[i].Term < 1 || student[i].Term > 8){
								    printf("Please try again!!!\n");
								    printf("You entered an invalid number. Choose 1,2,3, or 8 only.\n");
								    scanf("%d",&tempTerm);
								    student[i].Term = tempTerm;				    
								}
							sprintf(studentStr[m],"%s,%s,%s,%s,%s,%d",tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);											
							printf("%d--------------%s\n",m,studentStr[m] );
						}
						
						printf("kişi güncellendi*\n");
						i++;		
						m++;
					}
					else
					{
						sprintf(studentStr[m],"%s,%s,%s,%s,%s,%d",tempTC,student[i].Name,student[i].surName,tempNo,tempStartYear,student[i].Term);											
						i++;		
						m++;

					}
											
				}
			}
			fclose(inoutpStudents);

			inoutpStudents = fopen(STUDENTS_INITIAL_FILE,"w");
			for (k = 0; k < m; ++k)
			{
				printf("%d--------------%s\n",k,studentStr[k] );
				fprintf(inoutpStudents,"%s\n",studentStr[k]);
			}
			fclose(inoutpStudents);	
		}
		else if( choice == 2){
			inoutpInstructors = fopen(INSTRUCTORS_INITIAL_FILE, "r");
			for(;;)
			{
				printf("\nGuncellenicek öğretmenin TC Kimlik numarasini giriniz:");
				scanf("%s",tempInstructorTC);
				x=TCquestioning(tempInstructorTC);
				if (x==0)
				{
					printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				}
				if (x==1)
				{
					break;
				}
			}
			
			if (inoutpInstructors == NULL)
			{
				printf("Dosya veya sunucu bulunamadi!\n");
			}
			else
			{
				printf("********************************************************************************************************");
				printf("\n\t\t\t\t  Modify USErs INSTRUCTORSS\n");
				printf("********************************************************************************************************\n\n");
				while(fscanf(inoutpInstructors, "%s,%s,%s", instructor[i].TC,instructor[i].Name,instructor[i].surName) != EOF){
					strtok(instructor[i].TC,",");
					strcpy(tempTC,instructor[i].TC);
					strcpy(instructor[i].Name,strtok(NULL,","));
					strcpy(tempIName,instructor[i].Name);
					strcpy(instructor[i].surName,strtok(NULL,"\n"));
					strcpy(tempSName,instructor[k].surName);

					/*instructor[i].TC[MAX_TC_SIZE]='\0';
					tempTC[MAX_TC_SIZE]='\0';*/

					printf("%s,\n%s,\n%s\n", tempTC,tempIName,tempSName);
					if (strcmp(tempTC, tempInstructorTC)==0)
					{	
						printf("adını değiştirmek istiyormusunuz:[ Yes-> Y-y  ~ No-> N-n ]\n");
						scanf(" %c",&charCheck);
						if (toupper(charCheck) == YES)
						{
							printf("Please enter the neww name of student\n");
							scanf(" %s",tempName);
							strcpy(tempIName,tempName);
							sprintf(instructorStr[m],"%s,%s,%s",tempTC,tempIName,instructor[i].surName);
							printf("%d--------------%s\n",m,instructorStr[m]);

						}
						printf("soyadnı değiştirmek istiyormusunuz:\n");
						scanf(" %c",&charCheck);
						if (toupper(charCheck) == YES)
						{
							printf("Please enter the neww surname of student\n");
							scanf("%s",tempSurname);
							strcpy(instructor[i].surName,tempSurname);
							sprintf(instructorStr[m],"%s,%s,%s",tempTC,tempIName,instructor[i].surName);
							printf("%d--------------%s\n",m,instructorStr[m]);
						}
						printf("kişi güncellendi*\n");
						i++;		
						m++;
					}
					else
					{
						sprintf(instructorStr[m],"%s,%s,%s",tempTC,tempIName,instructor[i].surName);
						i++;		
						m++;
					}
					
				}
				
			}

			fclose(inoutpInstructors);
		
			inoutpInstructors = fopen(INSTRUCTORS_INITIAL_FILE,"w");
			for (k = 0; k < m; ++k)
			{
				printf("%d--------------%s\n",k,instructorStr[k] );
				fprintf(inoutpInstructors,"%s\n",instructorStr[k]);
			}
			fclose(inoutpInstructors);		

		}	

	
		
		do{
			printf("Do you want to go back  the menu of system(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES){
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
				check = FALSE;
			}
			else if ( toupper( charCheck ) == NO){
				i=0;
				m=0;
				check = TRUE;
			}
			else{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );		
	}
}
void createCourse(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){
	
	char checkingCourse;
	char checkingAgain;
	char charCheck;
	int preCourseNumber;
	int check = TRUE;
	char tempPrerequisite[MAX_SIZE];
	int i = 0 ;

	while(check == TRUE){
		inoutpCourses = fopen(COURSES_INITIAL_FILE,"a+");
		
		do{
		printf("Please enter the code of new course:[6 basamaklı giriniz]\n");
		scanf("%s",course[i].courseCode);
		}while(strlen(course[i].courseCode)!= MAX_COURSE_SIZE );
		printf("%s\n", course[i].courseCode);
		course[i].courseCode[MAX_COURSE_SIZE+1]='\0';
		printf("corse code %s\n",course[i].courseCode );
		fprintf(inoutpCourses, "%s,",course[i].courseCode);

		printf("Please enter the name of course:\n");
		scanf("%s",course[i].courseName);
		course[i].courseName[strlen(course[i].courseName)]='\0';
		fprintf(inoutpCourses, "%s,",course[i].courseName);
			
		printf("Please enter the who give your courses\n");
		printf("Plese enter the name of Instructor\n");
		scanf("%s",course[i].instructorName);
		fprintf(inoutpCourses, "%s,",course[i].instructorName);

		printf("Please enter the surname of Instructor\n");
		scanf("%s",course[i].instructorSurName);
		fprintf(inoutpCourses, "%s,",course[i].instructorSurName);

		printf("Please enter the term of course in which period the course will be given\n");
		scanf("%d",&course[i].term);

		while(course[i].term < 1 || course[i].term > 8){
		    printf("Please try again!!!\n");
		    printf("You entered an invalid number. Choose 1,2,3, or 8 only.\n");
		    scanf("%d",&course[i].term);			    
		}
		fprintf(inoutpCourses, "%d,",course[i].term);

		printf("Please enter the passingGrade of course by system user:\n");
		scanf("%d",&course[i].passingGrade);
		
		while( 0 >course[i].passingGrade  || course[i].passingGrade >100 ){
		    printf("Please try again!!!\n");
		    printf("You entered an invalid number. Choose 0,1,,,100 only.\n");
		    scanf("%d",&course[i].passingGrade);			    
		}
		fprintf(inoutpCourses, "%d,",course[i].passingGrade);

		printf("Please enter add/remove of courses by system user(Add : 1  Remove : 0)\n");
		scanf("%d",&course[i].checkAddRemove);

		while( course[i].checkAddRemove!=0 && course[i].checkAddRemove !=1 ){
		    printf("Please try again!!!\n");
		    printf("You entered an invalid number. Choose 0 or 1 only.\n");
		    scanf("%d",&course[i].checkAddRemove);			    
		}
		fprintf(inoutpCourses, "%d,",course[i].checkAddRemove);

		printf("Please enter Open/Close of courses by system User(Open :1  Close : 0)\n");
		scanf("%d",&course[i].checkOpenClose);

		while( course[i].checkOpenClose!=0 && course[i].checkOpenClose !=1 ){
		    printf("Please try again!!!\n");
		    printf("You entered an invalid number. Choose 0 or 1 only.\n");
		    scanf("%d",&course[i].checkOpenClose);			    
		}
		fprintf(inoutpCourses, "%d,",course[i].checkOpenClose);
		if(course[i].term == 1)
		{
			printf("1.dönem derslerinin ön koşulu yoktur!\n");
			strcpy(course[i].prerequisiteCourse,"-");
			fprintf(inoutpCourses,"%s\n",course[i].prerequisiteCourse);
		}
		else
		{
			do{
			printf("Is there a the prerequisite of courses?(Y-y,N-n): \n");
			scanf(" %c",&checkingCourse);	
			}while( !(checkingCourse == YES || checkingCourse== NO || checkingCourse=='y' || checkingCourse=='n'));

			switch(checkingCourse){
			case 'Y':
			case 'y':
					course[i].courseCode[MAX_COURSE_SIZE]='\0';
					printf("%s",course[i].courseCode );
					printf("Please enter the prerequisite of Course:\n");
					do{
						check=FALSE;
						printf("The prerequisite of Course:[6 basamklı olmalı BIL102 BUYUK HARFLER KULLAN]\n");
						scanf(" %s",tempPrerequisite);
							if( strcmp(course[i].courseCode,tempPrerequisite)== 0 )
							{
								printf("Bir dersin ön koşulu kendisi olamaz !!\n");
								check=TRUE;
							}
					}while( strlen(tempPrerequisite)!= (MAX_COURSE_SIZE) || check==TRUE );

					strcpy(course[i].prerequisiteCourse,tempPrerequisite);
					fprintf(inoutpCourses, "%s\n",course[i].prerequisiteCourse);

			break;
			case 'N':
			case 'n':
				strcpy(course[i].prerequisiteCourse,"-");
				fprintf(inoutpCourses, "%s\n",course[i].prerequisiteCourse);
			break;
			}
		}
		
		fclose(inoutpCourses);

		do{
			printf("Do you want to go back  the menu of system(Y-y/N-y):\n");
			scanf(" %c",&charCheck);
		
			if ( toupper( charCheck ) == YES)
			{
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
				check = FALSE;
			}
			else if ( toupper( charCheck ) == NO)
			{
				i=0;
				check = TRUE;
			}
			else
				printf("Invalid character!! try again :\n");

		}while(!(charCheck == YES || charCheck== NO || charCheck=='y' || charCheck=='n'));

	}
}
void removeSystemCourse(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){

	char charCheck;
	int check;
	char removeSystemCourse[MAX_SIZE][MAX_SIZE];
	int checkControl=FALSE;
	int i = 0;
	int m = 0;
	int k = 0;
	char temp;
	char tempCourseCode[MAX_COURSE_SIZE];
	char tempCourseName[MAX_SIZE];
	char tempInstructorTC[11];
	char tempStudentTC[11];
	char tempName[MAX_SIZE];
	char tempInstructorSurname[MAX_SIZE];
	char tempPrerequisiteCourse[MAX_SIZE];
	char tempInstructorName[MAX_SIZE];
	int tempCheckOpenClose;
	int tempCheckAddRemove;
	int tempPassingGrade;

	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r+");

	check =TRUE;
	while(check == TRUE){
		if (inoutpCourses == NULL)
		{
			printf("There is not found file or users!\n");
		}
		else
		{
			printf("\n\t\t\t\t DERS SILME\n");	
			while(fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
				printf("course code  %s\n",course[i].courseCode);
				strtok(course[i].courseCode,",") ;
				/*course[i].courseCode[MAX_COURSE_SIZE] = '\0';*/
				strcpy(tempCourseCode,course[i].courseCode );
				printf("sonra course code : %s\n",course[i].courseCode);

				strcpy(course[i].courseName ,strtok(NULL,",") );
				printf("course name%s\n",course[i].courseName);			
				strcpy(tempCourseName,course[i].courseName );

				 
				strcpy(course[i].instructorName ,strtok(NULL,",") );
				printf("course instructorName: %s\n",course[i].instructorName);
				strcpy(tempInstructorName,course[i].instructorName );


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("COURSE İNSTRUCTOR  surname%s\n",course[i].instructorSurName  );
				strcpy(tempInstructorSurname,course[i].instructorSurName );
				
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].term  = atoi(course[i].instructorSurName );
				printf("course term %d\n",course[i].term );

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].passingGrade =  atoi(course[i].instructorSurName );
				printf("course passingGrade %d\n",course[i].passingGrade );


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkAddRemove =  atoi(course[i].instructorSurName );
				printf("course Add-Remove %d\n",course[i].checkAddRemove );



				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkOpenClose =  atoi(course[i].instructorSurName );
				printf("course open close %d\n",course[i].checkOpenClose);


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("prerequisiteCourse%s\n",course[i].instructorSurName );
				strcpy(course[i].prerequisiteCourse ,course[i].instructorSurName );
				printf("%s,%s,%s,%s,%d,%d,%d,%d,%s", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
				do{
					printf("Bu dersi silmek istiyor musunuz\n");
					scanf(" %c",&charCheck);
					printf("charCheck%c\n",charCheck );
					if ( toupper(charCheck) == YES)
					{
						printf("Ders sılındı\n ");
						i++;
					}
					else if( toupper(charCheck) == NO) 
					{
						sprintf(removeSystemCourse[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s",tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
						printf("removeSystemCourse[%d]-----------%s\n",m,removeSystemCourse[m] );
						i++;
						m++;
					}
					else
					{
						printf("Invalid character !! Try again:\n");
					}
				}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );

			}	
				
		}
	fclose(inoutpCourses);
	printf("m------>>>> %d\n",m );
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"w");
	for (k = 0; k < m; ++k)
	{
		printf("%d--------------%s\n",k,removeSystemCourse[k] );
		fprintf(inoutpCourses,"%s\n",removeSystemCourse[k]);
	}

	
		fclose(inoutpCourses);
		do{
			printf("Do you want to go back  the menu of system(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
				check = FALSE;
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				m = 0;
				k = 0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
}
	

void modifyCourse(FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){

	int x;

	char charCheck;
	char modifyStr[MAX_SIZE][MAX_SIZE];
	char tempCourseCode[MAX_COURSE_SIZE];
	char tempCourseName[MAX_SIZE];
	char tempInstructorTC[11];
	char tempStudentTC[11];
	char tempName[MAX_SIZE];
	char tempInstructorSurname[MAX_SIZE];
	char tempPrerequisiteCourse[MAX_SIZE];
	char tempInstructorName[MAX_SIZE];
	int tempCheckOpenClose;
	int tempCheckAddRemove;
	int tempPassingGrade;
	int choice;
	int check=TRUE;
	int tempTerm;
	int i=0;
	int k=0;
	int m = 0;

	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r");

	while(check==TRUE){
		if (inoutpCourses == NULL)
		{
			printf("There is not found file\n");
		}
		else
		{
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  Modify Coursess\n");
			printf("********************************************************************************************************\n\n");
				while(fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
					printf("course code  %s\n",course[i].courseCode);
					strtok(course[i].courseCode,",") ;
					/*course[i].courseCode[MAX_COURSE_SIZE] = '\0';*/
					strcpy(tempCourseCode,course[i].courseCode );
					printf("sonra course code : %s\n",course[i].courseCode);

					strcpy(course[i].courseName ,strtok(NULL,",") );
					printf("course name%s\n",course[i].courseName);			
					strcpy(tempCourseName,course[i].courseName );

					 
					strcpy(course[i].instructorName ,strtok(NULL,",") );
					printf("course instructorName: %s\n",course[i].instructorName);
					strcpy(tempInstructorName,course[i].instructorName );


					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					printf("COURSE İNSTRUCTOR  surname%s\n",course[i].instructorSurName  );
					strcpy(tempInstructorSurname,course[i].instructorSurName );
					
					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].term  = atoi(course[i].instructorSurName );
					printf("course term %d\n",course[i].term );

					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].passingGrade =  atoi(course[i].instructorSurName );
					printf("course passingGrade %d\n",course[i].passingGrade );


					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].checkAddRemove =  atoi(course[i].instructorSurName );
					printf("course Add-Remove %d\n",course[i].checkAddRemove );



					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].checkOpenClose =  atoi(course[i].instructorSurName );
					printf("course open close %d\n",course[i].checkOpenClose);


					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					printf("prerequisiteCourse%s\n",course[i].instructorSurName );
					strcpy(course[i].prerequisiteCourse ,course[i].instructorSurName );
					printf("%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
					do{
					printf("-----------------------------------------------\n");
					printf("Dersin  öğretmeninin adını değiştirmek için 1\n");
					printf("Dersin  öğretmenini soyadını değiştirmek için 2\n");
					printf("Dersin term i 3\n");
					printf("Dersin passingGrade 4\n");
					printf("Dersin add remove 5\n");
					printf("Dersin open open-close 6\n");
					printf("Dersin prerequisiteCourse 7\n");
					printf("degıstırmıjeem 8\n");

					printf("\nPlease enter the choice");
					scanf("%d",&choice);
					}while( choice<1 || choice>8 );

					switch(choice){
						case 1:
							printf("Please enter the neww name of instructor\n");
							scanf("%s",tempInstructorName);
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
						break;
						case 2:
							printf("Please enter the neww surname of instructor\n");
							scanf("%s",tempInstructorSurname);
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
						break;
						case 3:
							printf("Please enter the neww student term i  of Course\n");
							scanf("%d",&tempTerm);

							while(tempTerm < 1 || tempTerm > 8){
						    printf("Please try again!!!\n");
						    printf("You entered an invalid number. Choose 1,2,3, or 8 only.\n");
						    scanf("%d",&tempTerm);			    
							}
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
						break;
						case 4:
							printf("Please enter the neww passingGrade of Course\n");
							scanf("%d",&tempPassingGrade);

							while( 0 > tempPassingGrade || tempPassingGrade > 100 ){
							    printf("Please try again!!!\n");
							    printf("You entered an invalid number. Choose 0,1,,,100 only.\n");
							    scanf("%d",&tempPassingGrade);			    
							}
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,tempPassingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
						break;

						case 5:						
							printf("Please enter the neww Add-Remove mode of Course\n");
							scanf("%d",&tempCheckAddRemove);

							while( tempCheckAddRemove!=0 && tempCheckAddRemove !=1 ){
							    printf("Please try again!!!\n");
							    printf("You entered an invalid number. Choose 0 or 1 only.\n");
							    scanf("%d",&tempCheckAddRemove);			    
							}		
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,tempCheckAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
						break;
						case 6:
							printf("Please enter the neww open-close mode of Course\n");
							scanf("%d",&tempCheckOpenClose);

							while( tempCheckOpenClose!=0 && tempCheckOpenClose !=1 ){
							    printf("Please try again!!!\n");
							    printf("You entered an invalid number. Choose 0 or 1 only.\n");
							    scanf("%d",&tempCheckOpenClose);			    
							}									
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,tempCheckOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
						break;
						case 7:
							if(course[i].term==1){
								strcpy(tempPrerequisiteCourse,"-");
							}
							else
							{
								printf("Please enter the prerequisite of Course:\n");
								do{
									check=FALSE;
									printf("The prerequisite of Course:[6 basamklı olmalı]\n");
									scanf(" %s",tempPrerequisiteCourse);
										if( strcmp(course[i].courseCode,tempPrerequisiteCourse)== 0 )
										{
											printf("Bir dersin ön koşulu kendisi olamaz !!\n");
											check=TRUE;
										}
								}while( strlen(tempPrerequisiteCourse)!= (MAX_COURSE_SIZE) || check==TRUE );

							}
						sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,tempPrerequisiteCourse);
						m++;
						i++;
						break;
						case 8:
							sprintf(modifyStr[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n", tempCourseCode,tempCourseName,tempInstructorName,tempInstructorSurname,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							m++;
							i++;
							continue;
						break;
					}
				}
			printf("course hepsi guncellendi*\n");									
		}
		fclose(inoutpCourses);

		inoutpCourses = fopen(COURSES_INITIAL_FILE,"w");
		for (i = 0; i < m; ++i)
		{
			printf("%d--------------%s\n",i,modifyStr[i] );
			fprintf(inoutpCourses,"%s",modifyStr[i]);

		}
		fclose(inoutpCourses);
		do{
			printf("Do you want to go back  the menu of system(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{

				check = FALSE;
				systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				k=0;
				m = 0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
	
}


int TCquestioning(char TC[MAX_SIZE]){
	int checkTF = TRUE;
	int counter;
	/*The 11-digit number is entered and the the letter control section that is entered*/
	/*The isdigit() function shall return non-zero if c is a decimal digit; otherwise, it shall return 0.*/
	for (counter = 0; counter < MAX_TC_SIZE; counter++){
		if (isdigit(TC[counter])==0 || strlen(TC)!=MAX_TC_SIZE)
		{
		checkTF = FALSE;
		}
	}
	TC[MAX_TC_SIZE] = '\0';
	
return checkTF;
}

int studentNoQuestioning(char studentNo[MAX_SIZE]){
	int checkTF = TRUE;
	int counter;
	/*The 9-digit number is entered and the the letter control section that is entered*/
	for (counter = 0; counter < MAX_STUDENTNO_SIZE; counter++){
		if (isdigit(studentNo[counter])==0 || strlen(studentNo)!=MAX_STUDENTNO_SIZE )
		{
		checkTF = FALSE;
		}
	}
return checkTF;
}

int startYearQuestioning(char startYear[MAX_YEAR_SIZE]){
	int checkTF = TRUE;
	int counter;
	/*The 4-digit number is entered and the the letter control section that is entered*/
	for (counter = 0; counter < MAX_YEAR_SIZE; counter++){
		if (isdigit(startYear[counter])==0 || strlen(startYear)!=MAX_YEAR_SIZE)
		{
		checkTF = FALSE;
		}
	}
return checkTF;
}


void userTypeFunctionControl(int lineOfFile, FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,
users_t *user,students_t *student, instructors_t *instructor,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,courses_t *course,systemUser_t *systemUser){

	if ( lineOfFile == 0 )
	{
		printf("----Welcome system userrr !!! ---\n");
		systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
	}
	else if( lineOfFile != 0 ){

		if ( strcmp(user[lineOfFile].userType ,STUDENT_TYPE) == 0 || strcmp(user[lineOfFile].userType ,"s") == 0 )
		{
			studentFunction(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
		}
		else if ( strcmp(user[lineOfFile].userType ,INSTRUCTOR_TYPE) == 0 ||  strcmp(user[lineOfFile].userType ,"i") == 0  )
		{
			instructorFunction(lineOfFile, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
		}
		else
		{
			printf("sistem herhangi bir kullanıcı bulamadı .gıt sıstem user olustur\n");
		}
	}
}

void clear(void){     
    char a;        
    while ( a != '\n' ){
        scanf("%c",&a);
    }
}
char getCharFromUser(){
    char a;
    do{
        printf("That is from one of them [ I-i -> instructor, S-s -> student ]:\n");
        scanf(" %c",&a);
        clear();
    }while( !(a=='I'|| a=='S' || a=='i'|| a=='s') );
    
    return a;
}

void studentFunction(int lineOfFile, FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){

	int i = 0;	
	int k = 0;
	int choice;
	int tempStudentTerm;
	char tempStudentNo[MAX_STUDENTNO_SIZE];
	char tempStudentTC[MAX_TC_SIZE];

	inoutpUsers = fopen(USERS_INITIAL_FILE,"r");
	inoutpStudents = fopen(STUDENTS_INITIAL_FILE,"r");

	if (inoutpUsers == NULL)
	{
		printf("Dosya bulunamadı !! \n");
	}
	else
	{

		while( fscanf(inoutpUsers, "%s,%s,%s,%s", user[i].ID,user[i].userType,user[i].userName,user[i].password) != EOF ){
	
			strtok(user[i].ID,",") ;
			user[i].ID[MAX_ID_SIZE] = '\0';
			strcpy(user[i].userType ,strtok(NULL,",") );
			strcpy(user[i].userName ,strtok(NULL,",") );
			strcpy(user[i].password ,strtok(NULL,",") );				

			if (lineOfFile == i)
			{
				while( fscanf(inoutpStudents, "%s,%s,%s,%s,%s,%d",student[k].TC ,student[k].Name,student[k].surName,student[k].studentNo,student[k].startYear,&student[k].Term) != EOF){
				
					strtok(student[k].TC,",") ;
					
					user[i].ID[MAX_ID_SIZE] = '\0';
					student[k].TC[MAX_TC_SIZE] = '\0';

					if ( strcmp(user[i].ID,student[k].TC) == 0) {
						strcpy(tempStudentTC,student[k].TC);
						strcpy(student[k].Name ,strtok(NULL,",") );
						strcpy(student[k].surName ,strtok(NULL,",") );
						strcpy(student[k].studentNo,strtok(NULL,",") );
						strcpy(tempStudentNo,student[k].studentNo);
						strcpy(student[k].startYear,strtok(NULL,",") );
						printf("temp student term %d\n", student[k].Term);
						tempStudentTerm=student[k].Term;
						printf("temp student term %d\n", tempStudentTerm);
						printf("Welcome %s %s !!!\n",student[k].Name,student[k].surName);

						choice=studentMenuFunction();

						switch(choice){
						    case 1:
						    	addCourse(lineOfFile,tempStudentTerm,tempStudentTC,tempStudentNo,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 2:
						    	removeStudentCourse(lineOfFile,tempStudentTC,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 3:
						    	listCourse(tempStudentNo,tempStudentTC,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 4:
						    	createTranscript(lineOfFile,tempStudentTC, tempStudentTerm,tempStudentNo, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 5:
						        system_EXIT(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,instructorCourse,studentCourse,course,systemUser);
						    break;
						    default:
						    	printf("Incorrect choice !!! \n Try again pls\n");
						    break;
						}						
					}
					else
					{
						k++;
					}
				}
				
			}
			else
			{
				i++;
			}
		}
			
	}
	fclose(inoutpUsers);
	fclose(inoutpStudents);
 
}
void listCourse(char tempStudentNo[MAX_STUDENTNO_SIZE],char tempStudentTC[MAX_TC_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){

	FILE *outpListCourse;
	int k = 0;
	int i= 0;
	int j = 0;
	char tempTC[MAX_TC_SIZE];
	int check;
	char tempCourseCode[MAX_COURSE_SIZE];
	char charCheck;
	char temp[MAX_SIZE][MAX_SIZE];
	char tempFileName[MAX_SIZE];
	int tempGrade;
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");
	if (inoutpStudentCourses == NULL)
	{
		printf("Sistem acılmadı dosya yok\n");
	}
	else
	{
		while( fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d", studentCourse[i].TC,studentCourse[i].studentNo,studentCourse[i].courseCode,&studentCourse[i].Grade,&studentCourse[i].checkActivePasive) != EOF){

			strtok(studentCourse[i].TC,",") ;
			studentCourse[i].TC[MAX_TC_SIZE] = '\0';
			strcpy(tempTC,studentCourse[i].TC);
			tempStudentTC[MAX_TC_SIZE] = '\0';

			strcpy(studentCourse[i].studentNo  ,strtok(NULL,",") );

			strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
			strcpy(tempCourseCode,studentCourse[i].courseCode );
			strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
			studentCourse[i].Grade = atoi(studentCourse[i].courseName);
			tempGrade = studentCourse[i].Grade ;
			
			strcpy(studentCourse[i].courseName ,strtok(NULL,",") );
			studentCourse[i].checkActivePasive = atoi(studentCourse[i].courseName);

			if (  strcmp(tempStudentTC,tempTC) == 0 && studentCourse[i].checkActivePasive == 1 )
			{
					studentCourse[i].courseCode[MAX_COURSE_SIZE] = '\0';
					tempCourseCode[MAX_COURSE_SIZE] = '\0';
					printf("%s\t%s\t%s\t%d\n",tempStudentTC,studentCourse[i].studentNo,tempCourseCode,tempGrade);	
					sprintf(temp[k],"%s\t%s\t%s\t%d\n",tempStudentTC,studentCourse[i].studentNo,tempCourseCode,tempGrade);
					i++;
					k++;
					continue;
			}
			else{
			printf("Kayıtlı ders bulunamadı\n");
			}
		}
		
			do{
				printf("Kaydetmek istiyormusunuzz:\n");
				scanf(" %c",&charCheck);
				tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
				if ( toupper( charCheck ) == YES)
				{
					k = 0;
					sprintf(tempFileName,"%s_courses.csv",tempStudentNo);
					printf("%s adlı dosyaya kaydedilmiştir.\n",tempFileName );
					outpListCourse = fopen(tempFileName,"w");
						for ( j = 0; j < i; ++j)
						{
							fprintf(outpListCourse, "%s",temp[j] );
							j++;
						}
					fclose(outpListCourse);	
					check = FALSE;
				}
				else if ( toupper( charCheck ) == NO)
				{
					i++;
					check = TRUE;
				}
				else
					printf("Invalid character!! try again :\n");

			}while(!(charCheck == YES || charCheck== NO || charCheck=='y' || charCheck=='n'));	
	}
	do{
		printf("Do you want to go back  the menu of student(Y-y/N-n) no dersen komple cıkar :\n");
		scanf(" %c",&charCheck);
				
		if ( toupper( charCheck ) == YES)
		{
			studentFunction(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);			
		}
		else if ( toupper( charCheck ) == NO)
		{
			EXIT();
		}
		else
		{
			printf("Invalid character !! Try again:\n");
		}
	}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	
	fclose(inoutpStudentCourses);
}

void assignGrades(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser ){
	int i = 0;
	int k = 0;
	int m = 0;
	int status;
	char tempCourseCode[MAX_SIZE];
	char tempCouCode[MAX_COURSE_SIZE];
	char tempStudentNo[MAX_STUDENTNO_SIZE];
	char tempStuNo[MAX_STUDENTNO_SIZE];
	char tempTC[MAX_TC_SIZE];
	int tempGrade;
	int check=TRUE;
	char charCheck;
	char studentGrades[MAX_SIZE][MAX_SIZE];
	char Grades[MAX_SIZE][MAX_SIZE];
	char tempInstSName[MAX_SIZE];
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r");
	printf("%s %s\n",tempInstructorName, tempInstructorSurName);
	while(check==TRUE){
		printf("DERSLER:\n");
		while(fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s\n", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
				printf("Önce Course Code %s\n",course[i].courseCode);
				strtok(course[i].courseCode,",") ;

				printf("sonra Course Code %s\n",course[i].courseCode);
				strcpy(tempCourseCode,course[i].courseCode);

				strcpy(course[i].courseName ,strtok(NULL,",") );
				printf(" Course Name %s\n",course[i].courseCode);

				strcpy(course[i].instructorName ,strtok(NULL,",") );
				printf("course instructor name%s\n",course[i].instructorName );

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("course instructors surname%s\n",course[i].instructorSurName  );
				strcpy(tempInstSName,course[i].instructorSurName);
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].term = atoi(course[i].instructorSurName);
				printf("course term: %d\n",course[i].term);

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].passingGrade = atoi(course[i].instructorSurName);
				printf("course passingGrade: %d\n",course[i].passingGrade);
			
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkAddRemove = atoi(course[i].instructorSurName);
				printf("course check add remove %d\n",course[i].checkAddRemove);


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkOpenClose = atoi(course[i].instructorSurName);
				printf("course check open close %d\n",course[i].checkOpenClose);
				printf("tempInstName %s eşit %s instructorName \n",tempInstructorName,course[i].instructorName );
				printf("tempInstSurName %s eşit %s instructorSurName \n",tempInstructorSurName,tempInstSName );

				if ( strcmp(tempInstructorName,course[i].instructorName ) == 0 && strcmp(tempInstructorSurName,course[i].instructorSurName ) == 0  && course[i].checkOpenClose == 1  &&  course[i].checkAddRemove == 0 )
				{
					printf("%s\t%s\t%s\n",course[i].courseCode,tempInstructorName,tempInstructorSurName);
					i++;
				}
				else  
				{
					printf("Sisteme kayıtlı dersiniz bulunamadı.Ya da dersizin sistem tarafından notlandırlmaya açılmamıştır(add-remove control)\n");
				}
		}
		printf("2.AŞAMA");
		printf("Not vereceğiniz dersi girin\n");
		scanf("%s",tempCouCode);
		while(fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d\n", studentCourse[k].TC,studentCourse[k].studentNo,studentCourse[k].courseCode,&studentCourse[k].Grade,&studentCourse[k].checkActivePasive) != EOF){
			printf("TC of student :ilkk  %s\n",studentCourse[k].TC);
			strtok(studentCourse[k].TC,",") ;
			strcpy(tempTC,studentCourse[k].TC);
			printf("TC of student : %s\n",studentCourse[k].TC);

			strcpy(studentCourse[k].studentNo  ,strtok(NULL,",") );
			printf("student no%s\n",studentCourse[k].studentNo  );

			strcpy(tempStudentNo,studentCourse[k].studentNo);

			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			strcpy(tempCourseCode,studentCourse[k].courseCode );
			printf("student TEMPcoursesCode: %s\n",tempCourseCode);
			

			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			studentCourse[k].Grade = atoi(studentCourse[k].courseCode);
			printf("StudentCourses grade %d\n",studentCourse[k].Grade);
			tempGrade = studentCourse[k].Grade;

	
			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			studentCourse[k].checkActivePasive = atoi(studentCourse[k].courseCode);
			printf("Student checkActivePasive %d\n",studentCourse[k].checkActivePasive);


			studentCourse[k].courseCode[MAX_COURSE_SIZE] = '\0';
			printf("tempStudentNo %s \n",tempStudentNo );
			tempCourseCode[MAX_COURSE_SIZE] = '\0'; 
			printf("student course code  %s eşit %s tempCouCode\n",tempCourseCode,tempCouCode );
			printf("student grade %d\n",studentCourse[k].Grade );
			printf("Student checkActivePasive %d\n", studentCourse[k].checkActivePasive);
			if ( strcmp(tempCouCode,tempCourseCode) == 0 && studentCourse[k].checkActivePasive == 1 &&  studentCourse[k].Grade == 0 )
			{
				printf("ifeeeeeeeeeeee girdimmmmmm \n");

				printf("%s\t%s\t%s\t%d\n",tempTC,tempStudentNo,studentCourse[k].courseCode,tempGrade); 
				printf("Not vereceğiniz öğrencinin numarasını girin:\n");
				scanf("%s",tempStuNo);	
					tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
					printf("tempStudentNo %s eşit %s student course student No\n",tempStudentNo,studentCourse[k].studentNo );
					if ( strcmp(tempStuNo,tempStudentNo) == 0 )
					{	
						
						printf("Not girin:\n");
						scanf("%d",&tempGrade);
						sprintf(studentGrades[m],"%s,%s,%s,%d,%d\n",tempTC, tempStuNo,tempCourseCode,tempGrade ,studentCourse[k].checkActivePasive);
						printf("studentGrades[%d] *---------------%s\n",m,studentGrades[m] );
						m++;
						k++;
						}		
			}
			else{
				sprintf(studentGrades[m],"%s,%s,%s,%d,%d\n",tempTC, tempStuNo,tempCourseCode,tempGrade ,studentCourse[k].checkActivePasive);
				m++;
				k++;
			}
		}
		
		fclose(inoutpStudentCourses);
		fclose(inoutpCourses);
		inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"w");
		for (i = 0; i < m; ++i)
		{
			printf("%d--------------%s\n",i,studentGrades[i] );
			fprintf(inoutpStudentCourses,"%s",studentGrades[i]);
		}
		fclose(inoutpStudentCourses);		
		
		do{
			printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				check = FALSE;
				instructorFunction(lineOfFile, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				m=0;
				k=0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
}
void editGrades(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE] ,int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){
	int i = 0;
	int k = 0;
	int m = 0;
	int status;
	char tempCourseCode[MAX_SIZE];
	char tempCouCode[MAX_COURSE_SIZE];
	char tempStudentNo[MAX_STUDENTNO_SIZE];
	char tempStuNo[MAX_STUDENTNO_SIZE];
	int tempGrade;
	int check=TRUE;
	char charCheck;
	char studentGrades[MAX_SIZE][MAX_SIZE];
	char Grades[MAX_SIZE][MAX_SIZE];
	char tempInstSName[MAX_SIZE];
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r");
	printf("%s %s\n",tempInstructorName, tempInstructorSurName);
	while(check==TRUE){
		printf("DERSLER:\n");
		while(fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s\n", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
				printf("Önce Course Code %s\n",course[i].courseCode);
				strtok(course[i].courseCode,",") ;

				printf("sonra Course Code %s\n",course[i].courseCode);
				strcpy(tempCourseCode,course[i].courseCode);

				strcpy(course[i].courseName ,strtok(NULL,",") );
				printf(" Course Name %s\n",course[i].courseCode);

				strcpy(course[i].instructorName ,strtok(NULL,",") );
				printf("course instructor name%s\n",course[i].instructorName );

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("course instructors surname%s\n",course[i].instructorSurName  );
				strcpy(tempInstSName,course[i].instructorSurName);
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].term = atoi(course[i].instructorSurName);
				printf("course term: %d\n",course[i].term);

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].passingGrade = atoi(course[i].instructorSurName);
				printf("course passingGrade: %d\n",course[i].passingGrade);
			
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkAddRemove = atoi(course[i].instructorSurName);
				printf("course check add remove %d\n",course[i].checkAddRemove);


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkOpenClose = atoi(course[i].instructorSurName);
				printf("course check open close %d\n",course[i].checkOpenClose);
				printf("tempInstName %s eşit %s instructorName \n",tempInstructorName,course[i].instructorName );
				printf("tempInstSurName %s eşit %s instructorSurName \n",tempInstructorSurName,tempInstSName );

				if ( strcmp(tempInstructorName,course[i].instructorName ) == 0 && strcmp(tempInstructorSurName,course[i].instructorSurName ) == 0  && course[i].checkOpenClose == 1 && course[i].checkAddRemove == 0  )
				{
					
					printf("%s\t%s\t%s\n",course[i].courseCode,tempInstructorName,tempInstructorSurName);
					i++;
					continue;
				}
				else  
				{
					printf("Ders bulunamadı!!\n");
				}
		}
		printf("2.AŞAMA");
		printf("Düzeneleyeceğiniz  dersi girin\n");
		scanf("%s",tempCouCode);
		while(fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d\n", studentCourse[k].TC,studentCourse[k].studentNo,studentCourse[k].courseCode,&studentCourse[k].Grade,&studentCourse[k].checkActivePasive) != EOF){
			printf("TC of student :ilkk  %s\n",studentCourse[k].TC);
			strtok(studentCourse[k].TC,",") ;
			/*studentCourse[m].TC[MAX_TC_SIZE] = '\0';*/
			printf("TC of student : %s\n",studentCourse[k].TC);
			/*studentCourse[m].TC[MAX_TC_SIZE] = '\0';*/


			strcpy(studentCourse[k].studentNo  ,strtok(NULL,",") );
			printf("student no%s\n",studentCourse[k].studentNo  );

			strcpy(tempStudentNo,studentCourse[k].studentNo);

			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			strcpy(tempCourseCode,studentCourse[k].courseCode );
			printf("student TEMPcoursesCode: %s\n",tempCourseCode);
			

			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			studentCourse[k].Grade = atoi(studentCourse[k].courseCode);
			printf("StudentCourses grade %d\n",studentCourse[k].Grade);
			tempGrade = studentCourse[k].Grade;

	
			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			studentCourse[k].checkActivePasive = atoi(studentCourse[k].courseCode);
			printf("Student checkActivePasive %d\n",studentCourse[k].checkActivePasive);


			studentCourse[k].courseCode[MAX_COURSE_SIZE] = '\0';
			printf("tempStudentNo %s \n",tempStudentNo );
			tempCourseCode[MAX_COURSE_SIZE] = '\0'; 
			printf("student course code  %s eşit %s tempCouCode\n",tempCourseCode,tempCouCode );
			printf("student grade %d\n",studentCourse[k].Grade );
			printf("Student checkActivePasive %d\n", studentCourse[k].checkActivePasive);
			if ( strcmp(tempCouCode,tempCourseCode) == 0 && studentCourse[k].checkActivePasive == 1 &&  studentCourse[k].Grade != 0 )
			{
				printf("ifeeeeeeeeeeee girdimmmmmm \n");

				printf("%s\t%s\t%s\t%d\n",studentCourse[k].TC,tempStudentNo,studentCourse[k].courseCode,tempGrade); 
				printf("Notunu duzelteceğiniz öğrencinin numarasını girin:\n");
				scanf("%s",tempStuNo);	
					tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
					printf("tempStudentNo %s eşit %s student course student No\n",tempStudentNo,studentCourse[k].studentNo );
					if ( strcmp(tempStuNo,tempStudentNo) == 0 )
					{	
						
						printf("Not girin:\n");
						scanf("%d",&tempGrade);
					sprintf(studentGrades[m],"%s,%s,%s,%d,%d\n",studentCourse[k].TC, tempStuNo,tempCourseCode,tempGrade ,studentCourse[k].checkActivePasive);
					printf("studentGrades[%d] *---------------%s\n",m,studentGrades[m] );
					m++;
					k++;
					}
			
			}
			else{
				sprintf(studentGrades[m],"%s,%s,%s,%d,%d\n",studentCourse[k].TC, tempStuNo,tempCourseCode,tempGrade ,studentCourse[k].checkActivePasive);
				m++;
				k++;
			}
		}
		
		fclose(inoutpStudentCourses);
		fclose(inoutpCourses);
		inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"a+");
		for (i = 0; i < m; ++i)
		{
			printf("%d--------------%s\n",i,studentGrades[i] );
			fprintf(inoutpStudentCourses,"%s",studentGrades[i]);

		}
		fclose(inoutpStudentCourses);		
			
		do{
			printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				check = FALSE;
				instructorFunction(lineOfFile, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				m=0;
				k=0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
}
void addCourse(int lineOfFile, int tempStudentTerm,char tempStudentTC[MAX_TC_SIZE],char tempStudentNo[MAX_STUDENTNO_SIZE],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){
	int i = 0 ;
	char tempCourseCode[MAX_COURSE_SIZE];
	char charCheck;
	int check = TRUE;
	printf("student term %d\n",tempStudentTerm );

	
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r+");
	
	while( check == TRUE ){

		if (inoutpCourses == NULL)
		{
			printf("There is not found file\n");
		}
		else
		{
			while(  fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){

			strtok(course[i].courseCode,",") ;
			strcpy(tempCourseCode,course[i].courseCode);

			strcpy(course[i].courseName ,strtok(NULL,",") );

			strcpy(course[i].instructorName ,strtok(NULL,",") );

			strcpy(course[i].instructorSurName ,strtok(NULL,",") );

			strcpy(course[i].instructorSurName ,strtok(NULL,",") );
			course[i].term  = atoi(course[i].instructorSurName );

			strcpy(course[i].instructorSurName ,strtok(NULL,",") );
			course[i].passingGrade =  atoi(course[i].instructorSurName );

			strcpy(course[i].instructorSurName ,strtok(NULL,",") );
			course[i].checkAddRemove =  atoi(course[i].instructorSurName );

			strcpy(course[i].instructorSurName ,strtok(NULL,",") );
			course[i].checkOpenClose =  atoi(course[i].instructorSurName );
			printf("pree %s\n",course[i].prerequisiteCourse );
				if ( tempStudentTerm == course[i].term  && course[i].checkAddRemove == 1 && course[i].checkOpenClose == 1)
				{	
					
					printf("Alabileceğiniz derslerden bırı:\n");
					printf("%s,%d,%d,%d,%d,%s\n",tempCourseCode,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
					

					do{
						course[i].courseCode[MAX_COURSE_SIZE] = '\0';
						printf("%s dersıni eklemek ıster mısınız?[Y-y,N-n]\n",course[i].courseCode);
						scanf(" %c",&charCheck);
						if ( toupper( charCheck ) == YES)
						{	
							inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"a");
							fprintf(inoutpStudentCourses,"%s,%s,%s,0,1\n", tempStudentTC ,tempStudentNo,course[i].courseCode);						
							printf("Dersiniz eklenmiştir.:)\n");
							fclose(inoutpStudentCourses);	
						
						}
						else if ( toupper( charCheck ) == NO)
						{
							printf("ders eklenmedi.\n");
		
						}
						else
						{
							printf("Invalid character !! Try again:\n");
						}
					}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
				}	
			i++;
		
			}
			printf("İşleminiz tamamlandı yine bekelrizz. \n");
			do{
				printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
				scanf(" %c",&charCheck);
						
				if ( toupper( charCheck ) == YES)
				{
					check = FALSE;
					studentFunction(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);					
				}
				else if ( toupper( charCheck ) == NO)
				{
					i = 0;
					check = TRUE;
				}
				else
				{
					printf("Invalid character !! Try again:\n");
				}
			}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	
		}
		
	}
	fclose(inoutpCourses);
}
void removeStudentCourse(int lineOfFile, char tempStudentTC[MAX_TC_SIZE],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){
	
	int i= 0;
	int m = 0;
	int check = TRUE;
	char tempCourseCode[MAX_COURSE_SIZE];
	char removeCou[MAX_SIZE][MAX_SIZE];
	char charCheck;
	char tempCouName[MAX_SIZE];
	int tempGrade;
	char tempTC[MAX_SIZE];
	char temp[MAX_SIZE][MAX_SIZE];
	char tempCouCode[MAX_COURSE_SIZE];
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");

	while( check == TRUE ){
		if (inoutpStudentCourses == NULL)
		{
			printf("Sistem dersi silmenize izin vermedi!!!");
		}
		else
		{
			while( fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d", studentCourse[i].TC,studentCourse[i].studentNo,studentCourse[i].courseCode,&studentCourse[i].Grade,&studentCourse[i].checkActivePasive) != EOF){
				printf("TC of usser :ilkk  %s\n",studentCourse[i].TC);
				strtok(studentCourse[i].TC,",") ;
	
				printf("TC of usser : %s\n",studentCourse[i].TC);

				strcpy(studentCourse[i].studentNo ,strtok(NULL,",") );
				printf("student no%s\n",studentCourse[i].studentNo );

				strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
				printf("student coursesCode: %s\n",studentCourse[i].courseCode);
				strcpy(tempCouCode,studentCourse[i].courseCode);

				strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
				studentCourse[i].Grade = atoi(studentCourse[i].courseName);
				tempGrade = studentCourse[i].Grade;
				printf("Grade %d\n",studentCourse[i].Grade);
				

				strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
				studentCourse[i].checkActivePasive = atoi(studentCourse[i].courseCode);
				printf("checkActivePasive %d\n",studentCourse[i].checkActivePasive);

				if (studentCourse[i].checkActivePasive == 1  )
				{
					printf( "%s,%s,%s,%d,%d", studentCourse[i].TC,studentCourse[i].studentNo,studentCourse[i].courseCode,studentCourse[i].Grade,studentCourse[i].checkActivePasive);
					printf("%s dersıni silmek ıster mısınız?\n",tempCouCode);
					scanf(" %c",&charCheck);
						do{		
						
							if ( toupper( charCheck ) == YES)
							{						
								/*studentCourse[i].checkActivePasive  = 0;	*/		
								fprintf(inoutpStudentCourses,"-\t\n");	
								printf("dersınız sılındı\n");
								/*fprintf(inoutpStudentCourses, "%s\n", );*/
								i++;
							}
							else if ( toupper( charCheck ) == NO)
							{
								printf("ders sılınmedı.\n");
								sprintf(removeCou[m],"%s,%s,%s,%d,%d", studentCourse[i].TC,studentCourse[i].studentNo,tempCouCode,studentCourse[i].Grade,studentCourse[i].checkActivePasive);
								i++;
								m++;
							}
							else
							{
								printf("Invalid character !! Try again:\n");
							}
						}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );	
									
				}	
				else{
					printf("Ders bulunamadı\n");
				}
				
				
				
			}
			printf("İşleminiz tamamlandı yine bekelrizz. \n");	
			fclose(inoutpStudentCourses);	
			inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"w");
			for (i = 0; i < m; ++i)
			{
				fprintf(inoutpStudentCourses, "%s\n",removeCou[i] );
			}
			fclose(inoutpStudentCourses);

			do{
				printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
				scanf(" %c",&charCheck);
						
				if ( toupper( charCheck ) == YES)
				{
					check = FALSE;
					studentFunction(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);			
				
				}
				else if ( toupper( charCheck ) == NO)
				{
					i = 0;
					m=0;
					check = TRUE;
				}
				else
				{
					printf("Invalid character !! Try again:\n");
				}
			}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
		}		
	}
		

}
void createTranscript(int lineOfFile,char tempStudentTC[MAX_SIZE], int tempStudentTerm,char tempStudentNo[MAX_STUDENTNO_SIZE],FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){

	int i= 0;
	int k = 0;
	int j;
	char charCheck;
	int check;
	char temp[MAX_SIZE][MAX_SIZE];
	char tempCouCode[MAX_SIZE];
	char tempCouName[MAX_SIZE];
	int tempGrade;
	char tempFile[MAX_SIZE]; 

	FILE *outpCreate;
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");
	while(check==TRUE){
		while( fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d\n", studentCourse[i].TC,studentCourse[i].studentNo ,studentCourse[i].courseCode,&studentCourse[i].Grade,&studentCourse[i].checkActivePasive) != EOF){
			printf("TC of usser :ilkk  %s\n",studentCourse[i].TC);
			strtok(studentCourse[i].TC,",") ;
			studentCourse[i].TC[MAX_TC_SIZE] = '\0';
			printf("TC of student : %s\n",studentCourse[i].TC);

			strcpy(studentCourse[i].studentNo ,strtok(NULL,",") );
			printf("student no%s\n",studentCourse[i].studentNo );

		

			strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
			strcpy(tempCouCode,studentCourse[i].courseCode);
			printf("student coursesCode: %s\n",studentCourse[i].courseCode);
			

			strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
			studentCourse[i].Grade = atoi(studentCourse[i].courseCode);
			tempGrade = studentCourse[i].Grade;
			printf("Grade %d\n",studentCourse[i].Grade);

			strcpy(studentCourse[i].courseCode ,strtok(NULL,",") );
			studentCourse[i].checkActivePasive = atoi(studentCourse[i].courseCode);
			printf("checkActivePasive %d\n",studentCourse[i].checkActivePasive);



			printf("tempCourseCode%s\n",tempCouCode );
			printf("studentCourse course code: %s\n", studentCourse[i].courseCode);
			printf("Check aktive pasive %d\n",studentCourse[i].checkActivePasive);
			tempCouCode[MAX_COURSE_SIZE] ='\0';
			studentCourse[i].courseCode[MAX_COURSE_SIZE] = '\0';
			studentCourse[i].TC[MAX_TC_SIZE] = '\0';
			tempStudentTC[MAX_TC_SIZE] = '\0';
			printf("snra tempTC %s eşit %s StudentCourses TC \n",tempStudentTC,studentCourse[i].TC );
					printf("checkActivePasive %d\n",studentCourse[i].checkActivePasive);

			if( strcmp(tempStudentTC,studentCourse[i].TC) == 0 && studentCourse[i].checkActivePasive == 0 &&  tempStudentTerm!=1 ){
				tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
				printf("%s\t%s\t%d\n",tempCouCode,tempCouName,tempGrade );
				sprintf(temp[k],"%s\t%s\t%s\t%d\n",tempStudentNo, tempCouCode,tempCouName,tempGrade );
				printf("Temp[%d]  ------- %s\n",k,temp[k] );
				k++;
				i++;
				continue;
			}
			else if( tempStudentTerm == 1)
			{
				printf("Transcript oluşturacak dersiniz bulunamadı.1.dönem öğrencisisiniz.\n");
			}
		}
		do{
			printf("Dersleri kaydetmek 	istiyormusunuz:\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES){
				tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
				sprintf(tempFile,"%s_transcript.txt",tempStudentNo);
				printf("adı dosya%s\n",tempFile );
				outpCreate = fopen(tempFile,"w");
				k = 0;
				for (j = 0 ; j < i; ++j)
				{
					fprintf(outpCreate,"%s",temp[k]  );
					k++;
				}
				/*systemFunction(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
					instructor,instructorCourse,studentCourse,course,systemUser);
				*/check = FALSE;
				fclose(outpCreate);
			}
			else if ( toupper( charCheck ) == NO){
				i = 0;
				check = TRUE;
			}
			else{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
		check=TRUE;
		do{
			printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				check = FALSE;
				studentFunction(lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);			
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				k=0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
	fclose(inoutpStudentCourses);
}
void openCourse(char tempTC[MAX_TC_SIZE], int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){


	int i = 0;
	int m = 0;
	int k = 0; 
	char tempCourse[MAX_COURSE_SIZE];
	int check=TRUE;
	char charCheck;
	/*helper*/
	char tempInstName[MAX_SIZE];
	char tempIName[MAX_SIZE];
	char tempSName[MAX_SIZE];
	char crsCode[MAX_COURSE_SIZE];
	char crsName[MAX_SIZE];
	char openCourse[MAX_SIZE][MAX_SIZE];
	char tempCourseCode[MAX_COURSE_SIZE];
	char tempCourseName[MAX_SIZE];
	char tempInstSName[MAX_SIZE];

	inoutpInstructors = fopen(INSTRUCTORS_INITIAL_FILE,"r");
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r");

	tempTC[MAX_TC_SIZE]='\0';
	while( check == TRUE ){
		if (inoutpInstructors == NULL)
		{
			printf("There is not found file or users\n");
		}
		else
		{
			printf("else gırdım\n");
			while( fscanf(inoutpInstructors,"%s,%s,%s",instructor[k].TC,instructor[k].Name,instructor[k].surName) != EOF ){
				
				strtok(instructor[k].TC,",");
				strcpy(instructor[k].Name,strtok(NULL,","));
				strcpy(tempIName,instructor[k].Name);
				strcpy(instructor[k].surName,strtok(NULL,"\n"));
				strcpy(tempSName,instructor[k].surName);

				instructor[i].TC[MAX_TC_SIZE]='\0';
				tempTC[MAX_TC_SIZE]='\0';
				printf("tempTC %s eştit %s Instructor TC\n", tempTC,instructor[k].TC);
				if (strcmp(tempTC,instructor[k].TC)==0)
				{					
					if (inoutpCourses == NULL)
					{
						printf("There is not found file or courses\n");
					}
					else
					{
						printf("özür dilerimmmmm\n");
						while(fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
							printf("while gridm\n");
							printf("course code  %s\n",course[i].courseCode);
							strtok(course[i].courseCode,",") ;
							/*course[i].courseCode[MAX_COURSE_SIZE] = '\0';*/
							strcpy(tempCourseCode,course[i].courseCode );
							printf("sonra course code : %s\n",course[i].courseCode);

							strcpy(course[i].courseName ,strtok(NULL,",") );
							printf("course name%s\n",course[i].courseName);			
							strcpy(tempCourseName,course[i].courseName );

							
							strcpy(course[i].instructorName ,strtok(NULL,",") );
							printf("course instructorName: %s\n",course[i].instructorName);
							strcpy(tempInstName,course[i].instructorName );


							strcpy(course[i].instructorSurName ,strtok(NULL,",") );
							printf("COURSE İNSTRUCTOR  surname%s\n",course[i].instructorSurName  );
							strcpy(tempInstSName,course[i].instructorSurName );
							
							strcpy(course[i].instructorSurName ,strtok(NULL,",") );
							course[i].term  = atoi(course[i].instructorSurName );
							printf("course term %d\n",course[i].term );

							strcpy(course[i].instructorSurName ,strtok(NULL,",") );
							course[i].passingGrade =  atoi(course[i].instructorSurName );
							printf("course passingGrade %d\n",course[i].passingGrade );


							strcpy(course[i].instructorSurName ,strtok(NULL,",") );
							course[i].checkAddRemove =  atoi(course[i].instructorSurName );
							printf("course Add-Remove %d\n",course[i].checkAddRemove );



							strcpy(course[i].instructorSurName ,strtok(NULL,",") );
							course[i].checkOpenClose =  atoi(course[i].instructorSurName );
							printf("course open close %d\n",course[i].checkOpenClose);


							strcpy(course[i].instructorSurName ,strtok(NULL,",") );
							printf("prerequisiteCourse%s\n",course[i].instructorSurName );
							strcpy(course[i].prerequisiteCourse ,course[i].instructorSurName );
						

							printf("instructor name%s eşit %s course instructor name\n",tempIName,tempInstName);
							printf("instructor surname %s eşit %s course instructor surname\n",tempSName,tempInstSName);

							if(course[i].checkOpenClose == 0  &&  strcmp(tempIName,tempInstName) == 0 &&  strcmp(tempSName,tempInstSName) == 0 ){
							printf("Allah'ın cezası gir artık su ifeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
							printf("Aktif hale getirbilceğiniz dersler : \n");
							printf("%s,%s,%s,%s,%d,%d,%d,%d,%s\n\n\n",tempCourseCode,tempCourseName,tempIName,tempSName,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
							printf("Açmak istediğiniz dersin kodunu girin:\n");
							scanf("%s",crsCode);
							tempCourseCode[MAX_COURSE_SIZE] = '\0';
							crsCode[MAX_COURSE_SIZE] = '\0';
							printf("tempCourse %s eşit %s crsCode\n",tempCourse,crsCode);
							
								if ( strcmp(crsCode,tempCourseCode) == 0 )
								{
									course[i].checkOpenClose = 1;
									sprintf(openCourse[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n",tempCourseCode,tempCourseName,tempIName,tempSName,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
									printf("openCourse[%d]----------------%s\n",m,openCourse[m] );
									m++;
									i++;
								}
								else{
									printf("ders bulamadı\n");
								}

							}
							else{
									printf("değilse girrrrrrrrrrrrrrrrrrrr\n");
									sprintf(openCourse[m],"%s,%s,%s,%s,%d,%d,%d,%d,%s\n",tempCourseCode,tempCourseName,tempIName,tempSName,course[i].term,course[i].passingGrade,course[i].checkAddRemove,course[i].checkOpenClose,course[i].prerequisiteCourse);
									printf("openCourse[%d]----------------%s\n",m,openCourse[m] );
									m++;
									i++;
								}					
							
						}	
					}
				}
				else
				{
					k++;
				}
			}
			fclose(inoutpCourses);
			fclose(inoutpInstructors);
			inoutpCourses = fopen(COURSES_INITIAL_FILE,"w");
			for (i = 0; i < m; ++i)
			{
				printf("%d--------------%s",i,openCourse[i] );
				fprintf(inoutpCourses,"%s",openCourse[i]);

			}
			fclose(inoutpCourses);
			do{
				printf("İşleminiz gerceklesmıstır.\n");		
				printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
				scanf(" %c",&charCheck);
						
				if ( toupper( charCheck ) == YES)
				{
					check = FALSE;
					instructorFunction(lineOfFile, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);						
				}
				else if ( toupper( charCheck ) == NO)
				{
					i = 0;
					m=0;
					k=0;
					check = TRUE;
				}
				else
				{
					printf("Invalid character !! Try again:\n");
				}
			}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
		}
	}
	

}
void instructorFunction(int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){

	int i = 0;	
	int k = 0;
	int choice;
	char tempTC[MAX_TC_SIZE];
	char tempInstructorName[MAX_SIZE];
	char tempInstructorSurName[MAX_SIZE];
	inoutpUsers = fopen(USERS_INITIAL_FILE,"r");
	inoutpInstructors = fopen(INSTRUCTORS_INITIAL_FILE,"r");

	printf("line of file %d\n",lineOfFile);
	if (inoutpUsers == NULL)
	{
		printf("Dosya bulunamadı !! \n");
	}
	else
	{

		while( fscanf(inoutpUsers, "%s,%s,%s,%s", user[i].ID,user[i].userType,user[i].userName,user[i].password) != EOF ){
	
			strtok(user[i].ID,",") ;
			user[i].ID[MAX_ID_SIZE] = '\0';
			strcpy(user[i].userType ,strtok(NULL,",") );
			strcpy(user[i].userName ,strtok(NULL,",") );
			strcpy(user[i].password ,strtok(NULL,",") );		

			if (lineOfFile == i)
			{
				while( fscanf(inoutpInstructors, "%s,%s,%s", instructor[k].TC,instructor[k].Name,instructor[k].surName) != EOF){
	
					strtok(instructor[k].TC,",") ;
					
					user[i].ID[MAX_ID_SIZE] = '\0';
					instructor[k].TC[MAX_TC_SIZE] = '\0';

					if ( strcmp(user[i].ID,instructor[k].TC) == 0) {
						strcpy(instructor[k].Name ,strtok(NULL,",") );
						strcpy(instructor[k].surName ,strtok(NULL,",") );
						strcpy(tempInstructorName,instructor[k].Name );
						strcpy(tempInstructorSurName,instructor[k].surName);
						printf("inst temp name %s\n",tempInstructorName  );
						printf("inst temp surname %s\n",tempInstructorSurName );
						strcpy(tempTC,instructor[k].TC);						
						
						printf("Welcome %s %s !!!\n",instructor[k].Name,instructor[k].surName);

						choice=instructorMenuFunction();

						switch(choice){
						    case 1:
						    	openCourse(tempTC,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 2:
						    	finalizeCourse(tempInstructorName,tempInstructorSurName,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 3:
						    	assignGrades(tempInstructorName,tempInstructorSurName,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 4:
						    	editGrades(tempInstructorName,tempInstructorSurName,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 5:
						    	listOpenCourse(tempInstructorName,tempInstructorSurName,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);						        
						    break;
						    case 6:
						    	listGrades(tempInstructorName,tempInstructorSurName,lineOfFile,inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);
						    break;
						    case 7:
						    	system_EXIT(inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,
				instructor,instructorCourse,studentCourse,course,systemUser);
						    break;
						    default:
						    	printf("Incorrect choice !!! \n Try again pls\n");
						    break;
						}
						
					}
					else
					{
						k++;
					}
				}
				
			}
			else
			{
				i++;
			}
		}
			
	}
	fclose(inoutpUsers);
	fclose(inoutpInstructors);
}
void finalizeCourse(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){
	int i = 0;
	int k = 0;
	int m = 0;
	int status;
	char tempCourseCode[MAX_SIZE];
	char tempCouCode[MAX_COURSE_SIZE];
	char tempStudentNo[MAX_STUDENTNO_SIZE];
	char tempStuNo[MAX_STUDENTNO_SIZE];
	int tempGrade;
	int check=TRUE;
	char charCheck;
	char studentGrades[MAX_SIZE][MAX_SIZE];
	char Grades[MAX_SIZE][MAX_SIZE];
	char tempInstSName[MAX_SIZE];
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r");
	printf("%s %s\n",tempInstructorName, tempInstructorSurName);
	while(check==TRUE){
		printf("DERSLER:\n");
		while(fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s\n", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
				printf("Önce Course Code %s\n",course[i].courseCode);
				strtok(course[i].courseCode,",") ;

				printf("sonra Course Code %s\n",course[i].courseCode);
				strcpy(tempCourseCode,course[i].courseCode);

				strcpy(course[i].courseName ,strtok(NULL,",") );
				printf(" Course Name %s\n",course[i].courseCode);

				strcpy(course[i].instructorName ,strtok(NULL,",") );
				printf("course instructor name%s\n",course[i].instructorName );

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("course instructors surname%s\n",course[i].instructorSurName  );
				strcpy(tempInstSName,course[i].instructorSurName);
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].term = atoi(course[i].instructorSurName);
				printf("course term: %d\n",course[i].term);

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].passingGrade = atoi(course[i].instructorSurName);
				printf("course passingGrade: %d\n",course[i].passingGrade);
			
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkAddRemove = atoi(course[i].instructorSurName);
				printf("course check add remove %d\n",course[i].checkAddRemove);


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkOpenClose = atoi(course[i].instructorSurName);
				printf("course check open close %d\n",course[i].checkOpenClose);
				printf("tempInstName %s eşit %s instructorName \n",tempInstructorName,course[i].instructorName );
				printf("tempInstSurName %s eşit %s instructorSurName \n",tempInstructorSurName,tempInstSName );

				if ( strcmp(tempInstructorName,course[i].instructorName ) == 0 && strcmp(tempInstructorSurName,course[i].instructorSurName ) == 0  && course[i].checkOpenClose == 1 && course[i].checkAddRemove == 0  )
				{
					
					printf("%s\t%s\t%s\n",course[i].courseCode,tempInstructorName,tempInstructorSurName);
					i++;
					continue;
				}
				else  
				{
					printf("Ders bulunamadı!!\n");
				}
		}
		printf("2.AŞAMA");
		printf("Tamamlamak istediğiniz  dersi girin\n");
		scanf("%s",tempCouCode);
		while(fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d\n", studentCourse[k].TC,studentCourse[k].studentNo,studentCourse[k].courseCode,&studentCourse[k].Grade,&studentCourse[k].checkActivePasive) != EOF){
			printf("TC of student :ilkk  %s\n",studentCourse[k].TC);
			strtok(studentCourse[k].TC,",") ;
			printf("TC of student : %s\n",studentCourse[k].TC);

			strcpy(studentCourse[k].studentNo  ,strtok(NULL,",") );
			printf("student no%s\n",studentCourse[k].studentNo  );

			strcpy(tempStudentNo,studentCourse[k].studentNo);

			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			strcpy(tempCourseCode,studentCourse[k].courseCode );
			printf("student TEMPcoursesCode: %s\n",tempCourseCode);
			

			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			studentCourse[k].Grade = atoi(studentCourse[k].courseCode);
			printf("StudentCourses grade %d\n",studentCourse[k].Grade);
			tempGrade = studentCourse[k].Grade;

	
			strcpy(studentCourse[k].courseCode ,strtok(NULL,",") );
			studentCourse[k].checkActivePasive = atoi(studentCourse[k].courseCode);
			printf("Student checkActivePasive %d\n",studentCourse[k].checkActivePasive);


			studentCourse[k].courseCode[MAX_COURSE_SIZE] = '\0';
			printf("tempStudentNo %s \n",tempStudentNo );
			tempCourseCode[MAX_COURSE_SIZE] = '\0'; 
			printf("student course code  %s eşit %s tempCouCode\n",tempCourseCode,tempCouCode );
			printf("student grade %d\n",studentCourse[k].Grade );
			printf("Student checkActivePasive %d\n", studentCourse[k].checkActivePasive);
			if ( strcmp(tempCouCode,tempCourseCode) == 0 && studentCourse[k].checkActivePasive == 1 &&  studentCourse[k].Grade != 0 &&  studentCourse[k].Grade >= course[i].passingGrade )
			{
				printf("ifeeeeeeeeeeee girdimmmmmm \n");
				printf("Dersi geçen öğrenciler\n");
				printf("%s\t%s\t%s\t%d\n",studentCourse[k].TC,tempStudentNo,studentCourse[k].courseCode,tempGrade ); 
			
					tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
					
				
					studentCourse[k].checkActivePasive = 0 ;
					
					sprintf(studentGrades[m],"%s,%s,%s,%d,%d\n",studentCourse[k].TC, tempStudentNo,tempCourseCode,tempGrade ,studentCourse[k].checkActivePasive);
					printf("studentGrades[%d] *---------------%s\n",m,studentGrades[m] );
					m++;
					k++;
	
			
			}
			else{
				sprintf(studentGrades[m],"%s,%s,%s,%d,%d\n",studentCourse[k].TC, tempStudentNo,tempCourseCode,tempGrade ,studentCourse[k].checkActivePasive);
				m++;
				k++;
			}
		}
		
		fclose(inoutpStudentCourses);
		fclose(inoutpCourses);
		inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"w");
		for (i = 0; i < m; ++i)
		{
			printf("%d--------------%s\n",i,studentGrades[i] );
			fprintf(inoutpStudentCourses,"%s",studentGrades[i]);

		}
		fclose(inoutpStudentCourses);		
			



		do{
			printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				check = FALSE;
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				m=0;
				k=0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
		
}

void listOpenCourse(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE] ,int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){

	int i= 0;
	int k = 0;
	int j = 0;
	int m = 0;
	FILE *outpOpenCourse;
	int check=TRUE;
	char tempCourseCode[MAX_COURSE_SIZE];
	char tempCourseName[MAX_SIZE];
	char charCheck;
	char temp[MAX_SIZE][MAX_SIZE];
	char tempFileName[MAX_SIZE];
	char showCourseCode[MAX_COURSE_SIZE];
	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r+");
	while(check == TRUE ){
		if (inoutpCourses == NULL)
		{
			printf("Sistem dersi listelemenize izin vermedi!!!");
		}
		else{
			while( fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s\n", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
				printf("course code  %s\n",course[i].courseCode);
				strtok(course[i].courseCode,",") ;
				course[i].courseCode[MAX_COURSE_SIZE] = '\0';
				strcpy(tempCourseCode,course[i].courseCode );
				printf("sonra course code : %s\n",course[i].courseCode);

				strcpy(course[i].courseName ,strtok(NULL,",") );
				printf("course name%s\n",course[i].courseName);
				
				strcpy(tempCourseName,course[i].courseName );

				
				strcpy(course[i].instructorName ,strtok(NULL,",") );
				printf("course instructorName: %s\n",course[i].instructorName);

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("student  surname%s\n",course[i].instructorSurName  );

				printf("tempInstName %s eşit %s course inst name \n",tempInstructorName,course[i].instructorName );
				printf("tempInstSurName %s eşit %s course inst surname \n",tempInstructorSurName,course[i].instructorSurName );
				if (strcmp(tempInstructorName,course[i].instructorName) == 0  && strcmp(tempInstructorSurName,course[i].instructorSurName) == 0)
				{
					printf("ife girdimm name-surname\n");
					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].term = atoi(course[i].instructorSurName);
					printf("course term %d\n",course[i].term);

					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].passingGrade = atoi(course[i].instructorSurName);
					printf("passingGrade %d\n",course[i].passingGrade);


					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].checkAddRemove = atoi(course[i].instructorSurName);
					printf("Add-Remove%d\n",course[i].checkAddRemove );

					strcpy(course[i].instructorSurName ,strtok(NULL,",") );
					course[i].checkOpenClose = atoi(course[i].instructorSurName);
					printf("open close%d\n",course[i].checkOpenClose );

				


				printf("Check Open-Close %d\n",course[i].checkOpenClose);
				tempCourseCode[MAX_COURSE_SIZE] ='\0';

					if (course[i].checkOpenClose == 1 )
					{
						tempCourseCode[MAX_COURSE_SIZE+1] = '\0';
						printf("check open ife girdimmm\n");
						printf("%s\t%s\t%s\t%s\n",tempInstructorName,tempInstructorSurName ,tempCourseCode,tempCourseName );

						sprintf(temp[k],"%s\t%s\t%s\t%s\n",tempInstructorName,tempInstructorSurName ,tempCourseCode,tempCourseName );
						i++;
						k++;
						continue;
					}
				}
				else{
					printf("Hoca bulunmadı\n");
				}
				

			}
					
			do{
				printf("Kaydetmek istiyormusunuzz:\n");
				scanf(" %c",&charCheck);
			
				if ( toupper( charCheck ) == YES){
				k = 0;
				sprintf(tempFileName,"%s_%s_openCourses.csv",tempInstructorName,tempInstructorSurName);
				printf("file name %s\n",tempFileName );
				outpOpenCourse = fopen(tempFileName,"w");
				for ( j = 0; j < i; ++j)
				{
					fprintf(outpOpenCourse, "%s",temp[j] );
					j++;
				}
				fclose(outpOpenCourse);
		
				check = FALSE;
				}
				else if ( toupper( charCheck ) == NO){
					i++;
					check = TRUE;
				}
				else
					printf("Invalid character!! try again :\n");

			}while(!(charCheck == YES || charCheck== NO || charCheck=='y' || charCheck=='n'));	
		}
		fclose(inoutpCourses);
		do{
			printf("İşleminiz gerceklesmıstır.\n");		
			printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				check = FALSE;
				instructorFunction(lineOfFile, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);						
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				m=0;
				k=0;
				j=0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
}
void listGrades(char tempInstructorName[MAX_SIZE],char tempInstructorSurName[MAX_SIZE],int lineOfFile,FILE *inoutpUsers,FILE *inoutpCourses,FILE *inoutpStudents,FILE *inoutpInstructors,FILE *inoutpInstructorCourses,FILE *inoutpStudentCourses,users_t *user,students_t *student, instructors_t *instructor,courses_t *course,instructorsCourses_t *instructorCourse,studentsCourses_t *studentCourse,systemUser_t *systemUser){

	int i= 0;
	int k = 0;
	int j = 0;
	int m = 0;
	FILE *outpListGrade;
	char tempCourseCode[MAX_COURSE_SIZE];
	char tempCourseName[MAX_SIZE];
	char charCheck;
	int check=TRUE;
	char temp[MAX_SIZE][MAX_SIZE];
	char tempFileName[MAX_SIZE];
	char showCourseCode[MAX_COURSE_SIZE];
	char tempStudentNo[MAX_STUDENTNO_SIZE];
	int tempGrade;
	char tempInstSName[MAX_SIZE];

	inoutpCourses = fopen(COURSES_INITIAL_FILE,"r");
	inoutpStudentCourses = fopen(STUDENTSCOURSES_INITIAL_FILE,"r");

	while(check==TRUE){
		if (inoutpCourses == NULL)
		{
			printf("Sistem dersleri görmenize izin vermedi!!!");
		}
		else{
			while( fscanf(inoutpCourses, "%s,%s,%s,%s,%d,%d,%d,%d,%s\n", course[i].courseCode,course[i].courseName,course[i].instructorName,course[i].instructorSurName,&course[i].term,&course[i].passingGrade,&course[i].checkAddRemove,&course[i].checkOpenClose,course[i].prerequisiteCourse) != EOF){
				printf("course code  %s\n",course[i].courseCode);
				strtok(course[i].courseCode,",") ;

				strcpy(tempCourseCode,course[i].courseCode );
				printf("sonra course code : %s\n",course[i].courseCode);

				strcpy(course[i].courseName ,strtok(NULL,",") );
				printf("course name%s\n",course[i].courseName);			
				strcpy(tempCourseName,course[i].courseName );

				
				strcpy(course[i].instructorName ,strtok(NULL,",") );
				printf("course instructorName: %s\n",course[i].instructorName);

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				printf("COURSE İNSTRUCTOR  surname%s\n",course[i].instructorSurName  );
				strcpy(tempInstSName,course[i].instructorSurName );
				
				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].term  = atoi(course[i].instructorSurName );
				printf("course term %d\n",course[i].term );

				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].passingGrade =  atoi(course[i].instructorSurName );
				printf("course passingGrade %d\n",course[i].passingGrade );


				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkAddRemove =  atoi(course[i].instructorSurName );
				printf("course Add-Remove %d\n",course[i].checkAddRemove );



				strcpy(course[i].instructorSurName ,strtok(NULL,",") );
				course[i].checkOpenClose =  atoi(course[i].instructorSurName );
				printf("course open close %d\n",course[i].checkOpenClose);

				printf("tempInstName %s eşit %s instructorName \n",tempInstructorName,course[i].instructorName );
				printf("tempInstSurName %s eşit %s instructorSurName \n",tempInstructorSurName,tempInstSName );
				if (  strcmp(tempInstructorName,course[i].instructorName) == 0 &&  strcmp(tempInstructorSurName ,tempInstSName) == 0  && course[i].checkOpenClose == 1 )
				{
						printf("ife girdimmm open close 1 olan  ");
						studentCourse[i].courseCode[MAX_COURSE_SIZE] = '\0';
						tempCourseCode[MAX_COURSE_SIZE] = '\0';
						
						printf("%s\t%s\t%s\n",course[i].courseCode,tempInstructorName,tempInstructorSurName );	
						i++;
						continue;
				}
				else{
				printf("Kayıtlı ders bulunamadı\n");
				}			

			}
			printf("Hangi dersi görmek  istiyor musunuzz\n");
			scanf("%s",showCourseCode);

			while( fscanf(inoutpStudentCourses, "%s,%s,%s,%d,%d\n", studentCourse[m].TC,studentCourse[m].studentNo,studentCourse[m].courseCode,&studentCourse[m].Grade,&studentCourse[m].checkActivePasive) != EOF){
				printf("TC of student :ilkk  %s\n",studentCourse[i].TC);
				strtok(studentCourse[m].TC,",") ;
				/*studentCourse[m].TC[MAX_TC_SIZE] = '\0';*/
				printf("TC of student : %s\n",studentCourse[m].TC);
				/*studentCourse[m].TC[MAX_TC_SIZE] = '\0';*/


				strcpy(studentCourse[m].studentNo  ,strtok(NULL,",") );
				printf("student no%s\n",studentCourse[i].studentNo  );

				strcpy(tempStudentNo,studentCourse[m].studentNo);

				strcpy(studentCourse[m].courseCode ,strtok(NULL,",") );
				printf("student coursesCode: %s\n",studentCourse[m].courseCode);
			

				strcpy(tempCourseCode,studentCourse[m].courseCode );
				strcpy(studentCourse[m].courseCode ,strtok(NULL,",") );

				studentCourse[m].Grade = atoi(studentCourse[m].courseCode);
				tempGrade = studentCourse[m].Grade ;
				printf("Grade %d\n",studentCourse[m].Grade);
				
				strcpy(studentCourse[m].courseName ,strtok(NULL,",") );
				studentCourse[m].checkActivePasive = atoi(studentCourse[m].courseName);
				printf("checkActivePasive %d\n",studentCourse[m].checkActivePasive);
				showCourseCode[MAX_COURSE_SIZE] = '\0'; 
				studentCourse[m].courseCode[MAX_COURSE_SIZE] = '\0';
				
				printf("showCourseCode %s student coursee Coursecode  %s \n", showCourseCode,studentCourse[m].courseCode);
				tempCourseCode[MAX_COURSE_SIZE] = '\0';
				if ( strcmp(showCourseCode,tempCourseCode ) == 0 &&  studentCourse[m].checkActivePasive == 0 )
				{
					printf("iffee girdimmm \n");
					showCourseCode[MAX_COURSE_SIZE] = '\0';
					tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
					printf("%s\t%s\t%d\n",showCourseCode,tempStudentNo, tempGrade );
					sprintf(temp[k],"%s\t%s\t%d\n",showCourseCode,tempStudentNo, tempGrade);
					printf("temp[%d]------------%s\n",k,temp[k] );
					m++;
					k++;
					continue;
				}
				else{
					printf("Ders bulunamadı\n");
				}

			}	
				do{
					printf("Kaydetmek istiyormusunuzz:\n");
					scanf(" %c",&charCheck);
					tempStudentNo[MAX_STUDENTNO_SIZE] = '\0';
					if ( toupper( charCheck ) == YES){
				
					sprintf(tempFileName,"%s_grades.csv",showCourseCode);
					printf("file name %s\n",tempFileName );
					outpListGrade = fopen(tempFileName,"w");
					for ( j = 0; j < m; ++j)
					{
						fprintf(outpListGrade, "%s",temp[j] );
						
					}
					fclose(outpListGrade);
					}
					else if ( toupper( charCheck ) == NO){
						i++;
					}
					else
						printf("Invalid character!! try again :\n");

				}while(!(charCheck == YES || charCheck== NO || charCheck=='y' || charCheck=='n'));	
		}
		fclose(inoutpStudentCourses);
		fclose(inoutpCourses);
		do{
			printf("İşleminiz gerceklesmıstır.\n");		
			printf("Do you want to go back  the menu of student(Y-y/N-n):\n");
			scanf(" %c",&charCheck);
					
			if ( toupper( charCheck ) == YES)
			{
				check = FALSE;
				instructorFunction(lineOfFile, inoutpUsers,inoutpCourses,inoutpStudents,inoutpInstructors,inoutpInstructorCourses,inoutpStudentCourses,user,student,instructor,course,instructorCourse,studentCourse,systemUser);						
			}
			else if ( toupper( charCheck ) == NO)
			{
				i = 0;
				m=0;
				k=0;
				j=0;
				check = TRUE;
			}
			else
			{
				printf("Invalid character !! Try again:\n");
			}
		}while( !(charCheck==YES || charCheck==NO || charCheck=='y' || charCheck=='n') );
	}
}
