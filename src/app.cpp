#include <iostream>
#include <string>

#include "services/customer_service.hpp"
#include "services/article_service.hpp"
#include "services/sales_invoice_service.hpp"

class SalesApplication {
private:
    CustomerService customerService;
    ArticleService articleService;
    SalesInvoiceService salesInvoiceService;

public:
    SalesApplication();

    void Run()
    {
        while (true)
        {
            DisplayMenu();

            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;
            std::cin.ignore();

            switch (choice)
            {
                case 1:
                    CreateCustomer();
                    break;
                case 2:
                    CreateArticle();
                    break;
                case 3:
                    CreateInvoice();
                    break;
                case 4:
                    return;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }

            std::cout << std::endl;
        }
    }

private:
    void DisplayMenu()
    {
        std::cout << "Sales Application Menu:" << std::endl;
        std::cout << "1. Create Customer" << std::endl;
        std::cout << "2. Create Article" << std::endl;
        std::cout << "3. Create Invoice" << std::endl;
        std::cout << "4. Exit" << std::endl;
    }

    void CreateCustomer()
    {
        std::cout << "Enter customer name (press Enter to skip): ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Enter customer email (press Enter to skip): ";
        std::string email;
        std::getline(std::cin, email);

        std::cout << "Enter customer address (press Enter to skip): ";
        std::string address;
        std::getline(std::cin, address);

        Customer customer(0, name, "", email, address);

        bool success = customerService.createCustomer(customer);

        if (success)
        {
            std::cout << "Customer created successfully." << std::endl;
        }
        else
        {
            std::cout << "Failed to create customer." << std::endl;
        }
    }

    void CreateArticle()
    {
        std::cout << "Enter article name (press Enter to skip): ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Enter article description (press Enter to skip): ";
        std::string description;
        std::getline(std::cin, description);

        std::cout << "Enter article price (press 0 to skip): ";
        double price;
        std::cin >> price;
        std::cin.ignore();

        std::cout << "Enter article quantity (press 0 to skip): ";
        int quantity;
        std::cin >> quantity;
        std::cin.ignore();

        std::cout << "Enter article category (press Enter to skip): ";
        std::string category;
        std::getline(std::cin, category);

        std::cout << "Enter article supplier (press Enter to skip): ";
        std::string supplier;
        std::getline(std::cin, supplier);

        Article article(0, name, description, price, quantity, category, supplier);

        bool success = articleService.createArticle(article);

        if (success)
        {
            std::cout << "Article created successfully." << std::endl;
        }
        else
        {
            std::cout << "Failed to create article." << std::endl;
        }
    }

    void CreateInvoice()
{
    std::cout << "Enter customer ID: ";
    int customerId;
    std::cin >> customerId;
    std::cin.ignore();

    std::cout << "Enter article ID: ";
    int articleId;
    std::cin >> articleId;
    std::cin.ignore();

    Customer customer = customerService.getCustomerById(customerId);
    Article article = articleService.getArticleById(articleId);

    if (customer.getCustomerID() == 0)
    {
        std::cout << "Customer not found." << std::endl;
        return;
    }

    if (article.getArticleID() == 0)
    {
        std::cout << "Article not found." << std::endl;
        return;
    }

    SalesInvoice salesInvoice(0, article, customer);

    bool success = salesInvoiceService.createSalesInvoice(salesInvoice);

    if (success)
    {
        std::cout << "Invoice created successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to create invoice." << std::endl;
    }
}

};
