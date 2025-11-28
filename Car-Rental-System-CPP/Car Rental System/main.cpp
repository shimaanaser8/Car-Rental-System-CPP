#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void surface ()
{
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << "                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "                   ~~~~~~~~~~~~~~ Welcome to The Originals car rental system ~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    Sleep(1500) ;
    system("cls");
}

class car
{
public:
    string name;
    string brand;
    string model;
    float dayprice;
    string color;
    int takenperiod;
    car* next, * prev;
    car()
    {
        name = " ";
        brand = " ";
        model = " ";
        dayprice = 0.0;
        color = " ";
        takenperiod = 0;
    }
    car(string n, string b, string m, float p, string c, int tp)
    {
        name = n;
        brand = b;
        model = m;
        dayprice = p;
        color = c;
        takenperiod = tp;
    }

};
class car_double_list
{
public:
    car* head;
    car* tail;
    car_double_list()
    {
        head = NULL;
        tail = NULL;
    }
    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



    void insertfirst(string newbrand, string newmodel, float newdayprice, string newcolor)
    {
        car* newnode = new car();
        newnode->brand = newbrand;
        newnode->model = newmodel;
        newnode->dayprice = newdayprice;
        newnode->color = newcolor;
        if (isempty()) {
            head = tail = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else
        {
            newnode->next = head;
            newnode->prev = NULL;
            head->prev = newnode;
            head = newnode;
        }
    }
    void insertlast(string newbrand, string newmodel, float newdayprice, string newcolor) {
        car* newnode = new car();
        newnode->brand = newbrand;
        newnode->model = newmodel;
        newnode->dayprice = newdayprice;
        newnode->color = newcolor;
        if (isempty()) {
            head = tail = newnode;
            newnode->next = newnode->prev = NULL;
        }
        else {
            newnode->next = NULL;
            newnode->prev = tail;
            tail->next = newnode;

        }

    }
    void insertmiddel(string item, string newbrand, string newmodel, float newdayprice, string newcolor) {
        car* newnode = new car();
        newnode->brand = newbrand;
        newnode->model = newmodel;
        newnode->dayprice = newdayprice;
        newnode->color = newcolor;

        car* temp = head;
        while (temp != NULL && temp->next->brand != item) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    void traverse()
    {
        cout << "The elements of the double linkedlist are........" << endl;
        car* temp = head;
        while (temp != NULL)
        {
            cout << "the brand of the car are :-   ";
            cout << temp->brand << " ";
            cout << endl;
            cout << "the model of the car are :-   ";
            cout << temp->model << " ";
            cout << endl;
            cout << "the day price of the car are :-  ";
            cout << temp->dayprice << " ";
            cout << endl;
            cout << "the color of the car are :-   ";
            cout << temp->color << " ";
            cout << endl;
            temp = temp->next;
            cout << endl;

        }
        cout << endl;
    }
    void deletion_at_the_end()
    {
        car* p = head;
        if (head == NULL)
        {
            cout << "Error , There is no car in the system to be deleted " << endl;
        }
        if (p->next == NULL)
        {
            head = NULL;
            delete p;
        }
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->prev->next = NULL;
        delete p;
    }
    void deletion_from_first()
    {
        car* p = head;
        if (p != NULL)
        {
            head = head->next;
            delete p;
            head->prev = NULL;
        }
    }
    void deletion_certain_car(int pos)
    {
        car* p;
        p = head;
        if (p == NULL || pos < 0)
        {
            cout << "The list is empty" << endl;
        }
        int i = 1;
        while (p != NULL && i < pos)
        {
            p = p->next;
            i++;
        }
        if (p->next != NULL)
        {
            p->next->prev = p->next;
        }
        if (p == NULL)
        {
            return;
        }
        if (p->prev != NULL)
        {
            p->prev->next = p->next;

        }
    }
    int sortlist()
    {
        car* previous;
        car* q;
        previous = head;
        q = NULL;
        if (head == NULL)
        {
            return 0;
        }
        else {
            while (previous != NULL) {
                q = previous->next;
                while (q != NULL) {
                    if (previous->dayprice > q->dayprice) {
                        int temp1 = previous->dayprice;
                       string temp2=previous->brand;
                       string temp3=previous->model;
                       string temp4=previous->color;

                        previous->dayprice = q->dayprice;
                        previous->brand = q->brand;
                        previous->model = q->model;
                        previous->color = q->color;

                        q->dayprice = temp1;
                        q->brand=temp2;
                        q->model=temp3;
                        q->color=temp4;

                    }
                    q = q->next;
                }
                previous = previous->next;
            }

        }
    }
    void searchbrand(string s_brand)
    {
        int found = 0;
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->brand == s_brand) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1)
        {
            cout << "the brand is  found" << endl;
        }
        else
        {
            cout << "the brand is not found" << endl;
        }
    }
    void searchmodel(string s_model)
    {
        int found = 0;
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->model == s_model) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1)
        {
            cout << "the model is  found" << endl;
        }
        else
        {
            cout << "the model is not found" << endl;
        }
    }
    void searcdayprice(int s_price)
    {
        int found = 0;
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->dayprice == s_price) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1)
        {
            cout << "the price is  found" << endl;
        }
        else
        {
            cout << "the price is not found" << endl;
        }
    }
    void searchcolor(string s_color)
    {
        int found = 0;
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->color == s_color) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1)
        {
            cout << "the color  is  found" << endl;
        }
        else
        {
            cout << "the color is not found" << endl;
        }
    }
    car* searchBrand(string s_brand)
    {
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->brand == s_brand) {
                return temp;
            }
            temp = temp->next;
        }
        return (NULL);
    }
    car* searchModel(string s_model)
    {
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->model == s_model) {
                return temp;
            }
            temp = temp->next;
        }
        return (NULL);
    }
    car* searchDayprice(float s_dayprice)
    {
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->dayprice == s_dayprice) {
                return temp;
            }
            temp = temp->next;
        }
        return (NULL);
    }
    car* searchColor(string s_color)
    {
        car* temp = head;
        while (temp != NULL)
        {
            if (temp->color == s_color) {
                return temp;
            }
            temp = temp->next;
        }
        return (NULL);
    }
    void updateBrand() {
        if (head == NULL) {
            cout << "List is Empty,Kindly insert some Node" << endl;
        }
        else {
            string oldBrand, newBrand;
            cout << "Enter The  old Node Data you want to Update: " << endl;
            cin >> oldBrand;
            car* ptr = searchBrand(oldBrand);
            if (ptr == NULL) {
                cout << "Node not found, hence update can not be done" << endl;
            }
            else {
                cout << "Enter The New Data: " << endl;
                cin >> newBrand;
                ptr->brand = newBrand;
                cout << "Node successfully update" << endl;
            }
        }

    }
    void updateModel() {
        if (head == NULL) {
            cout << "List is Empty,Kindly insert some Node" << endl;
        }
        else {
            string oldModel, newModel;
            cout << "Enter The Node Data you want to Update: " << endl;
            cin >> oldModel;
            car* ptr = searchModel(oldModel);
            if (ptr == NULL) {
                cout << "Node not found, hence update can not be done" << endl;
            }
            else {
                cout << "Enter The New Data: " << endl;
                cin >> newModel;
                ptr->model = newModel;
                cout << "Node successfully update" << endl;
            }
        }

    }
    void updateDayprice() {
        if (head == NULL) {
            cout << "List is Empty,Kindly insert some Node" << endl;
        }
        else {
            float oldDayprice, newDayprice;
            cout << "Enter The Node Data you want to Update: " << endl;
            cin >> oldDayprice;
            car* ptr = searchDayprice(oldDayprice);
            if (ptr == NULL) {
                cout << "Node not found, hence update can not be done" << endl;
            }
            else {
                cout << "Enter The New Data: " << endl;
                cin >> newDayprice;
                ptr->dayprice = newDayprice;
                cout << "Node successfully update" << endl;
            }
        }

    }
    void updateColor() {
        if (head == NULL) {
            cout << "List is Empty,Kindly insert some Node" << endl;
        }
        else {
            string oldColor,  newColor;
            cout << "Enter The Node Data you want to Update: " << endl;
            cin >> oldColor;
            car* ptr = searchColor(oldColor);
            if (ptr == NULL) {
                cout << "Node not found, hence update can not be done" << endl;
            }
            else {
                cout << "Enter The New Data: " << endl;
                cin >> newColor;
                ptr->color = newColor;
                cout << "Node successfully update" << endl;
            }
        }
    }

};


void firstChoice ()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "~~~  Welcome to the main system       ~~~" << endl ;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << "~~~                                   ~~~" << endl ;
    cout << "~~~        1- Insert                  ~~~" << endl ;
    cout << "~~~        2- Delete                  ~~~" << endl ;
    cout << "~~~        3- search                  ~~~" << endl ;
    cout << "~~~        4- update                  ~~~" << endl ;
    cout << "~~~        5- sort                    ~~~" << endl ;
    cout << "~~~        6- Stack                   ~~~" << endl ;
    cout << "~~~        7- Exit                    ~~~" << endl ;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
    cout << " ---> Please , Enter the number of your choice : " ;
}


class Stack {
public:
    car* top = NULL;
    bool IsEmpty() {
        if (top == NULL)
            return true;
        else
            return false;
    }
    bool IsFull() {
        car* s = new car();
        if (s == NULL) {
            cout << "                  ((((((((((((( Stack is full )))))))))))))           " << endl ;
        }
        else
            cout << "                  ((((((((((((((( Stack is not full and you can apply any operation )))))))))))))))" << endl ;
    }
    void push(string b, string m , float p , string c) {
        car* s = new car();
        s->brand = b;
        s->model = m;
        s->dayprice = p ;
        s->color = c;
        if (!s)
            return;
        else if (IsEmpty()) {
            top = s;
        }
        else {
            top->next = s;
            s->next = NULL;
            s->prev = top;
            top = s;
        }
    }
    void peak() {
        cout << "the brand of the top car :-   " << top->brand << endl;
        cout << "the model of the top car :-   " << top->model << endl;
        cout << "the price of the top car :-   " << top->dayprice << endl;
        cout << "the color of the top car :-   " << top->color << endl;
    }
    void disPlay() {
        if (IsEmpty())
            cout << "Stack is Empty";
        else {
            car* p = top;
            while (p != NULL) {
                cout << "              Brand: " << p->brand  ;
                cout << "              Model: " << p->model ;
                cout << "              Price: " << p->dayprice ;
                cout << "              Color: " << p->color ;
                cout << endl ;
                p = p->prev;
            }
        }
    }
    void pop() {
        if (IsEmpty())
            return;
        else
            top = top->prev;
        delete top->next;
    }
};


int main(){
    surface() ;
    int choice ;
    car_double_list c1;
    firstChoice() ;
    string brand , model , color ;
    double price ;
    int Start_choice ;
    cin >> Start_choice ;
    system("cls") ;
    if (Start_choice==1)
    {
        cout << "The list contains :-  " << endl ;
        c1.insertlast("BMW", "B2000", 9000 , "Orange");
        c1.insertfirst("mercedes", "ME2001", 10000 , "Red");
        c1.insertfirst("toyota" , "Ty2022" , 4600 , "Black") ;
        c1.insertfirst("MG" , "MM2010" , 3800 , "Blue") ;
        c1.traverse();
        Sleep(3000) ;
        system("cls") ;
        // the order of cars already exist on the system (MG , toyota , mercedes , BMW).
        cout << "Enter the data of the car you want to insert \n" ;
        cout << "                           ------->>>>> Enter the brand of the car :-  " ;
        cin >> brand ;
        cout << "                           ------->>>>> Enter the model of the car :-  " ;
        cin >> model ;
        cout << "                           ------->>>>> Enter the price of the car :-  " ;
        cin >> price ;
        cout << "                           ------->>>>> Enter the color of the car :-  " ;
        cin >> color ;
        system("cls") ;
        cout<<endl;
        cout << "                            $$$$$$   Which of the following operations you want to apply    $$$$$$ " << endl ;
        cout << "                            $$$$$$                   1- Insert at first                     $$$$$$ " << endl ;
        cout << "                            $$$$$$                   2- Insert at last                      $$$$$$ " << endl ;
        cout << "                            $$$$$$                   3- Insert in the middle                $$$$$$ " << endl ;
        cout<<endl;
        cout << " ---> Please , Enter the number of your choice : " ;
        cin >> choice ;
        system("cls") ;
        if (choice==1)
        {
            c1.insertfirst(brand , model , price , color) ;
            cout << "                        (((((((((((((((( The elements of the list after inserting :- " << endl ;
            c1.traverse() ;
        }
        if (choice==2)
        {
            c1.insertlast(brand , model , price , color) ;
            cout << "                        (((((((((((((((( The elements of the list after inserting :- " << endl ;
            c1.traverse() ;
        }
        if (choice==3)
        {
            string item ;
            cout << "Enter the brand of the car you want to insert at :-" ;
            cin >> item ;
            c1.insertmiddel(item , brand , model , price , color) ;
            cout << "                        (((((((((((((((( The elements of the list after inserting :- " << endl ;
            c1.traverse() ;
        }
    }

    if (Start_choice==2)
    {
        cout << "The list contains :-  " << endl ;
        c1.insertlast("BMW", "B2000", 9000 , "Orange");
        c1.insertfirst("mercedes", "ME2001", 10000 , "Red");
        c1.insertfirst("toyota" , "Ty2022" , 4600 , "Black") ;
        c1.insertfirst("MG" , "MM2010" , 3800 , "Blue") ;
        c1.traverse();
        Sleep(3000) ;
        system("cls") ;
        cout<<endl;

        cout << "                            ******   Which of the following operations you want to apply    ****** " << endl ;
        cout << "                            ******                   1- delete at first                     ****** " << endl ;
        cout << "                            ******                   2- delete at last                      ****** " << endl ;
        cout << "                            ******                   3- delete in the middle                ****** " << endl ;
        cout<<endl;
        cout << " ---> Please , Enter the number of your choice : " ;
        cin >> choice ;
        system("cls") ;
        if (choice==1)
        {
            c1.deletion_from_first() ;
            system("cls") ;
            cout << "                  ------->>>> The list after removing the wanted car :-" << endl ;
            c1.traverse() ;
        }
        if (choice==2)
        {
            c1.deletion_at_the_end() ;
            system("cls") ;
            cout << "                  ------->>>> The list after removing the wanted car :-" << endl ;
            c1.traverse() ;
        }
        if (choice==3)
        {
            int pos ;
            cout << "    ^^^^^^^^ Enter the position of the car you want to remove :- " ;
            cin >> pos ;
            c1.deletion_certain_car(pos) ;
            system("cls") ;
            cout << "                  ------->>>> The list after removing the wanted car :-" << endl ;
            c1.traverse() ;
        }
    }

    if (Start_choice==6)
    {
        string brand , model , color ;
        float price ;
        int choice ;
        Stack c;
        cout << "The elements exist in the stack until now :- " << endl ;
        c.push("kia", "2017" , 6000  , "Red");
        c.push("BMW", " 2020" , 8000 , "Black");
        c.push("toyota", "2012", 10000 , "Blue");
        cout<<endl;

        cout << "                         ******   Which of the following operations you want to apply on the stack    ****** " << endl ;
        cout << "                         ******                   1- Push                                             ****** " << endl ;
        cout << "                         ******                   2- Pop                                              ****** " << endl ;
        cout << "                         ******                   3- peak                                             ****** " << endl ;
        cout << "                         ******                   4- Is Full                                          ****** " << endl ;
        cout << "                         ******                   5- Is Empty                                         ****** " << endl ;
        cout<<endl;

        cout << " ---> Please , Enter the number of your choice : " ;
        cin >> choice ;
        if (choice==1){
            cout << "Enter the data of the car you want to add " << endl ;
            cout << "                               --------->>>>>>> Enter the brand of the car :- " ;
            cin >> brand ;
            cout << "                               --------->>>>>>> Enter the model of the car :- " ;
            cin >> model ;
            cout << "                               --------->>>>>>> Enter the price of the car :- " ;
            cin >> price ;
            cout << "                               --------->>>>>>> Enter the color of the car :- " ;
            cin >> color ;
            system("cls") ;
            c.push(brand , model , price , color);
            cout << "The list after adding the new car :- " << endl ;
            c.disPlay() ;
        }
        if (choice==2)
        {
            cout << "The list after removing an element :- " << endl ;
            c.pop();
            c.disPlay();
        }
        if (choice==3)
        {
            c.peak();
        }
        if (choice==4)
        {
            c.IsFull() ;
        }
        if (choice==5)
        {
            if(c.IsEmpty()==true)
            {
                cout << "              (((((((((((((((   The stack is empty    )))))))))))))))) " << endl ;
            }
            else
                cout << "              ((((((((((((((( The stack has elements  )))))))))))))))) " << endl ;
        }
    }
    if(Start_choice==3)
    {
        cout << "The list contains :-  " << endl ;
        c1.insertlast("BMW", "B2000", 9000 , "Orange");
        c1.insertfirst("mercedes", "ME2001", 10000 , "Red");
        c1.insertfirst("toyota" , "Ty2022" , 4600 , "Black") ;
        c1.insertfirst("MG" , "MM2010" , 3800 , "Blue") ;
        c1.traverse();
        Sleep(3000) ;
        system("cls") ;
        cout << "                            ******   Which of the following operations you want to apply    ****** " << endl ;
        cout << "                            ******                   1- search about brand                    ****** " << endl ;
        cout << "                            ******                   2- search about model                     ****** " << endl ;
        cout << "                            ******                   3- search about Dayprice                  ****** " << endl ;
        cout <<"                             ******                   4-search about color                       ******"<<endl;
        cout << " ---> Please , Enter the number of your choice : " ;
        cin >> choice ;
        system("cls") ;
        if(choice==1)
        {
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> the search about brand ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.searchbrand("toyota");
        }
        if(choice==2)
        {
            system("cls");
            cout<<"  ~~~~~~~~~~~>>>>>>>> the search about model ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.searchmodel("ME2001");

        }
        if(choice==3)
        {
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> the search about Dayprice ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.searcdayprice(1000);
        }
        if(choice==4)
        {
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> the search about color ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.searchcolor("Red");

        }
    }
    if(Start_choice==5)
    {
        cout << "The list contains :-  " << endl ;
        c1.insertlast("BMW", "B2000", 4600 , "Orange");
        c1.insertfirst("mercedes", "ME2001", 1000 , "Red");
        c1.insertfirst("toyota" , "Ty2022" , 9000 , "Black") ;
        c1.insertfirst("MG" , "MM2010" , 3800 , "Blue") ;
        c1.traverse();
        Sleep(3000) ;
        system("cls") ;
        cout << "                *********   Which of the following operations you want to apply    ****** " << endl ;
        cout<<endl;;
        cout<<"     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    1- sort the Dayprice  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<endl;
        cout << " ---> Please , Enter the number of your choice : " ;
        cin >> choice ;
        system("cls") ;
        if(choice==1)
        {
            c1.sortlist();
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> sort the Dayprice ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.traverse();
        }

    }
    if(Start_choice==4)
    {
        cout << "The list contains :-  " << endl ;
        c1.insertlast("BMW", "B2000", 9000 , "Orange");
        c1.insertfirst("mercedes", "ME2001", 100000 , "Red");
        c1.insertfirst("toyota" , "Ty2022" , 4600 , "Black") ;
        c1.insertfirst("MG" , "MM2010" , 3800 , "Blue") ;
        c1.traverse();
        Sleep(3000) ;
        system("cls") ;
        cout<<endl;
        cout << "                            ******   Which of the following operations you want to apply    ****** " << endl ;
        cout<<endl;
        cout << "                            ******                   1- update brand                    ****** " << endl ;
        cout << "                            ******                   2- update model                     ****** " << endl ;
        cout << "                            ******                   3- update Dayprice                  ****** " << endl ;
        cout <<"                             ******                   4- update color                       ******"<<endl;
        cout << " ---> Please , Enter the number of your choice : " ;
        cin >> choice ;
        system("cls") ;
        if(choice==1)
        {
            c1.updateBrand();
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> update brand ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.traverse();
        }
        if(choice==2)
        {
            c1.updateModel();
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> update model ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.traverse();

        }
        if(choice==3)
        {
            c1.updateDayprice();
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> update Dayprice ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.traverse();

        }
        if(choice==4)
        {
            c1.updateColor();
            system("cls");
            cout<<"                  ~~~~~~~~~~~>>>>>>>> update color ~~~~~~~~~~~~~~~~~~~~~~~~>>>>>>"<<endl;
            c1.traverse();

        }
    }
    if(Start_choice==7)
    {
        return 0;
    }


    return 0;
}
