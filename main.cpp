#include <iostream>
#include <string>
#include <iomanip>


#define INFINITY 9999
#define max 3

//Travel Cost Calculator


using namespace std;

class Link{

public:
    double unitprice;
    string item;
    int qty;
    double totalprice;


    Link *next;
    Link (double unitprice,string item,int qty,double totalprice);
    void displayLink();
    Link *findx(string name);






};


Link::Link(double unitprice,string item,int qty,double totalprice){

    this->unitprice = unitprice;
    this->item = item;
    this->qty = qty;
    this->totalprice = totalprice;
    next = NULL;

}

void Link::displayLink(){

    const char separator    = ' ';
    const int nameWidth     = 12;
    const int numWidth      =12;

   // cout<<"itemname \t price \t qty \t total\n";
    //cout << item << "\t" << unitprice << "Rs\t" << qty <<"\t"<<totalprice<<"Rs \n"<<endl;

    //////////////////////
    cout<<endl;

    /*  cout << left << setw(nameWidth) << setfill(separator) <<"item name";
    cout << left << setw(nameWidth) << setfill(separator) << "Unitprice(Rs)";
    cout << left << setw(numWidth) << setfill(separator) <<"qty";
    cout << left << setw(numWidth) << setfill(separator) <<"Totalprice(Rs)";*/

      cout << endl;


     cout << left << setw(nameWidth) << setfill(separator) << item;
    cout << left << setw(nameWidth) << setfill(separator) << unitprice;
    cout << left << setw(numWidth) << setfill(separator) <<qty;
    cout << left << setw(numWidth) << setfill(separator) <<totalprice;


    cout << endl;

   // cin.get();
}


    ///////////////////////////////



class LinkList{


public:
    Link *first;

    LinkList();

    LinkList(LinkList &cl);

    void inserfirst(double unitprice,string item,int qty,double totalprice);
    bool deleteFirst();
    bool deleteNode(string name);
    void displayList();
    Link *findx(string name);
    void ascendingorder();
    void descendingorder();












};

LinkList::LinkList(){

    first = NULL;
}

LinkList::LinkList(LinkList &cl){
    Link *temp;

    temp = cl.first;

    while (temp!=NULL){
        inserfirst(temp->unitprice,temp->item,temp->qty,temp->totalprice);
    }



}


void LinkList::inserfirst(double unitprice,string item,int qty,double totalprice){

    Link *newlink = new Link(unitprice,item,qty,totalprice);

    newlink->next = first;

    first = newlink;

}

void LinkList::displayList(){
    Link  *current=first;


    while(current != NULL){

        current->displayLink();


        current = current -> next;

    }


};


Link* LinkList::findx(string name){

    Link *temp=first;

    while(temp != NULL && temp->item.compare(name)!=0){

        temp = temp->next;
    }



    return temp;

}


bool LinkList::deleteFirst(){
    if(first==NULL){

        return false;
    }

    else{

        Link *temp = first;


        first = temp->next;


        delete temp;

        return true;

    }
}


bool LinkList::deleteNode(string name){

    Link *current = first;
    Link *pre = current;

    while(current !=NULL){

        if(current->item.compare(name)==0){

            if(current == first){

                first = first->next;

            }
            else{

                pre->next = current->next;

            }

            delete current;
            return true;

        }

        else{

            pre = current;
            current = current->next;

        }


    }//end while

    return false;


}


void LinkList::ascendingorder(){

    Link *current = first;
    Link *key = first;
    double temptot;
    double tempunitprice;
    int tempqty;
    string tempitem;

    while(key != NULL){

        while(current != NULL){

            if(!(key->totalprice < current->totalprice)){

                tempitem = key->item;
                tempunitprice = key->unitprice;
                tempqty = key->qty;
                temptot = key->totalprice;


                key->item = current->item;
                key->unitprice = current->unitprice;
                key->qty = current->qty;
                key->totalprice = current->totalprice;


                current->item = tempitem;
                current->unitprice = tempunitprice;
                current->qty = tempqty;
                current->totalprice = temptot;

            }

            current = current ->next;

        }

        /* this is for decening order
        current = first;
        key = key->next;*/


        key = key->next;

        current = key;

        //  current = key;
    }



}


void LinkList::descendingorder(){

    Link *current = first;
    Link *key = first;
    double temptot;
    double tempunitprice;
    int tempqty;
    string tempitem;

    while(key != NULL){

        while(current != NULL){

            if(!(key->totalprice > current->totalprice)){

                tempitem = key->item;
                tempunitprice = key->unitprice;
                tempqty = key->qty;
                temptot = key->totalprice;


                key->item = current->item;
                key->unitprice = current->unitprice;
                key->qty = current->qty;
                key->totalprice = current->totalprice;


                current->item = tempitem;
                current->unitprice = tempunitprice;
                current->qty = tempqty;
                current->totalprice = temptot;

            }

            current = current ->next;

        }

        /* this is for decening order
        current = first;
        key = key->next;*/


        key = key->next;

        current = key;

        //  current = key;
    }



}












//testing
LinkList objlinklist;

//function declaration
void init();
void inti_dijkstra();
void dijkstra(int G[max][max],int n,int startnode);
void insertitems();
void displayitemlist();
void find_item_details();
void delete_lastinput_item();
void deleteitem();
void get_addedcheap_item();
void get_addedexpensive_item();
void switchtomenu();




int main() {

    init();


    return 0;
}

//functions

void init(){

    char status;

    system("cls");
    cout<<"\n\t\t------- Travel Budget Calculator -------\n"<<endl;

    cout<<"\t1. press 1 for insert items"<<endl;
    cout<<"\t2. press 2 for display items"<<endl;
    cout<<"\t3. press 3 for find a item"<<endl;
    cout<<"\t4. press 4 for cheap to expensive items"<<endl;
    cout<<"\t5. press 5 for expensive to cheap items"<<endl;
    cout<<"\t6. press 6 for delete last added item"<<endl;
    cout<<"\t7. press 7 for delete item"<<endl;
    cout<<"\t8. press 8 for plan your route"<<endl;

    cout<<"\nPlease select any option - ";
    cin>>status;

    system("cls");

    switch (status) {
        case '1':
            insertitems();
            break;
        case '2':
            displayitemlist();
            break;
        case '3':
            find_item_details();
            break;
        case '4':
            get_addedcheap_item();
            break;
        case '5':
            get_addedexpensive_item();
            break;
        case '6':
            delete_lastinput_item();
            break;
        case '7':
            deleteitem();
            break;

        case '8':
            inti_dijkstra();
            break;
        default:
            system("cls");
            init();


    }




}

void insertitems(){

    cout<<"\t\t---------- New item add ----------"<<endl;

    string name;
    int qty;
    double unitp , tot;
    char status;

    cin.ignore();

    while(true){
        cout<<"enter new item - ";

        getline(cin, name);


        cout<<"unit price - ";
        cin>>unitp;
        cout<<"enter qty - ";
        cin>>qty;

        tot = qty * unitp;



        objlinklist.inserfirst(unitp,name,qty,tot);

        cout<<"press any key add a new item or press 'n/N' to stop "<<endl;

        cin>>status;

        if(status == 'n' || status == 'N'){
            init();
            break;
        }



        cin.ignore();

        system("cls");
    }



}

void displayitemlist(){
    system("cls");

    cout<<"\t\t---------- Display items ----------"<<endl;

    objlinklist.displayList();

    switchtomenu();
}

void find_item_details(){

    system("cls");

    cout<<"\t\t----------Find item ----------"<<endl;

    cout<<"enter a item name that you want to find details"<<endl;

    string name;

    cin>>name;

    cout<<"search results"<<endl;

    cout<<"-------------------------------"<<endl;

    Link *templink = objlinklist.findx(name);

    if(templink==NULL){
        cout<<"No result found with the given item"<<endl;
        switchtomenu();
        return;
    }

    int qty = templink->qty; //l.findx(name)->qty;
    double unitprice =templink->unitprice;// l.findx(name)->unitprice;
    double tot =templink->totalprice; //l.findx(name)->totalprice;


    cout << name << " " << unitprice << "Rs " << qty <<" "<<tot<<"Rs "<<endl;

    switchtomenu();


}

void delete_lastinput_item(){

    system("cls");

    cout<<"\t\t---------- Delete last added items ----------"<<endl;

   if(objlinklist.deleteFirst()){
       cout<<"last input item deleted"<<endl;

   }
   else{
       cout<<"no records in the list"<<endl;
   }

   switchtomenu();



}

void deleteitem(){

    system("cls");
    cout<<"\t\t---------- Delete items ----------"<<endl;

    cout<<"enter a item name"<<endl;

    string name;

    cin>>name;

    if(objlinklist.deleteNode(name)){
        cout<<name<< "item deleted "<<endl;
    }
    else{

        cout<<"Theres no records for given item "<<name<<endl;
    }

    switchtomenu();


}

void get_addedcheap_item(){

    system("cls");
    cout<<"\t\t---------- Display cheap items to expensive ----------"<<endl;



    objlinklist.ascendingorder();


    objlinklist.displayList();

    switchtomenu();

}

void get_addedexpensive_item(){

    system("cls");

    cout<<"\t\t---------- Display expensive items to cheap ----------"<<endl;



    objlinklist.descendingorder();

    objlinklist.displayList();

    switchtomenu();
}

void switchtomenu(){

    char status;

    cout<<"Back to main menu (Y) ";
    cin>>status;
    if(status=='Y' || status=='y'){
        init();
        return;
    }



}


void inti_dijkstra(){

    system("cls");

    cout<<"\t\t---------- route planning ----------"<<endl;

    int placecount;
    int distance;
    int sourcenode;
    int graph[max][max];

    cout<<"You can add five places only "<<endl;


    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
                cout<<"Please enter distance ";
                cin>>distance;
                graph[i][j] = distance;
                cout<<endl;
        }
    }

    cout<<"please enter the number related to your location ";
    cin>>sourcenode;




    /*int G[max][max]={{10,0,5,0,0},{0,0,2,1,0},{0,5,0,9,2},{0,0,0,0,4},{7,0,0,6,0}};*/

    dijkstra(graph,placecount,sourcenode);
}


//dijkstra algorithm implement
void dijkstra(int G[max][max],int n,int startnode) {

    system("cls");

    cout<<"\t\t---------- route planning ----------"<<endl;

    int cost[max][max],distance[max],pred[max];
    int visited[max],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++) {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1) {
        mindistance=INFINITY;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]) {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]) {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }

    int nnode = 4;

    for(i=0;i<n;i++)
        if(i!=startnode) {
            cout<<"\nDistance of node"<<i<<"="<<distance[i];
            cout<<"\nPath="<<i;
            j=i;
            do {
                j=pred[j];
                cout<<"<-"<<j;
            }while(j!=startnode);
        }


    cout<<"\n"<<endl;
    switchtomenu();

}
