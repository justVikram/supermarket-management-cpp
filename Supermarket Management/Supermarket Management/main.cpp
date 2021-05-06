#include <iostream>
#include <string>
#include <map>
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
    multimap<int,int>product_purchased;
    membership membership_pts;
    
public:
    
    customer () {}
    
    customer(string name,int phNo,string addr): membership_pts (0) ,person(name,phNo,addr) {}
    
    void purchasedProducts(int txn_id, int product_id)
    {
        product_purchased.emplace(pair <int, int> (txn_id, product_id));
    }
    
    void addPoints (int points)
    {
        membership_pts.addPoints(points);
    }
    
    virtual int convertToPoints (int bill_amount)
    {
        return 0;
    }
    
    virtual void calcPoints(int bill_amount)
    {}
    
};

class goldmember : public customer
{
public:
    
    goldmember (string name,int phNo,string addr) : customer (name, phNo, addr) {}
    
    int convertToPoints (int bill_amount) override
    {
        int eqvt_pts = 0.20 * bill_amount;
        return eqvt_pts;
    }
    
    void calcPoints(int bill_amount) override
    {
        // Silver member gets 15% of total bill amount as
        
        addPoints (convertToPoints (bill_amount));
    }
};

class silvermember : public customer
{
public:
    
    silvermember (string name,int phNo,string addr) : customer (name, phNo, addr) {}
    
    int convertToPoints (int bill_amount) override
    {
        int eqvt_pts = 0.15 * bill_amount;
        return eqvt_pts;
    }
    
    void calcPoints(int bill_amount) override
    {
        // Silver member gets 15% of total bill amount as
        
        addPoints (convertToPoints (bill_amount));
    }
};

class bronzemember : public customer
{
public:
    
    bronzemember (string name,int phNo,string addr) : customer (name, phNo, addr) {}
    
    int convertToPoints (int bill_amount) override
    {
        int eqvt_pts = 0.10 * bill_amount;
        return eqvt_pts;
    }
    
    void calcPoints(int bill_amount) override
    {
        // Silver member gets 15% of total bill amount as
        
        addPoints (convertToPoints (bill_amount));
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
    int txns_processed = 0;
    
public:
    
    cashier (int txns_processed, string name,int phNo,string addr,int aadharNo,float salary,date join_date) : txns_processed (txns_processed),
    staff (name,phNo,addr,aadharNo,salary,join_date) {}
    
    void processedTxn ()
    {
        txns_processed++;
    }
    
    int getTotalTxnsProcessed ()
    {
        return txns_processed;
    }
};

class  assistant : public staff
{
    string advice;
    
public:
    
    assistant (string advice, string name,int phNo,string addr,int aadharNo,float salary,date join_date) : advice (advice),
    staff (name,phNo,addr,aadharNo,salary,join_date) {}
    
    auto getAdvice ()
    {
        return advice;
    }
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
    
public:
    
    supplier (string name) : agency_name (name) {}
    
    string getAgencyName ()
    {
        return agency_name;
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



customer * findByPhNo (vector <goldmember> gold_person, vector <silvermember> silver_person, vector <bronzemember> bronze_person, int ph_no)
{
    customer * reqd_customer = new customer ("invalid", 00, "invalid");
    
    for (auto i : gold_person)
    {
        if (i.getPhoneNo() == ph_no)
            reqd_customer = &i;
    }
    
    for (auto i : silver_person)
    {
        if (i.getPhoneNo() == ph_no)
            reqd_customer = &i;
    }

    for (auto i : bronze_person)
    {
        if (i.getPhoneNo() == ph_no)
            reqd_customer = &i;
    }
    
    return reqd_customer;
}

product * findByProductID (vector <product> list_of_products, int p_id)
{
    //FIXME:- RETURN OBJECT OF PRODUCT WHICH HAS SAME PRODUCT ID AS ONE OF THE PRODUCTS IN THE LIST
    product *reqd_product = new product("invalid", 00, "invalid",00,00);

    for (auto i : list_of_products)
    {
        if (i.getId() == p_id)
           {
               reqd_product = &i;
               return reqd_product;
           } 
    }
    
   return reqd_product;
}

bool isProductIdValid (vector <product> list_of_products,int p_id)
{
    //FIXME:- SEARCH FOR PRODUCT WITH PRODUCT ID PASSED
    product *p = findByProductID(list_of_products,p_id);
    if(p->getId() == 00)
      return false;
    else 
      return true;
    
}
float calcSum (vector <product> cart)
{
    //FIXME:- CALCULATE TOTAL PRICE OF ALL PRODUCTS IN PRICE
    float sum=0;
    for (auto i : cart)
    {
        product *p = findByProductID(cart,i.getId());
        sum+=p->getCost();
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    vector <person> list_of_customers;
    
    vector <goldmember> gold_customers;
    vector <silvermember> silver_customers;
    vector <bronzemember> bronze_customers;
    
    vector <assistant> list_of_assistants;
    vector <cashier> list_of_cashiers;
    
    vector <product> list_of_products;
    vector <product> cart;
    
    vector <supplier> list_of_suppliers;
    
    cout << "Welcome to Vinayak Mart!" << endl;
    
    while (1)
    {
        cout << "1. Customer login\n2. Admin login" << endl;
        int ch;
        cin >> ch;
        
        
        if (ch == 2)
        {
            cout << "1. View transactions processed by each staff\n2. View all staffs' details\n3. Restock items" << endl;
            int ch;
            cin >> ch;
            
            switch (ch)
            {
                case 1:
                {
                    for (auto i : list_of_cashiers)
                        i.getTotalTxnsProcessed();
                    
                    break;
                }
                    
                case 2:
                {
                    for (auto i : list_of_cashiers)
                        i.printStaffDetails();
                    
                    break;
                }
                    
                case  3:
                {
                    cout << "Enter product ID of product to be restocked:";
                    int p_id;
                    
                    try
                    {
                        cin >> p_id;
                        
                        if (! isProductIdValid (list_of_products,p_id))
                            throw 404;
                        
                        int rand_supplier = rand() % list_of_suppliers.size();
                        
                        cout << "Your order will be serviced by " << list_of_suppliers.at(rand_supplier).getAgencyName() << endl;
                    }
                    
                    catch (...)
                    {
                        cout << "Invalid product ID, try again" << endl;
                    }
                }
            }
        }
        
        int IsValid = 1;
        auto ph_no = 0;
        
        while (IsValid)
        {
            cout << "1. New customer\n2. Existing customer" << endl;
            cin >> ch;
            
            if (ch == 1)
            {
                int ch;
                cout << "What membership tier would you like to avail?\n 1. Gold \n 2. Silver \n 3. Bronze" << endl;
                cin >> ch;
                
                try
                {
                    if (ch > 0 && ch < 4)
                    {
                        cout << "Enter your name:";
                        string name;
                        cin >> name;
                        
                        cout << "Enter your phone number:";
                        cin >> ph_no;
                        
                        cout << "Enter your address:";
                        string addr;
                        cin >> addr;
                        
                        switch (ch)
                        {
                            case 1:
                            {
                                gold_customers.push_back (goldmember (name, ph_no, addr));
                                IsValid = 0;
                                cout << "You're now a member!" << endl;
                                break;
                            }
                                
                            case 2:
                            {
                                silver_customers.push_back (silvermember (name, ph_no, addr));
                                IsValid = 0;
                                cout << "You're now a member!" << endl;
                                break;
                            }
                                
                            case 3:
                            {
                                bronze_customers.push_back (bronzemember (name, ph_no, addr));
                                IsValid = 0;
                                cout << "You're now a member!" << endl;
                                break;
                            }
                        }
                    }
                    
                    else
                    {
                        IsValid = 1;
                        throw 404;
                    }
                }
                
                catch (...)
                {
                    cout << "Invalid preference. Please try again." << endl;
                }
            }
            
            else if (ch == 2)
            {
                cout << "Enter your phone number:" << endl;
                cin >> ph_no;
                
                
                try
                {
                    auto person = findByPhNo (gold_customers, silver_customers, bronze_customers, ph_no);
                    
                    if (person->getName() == "invalid")
                    {
                        IsValid = 1;
                        throw 404;
                    }
                    
                    else
                        IsValid = 0;
                }
                catch (...)
                {
                    cout << "Invalid phone number, please try again." << endl;
                }
            }
            
            else
                cout << "You have selected an incorrect option, please try again." << endl;
        }
        
        
        auto curr_customer = findByPhNo(gold_customers, silver_customers, bronze_customers, ph_no);
        
        int cont = 1;
        
        while (cont)
        {
            cout << "What would you like to do next?" << endl;
            cout << "1. View product catalogue\n2. Add a product to cart\n3. Ask for assistance\n4. Head to billing\n 5. Get product details" << endl;
            cin >> ch;
            
            
            switch (ch)
            {
                case 1:
                {
                    cout << "Displaying all products in the store..." << endl;
                    
                    for (auto i: list_of_products)
                    {
                        i.printproductdetails();
                        cout << endl;
                    }
                    
                    cont = 1;
                    break;
                }
                    
                case 2:
                {
                    cout << "Enter product ID of the product you wish to add to cart:" << endl;
                    auto p_id = 0;
                    
                    try
                    {
                        cin >> p_id;
                        
                        if (! isProductIdValid (list_of_products,p_id))
                            throw 404;
                    }
                    
                    catch (...)
                    {
                        cout << "Invalid product ID, try again" << endl;
                    }
                    
                    auto product_to_be_added = *findByProductID(list_of_products, p_id);
                    cart.push_back(product_to_be_added);
                    
                    cont = 1;
                    
                    break;
                }
                    
                case 3:
                {
                    cout << "You've requested for assistance..." << endl;
                    auto rand_assistant = rand () % list_of_assistants.size();
                    
                    cout << "Mr. " << list_of_assistants.at(rand_assistant).getName() << "will assist you today" << endl;
                    cout << "He advices you to " << list_of_assistants.at(rand_assistant).getAdvice();
                    
                    cont = 1;
                    break;
                }
                    
                case 4:
                {
                    cout << "Heading to billing..." << endl;
                    
                    int random_cashier = rand () % list_of_cashiers.size();
                    cout << "Mr. " << list_of_cashiers.at(random_cashier).getName()<< " is at your service" << endl;
                    
                    auto amt_to_pay = calcSum (cart);
                    cout << "The amount to be paid is Rs. " << amt_to_pay << endl;
                    
                    try
                    {
                        
                        cout << "1. Pay bill\n2. Exit the store" << endl;
                        cin >> ch;
                        
                        if (ch != 1 && ch != 2)
                            throw 404;
                        
                        switch (ch)
                        {
                            case 1:
                            {
                                cout << "Bill paid successfully!" << endl;
                                cout << "Your transaction ID is " << transaction :: txn_id << endl;
                                
                                
                                for (auto i : cart)
                                    curr_customer->purchasedProducts (transaction :: txn_id, i.getId()); //FIXME:- ADD OPTION TO VIEW PAST PURCHASED PRODUCTS FOR A CUSTOMER
                                
                                cout << "You've earned " << curr_customer->convertToPoints(amt_to_pay) << " points for this txn!" << endl;
                                
                                list_of_cashiers.at(random_cashier).processedTxn();
                                
                                transaction :: getNextTxnId();
                                cont = 0;
                                break;
                            }
                                
                            case 2:
                            {
                                cout << "Please come again. Thank you." << endl;
                                cont = 0;
                                break;
                            }
                        }
                    }
                    
                    catch (...)
                    {
                        cout << "invalid choice. Try again" << endl;
                        cont = 1;
                    }
                    break;
                }
                    
                case 5:
                {
                    cout << "Enter product ID of the product you wish to get details of:" << endl;
                    auto p_id = 0;
                    
                    try
                    {
                        cin >> p_id;
                        
                        if (! isProductIdValid (list_of_products,p_id))
                            throw 404;
                    }
                    
                    catch (...)
                    {
                        cout << "Invalid product ID, try again" << endl;
                    }
                    
                    auto prod = findByProductID(list_of_products, p_id);
                    prod->printproductdetails();
                    
                    cont  = 1;
                    
                    break;
                }
            }
        }
    }
    }
