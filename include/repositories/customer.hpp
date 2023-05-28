#pragma once

#include <vector>
#include <string>
#include "models/customer.h"
#include "orm.h"

class CustomerRepository
{
public:
    CustomerRepository(ORM& orm);

    std::vector<Customer> getAllCustomers();

    Customer getCustomerByID(int customerID);

    bool save(const Customer& customer);

private:
    ORM& orm;
};
