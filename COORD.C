/*
			LIBRARY MANAGEMENT SYSTEM
		    	  --- Juriel Botoy ---
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define DURATION 5

const char *menu[] = {"  Add Books","  Delete Books", "  Search Books", "  Issue Books","  View Book Records","  Edit Book Record", "  Close Application"};
char category[][30] = {"  Computer Studies", "  Engineering & Architecture", "  Arts & Sciences", "  Business Management", "  Politics", "  Literature", "  History", "  Return to Main"};
char bookCat[][30] = {"Computer", "Engineering", "Science", "Business", "Politics", "Literature", "History"};
char bookCatDetail[][30] = {"Computer Studies", "Engineering & Architecture", "Arts & Sciences", "Business Management", "Politics", "Literature", "History"};
const char *sortMenu[] = {"  By Category", "  By Book ID", "  By Book Title", "  By Book Author", "  By Year Published"};
const char *srtMenu[] = {"Sort By Category", "Sort By Book ID", "Sort By Title", "Sort By Author", "Sort By Year"};
const char *columnHeader[] = {"Category", "ID", "Book Title", "Book Author", "Year", "Quantity"};
const char *issuedBooksHeader[] = {"Student ID", "Student Name" , "Book Title", "Issued", "Due Date", "State"};
const char *issueMenu[] = {"  Issue Books","  Renew Issued Books", "  View Issued Books", "  Return Issued Books"};
char bookDetail[][15] = {"Category", "ID", "Title", "Author", "Year", "Quantity"};

int s;
int p=0;
int choice;
int sortIndex;
int add = 0;
int issue = 0;
int renew = 0;

typedef struct issueDate{
	int mm,dd,yy;
};

typedef struct books{
	char studentID[12];
	char studentName[25];
	char bookCategoryDetail[25];
	char bookCategory[25];
	int bookID;
	char bookTitle[25];
	char bookAuthor[25];
	int yearPublished;
	int quantity;

	struct issueDate dateIssued[1];
	struct issueDate duedate[1];

	struct books *next;


};

typedef struct books Book;
Book *head = NULL;


void mainmenu();
void addBooks(void);
int deleteBooks(Book **head);
void searchBooks(Book *head);
void searchBookMenu(void);
void issueBookMenu(void);
void issueBooks(Book *head);
void booksIssued(Book *head, char studID[]);
void viewIssuedBooks(Book *head);
void returnIssuedBooks(void);
void renewIssuedBooks(Book *head);
void viewBooks(Book *head);
void editBooks(Book *head);
void editDetail(char detail[],int id);
void sortBookMenu(void);
void sortBooksByCategory(Book **head);
void sortBooksByID(Book **head);
void sortBooksByTitle(Book **head);
void sortBooksByAuthor(Book **head);
void sortBooksByYear(Book **head);
void topBorder(int,int,int,int);
void bookTable(int,int,int,int);
void issuedBooksTable(int,int,int,int);
void window(int a, int b, int c, int d);
void cursor(int no);
void highlight(int no, int count);
int checkBookID(int id);
int checkStudentID(char studID[]);
int insertAtEnd();
int getBookData();
int dateTime(void);


void main()
{
	mainmenu();
}

void mainmenu(){

	int i,j=0;

	clrscr();

	textcolor(WHITE);

	window(27,55,7,23);



	gotoxy(35,5);
	printf("M AI N  M E N U");
	for(i=0;i<7;i++){
		gotoxy(32,9+j);
		printf("%s", menu[i]);

		j = j + 2;

	}

	gotoxy(20,24);
	dateTime();

	cursor(7);
	getch();
}

void addBooks(void){

		int j=0;
	       char ch;
	       int i;

	       clrscr();

	       window(23,60,7,25);

	       gotoxy(34,5);
	       printf("SELECT CATEGORY");

	       for(i=0;i<=7;i++){
			gotoxy(28,9+j);
			printf("%s", category[i]);

			j+=2;
	       }

	       cursor(8);


}

int getBookData(){
	int id;
	int i;
	Book *newNode,*temp;

	clrscr();

	head = (Book *)malloc(sizeof(Book));

	window(20,62,7,25);

	gotoxy(37,5);
	printf("ADD BOOKS");

	if(head == NULL){
		gotoxy(24,11);
		printf("Error: Unable to allocate memory!");
		exit(0);
	}

	else{

		 //if(add==0){

			gotoxy(24,9);
			printf("Category:");
			gotoxy(33,9);
			printf("%s", category[s]);

			gotoxy(24,11);
			printf("Book ID: \t");
			gotoxy(33,11);
			scanf("%d", &id);

			if(checkBookID(id) == 0){
				gotoxy(24,13);
				printf("\aError: Book ID already exists\a");
				getch();
				mainmenu();
				return 0;

			}
			strcpy(head->bookCategory,bookCatDetail[s]);
			strcpy(head->bookCategoryDetail, bookCat[s]);
			head->bookID = id;

			fflush(stdin);
			gotoxy(24,13);
			printf("Book Title:");
			gotoxy(36,13);
			scanf("%[^\n]s", &head->bookTitle);

			fflush(stdin);
			gotoxy(24,15);
			printf("Author:");
			gotoxy(32,15);
			scanf("%[^\n]s", &head->bookAuthor);

			gotoxy(24,17);
			printf("Year Published: ");
			gotoxy(40,17);
			scanf("%d", &head->yearPublished);

			gotoxy(24,19);
			printf("Quantity: ");
			gotoxy(34,19);
			scanf("%d", &head->quantity);

			head->next = NULL;


			add=1;


			gotoxy(30,22);
			printf("Book added successfully!");
			getch();
			mainmenu();



       }


}

int insertAtEnd(){

	int id;
	int i;
	Book *newNode,*temp;

	clrscr();


	window(20,62,7,25);

	gotoxy(37,5);
	printf("ADD BOOKS");

	if(head == NULL){
		gotoxy(24,11);
		printf("Error: Unable to allocate memory!");
		exit(0);
	}

	else{

			 newNode = (Book *)malloc(sizeof(Book));

			 if(newNode == NULL){
				gotoxy(24,9);
				printf("Error: Memory not allocated!");
				getch();
				mainmenu();
			 }

			 else{
				gotoxy(24,9);
				printf("Category:");
				gotoxy(33,9);
				printf("%s", category[s]);

				gotoxy(24,11);
				printf("Book ID: \t");
				gotoxy(33,11);
				scanf("%d", &id);

				if(checkBookID(id) == 0){
					gotoxy(24,13);
					printf("\aError: Book ID already exists\a");
					getch();
					mainmenu();
					return 0;

				}
				strcpy(newNode->bookCategory,bookCatDetail[s]);
				strcpy(newNode->bookCategoryDetail, bookCat[s]);
				newNode->bookID = id;

				fflush(stdin);
				gotoxy(24,13);
				printf("Book Title:");
				gotoxy(36,13);
				scanf("%[^\n]s", &newNode->bookTitle);

				fflush(stdin);
				gotoxy(24,15);
				printf("Author:");
				gotoxy(32,15);
				scanf("%[^\n]s", &newNode->bookAuthor);

				gotoxy(24,17);
				printf("Year Published: ");
				gotoxy(40,17);
				scanf("%d", &newNode->yearPublished);

				gotoxy(24,19);
				printf("Quantity: ");
				gotoxy(34,19);
				scanf("%d", &newNode->quantity);

				newNode->next = NULL;

				temp = head;

				while(temp->next != NULL)
					temp = temp->next;

				temp->next = newNode;

				gotoxy(30,22);
				printf("Book added successfully!");
				getch();
				mainmenu();
		}
	}
}



int checkBookID(int id){
	Book *tmp;

	if(tmp == NULL){
		gotoxy(24,9);
		printf("List is empty!");
		mainmenu();
		return 0;
	}

	else{
		tmp = head;
		if(head->bookID == id){
			return 0;
		}

			while(tmp != NULL){
				if(tmp->bookID == id){
					return 0;
				}

			 tmp = tmp->next;
			}


	       return 1;

	}

}


int checkStudentID(char studID[]){
	Book *tmp;

	if(tmp == NULL){
		gotoxy(32,11);
		printf("Error: Book list empty!");
		getch();
		mainmenu();
	}

	else{
		tmp = head;

		while(tmp!=NULL){
			if(strcmpi(tmp->studentID,studID)==0){
				return 0;

			}

			tmp = tmp->next;
		}

		return 1;
	}
}

int deleteBooks(Book **head){
	char ch;
	int key;
	Book *p,*q;

	window(20,62,7,25);

	gotoxy(36,5);
	printf("DELETE BOOKS");

	gotoxy(24,9);
	printf("Enter Book ID: ");
	gotoxy(39,9);
	scanf("%d", &key);

	p =  *head;

	if(p->bookID == key){

			gotoxy(24,11);
			printf("Category: ");
			gotoxy(34,11);
			printf("%s", p->bookCategory);
			gotoxy(24,13);
			printf("Book ID: %d", p->bookID);
			gotoxy(24,15);
			printf("Book Title: %s", p->bookTitle);
			gotoxy(24,17);
			printf("Author: %s", p->bookAuthor);
			gotoxy(24,19);
			printf("Year Published: %d", p->yearPublished);


			fflush(stdin);
			gotoxy(32,21);
			printf("Delete[y/n]: ");
			gotoxy(45,21);
			scanf("%c", &ch);

			if(ch == 'y'){
				*head = p->next;
				free(p);
			}

			else{
				mainmenu();
				return 0;
			}

			gotoxy(30,23);
			printf("Book deleted successfully!");
			getch();
			mainmenu();

	}

	else{
		while((p!=NULL) && (p->bookID != key))
		{
			q = p;
			p= p->next;
		}

		if(p==NULL){
			gotoxy(24,11);
			printf("Book ID not found!");
			getch();
			mainmenu();
			return 0;

		}


		else if(p->bookID == key){

			gotoxy(24,11);
			printf("Category: ");
			gotoxy(34,11);
			printf("%s", p->bookCategory);
			gotoxy(24,13);
			printf("Book ID: %d", p->bookID);
			gotoxy(24,15);
			printf("Book Title: %s", p->bookTitle);
			gotoxy(24,17);
			printf("Author: %s", p->bookAuthor);
			gotoxy(24,19);
			printf("Year Published: %d", p->yearPublished);

			fflush(stdin);
			gotoxy(28,21);
			printf("Delete[y/n]: ");
			gotoxy(40,21);
			scanf("%c", &ch);

			if(ch == 'y'){
				q->next = p->next;
				free(p);
			}

			else{
				mainmenu();
				return 0;
			}

			gotoxy(30,22);
			printf("Book deleted successfully!");
			getch();
			mainmenu();

		}
	}

	return 0;

}

void searchBookMenu(void){
	int i;
	int j=0;
	const char *searchMenu[] = {"  Search By ID", "  Search By Title", "  Return to Main"};

	clrscr();

	window(29,53,7,15);

	gotoxy(35,5);
	printf("SEARCH BOOKS");

	for(i=0;i<=2;i++){
		gotoxy(32,9+j);
		printf("%s", searchMenu[i]);

		j += 2;
	}

	cursor(3);




}

void searchBooks(Book *head){
	Book *tmp, *ext;
	Book *chk;
	int found = 0;
	int key;
	char title[25];

	if(choice == 1){
		clrscr();
		window(20,62,7,25);

		gotoxy(36, 5);
		printf("SEARCH BY ID");

		gotoxy(24,9);
		printf("Enter Book ID:");
		gotoxy(39,9);
		scanf("%d", &key);

		if(checkBookID(key) == 1){
			gotoxy(24,11);
			printf("Error: Book not found!");
			getch();
			mainmenu();

		}


			tmp = head;

			while(tmp != NULL){
				if(tmp->bookID == key){
					gotoxy(24,11);
					printf("Category: ");
					gotoxy(35,11);
					printf("%s", tmp->bookCategory);
					gotoxy(24,13);
					printf("Book ID: %d", tmp->bookID);
					gotoxy(24,15);
					printf("Book Title: %s", tmp->bookTitle);
					gotoxy(24,17);
					printf("Author: %s", tmp->bookAuthor);
					gotoxy(24,19);
					printf("Year Published: %d", tmp->yearPublished);
					gotoxy(24,21);
					printf("Quantity: %d", tmp->quantity);

					getch();
					searchBookMenu();
				}

		}
	}//End of Choice 1

	if(choice == 2){
		clrscr();

		window(20,62,7,25);

		fflush(stdin);
		gotoxy(24,9);
		printf("Enter Book Title: ");
		gotoxy(42,9);
		scanf("%[^\n]s", &title);

		//Check if title exists
		chk = head;
		while(chk != NULL){
			if(strcmpi(chk->bookTitle, title) == 0){

				found = 1;
			}
			chk = chk->next;
		}

		if(found == 0){
			gotoxy(26,11);
			printf("Error: Book not found!");
			getch();
			mainmenu();

		}

		if(found == 1){


				ext = head;

				while(ext != NULL){
					if(strcmpi(ext->bookTitle, title) == 0){
						gotoxy(24,11);
						printf("Category: ");
						gotoxy(35,11);
						printf("%s", ext->bookCategory);
						gotoxy(24,13);
						printf("Book ID: %d", ext->bookID);
						gotoxy(24,15);
						printf("Book Title: %s", ext->bookTitle);
						gotoxy(24,17);
						printf("Author: %s", ext->bookAuthor);
						gotoxy(24,19);
						printf("Year Published: %d", ext->yearPublished);
						gotoxy(24,21);
						printf("Quantity: %d", ext->quantity);

						getch();
						searchBookMenu();

					}

					ext = ext->next;

				}
		}

	}//End Choice 2

	if(choice == 3){
		mainmenu();
	}
}

void editBooks(Book *head){
	Book *tmp;
	int id;
	char detail[15];

	window(20,62,7,25);

	gotoxy(36,5);
	printf("EDIT BOOKS");

	gotoxy(24,9);
	printf("Enter Book ID: ");
	gotoxy(39,9);
	scanf("%d", &id);

	fflush(stdin);
	if(checkBookID(id) == 1){
		gotoxy(31,11);
		printf("Error: Book not found!");
		getch();
		mainmenu();
	}

	tmp = head;

	while(tmp != NULL){
		if(tmp->bookID == id){
			gotoxy(24,11);
			printf("Category: ");
			gotoxy(34,11);
			printf("%s", tmp->bookCategory);
			gotoxy(24,13);
			printf("Book ID: %d", tmp->bookID);
			gotoxy(24,15);
			printf("Book Title: %s", tmp->bookTitle);
			gotoxy(24,17);
			printf("Author: %s", tmp->bookAuthor);
			gotoxy(24,19);
			printf("Year Published: %d", tmp->yearPublished);
			gotoxy(24,21);
			printf("Quantity: %d", tmp->quantity);

			getch();

			fflush(stdin);
			gotoxy(35,23);
			printf("Edit: ");
			gotoxy(41,23);
			scanf("%[^\n]s", &detail);


			break;

		}

		tmp = tmp->next;

	}

	editDetail(detail,id);

}

void editDetail(char detail[], int id){
	Book *tmp, *ext;
	int index;
	int cFound;
	int i;
	int j=1;
	char tempstr[25];
	int tempint;

	window(20,62,7,25);


	for(i=0;i<6;i++){
		if(strcmpi(bookDetail[i], detail) == 0){
			if(i==1){
				gotoxy(36,5);
				printf("EDIT Book %s", bookDetail[i]);

			}
			else{
				gotoxy(36,5);
				printf("EDIT %s", bookDetail[i]);
			}

			index = i;
			break;
		}
	}

	j = j + (strlen(bookDetail[index]));


	gotoxy(24,9);
	printf("Enter New %s: ", bookDetail[index]);

	if(index == 0 || index == 2 || index == 3){
		fflush(stdin);
		gotoxy(35+j,9);
		scanf("%[^\n]s", &tempstr);
	}

	if(index == 1 || index == 4 || index == 5){
		gotoxy(35+j, 9);
		scanf("%d", &tempint);
	}

	if(index == 1){
		if(checkBookID(tempint) == 0){
			gotoxy(28,11);
			printf("Error: Book ID already exists!");
			getch();
			editDetail(detail, id);
		}
	}

	ext = head;

	while(ext != NULL){
		if(ext->bookID == id){
			if(index == 0){
				for(i=0;i<7;i++){
					if(strcmpi(bookCat[i],tempstr)==0){
						cFound = i;
					}
				}
				strcpy(ext->bookCategory,bookCatDetail[cFound]);
			}
			if(index == 1){
				ext->bookID = tempint;
			}
			if(index == 2){
				strcpy(ext->bookTitle, tempstr);
			}
			if(index == 3){
				strcpy(ext->bookAuthor, tempstr);
			}
			if(index == 4){
				ext->yearPublished = tempint;
			}
			if(index == 5){
				ext->quantity = tempint;
			}
		}

		ext = ext->next;
	}

	tmp = head;

	while(tmp != NULL){
		if(tmp->bookID == id){
			gotoxy(24,11);
			printf("Category: ");
			gotoxy(34,11);
			printf("%s", tmp->bookCategory);
			gotoxy(24,13);
			printf("Book ID: %d", tmp->bookID);
			gotoxy(24,15);
			printf("Book Title: %s", tmp->bookTitle);
			gotoxy(24,17);
			printf("Author: %s", tmp->bookAuthor);
			gotoxy(24,19);
			printf("Year Published: %d", tmp->yearPublished);
			gotoxy(24,21);
			printf("Quantity: %d", tmp->quantity);


		}

		tmp = tmp->next;
	}

	getch();
	mainmenu();

}

void issueBookMenu(void){
	int j=0,i;

	window(27,56,7,17);

	gotoxy(35,5);
	printf("ISSUE BOOKS");

	for(i=0;i<=2;i++){
		gotoxy(30, 9+j);
		printf("%s", issueMenu[i]);

		j += 2;
	}

	cursor(4);

}

void booksIssued(Book *head, char studID[]){
	Book *ext,*sNode;
	int y =0;
	int id;

	topBorder(30,53,7,21);
	issuedBooksTable(1,80,7,17);

	gotoxy(34,5);
	printf("View Issued Books");

	ext = head;

	gotoxy(5,8);
	printf("%s", issuedBooksHeader[0]);
	gotoxy(20,8);
	printf("%s", issuedBooksHeader[1]);
	gotoxy(38,8);
	printf("%s", issuedBooksHeader[2]);
	gotoxy(54,8);
	printf("%s", issuedBooksHeader[3]);
	gotoxy(64,8);
	printf("%s", issuedBooksHeader[4]);
	gotoxy(75,8);
	printf("%s", issuedBooksHeader[5]);

	ext = head;

	while(ext != NULL){
		if(strcmp(ext->studentID, studID) == 0){
		       gotoxy(4,10+y);
		       printf("%s", ext->studentID);
		       gotoxy(19,10+y);
		       printf("%s", ext->studentName);
		       gotoxy(36,10+y);
		       printf("%s", ext->bookTitle);
		       gotoxy(53,10+y);
		       printf("%d/%d/%d", ext->dateIssued->mm, ext->dateIssued->dd, ext->dateIssued->yy);
		       gotoxy(64,10+y);
		       printf("%d/%d/%d", ext->duedate->mm, ext->duedate->dd, ext->duedate->yy);

		       if(ext->dateIssued->dd == ext->duedate->dd){
				textcolor(20);
				gotoxy(75,10+y);
				cprintf("DUE");

		       }
		       y++;
		}
		ext = ext->next;
	}

	gotoxy(28,19);
	printf("Return Book[ID]: ");
	gotoxy(44,19);
	scanf("%d", &id);



	sNode = head;

	while(sNode != NULL){
		if(sNode->bookID == id){
			strcpy(sNode->studentID, '\0');
			strcpy(sNode->studentName, '\0');
		}

		sNode = sNode->next;
	}

	gotoxy(28,19);
	printf("Book Returned Successfully!");


	getch();
	mainmenu();

}

void returnIssuedBooks(void){
	char studID[12];

	window(29,55,7,11);

	gotoxy(32,5);
	printf("RETURN ISSUED BOOKS");

	gotoxy(31,9);
	printf("Student ID: ");
	gotoxy(43,9);
	scanf("%s", &studID);

	if(checkStudentID(studID) == 1){
		gotoxy(35,11);
		printf("Error: Student ID not found!");
		getch();
		mainmenu();
	}

	booksIssued(head, studID);

}

void renewIssuedBooks(Book *head){
	Book *tmp,*ext;
	char studID[12];
	int id;
	char ch;

	window(22,58,7,25);

	gotoxy(34,5);
	printf("RENEW BOOKS");


	if(renew == 0){
		gotoxy(26,9);
		printf("Student ID: ");
		gotoxy(38,9);
		scanf("%s", &studID);

		if(checkStudentID(studID) == 1){
			gotoxy(28,11);
			printf("Error: Student ID not found!");
			getch();
			mainmenu();
		}

	}


	else if(renew == 1){
		tmp = head;

		while(tmp != NULL){
			if(tmp->studentID == studID){
				gotoxy(26,9);
				printf("Student ID: %s", tmp->studentID);

			}
			tmp = tmp->next;
		}
	}

	gotoxy(26,11);
	printf("Enter Book ID: ");
	gotoxy(41,11);
	scanf("%d", &id);

	if(checkBookID(id) == 1){
		gotoxy(28,13);
		printf("Error: Book ID not found!");
		getch();
		renew = 1;
		renewIssuedBooks(head);
	}

	ext = head;

	while(ext != NULL){
		if(ext->bookID == id){
			gotoxy(26,13);
			printf("Book ID: %d", ext->bookID);
			gotoxy(26,15);
			printf("Book Title: %s", ext->bookTitle);
			gotoxy(26,17);
			printf("Author: %s", ext->bookAuthor);
			gotoxy(26,19);
			printf("Date Issued: %d/%d/%d", ext->dateIssued->mm, ext->dateIssued->dd, ext->dateIssued->yy);
			gotoxy(26,21);
			printf("Due Date: %d/%d/%d", ext->duedate->mm, ext->duedate->dd, ext->duedate->yy);


			getch();
		}

		ext = ext->next;
	}

	fflush(stdin);
	gotoxy(30,23);
	printf("Renew Book[Y/N]: ");
	gotoxy(47,23);
	scanf("%c", &ch);

	if(ch == 'y' || ch == 'Y'){
		gotoxy(30,23);
		printf("    Book Renewed!   ");
		getch();
		mainmenu();
	}
	else{
		mainmenu();
	}


}

void issueBooks(Book *head){
	Book *tmp, *ext;
	char studID[12];
	char studName[25];
	char tempSID[12];
	char tempSName[25];
	int id;
	int y=0;
	char ch;

	window(20,62,7,25);

	gotoxy(36,5);
	printf("ISSUE BOOKS");

	if(issue == 0){
		gotoxy(24,9);
		printf("Student ID: ");
		gotoxy(36,9);
		scanf("%s", &studID);

		strcpy(tempSID,studID);

		if(checkStudentID(studID) == 0){
			gotoxy(30,11);
			printf("Error: Student ID already exists!");
			getch();
			issueBooks(head);
		}

		gotoxy(24,11);
		printf("Student Name: ");
		fflush(stdin);
		gotoxy(38,11);
		scanf("%[^\n]s", &studName);
		strcpy(tempSName, studName);
	}

	else if(issue == 1){
		ext = head;
		while(ext != NULL){
			gotoxy(24,9);
			printf("Student ID: %s", ext->studentID);
			gotoxy(24,11);
			printf("Student Name: %s", ext->studentName);

			ext = ext->next;
		}
	}

	gotoxy(24,13);
	printf("Enter Book ID: ");
	gotoxy(39,13);
	scanf("%d", &id);

	if(checkBookID(id) == 1){
		gotoxy(28,15);
		printf("Error: Book does not exist!");
		getch();
		mainmenu();
	}

	tmp = head;

	while(tmp != NULL){
		if(tmp->bookID == id){
			gotoxy(24,15+y);
			printf("Category: %s", tmp->bookCategory);
			gotoxy(24,17+y);
			printf("Book ID: %d", tmp->bookID);
			gotoxy(24, 19+y);
			printf("Book Title: %s", tmp->bookTitle);
			gotoxy(24,21+y);
			printf("Author: %s", tmp->bookAuthor);
			gotoxy(24, 23+y);
			printf("Year Published: %d", tmp->yearPublished);

			strcpy(tmp->studentID, studID);
			strcpy(tmp->studentName, studName);

			tmp->dateIssued->mm = 10;
			tmp->dateIssued->dd = 21;
			tmp->dateIssued->yy = 19;

			tmp->duedate->mm = 10;
			tmp->duedate->dd = tmp->dateIssued->dd + DURATION;
			tmp->duedate->yy = 19;

			getch();
		}
		tmp = tmp->next;
	}

	gotoxy(32,27);
	printf("Issue More[Y/N]: ");
	fflush(stdin);
	gotoxy(45,27);
	scanf("%c", &ch);

	if(ch == 'y' || ch == 'Y'){
		issue = 1;
		issueBooks(head);
	}
	else if(ch == 'n' || ch == 'N'){
		issue = 0;
		mainmenu();
	}

}

void viewIssuedBooks(Book *head){
	Book *tmp;
	int i;
	int x  = 0, y = 0;

	topBorder(30,53,7,21);
	issuedBooksTable(1,80,7,21);

	gotoxy(34,5);
	printf("View Issued Books");

	tmp = head;

	gotoxy(5,8);
	printf("%s", issuedBooksHeader[0]);
	gotoxy(20,8);
	printf("%s", issuedBooksHeader[1]);
	gotoxy(38,8);
	printf("%s", issuedBooksHeader[2]);
	gotoxy(54,8);
	printf("%s", issuedBooksHeader[3]);
	gotoxy(64,8);
	printf("%s", issuedBooksHeader[4]);
	gotoxy(75,8);
	printf("%s", issuedBooksHeader[5]);


	while(tmp != NULL){
		if(tmp->studentID != NULL){
		       gotoxy(4,10+y);
		       printf("%s", tmp->studentID);
		       gotoxy(19,10+y);
		       printf("%s", tmp->studentName);
		       gotoxy(36,10+y);
		       printf("%s", tmp->bookTitle);
		       gotoxy(53,10+y);
		       printf("%d/%d/%d", tmp->dateIssued->mm, tmp->dateIssued->dd, tmp->dateIssued->yy);
		       gotoxy(64,10+y);
		       printf("%d/%d/%d", tmp->duedate->mm, tmp->duedate->dd, tmp->duedate->yy);

		       if(tmp->dateIssued->dd == tmp->duedate->dd){
				textcolor(20);
				gotoxy(75,10+y);
				cprintf("DUE");
		       }

		       y++;

		}

		tmp = tmp->next;
	}


	getch();
	mainmenu();

}

void viewBooks(Book *head){
	Book *tmp;
	int i;
	int x = 0, y = 0;

	topBorder(30,53,7,21);
	bookTable(1,80,7,21);

	 if(tmp == NULL){
		clrscr();
		gotoxy(33,15);
		printf("Error: Book List empty!");
		getch();
		mainmenu();
	 }

	 else{

		gotoxy(34+p,5);
		printf("%s", srtMenu[sortIndex]);



		tmp = head;

		gotoxy(5,8);
		printf("%s", columnHeader[0]);
		gotoxy(18,8);
		printf("%s", columnHeader[1]);
		gotoxy(26,8);
		printf("%s", columnHeader[2]);
		gotoxy(45,8);
		printf("%s", columnHeader[3]);
		gotoxy(64,8);
		printf("%s", columnHeader[4]);
		gotoxy(72,8);
		printf("%s", columnHeader[5]);

		while(tmp != NULL){
		      gotoxy(4,10+y);
		      printf("%s", tmp->bookCategoryDetail);
		      gotoxy(17,10+y);
		      printf("%d", tmp->bookID);
		      gotoxy(24,10+y);
		      printf("%s", tmp->bookTitle);
		      gotoxy(43,10+y);
		      printf("%s", &tmp->bookAuthor);
		      gotoxy(64,10+y);
		      printf("%d", tmp->yearPublished);
		      gotoxy(75,10+y);
		      printf("%d", tmp->quantity);


		      y++;
		      tmp = tmp->next;

		}
	 }

	 getch();
	 mainmenu();

}

void sortBookMenu(void){
	int i;
	int j=0;

	window(29,53,7,19);

	gotoxy(37,5);
	printf("SORT BOOKS");

	for(i=0;i<5;i++){
		gotoxy(31, 9+j);
		printf("%s", sortMenu[i]);

		j = j+2;
	}

	cursor(5);
}

void sortBooksByCategory(Book **head){
	Book *sNode = NULL, *temp = NULL;
	int tempid;
	char tempcat[20];
	char tempcat2[20];
	char temptitle[25];
	char tempauthor[25];
	int tempyear;
	int tempquant;

	sNode = *head;

	while(sNode != NULL){
		temp = sNode;

		while(temp->next != NULL){
			if(temp->bookCategory[0] > temp->next->bookCategory[0]){
				strcpy(tempcat, temp->bookCategory);
				strcpy(tempcat2, temp->bookCategoryDetail);
				tempid = temp->bookID;
				strcpy(temptitle, temp->bookTitle);
				strcpy(tempauthor, temp->bookAuthor);
				tempyear = temp->yearPublished;
				tempquant = temp->quantity;

				strcpy(temp->bookCategory, temp->next->bookCategory);
				strcpy(temp->bookCategoryDetail, temp->next->bookCategoryDetail);
				temp->bookID = temp->next->bookID;
				strcpy(temp->bookTitle, temp->next->bookTitle);
				strcpy(temp->bookAuthor, temp->next->bookTitle);
				temp->yearPublished = temp->next->yearPublished;
				temp->quantity = temp->next->quantity;

				strcpy(temp->next->bookCategory, tempcat);
				strcpy(temp->next->bookCategoryDetail,tempcat2);
				temp->next->bookID = tempid;
				strcpy(temp->next->bookTitle, temptitle);
				strcpy(temp->next->bookAuthor , tempauthor);
				temp->next->yearPublished = tempyear;
				temp->next->quantity = tempquant;
			    }

				temp = temp->next;

		}

		sNode = sNode->next;
	}
}

void sortBooksByID(Book **head){
	Book *sNode = NULL, *temp = NULL;
	int tempid;
	char tempcat[20];
	char tempcat2[20];
	char temptitle[25];
	char tempauthor[25];
	int tempyear;
	int tempquant;

	sNode = *head;

	while(sNode != NULL){
		temp = sNode;

		while(temp->next != NULL){
			if(temp->bookID > temp->next->bookID){
				strcpy(tempcat, temp->bookCategory);
				strcpy(tempcat2,temp->bookCategoryDetail);
				tempid = temp->bookID;
				strcpy(temptitle, temp->bookTitle);
				strcpy(tempauthor, temp->bookAuthor);
				tempyear = temp->yearPublished;
				tempquant = temp->quantity;

				strcpy(temp->bookCategory, temp->next->bookCategory);
				strcpy(temp->bookCategoryDetail, temp->next->bookCategoryDetail);
				temp->bookID = temp->next->bookID;
				strcpy(temp->bookTitle, temp->next->bookTitle);
				strcpy(temp->bookAuthor, temp->next->bookAuthor);
				temp->yearPublished = temp->next->yearPublished;
				temp->quantity = temp->next->quantity;

				strcpy(temp->next->bookCategory, tempcat);
				strcpy(temp->next->bookCategoryDetail,tempcat2);
				temp->next->bookID = tempid;
				strcpy(temp->next->bookTitle, temptitle);
				strcpy(temp->next->bookAuthor, tempauthor);
				temp->next->yearPublished = tempyear;
				temp->next->quantity = tempquant;
				}
				temp = temp->next;
			}
			sNode = sNode->next;
		}


}

void sortBooksByTitle(Book **head){
	Book *sNode = NULL, *temp = NULL;
	int tempid;
	char tempcat[20];
	char tempcat2[20];
	char temptitle[25];
	char tempauthor[25];
	int tempyear;
	int tempquant;

	sNode = *head;

	while(sNode != NULL){
		temp = sNode;

		while(temp->next != NULL){
			if(temp->bookTitle[0] > temp->next->bookTitle[0]){
				strcpy(tempcat, temp->bookCategory);
				strcpy(tempcat2,temp->bookCategoryDetail);
				tempid = temp->bookID;
				strcpy(temptitle, temp->bookTitle);
				strcpy(tempauthor, temp->bookAuthor);
				tempyear = temp->yearPublished;
				tempquant = temp->quantity;

				strcpy(temp->bookCategory, temp->next->bookCategory);
				strcpy(temp->bookCategoryDetail, temp->next->bookCategoryDetail);
				temp->bookID = temp->next->bookID;
				strcpy(temp->bookTitle, temp->next->bookTitle);
				strcpy(temp->bookAuthor, temp->next->bookAuthor);
				temp->yearPublished = temp->next->yearPublished;
				temp->quantity = temp->next->quantity;

				strcpy(temp->next->bookCategory ,tempcat);
				strcpy(temp->next->bookCategoryDetail, tempcat2);
				temp->next->bookID = tempid;
				strcpy(temp->next->bookTitle, temptitle);
				strcpy(temp->next->bookAuthor, tempauthor);
				temp->next->yearPublished = tempyear;
				temp->next->quantity = tempquant;
				}

				temp = temp->next;
			}

			sNode = sNode->next;
		}

}

void sortBooksByAuthor(Book **head){
	Book *sNode = NULL, *temp = NULL;
	int tempid;
	char tempcat[20];
	char tempcat2[20];
	char temptitle[25];
	char tempauthor[25];
	int tempyear;
	int tempquant;

	sNode = *head;

	while(sNode != NULL){
		temp = sNode;

		while(temp->next != NULL){
			if(temp->bookAuthor[0] > temp->next->bookAuthor[0]){
				strcpy(tempcat, temp->bookCategory);
				strcpy(tempcat2,temp->bookCategoryDetail);
				tempid = temp->bookID;
				strcpy(temptitle, temp->bookTitle);
				strcpy(tempauthor, temp->bookAuthor);
				tempyear = temp->yearPublished;
				tempquant = temp->quantity;

				strcpy(temp->bookCategory, temp->next->bookCategory);
				strcpy(temp->bookCategoryDetail, temp->next->bookCategoryDetail);
				temp->bookID = temp->next->bookID;
				strcpy(temp->bookTitle, temp->next->bookTitle);
				strcpy(temp->bookAuthor, temp->next->bookAuthor);
				temp->yearPublished = temp->next->yearPublished;
				temp->quantity = temp->next->quantity;

				strcpy(temp->next->bookCategory ,tempcat);
				strcpy(temp->next->bookCategoryDetail,tempcat2);
				temp->next->bookID = tempid;
				strcpy(temp->next->bookTitle, temptitle);
				strcpy(temp->next->bookAuthor, tempauthor);
				temp->next->yearPublished = tempyear;
				temp->next->quantity = tempquant;
				}

				temp = temp->next;
			}

			sNode = sNode->next;
		}


}


void sortBooksByYear(Book **head){
	Book *sNode = NULL, *temp = NULL;
	int tempid;
	char tempcat[20];
	char tempcat2[20];
	char temptitle[25];
	char tempauthor[25];
	int tempyear;
	int tempquant;

	sNode = *head;

	while(sNode != NULL){
		temp = sNode;

		while(temp->next != NULL){
			if(temp->yearPublished > temp->next->yearPublished){
				strcpy(tempcat, temp->bookCategory);
				strcpy(tempcat2,temp->bookCategoryDetail);
				tempid = temp->bookID;
				strcpy(temptitle, temp->bookTitle);
				strcpy(tempauthor, temp->bookAuthor);
				tempyear = temp->yearPublished;
				tempquant = temp->quantity;

				strcpy(temp->bookCategory, temp->next->bookCategory);
				strcpy(temp->bookCategoryDetail,temp->next->bookCategoryDetail);
				temp->bookID = temp->next->bookID;
				strcpy(temp->bookTitle, temp->next->bookTitle);
				strcpy(temp->bookAuthor, temp->next->bookAuthor);
				temp->yearPublished = temp->next->yearPublished;
				temp->quantity = temp->next->quantity;

				strcpy(temp->next->bookCategory ,tempcat);
				strcpy(temp->next->bookCategoryDetail,tempcat2);
				temp->next->bookID = tempid;
				strcpy(temp->next->bookTitle, temptitle);
				strcpy(temp->next->bookAuthor, tempauthor);
				temp->next->yearPublished = tempyear;
				temp->next->quantity = tempquant;
				}

				temp = temp->next;
			}

			sNode = sNode->next;
		}

}

void cursor(int no){
	int count = 1;
	char ch = '0';

	gotoxy(32,9);

	while(1){
		switch(ch){
			case 80:
				count++;
				if(count == no+1)
				count = 1;
				break;
			case 72:
				count--;
				if(count == 0)
				count = no;
				break;
		}

		highlight(no,count);

		ch = getch();

		if(ch == '\r'){
			if(no==7){
				if(count == 1)
				addBooks();

				else if(count == 2)
				deleteBooks(&head);

				else if(count == 3)
				searchBookMenu();

				else if(count == 4)
				issueBookMenu();

				else if(count == 5)
				sortBookMenu();

				else if(count == 6)
				editBooks(head);

				else{
					head = NULL;
					exit(0);
				}
			}


			if(no == 8)
			{
				if(count == 1){
					s=0;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else if(count == 2){
					s=1;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else if(count == 3){
					s=2;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else if(count == 4){
					s=3;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else if(count == 5){
					s=4;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else if(count == 6){
					s=5;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else if(count == 7){
					s=6;
					if(add == 0){
						getBookData();
					}
					else if(add == 1){
						insertAtEnd();
					}
				}

				else
				mainmenu();


			}

			if(no == 3){
				if(count == 1){
					choice = 1;
					searchBooks(head);
				}

				else if(count == 2){
					choice = 2;
					searchBooks(head);
				}

				else
				mainmenu();

			}

			if(no == 4){
				if(count == 1)
				issueBooks(head);

				else if(count == 2)
				renewIssuedBooks(head);


				else if(count == 3)
				viewIssuedBooks(head);

				else if(count == 4)
				returnIssuedBooks();

			}

			if(no == 5){
				if(count == 1){
					sortIndex = 0;
					sortBooksByCategory(&head);
					viewBooks(head);
				}
				else if(count == 2){
					sortIndex = 1;
					p=1;
					sortBooksByID(&head);
					viewBooks(head);
				}

				else if(count == 3){
					sortIndex = 2;
					p=2;
					sortBooksByTitle(&head);
					viewBooks(head);
				}

				else if(count == 4){
					sortIndex = 3;
					p=1;
					sortBooksByAuthor(&head);
					viewBooks(head);
				}
				else if(count == 5){
					sortIndex = 4;
					p=2;
					sortBooksByYear(&head);
					viewBooks(head);
				}
			}

		}

	}
}

void highlight(int no, int count){
	       if(no == 8){
		gotoxy(28,9);
		printf("  Computer Studies           ");
		gotoxy(28,11);
		printf("  Engineering & Architecture ");
		gotoxy(28,13);
		printf("  Arts & Sciences            ");
		gotoxy(28,15);
		printf("  Business Management        ");
		gotoxy(28,17);
		printf("  Politics                   ");
		gotoxy(28,19);
		printf("  Literature                 ");
		gotoxy(28,21);
		printf("  History                    ");
		gotoxy(28,23);
		printf("  Return to Main             ");

		switch(count){
			case 1:
				gotoxy(28,9);
				printf(" - Computer Studies           ");
				break;
			case 2:
				gotoxy(28,11);
				printf(" - Engineering & Architecture ");
				break;
			case 3:
				gotoxy(28,13);
				printf(" - Arts & Sciences            ");
				break;
			case 4:
				gotoxy(28,15);
				printf(" - Business Management        ");
				break;
			case 5:
				gotoxy(28,17);
				printf(" - Politics                   ");
				break;
			case 6:
				gotoxy(28,19);
				printf(" - Literature                 ");
				break;
			case 7:
				gotoxy(28,21);
				printf(" - History                    ");
				break;
			case 8:
				gotoxy(28,23);
				printf(" - Return to Main             ");
				break;
		}
	}

	if(no==7){
		gotoxy(32,8);
		printf("  Add Books         ");
		gotoxy(32,10);
		printf("  Delete Books      ");
		gotoxy(32,12);
		printf("  Search Books      ");
		gotoxy(32,14);
		printf("  Issue Books       ");
		gotoxy(32,16);
		printf("  View Book Records ");
		gotoxy(32,18);
		printf("  Edit Book Record  ");
		gotoxy(32,20);
		printf("  Close Application ");

		switch(count){
			case 1:
				gotoxy(32,8);
				printf(" - Add Books         ");
				break;
			case 2:
				gotoxy(32,10);
				printf(" - Delete Books      ");
				break;
			case 3:
				gotoxy(32,12);
				printf(" - Search Books      ");
				break;
			case 4:
				gotoxy(32,14);
				printf(" - Issue Books       ");
				break;
			case 5:
				gotoxy(32,16);
				printf(" - View Book Records ");
				break;
			case 6:
				gotoxy(32,18);
				printf(" - Edit Book Record  ");
				break;
			case 7:
				gotoxy(32,20);
				printf(" - Close Application ");
				break;
		}


	}

	if(no == 3){
		gotoxy(32,9);
		printf("  Search By ID    ");
		gotoxy(32,11);
		printf("  Search By Title ");
		gotoxy(32,13);
		printf("  Return to Main  ");

		switch(count){
			case 1:
				gotoxy(32,9);
				printf(" - Search By ID    ");
				break;
			case 2:
				gotoxy(32,11);
				printf(" - Search By Title ");
				break;
			case 3:
				gotoxy(32,13);
				printf(" - Return to Main  ");
				break;

		}
	}

	if(no == 4){
		gotoxy(30,9);
		printf("  Issue Books         ");
		gotoxy(30,11);
		printf("  Renew Issued Books  ");
		gotoxy(30,13);
		printf("  View Issued Books   ");
		gotoxy(30,15);
		printf("  Return Issued Books ");

		switch(count){
			case 1:
				gotoxy(30,9);
				printf(" - Issue Books         ");
				break;
			case 2:
				gotoxy(30,11);
				printf(" - Renew Issued Books  ");
				break;
			case 3:
				gotoxy(30,13);
				printf(" - View Issued Books   ");
				break;
			case 4:
				gotoxy(30,15);
				printf(" - Return Issued Books ");
				break;
		}
	}

	if(no == 5){
		gotoxy(31,9);
		printf("  By Category       ");
		gotoxy(31,11);
		printf("  By Book ID        ");
		gotoxy(31,13);
		printf("  By Book Title     ");
		gotoxy(31,15);
		printf("  By Book Author    ");
		gotoxy(31,17);
		printf("  By Year Published ");

		switch(count){
			case 1:
				gotoxy(31,9);
				printf(" - By Category       ");
				break;

			case 2:
				gotoxy(31,11);
				printf(" - By Book ID        ");
				break;

			case 3:
				gotoxy(31,13);
				printf(" - By Book Title     ");
				break;

			case 4:
				gotoxy(31,15);
				printf(" - By Book Author    ");
				break;

			case 5:
				gotoxy(31,17);
				printf(" - By Year Published ");
				break;
		}

	}

}

void topBorder(int a, int b, int c, int d){
	int i;

	clrscr();

	gotoxy(16,2);
	for(i=1;i<=10;i++)
		printf("*");
	printf(" * LIBRARY MANAGEMENT SYSTEM * ");
	for(i=1;i<=10;i++)
		printf("*");

	for(i=a;i<=b;i++){
		gotoxy(i,4);
		printf("\xcd");
		gotoxy(i,6);
		printf("\xcd");
	}

	gotoxy(a,4);
	printf("\xc9");
	gotoxy(a,5);
	printf("\xba");
	gotoxy(a,6);
	printf("\xc8");
	gotoxy(b,4);
	printf("\xbb");
	gotoxy(b,5);
	printf("\xba");
	gotoxy(b,6);
	printf("\xbc");

}

void issuedBooksTable(int a, int b, int c, int d){
	int i;

	for(i=a;i<b;i++){
		gotoxy(i,c);
		printf("\xcd");
		gotoxy(i,9);
		printf("\xcd");
		gotoxy(i,d);
		printf("\xcd");
	}

	for(i=c;i<=d;i++){
		gotoxy(a,i);
		printf("\xba");
		gotoxy(17,i);
		printf("\xba");
		gotoxy(34,i);
		printf("\xba");
		gotoxy(51,i);
		printf("\xba");
		gotoxy(62,i);
		printf("\xba");
		gotoxy(73,i);
		printf("\xba");
		gotoxy(b,i);
		printf("\xba");
	}

	gotoxy(a,c);
	printf("\xc9");
	gotoxy(a,d);
	printf("\xc8");
	gotoxy(17,c);
	printf("\xbb");
	gotoxy(17,d);
	printf("\xbc");
	gotoxy(34,c);
	printf("\xbb");
	gotoxy(34,d);
	printf("\xbc");
	gotoxy(51,c);
	printf("\xbb");
	gotoxy(51,d);
	printf("\xbc");
	gotoxy(62,c);
	printf("\xbb");
	gotoxy(62,d);
	printf("\xbc");
	gotoxy(73,c);
	printf("\xbb");
	gotoxy(73,d);
	printf("\xbc");
	gotoxy(b,c);
	printf("\xbb");
	gotoxy(b,d);
	printf("\xbc");
}

void bookTable(int a, int b, int c, int d){
	int i;

	for(i=a;i<b;i++){
		gotoxy(i,c);
		printf("\xcd");
		gotoxy(i,9);
		printf("\xcd");
		gotoxy(i,d);
		printf("\xcd");
	}

	for(i=c;i<=d;i++){
		gotoxy(a,i);
		printf("\xba");
		gotoxy(15,i);
		printf("\xba");
		gotoxy(21,i);
		printf("\xba");
		gotoxy(40,i);
		printf("\xba");
		gotoxy(60,i);
		printf("\xba");
		gotoxy(70,i);
		printf("\xba");
		gotoxy(b,i);
		printf("\xba");
	}

	gotoxy(a,c);
	printf("\xc9");
	gotoxy(a,d);
	printf("\xc8");
	gotoxy(15,c);
	printf("\xbb");
	gotoxy(15,d);
	printf("\xbc");
	gotoxy(21,c);
	printf("\xbb");
	gotoxy(21,d);
	printf("\xbc");
	gotoxy(40,c);
	printf("\xbb");
	gotoxy(40,d);
	printf("\xbc");
	gotoxy(60,c);
	printf("\xbb");
	gotoxy(60,d);
	printf("\xbc");
	gotoxy(70,c);
	printf("\xbb");
	gotoxy(70,d);
	printf("\xbc");
	gotoxy(b,c);
	printf("\xbb");
	gotoxy(b,d);
	printf("\xbc");
}

void window(int a, int b, int c, int d){
	int i;
	clrscr();

	gotoxy(16,2);
	for(i=1;i<=10;i++)
		printf("*");
	printf(" * LIBRARY MANAGEMENT SYSTEM * ");
	for(i=1;i<=10;i++)
		printf("*");
	printf("\n\n");


	for(i=a;i<=b;i++)
	{
		gotoxy(i,4);
		printf("\xcd");
		gotoxy(i,6);
		printf("\xcd");
		gotoxy(i,c);
		printf("\xcd");
		gotoxy(i,d);
		printf("\xcd");
	}

	gotoxy(a,4);
	printf("\xc9");
	gotoxy(a,5);
	printf("\xba");
	gotoxy(a,6);
	printf("\xc8");
	gotoxy(b,4);
	printf("\xbb");
	gotoxy(b,5);
	printf("\xba");
	gotoxy(b,6);
	printf("\xbc");

	for(i=c;i<=d;i++){
		gotoxy(a,i);
		printf("\xba");
		gotoxy(b,i);
		printf("\xba");
	}

	gotoxy(a,c);
	printf("\xc9");
	gotoxy(a,d);
	printf("\xc8");
	gotoxy(b,c);
	printf("\xbb");
	gotoxy(b,d);
	printf("\xbc");

}



int dateTime(void){
	time_t t;
	time(&t);

	printf("Date-Time:%s\n", ctime(&t));

	return 0;
}
