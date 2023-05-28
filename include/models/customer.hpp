#pragma once

#include <odb/core.hxx>
#include <string>

class Customer
{
public:
    Customer(int id, const std::string& firstName, const std::string& lastName,
             const std::string& email, const std::string& address);

    int getCustomerID() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getEmail() const;
    const std::string& getAddress() const;

private:
    #pragma db id
    int id;
git init

    #pragma db column("first_name")
    std::string firstName;

    #pragma db column("last_name")
    std::string lastName;

    #pragma db column("email")
    std::string email;

    #pragma db column("address")
    std::string address;
};
