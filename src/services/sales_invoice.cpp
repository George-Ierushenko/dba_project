#include "services/sales_invoice.hpp"

SalesInvoiceService::SalesInvoiceService()
    : salesInvoiceRepository(WabDatabaseConnection::get_connection());

bool SalesInvoiceService::createSalesInvoice(const SalesInvoice& salesInvoice)
{
    return salesInvoiceRepository.save(salesInvoice);
}

bool SalesInvoiceService::updateSalesInvoice(const SalesInvoice& salesInvoice)
{
    return salesInvoiceRepository.save(salesInvoice);
}

SalesInvoice SalesInvoiceService::getSalesInvoiceById(int salesInvoiceId)
{
    return salesInvoiceRepository.getById(salesInvoiceId);
}

std::vector<SalesInvoice> SalesInvoiceService::getAllSalesInvoices()
{
    return salesInvoiceRepository.getAll();
}
