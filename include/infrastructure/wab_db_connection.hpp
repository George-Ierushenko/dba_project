#pragma once

#include "orm.h"

class WabDatabaseConnection {
private:
    static ORM m_connection;
    static void init_connection();

public:
    static ORM* get_connection();
};
