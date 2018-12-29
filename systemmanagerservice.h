#ifndef SYSTEMMANAGERSERVICE_H
#define SYSTEMMANAGERSERVICE_H

#include <QObject>

class SystemManagerService : public QObject
{
    Q_OBJECT
public:
    explicit SystemManagerService(QObject *parent = 0);

signals:

public slots:
    bool auth(const QString &username, const QString &password);
    bool connect(const QString &interface);
    qulonglong status(const QString &interface);
};

#endif // SYSTEMMANAGERSERVICE_H
