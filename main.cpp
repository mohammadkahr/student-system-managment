#include <iostream>
#include <string>
#include <fstream>
using namespace std ;

struct student{
    string name ;
    string family ;
    long long int id ;
    string lessons[10] ;
    float points [10] ;
    float units[10] ;
    float average;
    int cou;
};

student studentList[100] ;
int num = 0 ;

int firstPrint();
void info_student();
void info_lesson();
void average();
void show_info();
void write();
void read();

int firstPrint(){
    cout << "*******************************************************************\n" ;
    cout << "*                                                                 *\n" ;
    cout << "*                      Mohammad Kazem Harandi                     *\n" ;
    cout << "*                          mohammad._.hr                          *\n" ;
    cout << "*                                                                 *\n" ;
    cout << "*******************************************************************\n" ;
    return 0 ;
}

void menu (){
    short select ;

    cout << endl << endl ;
    cout << "1.Enter info student \n" ;
    cout << "2.Enter info lesson \n" ;
    cout << "3.See average \n" ;
    cout << "4.Save your info \n" ;
    cout << "5.Load your info \n" ;
    cout << "6.Show info \n" ;
    cout << "7.Exit \n" ;
    cout << "Enter number : " ;
    cin >> select ;
    cout << endl << endl;
    if (select == 1){
        info_student();
    }
    else if (select == 2){
        info_lesson();
        average();
    }
    else if (select == 3){
        average();
    }
    else if (select == 4){
            write();
    }
    else if (select == 5){
        read();
    }
    else if (select == 6){
        show_info();
    }
    else if (select == 7){
        exit(0);
    }
    else{
        cout << "Wrong selection";
        menu();
    }
}

void info_student(){
    cout << "Enter ID : " ;
    cin >> studentList[num].id ;
    cout << endl;
    cout << "Enter name : " ;
    cout << endl;
    cin >> studentList[num].name ;
    cout << "Enter family : " ;
    cin >> studentList[num].family ;
    cout << endl;

    num ++ ;
    cout << "Information received";
    menu() ;
}

void info_lesson(){
    long long int idd ;
    int j ;
    int les = 0, sum=0;
    float sump=0;
    cout << "Enter Id : \n" ;
    cin >>idd ;
    bool bl = false ;
    for( j = 0 ; j <100 ; j++){
        if(studentList[j].id == idd ){
            bl = true ;
        }
    }
    if(bl){
        for( j = 0 ; j <100 ; j++){
            if(studentList[j].id == idd ){
                while(true){
                    cout << "Enter the name of lesson : " ;
                    cin >> studentList[j].lessons[les] ;
                    cout << "Enter the point of lesson : " ;
                    cin >> studentList[j].points[les] ;
                    cout << "Enter the unit of lesson : " ;
                    cin >> studentList[j].units[les] ;
                    sum += studentList[j].units[les];
                    sump += (studentList[j].points[les] * studentList[j].units[les]);
                    les++;
                    studentList[j].cou +=1 ;
                    cout << "do you want to continue? ( y or n )";
                    char con = 0 ;
                    cin >> con ;
                    if(con == 'y')
                        continue ;
                    else
                        break ;
                }
                studentList[j].average = (sump / sum);
            }
        }
    }
    else{
        cout << "There isn't any user with this id! \n" ;
    }
    menu() ;

}

void average()
{
    long long int idd ;
    int j ;
    cout << "Enter Id : \n" ;
    cin >> idd ;
    for( j = 0 ; j <100 ; j++)
    {
        if(studentList[j].id == idd )
        {
            cout << "average is : " << studentList[j].average;
        }
    }
    menu();
}

void show_info()
{
    int j, p=0;
    long long int idd ;
    cout << "Enter Id : \n" ;
    cin >>idd ;
    int flag = 0 ;
    for( j = 0 ; j <100 ; j++){
        if(studentList[j].id == idd ){
            flag = 1;
            cout << "name : " << studentList[j].name << endl;
            cout << "family : " << studentList[j].family << endl;
            cout << "ID : " << studentList[j].id << endl;
            cout << "lesson\t" << "unit\t" << "point\n";

            while(studentList[j].points[p] != 0){
                cout << studentList[j].lessons[p] << "\t" << studentList[j].units[p] << "\t" << studentList[j].points[p] << endl;
                p++;
            }
            cout << "average : " << studentList[j].average << endl;
        }
    }
    if (flag==1){
        menu();
    }
    else{
        cout <<"There isn't any user with this id";
        menu();
    }
}

void write(){
    int i,j, flag=0;
    long long int idd ;
    cout << "Enter Id : \n" ;
    cin >>idd ;

    for(i=0; i<100; i++){
        if(studentList[i].id == idd){
            fstream file("c:\\project fpl\\test.txt",ios::in| ios::out | ios::app);
            if(!file.is_open()){
                cout << "file was not created" ;
                menu() ;
            }
            else{
                file << studentList[i].id << " " << studentList[i].name << " " << studentList[i].family << " " << studentList[i].average << " " << studentList[i].cou;
                for(j=0 ; j < studentList[i].cou ; j++){
                    file << " " << studentList[i].lessons[j] << " " << studentList[i].units[j] << " " << studentList[i].points[j] ;
                }
                file<<"\n";
                file.close();
                cout << "Information received";
                flag =1;
            }
        }
    }
    if(flag == 0){
        cout << "There isn't any user with this id!";
        menu();
    }
    else
        menu();
}

void read(){
    long long int idd ;
    int z ;
    cout << "Enter Id : " ;
    cin >>idd ;
    student std;


    ifstream read;
    read.open("c:\\project fpl\\test.txt", ios::in);
    if(read.is_open()){
        while (read){
            read >> std.id >> std.name >> std.family >> std.average >> std.cou ;
            for(z =0 ; z<std.cou ; z++){
                read >> std.lessons[z] >> std.units[z] >> std.points[z] ;
            }
            if(std.id == idd){
                cout << "name : " << std.name << endl;
                cout << "family : " << std.family << endl;
                cout << "ID : " << std.id << endl;
                cout << "lesson\t" << "unit\t" << "point\n";

                for(z=0; z < std.cou;z++){
                    cout << std.lessons[z] << "\t" << std.units[z] << "\t" << std.points[z] << endl;
                }
                cout << "average : " << std.average << endl;
                break ;
            }
        }
    }
    else{
        cout << "file was not created" ;
        menu();
    }
    menu();
}

int main (void)
{
    firstPrint();
    menu();

    return 0 ;
}

