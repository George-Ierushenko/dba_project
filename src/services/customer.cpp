#include "services/customer.hpp"

CustomerService::CustomerService()
    : customerRepository(WabDatabaseConnection::get_connection());

bool CustomerService::createCustomer(const Customer& customer)
{
    return customerRepository.save(customer);
}

bool CustomerService::updateCustomer(const Customer& customer)
{
    return customerRepository.save(customer);
}

Customer CustomerService::getCustomerById(int customerId)
{
    return customerRepository.getById(customerId);
}

std::vector<Customer> CustomerService::getAllCustomers()
{
    return customerRepository.getAll();
}