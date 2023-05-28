#pragma once

#include <odb/core.hxx>
#include "article.h"
#include "customer.h"

class SalesInvoice
{
public:
    SalesInvoice(int id, const Article& article, const Customer& customer);

    int getInvoiceID() const;
    const Article& getArticle() const;
    const Customer& getCustomer() const;

private:
    #pragma db id
    int id;

    #pragma db column("article_id")
    #pragma db not_null
    #pragma db foreign_key("fk_invoice_article")
    Article article;

    #pragma db column("customer_id")
    #pragma db not_null
    #pragma db foreign_key("fk_invoice_customer")
    Customer customer;
};
