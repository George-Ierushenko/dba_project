#pragma once

#include <odb/core.hxx>
#include <string>

class Article
{
public:
    Article(int id, const std::string& name, const std::string& description,
            double price, int quantity, const std::string& category, const std::string& supplier);

    int getArticleID() const;
    const std::string& getArticleName() const;
    const std::string& getDescription() const;
    double getPrice() const;
    int getQuantity() const;
    const std::string& getCategory() const;
    const std::string& getSupplier() const;

private:
    #pragma db id
    int id;

    #pragma db column("name")
    std::string name;

    #pragma db column("description")
    std::string description;

    #pragma db column("price")
    double price;

    #pragma db column("quantity")
    int quantity;

    #pragma db column("category")
    std::string category;

    #pragma db column("supplier")
    std::string supplier;
};
