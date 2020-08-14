#include<iostream>
#include<cstring>
#include<cstdlib>
#define MAX_DATA_SIZE 1000
#define SIZE 10

using namespace std;


/* ################################################################################################
 * # This program contain lot of options such as Sum of n numbers,                                #
 * #  List, Stack, Queue, Binary search, Selection Sort, Merge Sort, sequential search and        #    
 * #  Tree travsersal                                                                             #
 * # The options are going to be developped one after an other.                                   #
 * #                                                                                              #
 * # The program will be compiled before to run it in the linux terminal.                         #
 * #  example : compilation: g++ -o sum 2020-cci-05-pract-Makan-Garba-DIARISSO.cpp                #
 * #  to run it, use the compiled file.                                                           #
 * #  example : ./sum                                                                             #
 * #                                                                                              #
 * # ##############################################################################################
 * 
 * 
 * 
 * 
 * ##################################################################################################
 * FUNCTION SUM
 *  This will calculate the sum of of "n" numbers.
 * The n is a random integer like 10 or 20 given by the user.
 * example: when the user type 10, the function will do 1+2+3+4+5+6+7+8+9+10 and return the sum (55).
 
 *##################################################################################################
*/
int sum_of_n_numbers(int n) {//function declaration (begnning)
 
  int s=0 ; //initialization of the sum "s"
  for(int i=1;i<=n;i++) // the for loop will search all the values from 1 to n using the i variable an
    s=s+i; //the sum of the values 
  return s; //the funtion will return the sum.
  
 } //end function sum_of_n_numbers


// Calling the function sum_of_n_numbers

void Sum() {// the main method is the one used to call functions (beginning)
  
  cout<<"\n-----------------------------------------";
  cout<<"\n|     Welcome to the function  sum       |";
  cout<<"\n-----------------------------------------";
  int n; //declaration of the vairiable n
  cout<<"\n ";
  cout << "\nEnter a number :"; // the program will ask the user to type a number
  
  cin >> n; // the computer will read the typed number 
  
  if (n <= 0){ //test if the typed number is less than or equals to 0
    
    cout<<"Please type a positive number :"; //when the condition above is true, this message will appear.
    cin >>n; //the computer will now read the new integer
    
    int sum = sum_of_n_numbers(n); // assignment of the functions result to the variable sum.
    cout << "\nThe sum of the numbers from 1 to " <<n<< " is " << sum << endl; // this command is to print out the result of the function.
    }
   
    else{ //this code will be directely executed if time the user type a number greater than 0 at the first
      int sum = sum_of_n_numbers(n);
      cout << "\nThe sum of the numbers from 1 to " <<n<< " is " << sum << endl;
    }
  
 
}

// ####################################################
// #   The following section implements List.         #
// ####################################################

  class ListType{//class declaration
  public: // public variables
    ListType(int n){
     MAX_ITEMS = n;
     nbItems =0;
    };
    
    // Make the list empty or delete all the list content
    
    void MakeEmpty(){
      nbItems =0;
    };
    
    //check if the list is empty
    
    bool IsEmpty() const {
      return (nbItems == 0);
    };
    
    //check if the list is full
    
    bool IsFull() const{
      return(nbItems ==  MAX_ITEMS - 1);
    };
    
    // find the position of a given node in the list
    
    void FindNode(int searchItem){
      int i = 0;
      while (!((items[i] == searchItem) || (i > nbItems)))
        i++;
      if(i > nbItems)
        cout <<"\nThe item :"<<searchItem<<" is not found !\n";
      else cout<<"\nThe item :"<<searchItem<<" is found at position " << i << "\n";
    };
    
    //insert a node at a particular position in the list
    
   void InsertNode(int pos, int newItem){
     if(!(nbItems == MAX_ITEMS -1)){
       for(int i = nbItems; i > pos; i--)
         items[i] = items[i-1];
       items[pos] = newItem;
       nbItems++;
       
     }
   };
   
   //delet a given node using its index position
   
   void DeleteNode(int pos){
     if(!(nbItems == 0)){
       for(int i = pos; i < nbItems; i++)
         items[i] = items[i+1];
       items[MAX_ITEMS - 1] = 0;
       nbItems--;
     }
   };
   
   //The number of elements in the  list.
   
   int NbElements(){
     return nbItems;
   }
   
   // The List size
   
   int Size(){
     return MAX_ITEMS;
   }
   
   //display the list content
   
   void Display() {
     cout << "\nThe Queue size is " <<Size()<< " but the items actually inside are "  <<NbElements()<< " :\n"; 
     for(int i=0; i < nbItems; i++)
       cout <<"\n"<<i<<"\t"<<items[i]<<"\n";
     };
   
   //fill the list with random values
   
   void RandomNode(){
     for(int i = 0; i< MAX_ITEMS; i++) items[i] = rand()%100+1;
     nbItems = MAX_ITEMS;
   };
   
  ~ListType(){} // class destructor
  
  private : //private variables
    int MAX_ITEMS, nbItems;
    int items[MAX_DATA_SIZE];
  };

//CALLING THE FUNCTION

void List(){
  
char option ='+'; // character declaration
int size=0; //initialize the the list size

//Home Menu ----------------------------------------------

cout<<"\n---------------------------------------- ";
cout <<"\n| Welcome to the list function        |";
cout<<"\n----------------------------------------";
cout<<"\n";
cout<<"\nEnter the size of the list : ";
cin>>size; //let the user enter the list size
ListType list(size); // create a list with the typed size
cout<<"\n------------------------";

//home menu options-------

while(!(option=='s')){  
  cout << "\nSelect a List operation : ";
  cout<<"\n------------------------";
  cout << "\n1 : Create a list";
  cout << "\n2 : Insert a new item";
  cout << "\n3 : Delete an item";
  cout << "\n4 : Find an item";
  cout << "\n5 : Empty the list";
  cout << "\n6 : Test whether the list is empty";
  cout << "\n7 : Test whether the list is full";
  cout << "\n8: Fill the list randomly";
  cout << "\n9 : Display the content of the list";
  cout << "\ns : Stop";
  cout << "\nEnter option : ";
  cin >> option; //let the user enter a character---------
  
  //options implementation------------------------------
  
  switch(option){ 
  
  //option Create a list
  
  case'1':{ListType list(size); break;}
    
    //option Insert an item
    
  case '2': {
    int pos, item;
    cout<<"\nEnter a position and an item :";
    cin>>pos>>item;
    list.InsertNode(pos, item); break;
  }
    
    //option  Delete an item 
    
  case '3':{
    int pos;
    cout<<"n\Enter the position of an item to delete : ";
    cin >> pos;
    list.DeleteNode(pos); break;
  }
    
    //option Find an item
    
  case '4': {
    int item;
    cout << "\nEnter the item to find : ";
    cin >> item;
    list.FindNode(item);
    break; 
  }
    
    //option Make the list Empty
    
  case '5': {list.MakeEmpty(); cout << "\nThe list is emptied\n"; break;}
    
    //option Test whether the list is empty-------
    
  case '6': {if (list.IsEmpty()) cout << "\nThe list is empty\n";
  
   else cout << "\nThe list is not empty\n"; break;}
    
    //option Test whether the list is full-------
    
  case '7': {if (list.IsFull()) cout << "\nThe list is full\n"; 
  
  else cout << "\nThe list is not full\n"; break;}
    
    //option Fill the list randomly-------
    
  case '8': {list.RandomNode(); break;}
    
    //option Display the content of the list
    
  case '9': {list.Display(); break;}
    
    //option stop
    
    s:; 
  }
}

}

//########################################################
//#                Stack function                         #
//########################################################

 

 class StackType{
   
   
   int top;
   int count;
  
   
 public: //public variables--------------
   
   ~StackType(){}; //destructor
   
   // Stack initialization
   StackType(int size){ //clas constructure
     
     capacity = size;
     top = -1;
     count = 0;
     
     
   }
   
   
   //remove the stack top--------------------  
   
   void Pop(){
     if(IsEmpty()){
       cout<<"\nThe stack is empty. '\n";
       exit(EXIT_FAILURE);
     }
     cout<<"\nRemoving "<<arr[top]<<"\n";
     top--; 
     count--;
   }
   
   //add an item--------------------  
   
   void Push(int item){
     if(IsFull()){
       cout<<"\nThe stack is full. '\n";
       exit(EXIT_FAILURE);
     }
     cout<<item<<" Inserted\n";
     ++top;
     arr[top] = item;
     count++;
     
     
   }
   
   //make empty the stack--------------------  
   
   void MakeEmpty(){
     top = -1;
   };
   
   //return top element --------------------  
   
   int Peek(){
     if(IsEmpty()){
       cout<<"\nThe stack is empty.\n";
       exit(EXIT_FAILURE);
     }
     cout<<"\nThe stack top is : ";
     return arr[top];
     
   }
   
   // The number of elements in the stack---------------
   
   int NbElements(){
     return count;
   }
   
   //stack size--------------------  
   
   int size(){
     return capacity;
   }
   
   //Display the stack--------------------   
   
   void Display(){
     cout << "\nThe Stack size is " <<size()<< " and the items actually inside are "  <<NbElements()<< " :\n"; 
     if(top>=0){
       for ( int i=0; i <=top; i++)
         cout << "\n " << i << "\t" <<arr[i] <<"\n";
       
       
     }
   };
   //check if the stack is empty--------------------  
   
   bool IsEmpty(){
     return (top == -1);
   }
   //check if the stack is full
   
   bool IsFull(){
     return (top == capacity-1);
   }
 private : 
   int capacity;
   int arr[MAX_DATA_SIZE];
 };
 void Stack(){
   
   //Home Menu-----------------------------------
   
   cout<<"\n-----------------------------------------";
   cout<<"\n|     Welcome to the Stack function     |";
   cout<<"\n-----------------------------------------";
   cout<<"\n ";
   char option = '+'; //character declaration  
   int size = 0; // stack size initialization
   cout <<"\nEnter the stack size :\n";
   cin >> size; //this will let the user enter the stack size-------- 
   StackType s(size); //create a stack with the typed size
   cout<<"\n------------------------";
   
   // Menu options----------
   
   while (option != 's'){ 
     cout<<("\nSelect a stack operation :\n");
     cout<<"\n------------------------";
     cout<<"\n1 : Create a stack.\n ";
     cout<<"\n2 : Insert a new item.\n ";
     cout<<"\n3 : Get the stack top.\n ";
     cout<<"\n4 : Remove the stack top.\n ";
     cout<<"\n5 : Empty the stack .\n ";
     cout<<"\n6 : Test wether the stack is empty or not.\n ";
     cout<<"\n7 : Test wether the stack is full or not.\n ";
     cout<<"\n8 : Display the stack content.\n ";
     cout<<"\nS : Stop.\n ";
     cout<<"\nEnter an option.\n ";
     cin>> option;//this will let the user select one option.---------------
     
     //option implementation --------------------  ------
     
     switch(option){
     
     //option create a stack
     
     case '1' : { int  s(size);
       cout<<"\n Stack created.\n";break;}
       
       //option Insert a new item
       
     case '2' : {
       int item;
       cout<<"\nEnter an item :\n";
       cin >> item;
       s.Push(item); break;}
       
       //option Get the stack top---------
       
     case '3': {
       cout<<s.Peek()<<"\n";break;
     }
       
       //option Remove the stack top-------  
       
     case '4': {
       s.Pop(); 
       cout<<"\nTop removed.\n";break;
     }
       
       //option Empty the stack------------
       
     case '5' : {s.MakeEmpty(); 
       cout<<"\nStack emptied.\n"; break;}
       
       //option Test wether the stack is empty or not------------
       
     case '6' : {if(s.IsEmpty())
       cout<<"\nThe stack is empty.\n";
     else cout<<"\nThe stack is not empty.\n"; break;}
       
       //option Test wether the stack is full or not------------
       
     case '7' : {if(s.IsFull())
       cout<<"\nThe stack is full.\n";
     else cout<<"\nThe stack is not full.\n"; break;}
       
       //option Dispaly the stack content------------
       
     case '8' : {s.Display(); break;
     
     //option stop
     
     s:;
     }
       
     } 
     
   }
 }
//########################################################
//#                Queue function                         #
//########################################################

class QueueType{ // class declaration
  
  
  int front;
  int rear;
  int count;
  
public: //public variables
  
  ~QueueType(){}; //destructor
  
  
  // queue initialization--------------------  
  
  QueueType(int size){ //class constructor
    capacity = size;
    front = -1;
    rear = -1;
    count = 0;
    
  }
  
  //remove the queue front--------------------  
  
  void Dequeue(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty. '\n";
      exit(EXIT_FAILURE);
    }
    cout<<"\nRemoving "<<arr[front]<<"\n";
    
    if(front == rear)
    {
      front = -1;
      rear = -1;
    }
    else {if (front == capacity - 1)
      front = 0;
    
    }
    
    
    front++;
    count--;
    
  }
  
  //add an item---------------------------------
  
  void Enqueue(int item){
    if(IsFull()){
      cout<<"\nThe queue is full. '\n";
      exit(EXIT_FAILURE);
    }
    else if (front == -1)
    {
      cout<<item<<" Inserted\n";
      front =  0;
      rear = 0 ; 
      arr[rear] = item;
    }
    else if(rear == capacity-1 && front != 0)
    {
      cout<<item<<" Inserted\n";
      rear = 0;
      arr[rear] = item;
    }
    else 
      cout<<item<<" Inserted\n";
    rear = rear + 1;
    arr[rear] = item;
    count++;
  }
  
  //make empty the queue---------------------------------
  
  void MakeEmpty(){
    front = rear=-1;
    count = - 1;
  };
  
  //return front element---------------------------------
  
  int Peek(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty.\n";
      exit(EXIT_FAILURE);
    }
    return arr[front];
    
  }
  
  //The number of elements in the  queue.---------------------------------
  
  int NbElements(){
    return count+1;
  }
  
  //queue size---------------------------------
  
  int Size(){
    return capacity;
  }
  void Display(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty\n";
    }
    cout << "\nThe Queue size is " <<Size()<< " but the items actually inside are "  <<NbElements()<< " :\n"; 
    if(rear >= front){
      for (int i=front; i <= rear; i++)
        cout << "\n " << i << "\t" << arr[i] <<"\n";
      
    }
    else
    {
      for(int i=front; i < capacity - 1; i++)
        cout << "\n " << i << "\t" << arr[i] <<"\n";  
      
      for(int i = 0; i <= rear; i++)
        cout << "\n " << i << "\t" << arr[i] <<"\n";  
    }
    
  };
  
  //check if the queue is empty---------------------------------
  
  bool IsEmpty(){
    return front==-1;
  }
  
  //check if the queue is full---------------------------------
  
  bool IsFull(){
    return ((rear == capacity-1 && front == 0) || (front == (rear + 1) % (capacity-1)));
  }
private :
  int capacity;
  int arr[MAX_DATA_SIZE];
  
};
 
// calling the QueueType using the void method ------------------------

void Queue(){
  
  //Home Menu-------------------------------------------------------
  
  cout<<"\n-----------------------------------------";
  cout<<"\n|     Welcome to the Queue function     |\n";
  cout<<"\n-----------------------------------------";
  cout<<"\n ";
  char option = '+'; //character declaration
  int size = 0; //queue size initialization
  cout <<"\nEnter the queue size :\n";
  cin >> size; // this will let the user type the queue size
  QueueType q(size); //create a queue with the typed size
  cout<<"\n------------------------\n";
// Queue operations defintions --------------------------------------
  while (option != 's'){
    cout<<("\nSelect a queue operation :\n");
    cout<<"\n------------------------";
    cout<<"\n1 : Create a queue.\n ";
    cout<<"\n2 : Insert a new item.\n ";
    cout<<"\n3 : Get the queue front.\n ";
    cout<<"\n4 : Remove the queue front.\n ";
    cout<<"\n5 : Empty the queue .\n ";
    cout<<"\n6 : Test wether the queue is empty or not.\n ";
    cout<<"\n7 : Test wether the queue is full or not.\n ";
    cout<<"\n8 : Display the queue content.\n ";
    cout<<"\nS : Stop.\n ";
    cout<<"\nEnter an option.\n ";
    cin>> option; // this will let the user chose an option
    
    //option implementation -----------------------------------
    
    switch(option){
    
    //option create a queue
    
    case '1' : { QueueType q(size);
      cout<<"\n Queue created.\n";break;}
      
      //option Insert a new item
      
    case '2' : {
      int item;
      cout<<"\nEnter an item :\n";
      cin >> item;
      q.Enqueue(item); break;}
      
      //option Get the que front
      
    case '3': {
      cout<<"\nThe queue front is : "<<q.Peek()<<"\n";break;
    }
      
      //option Remove the queue front
      
    case '4': {
      q.Dequeue(); 
      cout<<"\nFront removed.\n";break;
    }
      
      //option Empty the queue
      
    case '5' : {q.MakeEmpty(); 
      cout<<"\nQueue emptied.\n"; break;}
      
      //option Test wether the queue is empty or not.
      
    case '6' : {if(q.IsEmpty())
      cout<<"\nThe queue is empty.\n";
    else cout<<"\nThe queue is not empty.\n"; break;}
      
      //option Test wether the queue is full or not.
      
    case '7' : {if(q.IsFull())
      cout<<"\nThe queue is full.\n";
    else cout<<"\nThe queue is not full.\n"; break;}
      
      // option Display the queue content
      
    case '8' : { 
      q.Display();break;}
      
      // option stop
      
    s:;
    }
      
    } 
    
}


//########################################################
//#                Selection Sort function               #
//########################################################

// swapping method This method -----------------------------------
void swaping(int *n1, int *n2){
  int temp;
  temp=*n1;
  *n1=*n2;
  *n2=temp;
}

//Displaying method. This method is also used in mergeSort function--------------------------------------
void display(int *Arr, int n){
  
  for(int i=0; i<n; i++){
    cout << Arr[i] << " "<< endl;
  }
}
// function writting --------------------------------------
void selectionSort(int *Arr, int n){
  int i, j, imin; //declaration of variables
  for(i=0; i<n-1; i++){
    imin=i; //get the index of minimum data
    for(j=i+1; j<n; j++)
    if(Arr[j] < Arr[imin])
        imin = j;
    swaping(&Arr[imin], &Arr[i]);//placing in the right position
  
    
  }
}
// calling the function using the vid method --------------------------------------
void SelectionSort(){
  
  char choice = '+';
  cout<<"\n-----------------------------------------";
  cout<<"\n|     Welcome to the selection sort     |";
  cout<<"\n-----------------------------------------";
  cout<<"\n";
  int nb;
  cout <<"\nPlease Enter the list size : ";
  cin >> nb;
  int array[nb];
  while(choice!= 's'){
    cout<<"\nSelect an option : "<<endl;
    cout<<"\n1 : List to be sorted : ";
    cout<<"\n ";
    cout<<"\nS : Stop :\n ";
    cin >> choice;
    switch(choice){
    
    case '1' : {
  cout<<"   --------------------";
  cout <<"\nEnter elements :"<< endl;
  for(int i=0; i<nb; i++){
    cin >> array[i];
  }
  cout << "Array before Sorting : "<<endl;
  display(array, nb);
  selectionSort(array, nb);
  cout << "Array after Sorting : "<<endl;
  display(array, nb);
  
      };break;
      s:;
    }
  }
  return;
}

//########################################################
//#                 Merge sort                       #
//########################################################


// function delaration and definition -----------------------------------------------
void merge(int *Amer, int l, int m, int r){
  int i, j, f, nl, nr;
  //size of left and the right sub-arrays------------
  nl = m-l+1; 
  int larr[nl];
  nr = r-m;
  int rarr[nr];
  
  for(i=0; i<nl; i++)
    larr[i] = Amer[l+i];
  for(j=0; j<nr; j++)
    rarr[j] = Amer[m+j+1];
  i=0; j=0; f=l;
  
  //merge temp array to real array-----------------
  
  while(i < nl and j < nr){
    if(larr[i] <= rarr[j]) {
      Amer[f] = larr[i]; i++;
    }else{
      Amer[f] = rarr[j] ; j++;   }
    f++;
  }
  
  //extra elements in left and right arrays--------------
  
  while(i<nl){
    Amer[f] = larr[i]; i++; f++;
  }
  while(j<nr){
    Amer[f] = rarr[j]; j++; f++;
  }
  
}
//merging sort method ------------------------------------------
void mergeSort(int *Amer, int l, int r){
  int m;
  if(l<r){
    int m = l+(r-l)/2;
    //sort the first and second array 
    mergeSort(Amer, l, m);
    mergeSort(Amer, m+1, r);
    merge(Amer, l, m, r);//array sorted
  }
}
//calling the function using the void method --------------------------------
void MergeSort(){
  char choice='+';
  cout<<"\n-------------------------------------";
  cout<<"\n|     Welcome to the merge sort     |";
  cout<<"\n-------------------------------------";
  int nb;
  cout<<"\n     ";
  cout << "\n Enter the length of the array : ";
  cin >>nb;
  int Amer[nb]; //create an array with typed number of elements
  cout<<" --------------------";
 
  while(choice!= 's'){
    cout<<"\nSelect an option : "<<endl;
    cout<<"\n1 : List to be sorted : ";
    cout<<"\n ";
    cout<<"\nS : Stop :\n ";
    cout<<"------------\n ";
    cin >> choice;
    switch(choice){
    
    case '1' : {
    
  cout <<"\nPlease Enter the items : " <<endl;
  for(int i=0; i<nb; i++){
    cin >>Amer[i];
  }
  cout <<"Array before sorting : \n" ;
  display(Amer, nb);
  mergeSort(Amer, 0, nb-1);
  cout <<"Array after sorting : \n";
  display(Amer, nb);
}; break;
s:;
    }
  }
}
//##########################################################################
//#                               Sequential search                         #
//###########################################################################

//sequential search method --------------------------------
int seqSearch(int Seq[], int t, int nbs){
  bool found=false;
  int pos=-1;
  for(int i=nbs; i>=0 and found != true; i--)
    if(t == Seq[i]){
      pos=i;
      found=true;
    }
    return pos;
}
//calling the function using the void method --------------------------------
void SeqSearch(){
  char choice='+';
  cout<<"\n-------------------------------------";
  cout<<"\n|  Welcome to the sequential search |";
  cout<<"\n-------------------------------------";
  int nbs;
  int pos;
  int val;
  cout<<"\n    ";
  cout<<"\nEnter the number of elements : "; //the user should type a value
  cin >> nbs;
  cout<<"     --------------------";
  while(choice!= 's'){
    cout<<"\nSelect an option : "<<endl;
    cout<<"\n1 : Search list : ";
    cout<<"\n ";
    cout<<"\nS : Stop :\n ";
    cout<<"------------\n ";  
    cin >> choice;
    switch(choice){
    
    case '1' : {
      cout<<"\nEnter the list elements : \n";
  
  int Seq[nbs];
  for(int i=0; i<nbs; i++)
    cin>>Seq[i];
  cout <<"List content : "<<endl;
  display(Seq,nbs);
  cout<<"Give the element to be searched sequentially : ";
  cin>> val;
  
  pos=seqSearch(Seq, val, nbs);
  if(pos != -1)
    cout << "The target "<< val<<" was found at location : "<<pos<<"."<<endl;
  else 
    cout <<"Target "<< val<<" not found ! "<<endl<<"please type one of the values given above  "<<endl;
  cin>> val;
  
  pos=seqSearch(Seq, val, nbs);
  //if(pos != -1)
    cout << "The target "<< val<<" was found at location : "<<pos<<"."<<endl;
  
    }; break;
    s:;
   }
  }
}
  

//######################################################################################
//#                                Binary search                                       #
//######################################################################################

//calling the function using the void method --------------------------------
int BinarySearch(int *arr, int l, int r, int num){
  while(r<=l){
    int mid = l+ (r-l)/2;
    if(arr[mid] == num)
      return mid;
    if(arr[mid] < num)
      l = mid + 1;
     // return BinarySearch(arr, l, mid-1, num);
    //if(arr[mid] > num)
     
     else r = mid - 1;
       //return BinarySearch(arr, mid+1, r, num);
  }
  return -1;
}
//calling the function using the void method --------------------------------
void BinarySearch(void) {
  char choice='+';
  cout<<"\n-------------------------------------";
  cout<<"\n|  Welcome to the Binary search |";
  cout<<"\n-------------------------------------";
  int n, num;
  cout<<"\n ";
  cout<<"\nEnter the number of the array : ";
  cin>> n;
  int arr[n];
  cout<<"------------------";
  
  while(choice!= 's'){
  cout<<"\nSelect an option : "<<endl;
  cout<<"\n1 : Search list : ";
  cout<<"\n ";
  cout<<"\nS : Stop :\n ";
  cout<<" ----------\n";
  cin >> choice;
  switch(choice){
  
  case '1' : {
  cout<<"\nEnter the list items : \n";
  for(int i=0; i<n; i++) {
    cin >>arr[i];}
  int s = sizeof(arr) / sizeof(arr[0]);
  cout<<"Which number are you loking for ? "<<endl;
  cin>> num;
  int index = BinarySearch(arr, 0, n-1, num);
  if(index != -1)
    cout<<"The number "<<num<< " is present at index "<<index << " in the array.\n";
  else
    cout<<"The number "<<num<<" is not in the array ! \n Please type one of the given numbers above :";
  cin>> num;
  index = BinarySearch(arr, 0, n-1, num);
  // if(index != -1)
  cout<<"The number "<<num<< " is present at index "<<index << " in the array.\n";
  }; break;
  s:;
  }
  }
}
//#####################################################################################
//#                  Tree Prefix, Infix and Postfix function                          #
//#####################################################################################

class TreeN  {//node declaration
  public: char d;
    TreeN *lst, *rst;
    TreeN (char d) {
      this->d = d;
      this->lst = NULL;
      this->rst = NULL;
    }
};

class StackNod  {// stack declaration
  public: TreeN *treeN;
    StackNod *n;
    StackNod(TreeN *treeN)  {//constructor
      this->treeN = treeN;
      n = NULL;
    }
};

class ExpressionTree {
  private: StackNod *top;
    public: ExpressionTree() {
      top = NULL;
    }
      void clear() {
        top = NULL;
      }
      
      void push(TreeN *item) {
        if (top == NULL)
          top = new StackNod(item);
        else {
          StackNod *newitem = new StackNod(item);
          newitem->n = top;
          top = newitem;
        }
      }
      
      TreeN *pop() {
        if (!(top == NULL)){
          /*
           cout<<"Tree leaves reached"<<endl;
           } else {*/
          TreeN *newitem = top->treeN;
          top = top->n;
          return newitem;
        }
      }
      
      TreeN *peek() {
        return top->treeN;
      }
      
      void insert(char val) {
        if (isDigit(val)) {
          TreeN *newitem = new TreeN(val);
          push(newitem);
        } else if (isOperator(val)) {
          TreeN *newitem = new TreeN(val);
          newitem->lst = pop();
          newitem->rst= pop();
          push(newitem);
        } else {
          cout<<"Invalid Expression"<<endl;
          return;
        }
      } 
      
      bool isDigit(char c) {
        return c >= '0' && c <= '9';
      }
      
      bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
      }
      
      int toDigit(char c) {
        return c - '0';
      }
      
      void buildTree(string tree) {
        for (int i = tree.length() - 1; i >= 0; i--)
          insert(tree[i]);
      }
      
      void postfix() {
        postOrder(peek());
      }
      
      void infix() {
        inOrder(peek());
      }
      
      
      void prefix() {
        preOrder(peek());
      }
      
      
      void postOrder(TreeN*po) {
        if (po != NULL) {
          postOrder(po->lst);
          postOrder(po->rst);
          cout<<po->d;
        }
      }
      
      
      void inOrder(TreeN *io) {
        if (io != NULL) {
          inOrder(io->lst);
          cout<<io->d;
          inOrder(io->rst);
        }
      }
      
      void preOrder(TreeN *ptr) {
        if (ptr != NULL) {
          cout<<ptr->d;
          preOrder(ptr->lst);
          preOrder(ptr->rst);
        }
      }
}; 

void Tree()
  {   
  
  cout<<"\n-------------------------------------------";
  cout <<"\n| Welcome to the tree traversal function  |";
  cout<<"\n-------------------------------------------";
  cout<<"\n";
  char option ='+';
  char choice = '+';
  
  while(choice!= 's'){
    std::cout<<"\nSelect one of the menus below : ";
    cout<<"\n";
    std::cout<<"\n1 : Build your tree : ";
    std::cout<<"\ns : Stop :\n ";
    std::cin >> choice;
    switch(choice){
    
    case '1' : { string s;
      ExpressionTree ET;
      cout<<"\nEnter the tree elements : ";
      cin>>s;
      ET.buildTree(s);
      cout<<"\nPrefix : ";
      ET.prefix();
      cout<<"\n\nInfix : ";
      ET.infix();
      cout<<"\n\nPostfix : ";
      ET.postfix();cout<<"\n";
      break;}
      s:;
    }
  } 
}


//#####################################################################################
//#                                      Main program                                 #
//#####################################################################################

int main(){
  //variable declaration---------------------
  char choice = '+';
  char option = '+';
  //General menu content--------------------
  cout<<"\n---------------------------------------- ";
  cout <<"\n| Welcome to DIARISSO's program        |";
  cout<<"\n---------------------------------------- ";
  cout<<"\n ";
  while(!((choice == 'e') || (choice == 'e'))){
    cout<<"\nSelect one of the menus below\n";
    cout<<"\n-------------------------------";
    cout<<"\n N : Sum of n numbers";
    cout<<"\n L : List";
    cout<<"\n K : Stack ";
    cout<<"\n Q : Queue ";
    cout<<"\n R : Sequential Search";
    cout<<"\n B : Binary Search";
    cout<<"\n S : Selection Sort";
    cout<<"\n M : Merge Sort";
    cout<<"\n T : Tree traversal orders ";
    cout<< "\n E : Exit ";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    choice= toupper(choice);
    if(choice == 'N') Sum();
    else if(choice == 'S') SelectionSort();
    else if(choice == 'M') MergeSort();
    else if(choice == 'R') SeqSearch();
    else if(choice == 'B') BinarySearch();
    else if(choice == 'Q') Queue();
    else if(choice == 'K') Stack();
    else if(choice == 'T') Tree();
    else if(choice =='L') List();
    else if(choice == 'E') exit(0);
}
  return 0;
}

