#include "systemmanagerservice.h"

SystemManagerService::SystemManagerService(QObject *parent) : QObject(parent)
{

}

bool SystemManagerService::auth(const QString &username, const QString &password)
{
    return true;
}

bool SystemManagerService::connect(const QString &interface)
{
    return true;
}

qulonglong SystemManagerService::status(const QString &interface)
{
    return (qulonglong)1234;
}
