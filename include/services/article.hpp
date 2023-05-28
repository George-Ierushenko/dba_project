#pragma once

#include "repositories/sales_invoice.hpp"
#include "infrastructure/wab_db_connection.hpp"

class ArticleService {
private:
    ArticleRepository articleRepository;

public:
    ArticleService();

    bool createArticle(const Article& article);
    bool updateArticle(const Article& article);
    bool deleteArticle(int articleId);
    Article getArticleById(int articleId);
    std::vector<Article> getAllArticles();
};
