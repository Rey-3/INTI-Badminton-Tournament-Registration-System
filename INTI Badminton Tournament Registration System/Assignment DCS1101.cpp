// Group Assignment by Wong Kai Jun and Chew Zhi Boon
#include<iostream>
#include<iomanip>
#include<string>
#include <fstream>
using namespace std;

struct Registration{
	string id ;
	string name;
	int age;
	string contactNo;
	char member;
	char categoryCode;
    int day;
    int month;
    int year;
	char receipt;
};

struct price{
    float aftDiscount=0;
	float discount=0;
	float befDiscount=0;
};

struct code{
	int codeJ=0;
	int codeS=0;
	int codeO=0;
};
int random();
int  registration(int);
void Temporary_registration_records();
void toUpperCase(string& );
void toUpperCasechar(char&);
void print(int);
void calcalation(int);
bool isIDExist(string id,int);
bool valid_or_not(char,int);
bool is_input_valid(int );

struct Registration participant[50];
struct price price[50];
struct code category;
int main(){
    int option,option2;
    int size=10;
    int i=10;
   
    Temporary_registration_records();// put Temporary_registration_records in to the main function
	
	while(true){
	cout<<endl<<setw(60)<<right<<"<<Badminton Tournament Registration System>> \n\n" ;
	cout<<"1-> Add New Registration \n"
	    <<"2-> Edit a Registration \n"
	    <<"3-> View Summary Report \n"
	    <<"4-> Exit \n";
	   	
		   
		   
	while(true){  //Dont allow user to enter 'd'or'@'......
    cout<<"Enter Option:";
      if (cin >> option) {
        break;
}   else{
     cout << "Invalid Option\n";  
       cin.clear(); // clear the error state
         cin.ignore(); // discard any input in the buffer
    }
}

	switch(option){
	case 1:{	
	string id;
    bool isDuplicate;
    if(i>49){  //if participant more then 50 will not allow user to register anymore
	  cout<<"Enrolment is Full\n";
	    break;
}
    cout << "Example: P1001";
    do{
    cout << "\nEnter ID for participant :";  //Ask User to input participant Id and it can't be repeat
      cin >> id;
        toUpperCase(id);  //turn to Uppercase

        isDuplicate = isIDExist(id,i);  //If Returns True if the Id Exists

    if(isDuplicate){  ////If Returns false if the Id Not Exists
      cout << "ID has been taken. Please reenter.";
    }

}   while(isDuplicate);
	    participant[i].id = id;
		  registration(i);
	        size++;  //To confirm the size of the number of participants (If the registration is not too many, the program will not run every 50 times)
		      i++;  //to check the limit of participants not more than 50   
				break;

	
}
	case 2:{
    int index=-1;
    string  Enrolment_Number;
	do {
      cout << "Enter participant ID to edit: ";  //Find  Enrolment_Number Exists or not
        cin >> Enrolment_Number;
          toUpperCase( Enrolment_Number);
    
    for (int i = 0; i <size; i++) {
      if (Enrolment_Number == participant[i].id) {
        index = i;
          break;
    }
}
        
    if(index == -1) {  //if entered id or Not valid will ask user to enter again
      cout << "Participant with ID " << Enrolment_Number << " not found" << endl;
    
	}
}   while (index == -1);       
	  participant[index].id = Enrolment_Number;
        registration(index);
          break;

}
    case 3:{
    do{
      cout<<endl<<setw(60)<<right<<"<<Badminton Tournament Registration System>> \n\n" ;
        cout<<"1) List all the participant \n";
       	  cout<<"2) Registration summary\n";
       	    cout<<"3) Back to Main Menu\n";
  	
		while(true){ //Dont allow user to enter 'd'or'@'......
		  cout<<"Enter Option: ";
          if(cin>>option2){
          	break;
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(); 
    }
				
}
    switch(option2){
    	char code;
    case 1:{  
	do {
      cout << "Please select the category (J/S/O) : ";  //Ask user to enter categorycode and print out the name
        cin >> code;
          toUpperCasechar(code);
    if (code != 'J' && code != 'S' && code != 'O') {
      cout << "Invalid Category Code\n";
   
    }
}   while (code != 'J' && code != 'S' && code != 'O');
	  int y=0;
	    for(int x=0;x<60;x++){
       	  if (participant[x].categoryCode==code){
       	    switch(participant[x].categoryCode){
       	      case 'J' : {
       		    cout << ++y << ". ";
				  cout << participant[x].name << endl;
				    break;
}
									
	case 'S' : {
	  cout << ++y << ". ";
	    cout << participant[x].name << endl;
		  break;
}
	case 'O' : {
	  cout << ++y << ". ";
		cout << participant[x].name << endl;
		  break;
					
		    }
       
	    }
	
    }

}
    break; 
							

							    	     
}   case 2:{   //Cout the total price and number of people
	  double fees[3]={35,40,50};
	    cout << "Registration Summary\n" << "_____________________________________________\n";
		  cout << setw(10) << left << "Junior";
		    cout << setw(12) << right << category.codeJ;
			  cout << setw(10) << right << "RM " <<category.codeJ*fees[0]<<" ";
												
	for(int a=0;a<category.codeJ;a++){
	  cout<< "*";
}						
	cout << endl;
	  cout << setw(10) << left << "Senior";
		cout << setw(12) << right <<category.codeS;
		  cout << setw(10) << right << "RM " <<category.codeS*fees[1]<<" ";
							
	for(int b=0; b<	category.codeS; b++){
	  cout<< "*";
}
							
	cout << endl;
	  cout << setw(10) << left << "Open";
	    cout << setw(12) << right << category.codeO;
		  cout << setw(10) << right << "RM " <<category.codeO*fees[2]<<" ";
							
	for(int c=0; c<	category.codeO; c++){
	  cout<< "*";
}	
	  cout<<"\n_____________________________________________";				

}
	case 3:{  //Byebye....
	  break;

	}
	default:{
		cout<<"Invalid Option.";
		break;
	}				     			      			      										   
}
       		
}while(option2!=3); //end loop
break;

}   case 4:{  //if user enter 4d or something else will having eror(receipt won't print)
      cout << "Program ends.";
	    print(size); //while ending the program print out the receipt
          exit(0);


}   default:{  //if input is Invalid
      cout<<"Invalid Input, Try again.\n";
        break;

        }


	}


}

     
     return 0;
}
void Temporary_registration_records(){
	int id= 2097443;
	int contact_number=1164514329;
	int day=2;
	int month=3;
	int year=2023;
	char member='Y';
    for(int i = 0; i < 10; i++) {
        int num = id + random();
        participant[i].id = "P" + std::to_string(num);
        int phone=contact_number+random();
        participant[i].contactNo="0"+std::to_string(phone);
        participant[i].day=day;
        participant[i].month=month;
        participant[i].year=year;
        participant[i].member=member;
        participant[i].receipt='Y';
        
          
    }
     participant[0].name="Dane Henry";
     participant[1].name="Rafael Garza";
     participant[2].name="Liliana Lin";
     participant[3].name="Sydney Cooley";
     participant[4].name="Gretchen Larson";
     participant[5].name="Grayson Haney";
     participant[6].name="Kianna Mccormick";
     participant[7].name="Giovani Trujillo";
     participant[8].name="Madeline Hendricks";
     participant[9].name="Fatima Vargas";
     
     participant[0].age=7;
     participant[1].age=13;
     participant[2].age=22;
     participant[3].age=16;
     participant[4].age=42;
     participant[5].age=15;
     participant[6].age=17;
     participant[7].age=9;
     participant[8].age=11;
     participant[9].age=13;
     
     participant[0].categoryCode='J';
     participant[1].categoryCode='S';
     participant[2].categoryCode='O';
     participant[3].categoryCode='S';
     participant[4].categoryCode='O';
     participant[5].categoryCode='S';
     participant[6].categoryCode='S';
     participant[7].categoryCode='J';
     participant[8].categoryCode='J';
     participant[9].categoryCode='S';
     category.codeS+=5; 
     category.codeJ+=3; 
     category.codeO+=2; 
}
int random()
{
	return rand()%35+5;
}

bool valid_or_not(char categoryCode,int age)  //Check the categoryCode Valid or Not
{                                    //If the condition is Valid, it will return False 
                                //else will return true and ask user to enter again
    switch(categoryCode)
{
    case 'J':{
    if(age>0 && age<=12){
		    return false;
    	      break;
}   else{       
        return true;
		  break;
	}
			
}
			   
	case'S':{
	if(age>=13 && age<=17){
		return false;
		  break;
}   else{
	  return true;
		break;
	}
			
}
	case'O':{
	if(age>0){
	  return false;
	    break;
}   else{
	  return true;
		 break;
    }
			
}
		
	default:{	
    return true;
	  break;
}
			
		
	}
}

bool isIDExist(string id, int size)  //Find if the Id Exists or not
{
    for(int i=0;i<size;i++){
        if(participant[i].id == id){
          return true;  //If Returns True if the Id Exists
        }
    }
    return false;  //If Returns False if the Id Not Exists
}

void toUpperCase(string& str)  //Change STRING to UpperCase
{
    for (char& c : str) {
      c = toupper(c);
    }
}
void toUpperCasechar(char& c){  //Change CHAR to UpperCase
  c= toupper(c);  
}

bool is_input_valid(int num) {
    return isdigit(num);
}

int registration(int i){
	
	bool categoryCode;
	
	  cout<<"Enter Name:";  //Ask User to input name 
	    cin.ignore();
	      getline(cin,participant[i].name);
		    toUpperCase(participant[i].name); //Change LowerCase to Uppercase

	while(true){   //Dont allow user to enter 'd'or'@'...... (still having bug can enter something like '3d")	   	         
    cout<<"Enter Age: ";
      if(cin>>participant[i].age){
        if(participant[i].age>0){
    	  break;
}   else{
			cout<<"The age must more then 0\n";
		}
	}else{
	cout << "Invalid input\n";
   cin.clear(); // clear the error state
    cin.ignore(); // discard any input in the buffer
}
     
}
	  cout<<"Enter Contact Number:";  //Ask user to input Contact Number
	    cin.ignore();
		    getline(cin,participant[i].contactNo);

	 if(participant[i].categoryCode=='S'){  //This code only works when the user edits
       category.codeS--;  	
	   }if(participant[i].categoryCode=='J'){
	   	category.codeJ--;
	   }if(participant[i].categoryCode=='O'){
	   category.codeO--;
	   }

	do
{     cout << "J for Junior (age below 12), S for Senior (13 to 17) and O for Open (any).\n";
      cout<<"Enter Category Code(J/S/O):";  //Ask User to input categoryCode
        cin>>participant[i].categoryCode;
          toUpperCasechar(participant[i].categoryCode);  //Change the categoryCode to Uppercase 
		    categoryCode=valid_or_not(participant[i].categoryCode,participant[i].age);  //Put categoryCode to valid_or_not
    	
		if(categoryCode){  //If CategoryCode Invalid will Ask User to input again ( When CategoryCode is true)
    	  cout << "Invalid Category Code" << endl;
    }  
    	      
}
while(categoryCode);  //When CategoryCode is False will get out the Do-while loop
       if(participant[i].categoryCode=='S'){
       category.codeS++;  	
	   }if(participant[i].categoryCode=='J'){
	   	category.codeJ++;
	   }if(participant[i].categoryCode=='O'){
	   category.codeO++;
	   }

    cout << "Enter Enrolment Date (xx/xx/xxxx):\n";  //Ask user to enter to date
    do {
      cout << "Month:";  //We change the date to this, because if we do date as string will apparate alot of problem [something like(33@544/312)] User will destroy the logic of date
        cin >> participant[i].month;
    if(participant[i].month < 1 || participant[i].month > 12) {
      cout << "Please enter a valid month (1-12)\n";
    }
} while(participant[i].month < 1 || participant[i].month > 12);

    do {
      cout << "Day:";
        cin >> participant[i].day;
    if(participant[i].day < 1 || participant[i].day > 31) {
       cout << "Please enter a valid day (1-31)\n";
    }
    if(participant[i].month == 2 && participant[i].day > 28) { //**
       cout << "February only has 28 days\n";
    }
} while(participant[i].month == 2 && participant[i].day > 28 || (participant[i].day < 1 || participant[i].day > 31));
   do{
    cout << "Year:";
    cin >> participant[i].year;	
    if(participant[i].year<2020||participant[i].year>2030){
    	cout<<"Please input correct the numebr of year\n";

	}
}while(participant[i].year<2020||participant[i].year>2030);

do {  //Ask if the user is a member
    cout << "Is the participant a member? [Y/N]: ";
    cin >> participant[i].member;
    toUpperCasechar(participant[i].member);

    if (participant[i].member != 'Y' && participant[i].member != 'N') {
        cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
    }  
} while (participant[i].member != 'Y' && participant[i].member != 'N');
	                 
	do {  //ask if the user want print receipt 
    cout << "Do you want to generate a receipt? [Y/N]: ";
    cin >> participant[i].receipt;
    toUpperCasechar(participant[i].receipt);

    if (participant[i].receipt != 'Y' && participant[i].receipt != 'N') {
        cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
    }
} while (participant[i].receipt != 'Y' && participant[i].receipt != 'N');

	    


}

void print(int size) {
    for(int i=0; i<size; i++){  //print out receipt
    	if(participant[i].receipt=='Y'){
        ofstream receipt("receipt_" + to_string(i+1) + ".txt"); //
        receipt << fixed << setprecision(2);
        receipt << "INTI Badminton Tournament Registration Slip\n";
        receipt << "*******************************************\n";
        receipt << "Enrolment number : " << participant[i].id;
        receipt << setw(80) << right << "Date : " << participant[i].day << "/" << participant[i].month << "/" <<participant[i]. year << endl << endl;
        receipt << setw(20) << left << "Name";
        receipt << ":";
        receipt << setw(50) << right << participant[i].name << endl;
        receipt << setw(20) << left << "Age";
        receipt << ":";
        receipt << setw(50) << right << participant[i].age << endl;
        receipt << setw(20) << left << "Contact Number";
        receipt << ":";
        receipt << setw(50) << right << participant[i].contactNo << endl;
        receipt << setw(20) << left << "Member";
        receipt << ":";
        if (participant[i].member=='Y'){
            receipt << setw(50) << right << "Yes" << endl << endl;
          
        } else {
            receipt << setw(50) << right << "No" << endl << endl;
        
        }
        receipt << setw(20) << left << "Description";
        receipt << setw(52) << right << "Fees (RM)\n";
        switch (participant[i].categoryCode){
            case 'J': {
                receipt << setw(20) << left << "Junior";
                break;
            }
            case 'S' : {
                receipt << setw(20) << left << "Senior";
				break;
            }
            case 'O' : {
                receipt << setw(20) << left << "Open";
				break;
            }
        }
        
        calcalation(i);
            receipt << setw(50) << right << price[i].befDiscount << endl;
                	receipt << setw(20) << left << "Discount";
                	receipt << setw(50) << right << price[i].discount  << endl;
                	receipt << setw(20) << left << "Total Payment";
                	receipt << setw(50) << right << price[i].aftDiscount << endl << endl;
                	receipt << "All the best and good luck !";
 
            receipt.close();

	    }
	   
	}  

}

void calcalation(int i ){  //An independent computing function
		 if(participant[i].categoryCode=='J'){
		 	price[i].befDiscount=35;
		 }if(participant[i].categoryCode=='S'){
		 	price[i].befDiscount=40;
		 }if(participant[i].categoryCode=='O'){
		 	price[i].befDiscount=50;
		 }
		 
	     if(participant[i].member=='Y'){
	     	price[i].discount=price[i].befDiscount*0.1;
		 }if(participant[i].member=='N'){
		 	price[i].discount=0;
		 }	 
	 price[i].aftDiscount=price[i].befDiscount-price[i].discount;
	}
//we giving price having an array, This will not lead to calculation errors
//maybe having another better way.....
/*
If you want to edit the first 10 registration records
There is information below

0
name:Dane Henry
id:P2097454
age:7
contactnumber:01164514356
member:Y
categoryCode:J
receipt:N
date:2/3/2023

1
name:Rafael Garza
id:P2097482
age:13
contactnumber:01164514339
member:Y
categoryCode:S
receipt:N
date:2/3/2023

2
name:Liliana Lin
id:P2097472
age:22
contactnumber:01164514343
member:Y
categoryCode:O
receipt:N
date:2/3/2023

3
name:Sydney Cooley
id:P2097481
age:16
contactnumber:01164514362
member:Y
categoryCode:S
receipt:N
date:2/3/2023

4
name:Gretchen Larson
id:P2097460
age:42
contactnumber:01164514368
member:Y
categoryCode:O
receipt:N
date:2/3/2023

5
name:Grayson Haney
id:P2097448
age:15
contactnumber:01164514339
member:Y
categoryCode:S
receipt:N
date:2/3/2023

6
name:Kianna Mccormick
id:P2097454
age:17
contactnumber:01164514361
member:Y
categoryCode:S
receipt:N
date:2/3/2023

7
name:Giovani Trujillo
id:P2097469
age:9
contactnumber:01164514335
member:Y
categoryCode:J
receipt:N
date:2/3/2023

8
name:Madeline Hendricks
id:P2097468
age:11
contactnumber:01164514341
member:Y
categoryCode:J
receipt:N
date:2/3/2023

9
name:Fatima Vargas
id:P2097480
age:13
contactnumber:01164514345
member:Y
categoryCode:S
receipt:N
date:2/3/2023
*/








