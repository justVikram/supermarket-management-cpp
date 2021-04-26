#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/// Abstract Class
class PERSON
{
private:
    int a;

public:
};

class CUSTOMER : public PERSON
{
private:
public:
};

class STAFF : public PERSON
{
private:
public:
};

class SUPPLIER : public PERSON
{
private:
public:
};

/// Abstract Class
class PRODUCT
{
private:
public:
};

class PROCURED_PRODUCT : public PRODUCT
{
private:
public:
};

/// Aggregation between INVENTORY & PRODUCT's derived classes
class INVENTORY
{
private:
public:
};

/// Aggregation between PROCUREMENT & SUPPLIER
class PROCUREMENT
{
private:
public:
};

/// Aggregation between MEMBERSHIP & CUSTOMER
class MEMBERSHIP
{
private:
public:
};

/// Aggregation between STORE & Staff
class STORE
{
private:
public:
};

int main(int argc, const char *argv[])
{
}
