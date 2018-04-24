#include "TemporaryImageFile.h"

#include <QDir>
#include <QDateTime>

//======================================================================================================================
TemporaryImageFile::TemporaryImageFile(const QString ext, QObject* parent)
  : _Base(parent)
  , ext_(ext)
{
}

//----------------------------------------------------------------------------------------------------------------------
TemporaryImageFile::~TemporaryImageFile()
{
  remove();
}

//----------------------------------------------------------------------------------------------------------------------
bool TemporaryImageFile::open()
{
  QString fileName = makeFileName();
  const QString ext = ext_.isEmpty() ? "" : "." + ext_;
  QString result = fileName + ext;

  for (quint8 cnt = 1; QFile::exists(result); ++cnt)
  {
    QString placeHolder = "(";
    placeHolder += QString::number(cnt);
    placeHolder += ")";

    result = fileName + placeHolder + ext;
  }

  _Base::setFileName(result);
  return _Base::open(QIODevice::ReadWrite);
}

//----------------------------------------------------------------------------------------------------------------------
void TemporaryImageFile::close()
{
  _Base::close();
}
//----------------------------------------------------------------------------------------------------------------------
QString TemporaryImageFile::fileName()
{
  return _Base::fileName();
}
//----------------------------------------------------------------------------------------------------------------------
QString TemporaryImageFile::makeFileName() const
{
  static const QString timeFormat = "yy-MM-dd_HH-mm-ss";

  auto fileName = QDir::tempPath() + "/pic_" + QDateTime::currentDateTime().toString(timeFormat);

  // RVO ?
  return fileName;
}

