#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QObject>
#include <QDebug>
#include <QCryptographicHash>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantList>

#include "simplecrypt.h"

enum class SearchResultType {
    DB = 0,
    SoundCloud = 1,
    Spotify = 2
};

class SearchResult : public QObject
{
    Q_OBJECT
public:
    explicit SearchResult(QString query, QObject *parent = 0);
    ~SearchResult();
    bool SEARCH_COMPLETE = false;

    QString query;

    QJsonObject* getSearchResults();
signals:
    void searchProcessingComplete();

private:
    bool SPOTIFY_COMPLETE = false;
    bool SOUNDCLOUD_COMPLETE = false;
    bool DB_COMPLETE = false;
    SimpleCrypt *crypto;

    QJsonArray *dbRes;
    QJsonArray *scRes;
    QJsonArray *spotifyRes;

    QJsonObject fullResult;

    QJsonArray resultsList;

    void constructFullResult();
    void insertObjectsIntoResults(QJsonArray *arr, SearchResultType type);

public slots:
    void onSpotifySearchComplete(QJsonArray *obj);
    void onSoundcloudSearchComplete(QJsonArray *obj);
    void onDbSearchComplete(QJsonArray *obj);
};

#endif // SEARCHRESULT_H