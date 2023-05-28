#include "customer_repository.h"

CustomerRepository::CustomerRepository(ORM& orm) : orm(orm);

std::vector<Customer> CustomerRepository::getAllCustomers()
{
    std::vector<Customer> customers;

    try
    {
        customers = orm.executeQuery<Customer>("SELECT * FROM customers");
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("Failed to retrieve customers from the database: " + std::string(ex.what()));
    }

    return customers;
}

Customer CustomerRepository::getCustomerByID(int customerID)
{
    try
    {
        Customer customer = orm.executeQuerySingle<Customer>("SELECT * FROM customers WHERE customer_id = ?", customerID);

        if (customer.isNull())
        {
            throw std::runtime_error("Customer not found with ID: " + std::to_string(customerID));
        }

        return customer;
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("Failed to retrieve customer from the database: " + std::string(ex.what()));
    }
}

bool CustomerRepository::save(const Customer& customer)
{
    try {
        orm->save(customer);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}

