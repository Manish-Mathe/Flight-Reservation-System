#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEAT 72;
int total_plane=0;
					

struct seats{
	int seat_no;
	char *name;
	int age;
	char gender;
	struct seats *next;
};

typedef struct seats seats;

					

typedef struct{
	int hour;
	int min;
	char meri[3];
} time;

					

struct plane{
	int plane_no;
	char *from;
	char *to;
	time depart;
	time reach;
	int price;
	seats *list;
	struct plane *next;
};

typedef struct plane plane;

plane *head=NULL,*temp=NULL;

					

plane* create_plane(){
	plane *work=(plane*)malloc(sizeof(plane));
	if(head==NULL)
		head=temp=work;
	else
		temp->next=work;
	temp->next=NULL;
	temp->list=NULL;
	total_plane++;
	return work;
}
					

plane* plane_address(int plane_no){

	for(plane *temp=head;(temp!=NULL && plane_no!=temp->plane_no);temp=temp->next);
	return temp;
}

					

void data_import(){

	FILE *fp=fopen("Flight-details","r");
	char c[50],*ch;
	int i=0,j=0;

	if(fp==NULL)
		printf("Import File Missing\n		_____Exiting_____");
	else{

		while(!feof(fp)){
			i++;
			plane *work=create_plane();
			work->plane_no=i;
			fscanf(fp,"%s",c);
			work->from=(char*)malloc(strlen(c));
			for(j=0;j<strlen(c);j++)
				work->from[j]=c[j];
			fscanf(fp,"%s",c);
			work->to=(char*)malloc(strlen(c));
			for(j=0;j<strlen(c);j++)
				work->to[j]=c[j];
			fscanf(fp,"%*c%d%*c%d%*c%s",&work->depart.hour,&work->depart.min,work->depart.meri);
			fscanf(fp,"%*c%d%*c%d%*c%s",&work->reach.hour,&work->reach.min,work->reach.meri);
			fscanf(fp,"%*c%d",&work->price);
		}
		return;

	}
	exit(0);

}

					

void plane_header(){

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|   Plane no.	|      From	|	To	|     Depart	|     Reach	|     Price 	|\n");
	printf("-------------------------------------------------------------------------------------------------\n");

}

					

void print_plane(plane *work){

	printf("|\t%d\t|",work->plane_no);
	printf(" %s\t\t|",work->from);
	printf(" %s\t\t|",work->to);
	printf(" %2d:%2d %s\t|",work->depart.hour,work->depart.min,work->depart.meri);
	printf(" %2d:%2d %s\t|",work->reach.hour,work->reach.min,work->reach.meri);
	printf(" ₹%d\t|\n",work->price);
	printf("-------------------------------------------------------------------------------------------------\n");
}

					

void info(){

	plane_header();
	for(plane *work=head;work != NULL; work = work->next)
		print_plane(work);

}

					

void filter(char *from,char *to){

	plane_header();
	for(plane *work=head;work!=NULL;work=work->next){
		int flag=0;
		if(from[0]!='\0' && from==work->from){
			print_plane(work);
			flag=1;
		}

		if(to[0]!='\0' && to==work->to && !flag)
			print_plane(work);

	}

}
					

int seat_taken(plane *work,int seat){

	seats *hold=work->list;
	while(hold!=NULL){
		if(hold->seat_no==seat)
			return 1;
	}
	return 0;
}

					

void seat_print(plane *work,int row){

	for(int i=row;i<73;i=i+6){
		if(!seat_taken(work,i)){
			if(i>36 && i<43)
				printf("      %d",i);
			else
				printf("   %d",i);
		}
		else{
			if(i<10)
				printf("X");
			else
				printf("XX");
		}
	}
}

					

void print_seat(plane *work){

int i;

printf("                                       _________\n");
printf("                                      //       |\n");
printf("                                     //        |\n");
printf("                                    //         |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("    ______________________________________________________________________________\n");
printf("   /      |  ");
seat_print(work,1);
printf(" |      \\\n");
printf("  /       |  ");
seat_print(work,2);
printf(" |       |\\\\\\\n");
printf(" /        |  ");
seat_print(work,3);
printf(" |       |///\n");
printf("| =0 C|    -                                                               |______/\n");
printf("|          _                                                               |______\n");
printf("| =0 C|   | ");
seat_print(work,4);
printf(" |      \\\n");
printf(" \\        | ");
seat_print(work,5);
printf(" |       |\\\\\\\n");
printf("  \\       | ");
seat_print(work,6);
printf(" |       |///\n");
printf("   \\______|________________________________________________________________|______/\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    |          |\n");
printf("                                    \\\\         |\n");
printf("                                     \\\\        |\n");
printf("                                      \\\\       |\n");
printf("                                        --------\n");

}

					

plane* find_plane(){

	char in,from[15],to[15];
	int i;
	do{
	info();
	printf("\n\nChoose a Plane (or f/F for filter)\n\n->");
	scanf("%*c%c",&in);
	if(in=='f' || in=='F'){
		printf("\n\nFrom : ");
		scanf("%s",from);
		printf("\nTo : ");
		scanf("%s",to);
		filter(from,to);
		printf("\n\nChoose a Plane (or f/F for filter)\n\n->");
		scanf("%c",&in);
	}
	sscanf(&in,"%d",&i);
	}while(i>0 && i<total_plane);
	return(plane_address(i));
}

					

void add_seat(plane *work,int seat){

	seats *temp=(seats *)malloc(sizeof(seats));
	char name[50];
	temp->seat_no=seat;
	printf("\nName of the passanger	 : ");
	scanf("%[^\n]s",name);
	temp->name=(char*)malloc(strlen(name));
	temp->name=name;
	printf("\nAge of the passanger	 : ");
	scanf("%d",&temp->age);
	printf("Gender of passanger (M/F): ");
	scanf("%c",&temp->gender);
	temp->next=NULL;
	if(work->list==NULL){
		work->list=temp;
		return;
	}
	else{
		seats *hold=work->list,*old=work->list;
		while(hold!=NULL){
			if(hold->next==NULL)
				hold->next=temp;
			if(hold->seat_no>seat){
				temp->next=old->next;
				old->next=temp;
			}
			old=hold;
			hold=hold->next;
		}
	}
}

					

void book(){

	int no_seats,*order_seats;
	plane *work=find_plane();
	char c;
	printf("Available Seats (\"X\" represents booked seats)\n\n");
	do{
		print_seat(work);
		printf("\n\n\n\nHow many seats would you like to book ?\n\n->");
		scanf("%d",&no_seats);
		order_seats=(int*)malloc(no_seats*sizeof(int));
		printf("Choose %d seats (type seat numbers seperated by space)\n\n->",no_seats);
		for(int i=0;i<no_seats;i++)
			scanf("%d",&order_seats[i]);
		for(int i=0;i<no_seats;i++){
			do{
				if(seat_taken(work,order_seats[i])){
					print_seat(work);
					printf("Chosen seat %d is already taken please choose another seat",order_seats[i]);
					printf("\n\nChoose another seat\n\n->");
					scanf("%d",&order_seats[i]);
				}
			}while(seat_taken(work,order_seats[i]));
		}
		printf("Chosen seats are : ");
		for(int i=0;i<no_seats;i++)
			printf("%d ",order_seats[i]);
		printf("\n\nContinue? (y/n)\n\n->");
		scanf("%*c%c",&c);
	}while(c!='y' || c!='Y');
	for(int i=0;i<no_seats;i++)
		add_seat(work,order_seats[i]);
	printf("\n\nTotal Amount : %d \nPaid in advance", no_seats*work->price);
	printf("\n\nTHANK YOU FOR CHOOSING OUR SERVICES");
	printf("PRESS ANY KEY TO RETURN TO HOME SCREEN");
	scanf("%*c");
}

					

void remove_seat(seats *hold,int seat){

	char check;
	seats *old=hold;
	while(hold->seat_no!=seat){
		old=hold;
		hold=hold->next;
	}
	printf("\n\nSeat no : %d\nName : %s\n\n",hold->seat_no,hold->name);
	do{
		printf("Cancel ? (y/n)\n\n->");
		scanf("%c",&check);
		if(check!='n' || check!='N' || check!='y' || check!='Y')
			printf("Invalid input");
	}while(check=='n' || check=='N' || check=='y' || check=='Y');
	if(check=='n' || check=='N'){
		printf("Cancelation Stopped");
		return;
	}
	else{
		old->next=hold->next;
		free(hold);
	}

}

					

void cancel(){

	int seat;
	plane *work=find_plane();
	printf("Give the seat no. : ");
	scanf("%d",&seat);
	if(seat_taken(work,seat))
		remove_seat(work->list,seat);
	else
		printf("The is not booked\nCheck the information and try again");
}

					

void booked_header(){
printf("____________________________________________________________\n");
printf("|  Seat Number	|   Name of Passanger	|  Age	|  Gender  |\n");
printf("------------------------------------------------------------\n");
}

					

void booked_info(plane *work){

	seats *hold=work->list;
	printf("Registration details for plane no. %d\n\n\t",work->plane_no);
	print_plane(work);
	booked_header();
	for(;hold!=NULL;hold = hold->next){
		printf("| %d\t|",hold->seat_no);
		printf("   %s\t",hold->name);
		printf("|  %d  |",hold->age);
		printf("  %s   |",(hold->gender=='m')?("Male"):("Female"));
	}

}

					

void credits(){

printf("Done by\n\n1)Manish\n2)Shwejan\n3)Pranav\n4)\n\nProject : Flight Reservation System");

}

					

void print_title(){

printf("  |----/\\      /----/| /---/\\    /---/|\n");
printf("  |----\\ \\    /----| | \\---\\ \\  /---/ |\n");
printf("  |     \\ \\  /     | |  \\   \\ \\/   / /\n");
printf("  |      \\ \\/      | |   \\   \\/   / /\n");
printf("  |       \\/       | |    \\      / /\n");
printf("  |    |\\    /|    | |     \\    / /\n");
printf("  |    | \\  / |    | |      |  | |\n");
printf("  |    | |\\/  |    | |      |  | |\n");
printf("  |____|/     |____|/       |__|/\n\n");


printf("        /-----/\\         /-------------/|  |-------\\             /---/|          /-------------/|   /---/\\  /----/|   /-----------/|\n");
printf("       /------\\ \\       |-------------| |  |   |\\   \\           |---| |         |-------------| |  |----\\ \\|----| |  |-----------| |\n");
printf("      /        \\ \\      |___|    |____|/   |   | \\   \\          |   | |         |___|    |____|/   |     \\ |    | |  |           | |\n");
printf("     /    /\\    \\ \\         |    | |       |   | /    \\         |   | |             |    | |       |      \\|    | |  |     ______|/\n");
printf("    /    /__\\    \\ \\        |    | |       |   |/     /         |   | |             |    | |       |            | |  |    |_____\n");
printf("   /              \\ \\       |    | |       |         /          |   | |______       |    | |       |            | |  |     _____|\n");
printf("  /     /----\\     \\ \\   /--|    | /---/|  |    |\\   \\          |   |/_____ /|   /--|    | /---/|  |    |\\      | |  |    |-------/|\n");
printf(" /     /      \\     \\ \\ |---|    |----| |  |    | \\   \\         |          | |  |---|    |----| |  |    | \\     | |  |    |------| |\n");
printf("/_____/        \\_____\\/ |_____________|/   |____|  \\___\\        |__________|/   |_____________|/   |____|/ \\____|/   |___________|/\n");


printf("  ______________________\n");
printf(" //                     \\\\\n");
printf(" | Welcome 2 My Airlines |\n");
printf(" \\\\_____________________//\n");

}

					
void exit_message(){

printf("Thank You For Using Our Services\n");
printf("\n\n-_-_-_-_-_Exiting_-_-_-_-_-\n\n");

}
					

void main(){

	char choice;
	data_import();
	do{
		system("clear");
		print_title();
		info();
		printf("1) Book seats\n2)Cancel seat\n3)Check reservations\n4)Credits\n5)Exit\n\n->");
		scanf("%c",&choice);
		switch(choice){
			case'1':
				book();
				break;
			case'2':
				cancel();
				break;
			case'3':
				plane *work=find_plane();
				booked_info(work);
				break;
			case'4':
				credits();
				break;
			case'5':
				exit_message();
				break;
			default:
				printf("Error : Invalid Input");
		}
	}while(choice!='5');
}
