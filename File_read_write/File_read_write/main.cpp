//
//  main.cpp
//  File_read_write
//
//  Created by Marcus Jian on 2019/12/10.
//  Copyright © 2019 Marcus Jian. All rights reserved.
//

#include<iostream>
#include<fstream>
using namespace std;
class Item{
    private:
    string name;
    float price;
    int qty;
    public:
    Item(){}
    Item(string n,float p,int q);
    friend ifstream & operator>>(ifstream &fis,Item &i);
    friend ofstream & operator<<(ofstream &fos,Item &i);
    friend ostream & operator<<(ostream &os,Item &i);
    
};

int main(){
    int n;
    string name;
    float price;
    int qty;
    cout<<"Enter number of Item:";
    cin>>n;Item *list[n];
    cout<<"Enter All Item "<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" Item Name , price and quantity";
        cin>>name;
        cin>>price;
        cin>>qty;
        list[i]=new Item(name,price,qty);
        
    }
    
    ofstream fos("Items.txt");
    for(int i=0;i<n;i++)
    {
        fos<<*list[i];
        
    }
    Item item;
    ifstream fis("Items.txt");
    for(int i=0;i<3;i++){        fis>>item;cout<<"Item "<<i<<item<<endl;
    }
    
}
Item::Item(string n,float p,int q)
{
    name=n;
    price=p;
    qty=q;
    
}
ofstream & operator<<(ofstream &fos,Item &i)
{
    fos<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
    return fos;
    
}

ifstream & operator>>(
ifstream &fis,Item &i){
    fis>>i.name>>i.price>>i.qty;
    return fis;
    
}

ostream & operator<<(
ostream &os,Item &i)
{    os<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
    return os;
    
}
