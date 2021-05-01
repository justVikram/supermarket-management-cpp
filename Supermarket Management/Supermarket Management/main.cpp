#include<iostream>
#include<string>
#include<map>
#include <vector>
#include <fstream>

using namespace std;

class date
{
    int dd,mm,yy;
    
public:
    date() {}
    
    date(int dd, int mm, int yy)
    {
        this->dd = dd;
        this->mm = mm;
        this->yy = yy;
    }
    void printdate()
    {
        cout << dd << "/" << mm << "/" << yy << endl;
    }
    
};

class person
{
protected:
    string name;
    int phNo;
    string addr;
    
public:
    person() {}
    
    person(string name, int phNo, string addr)
    {
        this->name = name;
        this->phNo = phNo;
        this->addr = addr;
    }
    void printPerson()
    {
        cout<<"Customer Name:"<<name<<endl;
        cout<<"Address:"<<addr<<endl;
        cout<<"Phone Number:"<<phNo<<endl;
        
    }
    string getName()
    {
        return name;
    }
    string getaddr()
    {
        return addr;
    }
    int getPhoneNo()
    {
        return phNo;
    }
    
};

class customer:public person
{
    multimap<int,int>product_purchased;
    
public:
    
    customer () {}
    
    customer(string name,int phNo,string addr):person(name,phNo,addr)
    {
        
    }
    
    void purchaseProducts(int pp)
    {
        
    }
    
};

class GoldMember 
{
    public:
    void addPoints()
    {

    }
};

class SilverMember
{
    public:
    void addPoints()
    {

    }
};

class BronzeMember
{
   public:
   void addPoints()
   {

   }
};

class staff:public person
{
    int aadharNo;
    string job_designation;
    float salary;
    date join_date;
public:
    
    staff () {}
    
    staff (string name,int phNo,string addr,int aadharNo,string jd,float salary,date join_date):person(name,phNo,addr)
    {
        this->aadharNo=aadharNo;
        this->job_designation=jd;
        this->salary=salary;
        this->join_date=join_date;
        
    }
    
    void printStaffDetails()
    {
        cout<<"name"<<name<<endl;
        cout<<"phoneNo"<<phNo<<endl;
        cout<<"address"<<addr<<endl;
        cout<<"aadharNumber"<<aadharNo<<endl;
        cout<<"job_designation"<<job_designation<<endl;
        cout<<"salary"<<salary<<endl;
    }
    int getaadhar()
    {
        return aadharNo;
    }
    string getJobDesignation()
    {
        return job_designation;
    }
    float getSalary()
    {
        return salary;
    }
};

class cashier : public staff
{
    int txns_processed;
    
public:
    
    cashier (int txns_processed, string name,int phNo,string addr,int aadharNo,string jd,float salary,date join_date) : txns_processed (txns_processed),
    staff (name,phNo,addr,aadharNo,jd,salary,join_date) {}
};

class  assistant : public staff
{
    vector <string> advice;
    
public:
    
    assistant (vector <string> advice, string name,int phNo,string addr,int aadharNo,string jd,float salary,date join_date) : advice (advice),
    staff (name,phNo,addr,aadharNo,jd,salary,join_date) {}
};

class product
{
    string category,name;
    float cost;
    int id,quantity;
    
public:
    product()
    {
        
    }
    product(string category,float cost,string name,int id,int quantity)
    {
        this->category=category;
        this->cost=cost;
        this->name=name;
        this->id=id;
        this->quantity=quantity;
    }
    
    void printproductdetails()
    {
        cout<<"Category:"<<category<<endl;
        cout<<"Product Name:"<<name<<endl;
        cout<<"Product Id"<<id<<endl;
        cout<<"Date of Manufacturer:";
        cout<<"Cost:"<<cost<<endl;
        cout<<"Quantity:"<<quantity << endl;
    }
    
    int getId()
    {
        return id;
    }
    
    int getQuantity()
    {
        return quantity;
    }
    
    string getName()
    {
        return name;
    }
    
    string getCategory()
    {
        return category;
    }
    
    float getCost()
    {
        return cost;
    }
    
};

class furniture : public product
{
private:
    
    vector <string> list_of_items;
    
public:
    
    furniture (vector <string> list_of_items, string category,float cost,string name,int id, int quantity) : list_of_items (list_of_items),
    product (category, cost, name, id, quantity) {}
    
};

class groceries : public product
{
private:
    
    date dom, doe;
    
public:
    
    groceries (date dom, date doe, string category,float cost,string name,int id, int quantity) : dom (dom), doe (doe),
    product (category, cost, name, id, quantity) {}
};

class clothes : public product
{
private:
    
    string brand_name;
    
public:
    
    clothes (string brand_name, string category,float cost,string name,int id, int quantity) : brand_name (brand_name),
    product (category, cost, name, id, quantity) {}
};

class inventory
{
    vector<product>products_available;
    
public:
    
};

class supplier
{
    string agency_name;
    multimap<int,int>items_restocked;
};

/// Aggregation between MEMBERSHIP & CUSTOMER
class membership
{
    int points;
    date added;
public:
    membership()
    {
        
    }
    membership(int points,date added)
    {
        this->points=points;
        this->added=added;
    }
    void printmembership()
    {
        cout<<"Points:"<<points<<endl;
        cout<<"Date on which points were added:";
        added.printdate();
    }
    int getpoints()
    {
        return points;
    }
    
};

/// Aggregation between STORE & Staff
class store
{
    string name;
    string location;
public:
    store()
    {
        
    }
    store(string name, string location)
    {
        this->name=name;
        this->location=location;
    }
    string getName()
    {
        return name;
    }
    string getLocation()
    {
        return location;
    }
    void printStore()
    {
        cout<<"Store Name:"<<name<<endl;
        cout<<"Location:"<<location<<endl;
    }
};

class transaction
{
    customer c;
    staff s;
    date date;
    float amount;
    string txn_id;
    
public:
    
    transaction()
    {
        
    }
};

int main(int argc, const char *argv[])
{
    
}
