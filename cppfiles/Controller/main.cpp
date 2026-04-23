#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "controller.h"
// #include <QIcon>  // show icon at the upper left window corner

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  // app.setWindowIcon(QIcon(":/icons/icon.png"));

  QQmlApplicationEngine engine;
  QObject::connect(
      &engine,
      &QQmlApplicationEngine::objectCreationFailed,
      &app,
      []()
      { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);
  qDebug() << "QML Import Paths:" << engine.importPathList();

  engine.addImportPath(QCoreApplication::applicationDirPath() + "/../../qml");
  engine.loadFromModule("AcousticUI", "Main");

  return app.exec();
}
