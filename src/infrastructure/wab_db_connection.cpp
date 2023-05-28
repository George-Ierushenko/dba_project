#include "infrastructure/wab_db_connection.hpp"

void WabDatabaseConnection::init_connection()
{
    std::string server = std::getenv("DB_SERVER");
    std::string user = std::getenv("DB_USER");
    std::string password = std::getenv("DB_PASSWORD");
    std::string port = std::getenv("DB_PORT");

    std::string connectionString = "Driver={SQL Server}";
    connectionString += ";Server=" + server;
    connectionString += ";User=" + user;
    connectionString += ";Password=" + password;
    connectionString += ";Port=" + port;

    m_connection = ORM(connectionString);
}

ORM* WabDatabaseConnection::get_connection()
{
    if (!m_connection.is_connected()) {
        init_connection();
    }

    return &m_connection;
}
