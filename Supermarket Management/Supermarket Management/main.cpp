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

/// Aggregation between MEMBERSHIP & CUSTOMER
class membership
{
    int points;
    date added;
public:
    membership () {}
    
    membership (int points)
    {
        this->points = points;
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
    
    void addPoints (int pts)
    {
        points += pts;
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
    map<int,int>product_purchased;
    membership membership_pts;
    
public:
    
    customer () {}
    
    customer(string name,int phNo,string addr): membership_pts (0) ,person(name,phNo,addr) {}
    
    void purchaseProduct(int txn_id, int product_id)
    {
        product_purchased.emplace(pair <int, int> (txn_id, product_id));
    }
    
    void addPoints (int points)
    {
        membership_pts.addPoints(points);
    }
    
};

class goldmember : public customer
{
    public:
    
    goldmember (string name,int phNo,string addr) : customer (name, phNo, addr) {}
    
    void calcPoints(float bill_amount)
    {
        // Gold member gets 20% of total purchase amount as
        int eqvt_pts = 0.2 * bill_amount;
        addPoints(eqvt_pts);
    }
};

class silvermember : public customer
{
    public:
    
    silvermember (string name,int phNo,string addr) : customer (name, phNo, addr) {}
    
    void calcPoints(int bill_amount)
    {
        // Silver member gets 15% of total bill amount as
        int eqvt_pts = 0.15 * bill_amount;
        addPoints(eqvt_pts);
    }
};

class bronzemember : public customer
{
   public:
    
    bronzemember (string name,int phNo,string addr) : customer (name, phNo, addr) {}
   
    void calcPoints(int bill_amount)
   {
        // bronze member gets 10% of total bill amount as
        int eqvt_pts = 0.1 * bill_amount;
        addPoints(eqvt_pts);
   }
};

class staff:public person
{
    int aadharNo;
    float salary;
    date join_date;
public:
    
    staff () {}
    
    staff (string name,int phNo,string addr,int aadharNo,float salary,date join_date):person(name,phNo,addr)
    {
        this->aadharNo=aadharNo;
        this->salary=salary;
        this->join_date=join_date;
        
    }
    
    void printStaffDetails()
    {
        cout<<"name"<<name<<endl;
        cout<<"phoneNo"<<phNo<<endl;
        cout<<"address"<<addr<<endl;
        cout<<"aadharNumber"<<aadharNo<<endl;
        cout<<"salary"<<salary<<endl;
    }
    
    int getaadhar()
    {
        return aadharNo;
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
    
    cashier (int txns_processed, string name,int phNo,string addr,int aadharNo,float salary,date join_date) : txns_processed (txns_processed),
    staff (name,phNo,addr,aadharNo,salary,join_date) {}
};

class  assistant : public staff
{
    vector <string> advice;
    
public:
    
    assistant (vector <string> advice, string name,int phNo,string addr,int aadharNo,float salary,date join_date) : advice (advice),
    staff (name,phNo,addr,aadharNo,salary,join_date) {}
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
    
public:
    
    static int txn_id;
    
    transaction()
    {
        
    }
    
    static void getNextTxnId ()
    {
        txn_id++;
    }
};

int transaction :: txn_id = 1;

int main(int argc, const char *argv[])
{
    
}
