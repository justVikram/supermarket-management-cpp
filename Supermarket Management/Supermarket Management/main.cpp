#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <unistd.h>

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
    
    int showPoints ()
    {
        return membership_pts.getpoints();
    }
    
};

class goldmember : public customer
{
public:
    goldmember () {}
    
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
    
    silvermember () {}
    
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
    
    bronzemember () {}
    
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
        cout<<"Name: "<<name<<endl;
        cout<<"phoneNo: "<<phNo<<endl;
        cout<<"address: "<<addr<<endl;
        cout<<"aadharNumber: "<<aadharNo<<endl;
        cout<<"salary: "<<salary<<endl;
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
    
    cashier (string name,int phNo,string addr,int aadharNo,float salary,date join_date) :
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
        cout<<"Product Id:"<<id<<endl;
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
    
    void setQuantityPurchased (int NewQty)
    {
        quantity = NewQty;
    }
    
    void decreaseQuantity (int qty)
    {
        quantity -= qty;
    }
    
    void restockProduct (int qty)
    {
        quantity += qty;
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
    
    inventory (vector <product> List_of_products)
    {
        products_available = List_of_products;
    }
    
    void viewInventory ()
    {
        for (auto i : products_available)
        {
            i.printproductdetails();
            cout << endl;
        }
    }
    
    void removeFromInventory (vector <product> cart)
    {
        for (auto i : cart)
        {
            for (auto j : products_available)
            {
                if (j.getId() == i.getId())
                    j.decreaseQuantity(i.getQuantity());
            }
        }
    }
    
    void initInventory (vector <product> list_of_products)
    {
        products_available = list_of_products;
    }
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
            *reqd_customer = i;
    }
    
    for (auto i : silver_person)
    {
        if (i.getPhoneNo() == ph_no)
            *reqd_customer = i;
    }
    
    for (auto i : bronze_person)
    {
        if (i.getPhoneNo() == ph_no)
            *reqd_customer = i;
    }
    
    return reqd_customer;
}

product * findByProductID (vector <product> list_of_products, int p_id)
{
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
    product p = *findByProductID(list_of_products,p_id);
    
    if(p.getId() == 00)
        return false;
    else
        return true;
    
}
int calcSum (vector <product> cart)
{
    int sum=0;
    for (auto i : cart)
    {
        product p = *findByProductID(cart,i.getId());
        sum += (p.getCost() * p.getQuantity());
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    vector <customer> list_of_customers;
    
    vector <goldmember> gold_customers;
    vector <silvermember> silver_customers;
    vector <bronzemember> bronze_customers;
    
    vector <assistant> list_of_assistants;
    vector <cashier> list_of_cashiers;
    
    vector <product> list_of_products;
    vector <product> cart;
    
    vector <supplier> list_of_suppliers;
    
    int amt_to_pay = 0;
    customer * current_customer = new customer;
    
    list_of_products.push_back(product("noodles",100,"maggi",11,50));
    list_of_products.push_back(product("biscuits",10,"oreo",12,45));
    list_of_products.push_back(product("washingPowder",65,"nirma",13,30));
    list_of_products.push_back(product("chocolates",5,"perk",14,76));
    list_of_products.push_back(product("cheese",60,"amul",15,24));
    list_of_products.push_back(product("hairdye",15,"garnier",16,37));
    list_of_products.push_back(product("shampoo",75,"johnson",17,13));
    list_of_products.push_back(product("coughSyrup",90,"dabur",18,17));
    list_of_products.push_back(product("pillow",100,"sleepwell",19,23));
    list_of_products.push_back(product("vermicilli",55,"bambino",20,24));
    
    date jd1(02,05,2019);
    date jd2(04,06,2020);
    date jd3(02,03,2019);
    date jd4(02,07,2018);
    date jd5(03,01,2020);
    
    list_of_cashiers.push_back(cashier("amal",83838391,"vidyanagar",473838282,10000,jd1));
    list_of_cashiers.push_back(cashier("krunal",98838282,"gokulnagar",466363621,12000,jd2));
    list_of_cashiers.push_back(cashier("preety",83839292,"dharwad",234657728,11000,jd3));
    list_of_cashiers.push_back(cashier("dev",92983821,"stationRoad",1248584883,10000,jd4));
    list_of_cashiers.push_back(cashier("akansha",92338111,"gokulroad",576855939,12000,jd5));
    
    list_of_suppliers.push_back(supplier("jai trading company"));
    list_of_suppliers.push_back(supplier("global food company"));
    list_of_suppliers.push_back(supplier("dayanand and co"));
    list_of_suppliers.push_back(supplier("organic products india"));
    list_of_suppliers.push_back(supplier("snacksLTD"));
    
    list_of_assistants.push_back(assistant("we have 30% discount today!\n","riddhi",98383902,"dharwad",337372772,13000,jd2));
    list_of_assistants.push_back(assistant("should check our new snacks!\n","raaj",93838211,"vidyanagar",939392920,12000,jd3));
    list_of_assistants.push_back(assistant("we are selling at buy one get one!\n","aryan",89383828,"vidyanagar",483838212,10000,jd4));
    list_of_assistants.push_back(assistant("we are back with incredible offers!\n","aditi",89473727,"gokulroad",348499283,12000,jd1));
    list_of_assistants.push_back(assistant("unbelievable rates today!\n","vishal",798883721,"stationroad",384636261,11000,jd5));
    
    inventory the_inventory (list_of_products);
    
    cout << "Welcome to Vinayak Mart!" << endl;
    
    cout << "1. Customer login\n2. Admin login" << endl;
    int ch;
    cin >> ch;
    
    
    if (ch == 2)
    {
        while (1)
        {
            cout << "1. View transactions processed by each staff\n2. View all staffs' details\n3. Restock items\n4. View Inventory\n5. Exit" << endl << endl;
            int ch;
            cin >> ch;
            
            switch (ch)
            {
                case 1:
                {
                    for (auto i : list_of_cashiers)
                        cout << i.getTotalTxnsProcessed() << endl;
                    
                    break;
                }
                    
                case 2:
                {
                    for (auto i : list_of_cashiers)
                    {
                        i.printStaffDetails();
                        cout << endl;
                    }
                    
                    for (auto i : list_of_assistants)
                    {
                        i.printStaffDetails();
                        cout << endl;
                    }
                    
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
                        
                        int qty_to_order;
                        int old_qty = list_of_products.at(p_id - 11).getQuantity();
                        cout << "Enter quantity:";
                        cin >> qty_to_order;
                        
                        int rand_supplier = rand() % list_of_suppliers.size();
                        
                        cout << "Your order will be serviced by " << list_of_suppliers.at(rand_supplier).getAgencyName() << endl;
                        list_of_products.at(p_id - 11).restockProduct(qty_to_order);
                        int new_qty = list_of_products.at(p_id - 11).getQuantity();
                        
                        usleep(2000000);
                        
                        cout << "Receiving order... RESTOCKED!" << endl;
                        
                        usleep (2000000);
                        
                        cout << "Old quantity = " << old_qty <<"\nNew Quantity = "<< new_qty << endl << endl;
                        
                        the_inventory.initInventory(list_of_products);
                    }
                    
                    catch (...)
                    {
                        cout << "Invalid product ID, try again" << endl;
                    }
                    
                    break;
                }
                    
                case 4:
                {
                    the_inventory.viewInventory();
                        
                    break;
                }
                    
                case 5:
                {
                    cout << "Exiting... thank you" << endl;
                    exit (0);
                }
            }
        }
    }
    
    int IsValid = 1;
    auto ph_no = 0;
    
    goldmember newgoldmember;
    silvermember newsilvermember;
    bronzemember newbronzemember;
    
    while (IsValid)
    {
        cout << "1. New customer\n2. Existing customer" << endl;
        cin >> ch;
        
        if (ch == 1)
        {
            int ch;
            cout << "What membership tier would you like to purchase?\n 1. Gold - Rs 200\n 2. Silver - Rs 100 \n 3. Bronze - Rs 50" << endl;
            cin >> ch;
            
            try
            {
                if (ch > 0 && ch < 4)
                {
                    IsValid = 0;
                    
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
                            newgoldmember = goldmember(name, ph_no, addr);
                            gold_customers.push_back (newgoldmember);
                            current_customer = &newgoldmember;
                            cout << "You're now a member!" << endl << endl;
                            
                            amt_to_pay += 200;
                            
                            break;
                        }
                            
                        case 2:
                        {
                            newsilvermember = silvermember (name, ph_no, addr);
                            silver_customers.push_back (newsilvermember);
                            current_customer = &newsilvermember;
                            cout << "You're now a member!" << endl << endl;
                            amt_to_pay += 100;
                            
                            break;
                        }
                            
                        case 3:
                        {
                            newbronzemember = bronzemember (name, ph_no, addr);
                            bronze_customers.push_back (newbronzemember);
                            current_customer = &newbronzemember;
                            cout << "You're now a member!" << endl << endl;
                            
                            amt_to_pay += 50;
                            
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
    
    int cont = 1;
    
    cout << "What would you like to do next?" << endl;
    
    while (cont)
    {
        cout << "1. View product catalogue\n2. Add a product to cart\n3. Ask for assistance\n4. Head to billing\n5. Get product details\n6. View cart" << endl;
        cin >> ch;
        
        switch (ch)
        {
            case 1:
            {
                cout << "Displaying all products in the store..." << endl << endl;
                
                for (auto i : list_of_products)
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
                int qty = 0;
                
                try
                {
                    cin >> p_id;
                    
                    if (! isProductIdValid (list_of_products,p_id))
                        throw 404;
                    
                    if (findByProductID(list_of_products, p_id))
                    
                    cout << "Enter quantity:";
                    cin >> qty;
                }
                
                catch (...)
                {
                    cout << "Invalid product ID, try again" << endl;
                }
                
                auto product_to_be_added = *findByProductID(list_of_products, p_id);
                product_to_be_added.setQuantityPurchased(qty);
                cart.push_back(product_to_be_added);
                
                cont = 1;
                
                break;
            }
                
            case 3:
            {
                cout << "You've requested for assistance..." << endl;
                auto rand_assistant = rand () % list_of_assistants.size();
                
                cout << list_of_assistants.at(rand_assistant).getName() << " will assist you today." << endl;
                cout << "Their advice: " << list_of_assistants.at(rand_assistant).getAdvice() << endl;
                
                cont = 1;
                break;
            }
                
            case 4:
            {
                cout << "Heading to billing..." << endl;
                
                int random_cashier = rand () % list_of_cashiers.size();
                cout << list_of_cashiers.at(random_cashier).getName()<< " is at your service" << endl;
                
                amt_to_pay += calcSum (cart);
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
                                current_customer->purchasedProducts (transaction :: txn_id, i.getId());
                            
                            cout << "You've earned " << current_customer->convertToPoints(amt_to_pay) << " points for this txn!" << endl;
                            
                            current_customer->calcPoints(amt_to_pay);
                            list_of_customers.push_back(*current_customer);
                            
                            list_of_cashiers.at(random_cashier).processedTxn();
                            transaction :: getNextTxnId();
                            
                            the_inventory.removeFromInventory(cart);
                            
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
                cout << "Enter product ID of the product you wish to get details of:";
                auto p_id = 0;
                
                try
                {
                    cin >> p_id;
                    
                    if (! isProductIdValid (list_of_products,p_id))
                        throw 404;
                }
                
                catch (...)
                {
                    cout << "Invalid product ID, try again" << endl << endl;
                }
                
                auto prod = *findByProductID(list_of_products, p_id);
                prod.printproductdetails();
                
                cont  = 1;
                
                break;
            }
                
            case 6:
            {
                cout << "Showing contents of your cart..." << endl << endl;
                
                for (auto i : cart)
                {
                    i.printproductdetails();
                    cout << endl;
                }
                
                cout << endl;
                
                break;
            }
        }
    }
}
