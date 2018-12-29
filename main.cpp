#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QDebug>
#include "network_adapter.h"
#include "user_adapter.h"
#include "systemmanagerservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SystemManagerService *service = new SystemManagerService;

    new UserInterfaceAdapter(service);
    new NetworkInterfaceAdapter(service);

    //注册服务名
    QDBusConnection connection = QDBusConnection::systemBus();
    qDebug() << "system bus connected";
    if(!connection.registerService("org.freedesktop.SystemManager")){
        qDebug() << "Failed to register dbus service: " <<connection.lastError();
        a.exit(1);
        return 1;
    }

    qDebug() << "dbus service registered";

    if (!connection.registerObject("/", service)) {
        qDebug() << "Failed to register /filectrl object: " << connection.lastError();
        a.exit(1);
    }

    qDebug() << "dbus object registered";


    return a.exec();
}
