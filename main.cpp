# include <iostream>
using namespace std;
struct node{
	int num_input;	
	string answer;
    char compar;
	node* right;
	node* left;
	};
    node *newnode,*root,*r,*l,*rp,*lp;
    int x;
    int z=1;
    int guessed_num=84;
    int input_num;
    int right_repeat=0,left_repeat=0;
    float TDa,TDb,PTA,PTB,PAa,PAb,perfa,perfb;
    float num_of_tryA=0;
    float num_of_tryB=0;
    char Equal,greater_or_less,player;
    string ans;
    string m;
    string answer="X";

void addR(int x,char y){
	if (root==NULL){
	newnode=new node();
	root=newnode;
	r=newnode;
	l=newnode;
	newnode->right=NULL;
    newnode->left=NULL;
}
    newnode=new node();
    newnode->answer=ans;
    newnode->num_input=input_num;
    newnode->compar=y;
    r->right=newnode;
    newnode->right=NULL;
    r=newnode;
}

void addL(int x,char y){
    newnode=new node();
    newnode->answer=ans;
    newnode->num_input=x;
    newnode->compar=y;
    l->left=newnode;
    newnode->right=NULL;
    l=newnode;
}

void Rdisplay(){
   rp=root;
   rp=rp->right;
    while(rp!=NULL){
cout<<"player A:\n" ;
cout<<"is the number: "<<rp->compar<<"="<<rp->num_input<<"\n";
 cout<<"computer "<<rp->answer<<"\n";
    rp=rp->right;
    }
}

void Ldisplay(){
    lp=root;
    lp=lp->left;
    while(lp!=NULL){
    cout<<"player B:\n";
cout <<"is the number: "<<lp->compar<<"="<<lp->num_input<<"\n";
    cout<<"computer "<<lp->answer<<"\n";
    lp=lp->left;
	}
}

void calculation(char player){
	if (player=='A'){
TDa+=abs(guessed_num-input_num);
num_of_tryA++;
	}
else{
TDb+=abs(guessed_num-input_num);
num_of_tryB++;}
}

void display_Of_percent(){
  float n;
  n=num_of_tryA+num_of_tryB;
  
  PTA=100-((num_of_tryA/100)*100);
  PTB=100-((num_of_tryB/100)*100);
  
  
PAa=100-( (TDa/(((n*(n+1) )/2)-(((guessed_num-100)*guessed_num)+guessed_num))*100));

PAb=100-( (TDb/(((n*(n+1) )/2)-(((guessed_num-100)*guessed_num)+guessed_num))*100));




 perfa=(PTA+PAa)/2;
 perfb=(PTB+PAb)/2;






    }



void display(){
cout<<"\n\n\t\t\t\t\t\t|-----------------------|\n";
cout<<"\t\t\t\t\t\t|    guess The Number   |\n";
cout<<"\t\t\t\t\t\t|-----------------------|\n";
cout<<"\t\t\t\t\t\t|\t\t\t|\n\t\t\t\t\t\t|\t\t\t|\n";
cout<<"\t\t\t\t\t\t|\t\    "<<answer<<"    \t|\n\t\t\t\t\t\t|\t\t\t|\n";
cout<<"\t\t\t\t\t\t|_______________________|\n";
}

int check_input_wrong(){
    int wr;

if(greater_or_less!='>'&&Equal!='='||greater_or_less!='<'&&Equal!='='||greater_or_less!='='&&Equal!='='){
    cout<<"WRONG INPUT!\n";
    cout<<"hint! use only \">=number\"\"<=number\"\"==number\" \n";
    wr=true;
if(Equal == '=' && greater_or_less != '='){
    cout<<"WRONG INPUT!\n";
    cout<<"hint! use only \">=number\"\"<=number\"\"==number\" \n";
    wr=true;
     }
    }
    else{
    wr=false;

    }
    return wr;
    }

void check_answer(char player){
    int temp=0;
    temp=abs(input_num-guessed_num);

if(input_num==guessed_num){
    answer="78";
      system("cls");
         display();
         display_Of_percent();
         if(player=='A'){
 cout<<"\nRIGHT CONGRAT! your     performanc Gusing is: " <<perfa;
    cout<<"\nhistory\n";
     Rdisplay();
     cout<<"\t\t GAME END\n";
 cout<<"\nPlayer A Won within gusing performance of"<<PAa;
 cout<<"\nPlayer B lost within gusing performance of"<<PAb;
 }
 else{
 cout<<"\nRIGHT CONGRAT! your     performanc Gusing is: " <<perfb;
    cout<<"\nhistory\n";
  Ldisplay();
 cout<<"\nPlayer A Won within gusing performance of"<<PTB;
 cout<<"\nPlayer B lost within gusing performance of"<<PTA;
 		}
 
      exit(0);
 }
else if(greater_or_less=='>'&&input_num < guessed_num){
        cout <<"\nYES\n";
       ans="YES";
        }
else if(greater_or_less=='<'&&input_num > guessed_num){
           cout <<"YES";
           ans="YES";}
 else{
   cout<<"\nNO\n";
   ans="No";
 }
}

int main()
{
    do{
    back_point:
    display();
    if (z>1){
    Rdisplay();
    }
cout<<"player A:\n";
player ='A';
cout <<"is the number: ";
cin>>greater_or_less>>Equal>>input_num;

if(check_input_wrong()){
cout<<"if u got input any key\n";
cin>>m;
system("cls");
goto back_point;
}

z++;
calculation(player);
addR(input_num,greater_or_less);
check_answer(player);
cout<<"press any key to hide ur history";
cin>>m;
system("cls");


display();
if (z>2){
    Ldisplay();
    }
back_point_b:
player ='B';
cout<<"player B:\n";
cout <<"is the number: ";
cin>>greater_or_less>>Equal>>input_num;
if(check_input_wrong()){
cout<<"if u got input any key\n";
cin>>m;
system("cls");
}
calculation(player);
addL(input_num,greater_or_less);
check_answer(player);
cout<<"press any key to hide ur history";
cin>>m;
system("cls");
    }while(true);
}


e);
}


