#include<iostream>
#include<string>
#include<map>

using namespace std;

class date{
    int dd,mm,yy;
public:
    
    date(int dd, int mm,int yy){
        this->dd=dd;
        this->mm=mm;
        this->yy=yy;
    }
    
    date(){}
};


class person{
protected:
    string name;
    int phNo;
    string addr;
public:
    person(string name,int phNo,string addr)
    {
        this->name=name;
        this->phNo=phNo;
        this->addr=addr;
    }
    person(){}
    
    
    
};

class customer:public person{
    multimap<int,int>product_purchased;
    
public:
    customer(string name,int phNo,string addr):person(name,phNo,addr)
    {
        
    }
    
    void purchaseProducts(int pp)
    {
        
    }
    
};

class staff:public person{
    int aadharNo;
    string job_designation;
    float salary;
    date join_date;
    
public:
    staff(string name,int phNo,string addr,int aadharNo,string jd,float salary,date join_date):person(name,phNo,addr)
    {
        this->aadharNo=aadharNo;
        this->job_designation=jd;
        this->salary=salary;
        this->join_date=join_date;
        
    }
    
    void getDetails(){
        cout<<"name"<<name<<endl;
        cout<<"phoneNo"<<phNo<<endl;
        cout<<"address"<<addr<<endl;
        cout<<"aadharNumber"<<aadharNo<<endl;
        cout<<"job_designation"<<job_designation<<endl;
        cout<<"salary"<<salary<<endl;
        
        
    }
};

class product
{
    string category;
    float cost;
    string name;
    int id;
    date dom;
    date doe;
    int quantity;
    int batchNo;
    
public:
    product(string category,float cost,string name,int id,date dom,date doe,int quantity,int batchNo)
    {
        this->category=category;
        this->cost=cost;
        this->name=name;
        this->id=id;
        this->dom=dom;
        this->doe=doe;
        this->quantity=quantity;
        this->batchNo=batchNo;
        
    }
    
    
};


int main(){
    return 0;
}
