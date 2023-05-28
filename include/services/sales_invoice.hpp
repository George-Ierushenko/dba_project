#pragma once

#include "repositories/sales_invoice.hpp"
#include "infrastructure/wab_db_connection.hpp"

class SalesInvoiceService {
private:
    SalesInvoiceRepository salesInvoiceRepository;

public:
    SalesInvoiceService();

    bool createSalesInvoice(const SalesInvoice& salesInvoice);
    bool updateSalesInvoice(const SalesInvoice& salesInvoice);
    bool deleteSalesInvoice(int salesInvoiceId);
    SalesInvoice getSalesInvoiceById(int salesInvoiceId);
    std::vector<SalesInvoice> getAllSalesInvoices();
};
