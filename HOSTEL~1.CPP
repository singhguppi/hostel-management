 #include<iostream.h>
 #include<dos.h>
 #include<process.h>
 #include<conio.h>
 #include<string.h>
 #include<fstream.h>
 #include<stdio.h>
 #include<iomanip.h>
 class hostel
 {  public:  long int regino,rollno;
    char name[30] ,fathername[30],stream[30],address[30],branch[30];
    public:
    void getdata()
    {  clrscr();
    cout<<"\t\n enter the name = ";
    gets(name);
    cout<<"\t\n enter the father name =";
    gets(fathername);
    cout<<"\t\n enter the class = ";
    gets(stream);
    cout<<"\t\n enter the roll no = ";
    cin>>rollno;
    cout<<"\t\n enter the registeration no = ";
    cin>>regino;
    cout<<"\t\n enter the address = ";
    gets(address);
    cout<<"\t\n enter the branch = ";
    gets(branch);
 }
   void showdata()
   {

    cout<<setw(5)<<name<<setw(7)<<fathername<<setw(8)<<stream<<setw(11)<<rollno<<setw(13)<<regino<<setw(15)<<address<<setw(17)<<branch<<endl;

   }
 };
      void main()
      {
       clrscr();
       char pass[]="gggg",epass[20],ch;
       cd:
       int i=0;
       gotoxy(30,11);
       cout<<"enter password";
       gotoxy(30,12);


      ch=getch();
      while(ch!='\r')  {
      epass[i]=ch;
      cout<<"*";
      i++;
      ch=getch();
     }
     epass[i]='\0';
     if(strcmp(pass,epass)==0)  {
     clrscr();
     gotoxy(30,12);
     int h=0;
     cout<<"LOADING...";
     for(h=0;h<=4;h++)
     {
      delay(300);
      cout<<".";
      }
    }
     else  {
     clrscr();
     goto cd;
     }
     {
     clrscr();
     int s,d,cho,rn;
     bc:
     hostel st;
     cout<<"\n\t\t *******  HOSTEL  MANAGEMENT  ******";
     cout<<"\n\t\t * press 1 to check the menu:      *";
     cout<<"\n\t\t * press 2 for enter data:         *";
     cout<<"\n\t\t * press 3 to display information: *";
     cout<<"\n\t\t * press 4 to select room type:    *";
     cout<<"\n\t\t * press 5 to update information:  *";
     cout<<"\n\t\t * press 6 to deleted information: *";
     cout<<"\n\t\t * press 7 to exit:                *";
     cout<<"\n\t\t ***********************************";
     cout<< "\n\n\n\t\t\t enter the choice"<<endl;
     cin>>cho;
     switch (cho)
     {
       case 1:
       {
	clrscr();
	cout<<"((((((((((((((((((((((((***********)))))))))))))))))))))))))))"<<endl;
	cout<<"\t\n TOTAL ROOMS IN HOSTEL:30"<<endl;
	cout<<"\t"<<endl;


	cout<<"\t\n CHARGES FOR NON-AC ROOM:30000"<<endl;
	goto bc;
  }
   case 2:
   {
    clrscr();
    char ch='y';
    fstream out;
    out.open("stu3.DAT",ios::in|ios::out|ios::app|ios::binary);
    while(ch=='y')
      {
       st.getdata();
       out.write((char*) & st,sizeof(st));
       cout<<"want to enter more data(y/n)";
       cin>>ch;
       }
      cout<<setw(5)<<"name"<<setw(7)<<" father name"<<setw(8)<<"stream"<<setw(11)<<"roll no"<<setw(13)<<"regino"<<setw(15)<<"address"<<setw(17)<<"branch"<<endl;
      out.seekg(0,ios::beg);
      out.read((char*)&st,sizeof(st));
      while(out.eof()==0)
      {
      st.showdata();
      out.read((char*)&st,sizeof(st));
       }
	out.close();
	goto bc;
      }
      case 3:
      {
	clrscr();
	fstream in;
	in.open("stu3.DAT",ios::in|ios::out|ios::binary);
	cout<<setw(5)<<"name"<<setw(7)<<"  father name"<<setw(8)<<"stream"<<setw(10)<<"roll no"<<setw(11)<<"regino"<<setw(13)<<"address"<<setw(15)<<"branch"<<endl;
	in.seekg(0,ios::beg);
	in.read((char*)&st,sizeof(st));
	while(in.eof()==0)
	{
	 st.showdata();
	 in.read((char*) &st,sizeof(st));
	 }
	 in.close();
	 goto bc;
	 }

   case 4:
  {
   clrscr();

   cout<<"enter the room no from 1-30"<<endl;
   cin>>rn;
   if (rn<=5)
  {
  cout<<"room is single wth ac:";
  }
   else if(rn<=10)
     {
     cout<<" room is single without ac :";
     }
     else if(rn<=15)
     {
      cout<<" room is double with ac:";
     }
      else if(rn<=20)
     {
    cout<<"room is with without ac:";
      }
     else if(rn<=25)
    {
      cout<<"room is triple with ac:";
      }
    else if(rn<=30)
    {
     cout<<"room is triple without ac:";
     }
     else
     {
     cout<<"no more rooms are available:";
      }
      goto bc;

 }
   case 5:
     {
      int p,pos;
      clrscr();
      fstream h4;
      h4.open("stu3.DAT",ios::in|ios::out|ios::binary);

      cout<<"\nEnter the serial no you want to update : ";
      cin>>p;
      pos=(p-1)*sizeof(st);
      h4.seekp(pos,ios::beg);
      st.getdata();
      h4.write((char*)&st,sizeof(st));
      cout<<"\nRecord is updated";
      h4.close();
      getch();
      goto bc;


 }
 case 6:
 {   long nrollno;
     clrscr();
     fstream h5;
     fstream h6;
     h5.open("stu3.DAT",ios::in|ios::out|ios::binary);
     h6.open("newstu3.DAT",ios::out|ios::binary|ios::in);
     cout<<"enter the roll no to delete record";
     cin>>nrollno;
     h5.seekg(0,ios::beg);
     h5.read((char*)&st,sizeof(st));
     while(h5.eof()==0)
     {  if(nrollno!=st.rollno)
	   h6.write((char*)&st,sizeof(st));
	   h5.read((char*)&st,sizeof(st));
     }
      h5.close();
      h6.close();
      remove("stu3.DAT");
      rename("newstu3.DAT","stu3.DAT");
      h6.open("stu3.DAT",ios::in|ios::out|ios::binary);
      cout<<setw(5)<<"name"<<setw(7)<<"  father name"<<setw(8)<<"stream"<<setw(10)<<"roll no"<<setw(11)<<"regino"<<setw(13)<<"address"<<setw(15)<<"branch"<<endl;
      h6.seekg(0,ios::beg);
      h6.read((char*)&st,sizeof(st));
      while(h6.eof()==0)
      {  st.showdata();
      h6.read((char*)&st,sizeof(st));
      }

  goto bc;
  }
    case 7:
   {
     exit(0);
   }
     }

 getch();
 }
 }


