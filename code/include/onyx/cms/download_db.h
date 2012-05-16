// Author: John

#ifndef CMS_DOWNLOAD_DB_H_
#define CMS_DOWNLOAD_DB_H_

#include <QtCore/QtCore>
#include <QtSql/QtSql>
#include "onyx/base/base.h"
#include "onyx/data/data.h"

namespace cms
{

enum DownloadState
{
    STATE_INVALID = -1,
    DOWNLOADING,
    FINISHED,       ///< Finished but not read.
    FAILED,         ///< Don't ever download it again.
    PENDING,        ///< Download next time.
    FINISHED_READ,  ///< Download finished and has been read.
};

class DownloadItemInfo : public OData
{
public:
    explicit DownloadItemInfo(const QVariantMap & vm = QVariantMap());
    ~DownloadItemInfo();

    bool operator == (const DownloadItemInfo &right);

    QString url() const;
    void setUrl(const QString & url);

    QString path() const;
    void setPath(const QString & path);

    int size() const;
    void setSize(int size);

    DownloadState state() const;
    void setState(DownloadState state);

    QString speed() const;
    void setSpeed(const QString & speed);

    int received() const;
    void setReceived(int size);

    QString timeStamp() const;
    void setTimeStamp(const QString & timeStamp);
};

typedef QVector<DownloadItemInfo> DownloadInfoList;

struct LessByUrl
{
    bool operator()( const DownloadItemInfo & a, const DownloadItemInfo & b ) const
    {
        return (a.url().compare(b.url(), Qt::CaseInsensitive) < 0);
    }
};

struct GreaterByUrl
{
    bool operator()( const DownloadItemInfo & a, const DownloadItemInfo & b ) const
    {
        return (a.url().compare(b.url(), Qt::CaseInsensitive) > 0);
    }
};

struct LessByTimestamp
{
    bool operator()( const DownloadItemInfo & a, const DownloadItemInfo & b ) const
    {
        return (a.timeStamp().compare(b.timeStamp(), Qt::CaseInsensitive) < 0);
    }
};

struct GreaterByTimestamp
{
    bool operator()( const DownloadItemInfo & a, const DownloadItemInfo & b ) const
    {
        return (a.timeStamp().compare(b.timeStamp(), Qt::CaseInsensitive) > 0);
    }
};

class DownloadDB
{
public:
    DownloadDB(const QString & db_name = "download.db");
    ~DownloadDB();

public:
    bool open();
    bool close();

    DownloadInfoList pendingList(const DownloadInfoList & input = DownloadInfoList(),
                             bool force_all = false,
                             bool sort = true);

    bool update(const DownloadItemInfo & item);
    bool updateState(const QString & url, DownloadState state = FINISHED);
    bool remove(const QString & url);

    QStringList list(DownloadState state = FINISHED);
    DownloadInfoList all(DownloadState state = STATE_INVALID);

    int  itemCount(DownloadState state = FINISHED);
    bool markAsRead(const QString & path, DownloadState state = FINISHED_READ);
    void markAllAsRead(DownloadState state = FINISHED_READ);
    QString getPathByUrl(const QString & url);

private:
    bool makeSureTableExist(QSqlDatabase &db);
    QSqlDatabase & db();

private:
    scoped_ptr<QSqlDatabase> database_;

    const QString database_name_;

};


}  // namespace cms

#endif  // CMS_DOWNLOAD_DB_H_
