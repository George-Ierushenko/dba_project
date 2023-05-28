#include "repositories/articles.hpp"

ArticleService::ArticleService()
    : articleRepository(WabDatabaseConnection::get_connection());

bool ArticleService::createArticle(const Article& article)
{
    return articleRepository.save(article);
}

bool ArticleService::updateArticle(const Article& article)
{
    return articleRepository.save(article);
}

Article ArticleService::getArticleById(int articleId)
{
    return articleRepository.getById(articleId);
}

std::vector<Article> ArticleService::getAllArticles()
{
    return articleRepository.getAll();
}
