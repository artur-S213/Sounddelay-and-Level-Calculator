#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "controller.h"
// #include "CoreCalculations.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

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
  engine.loadFromModule("AcousticUI", "AICode2");

  return app.exec();
}
