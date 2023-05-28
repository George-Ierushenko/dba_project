#include "article_repository.h"

ArticleRepository::ArticleRepository(ORM& orm) : orm(orm);

std::vector<Article> ArticleRepository::getAllArticles()
{
    std::vector<Article> articles;

    try
    {
        articles = orm.executeQuery<Article>("SELECT * FROM articles");
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("Failed to retrieve articles from the database: " + std::string(ex.what()));
    }

    return articles;
}

Article ArticleRepository::getArticleByID(int articleID)
{
    try
    {
        Article article = orm.executeQuerySingle<Article>("SELECT * FROM articles WHERE article_id = ?", articleID);

        if (article.isNull())
        {
            throw std::runtime_error("Article not found with ID: " + std::to_string(articleID));
        }

        return article;
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("Failed to retrieve article from the database: " + std::string(ex.what()));
    }
}

bool ArticleRepository::save(const Article& article)
{
    try {
        orm->save(article);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}
