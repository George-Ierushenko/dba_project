#pragma once

#include "models/sales_invoice.h"
#include "orm.h"

class SalesInvoiceRepository {

public:
    explicit SalesInvoiceRepository(ORM* orm);

    std::vector<SalesInvoice> getAll();

    SalesInvoice getInvoiceById(int id);

    bool save(const SalesInvoice& salesInvoice);

private:
    ORM* orm;
};
