#include "repositories/sales_invoice.hpp"

SalesInvoiceRepository::SalesInvoiceRepository(ORM& orm) : orm(orm);

std::vector<SalesInvoice> SalesInvoiceRepository::getAllSalesInvoices()
{
    std::vector<SalesInvoice> SalesInvoices;

    try
    {
        SalesInvoices = orm.executeQuery<SalesInvoice>("SELECT * FROM SalesInvoices");
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("Failed to retrieve SalesInvoices from the database: " + std::string(ex.what()));
    }

    return SalesInvoices;
}

SalesInvoice SalesInvoiceRepository::getSalesInvoiceByID(int SalesInvoiceID)
{
    try
    {
        SalesInvoice SalesInvoice = orm.executeQuerySingle<SalesInvoice>("SELECT * FROM SalesInvoices WHERE id = ?", SalesInvoiceID);

        if (SalesInvoice.isNull())
        {
            throw std::runtime_error("SalesInvoice not found with ID: " + std::to_string(SalesInvoiceID));
        }

        return SalesInvoice;
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("Failed to retrieve SalesInvoice from the database: " + std::string(ex.what()));
    }
}

bool SalesInvoiceRepository::save(const SalesInvoice& SalesInvoice)
{
    try {
        orm->save(SalesInvoice);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}
