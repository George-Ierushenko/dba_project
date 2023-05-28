#pragma once

#include <vector>
#include <string>
#include "models/article.h"
#include "orm.h"

class ArticleRepository
{
public:
    ArticleRepository(ORM& orm);

    std::vector<Article> getAllArticles();

    Article getArticleByID(int articleID);

    bool save(const Article& customer);

private:
    ORM& orm;
};
