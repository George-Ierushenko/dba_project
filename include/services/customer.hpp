#pragma once

#include "../repositories/customer.hpp"
#include "../infrastructure/wab_db_connection.hpp"

class CustomerService {
private:
    CustomerRepository customerRepository;

public:
    CustomerService();

    bool createCustomer(const Customer& customer);
    bool updateCustomer(const Customer& customer);
    Customer getCustomerById(int customerId);
    std::vector<Customer> getAllCustomers();
};
