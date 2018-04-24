#ifndef TEMPORARYIMAGEFILE_H
#define TEMPORARYIMAGEFILE_H

#include <QFile>

//======================================================================================================================
// TODO Place class description here
class TemporaryImageFile : protected QFile
{
  using _Base = QFile;
public:
  TemporaryImageFile(const QString ext, QObject* parent = nullptr);
  virtual ~TemporaryImageFile();

  bool open();
  void close();

  QString fileName();

private:
  // Disable copying
  TemporaryImageFile(const TemporaryImageFile&) = delete;
  TemporaryImageFile& operator=(const TemporaryImageFile&) = delete;

  QString makeFileName() const;

  QString ext_;
};

#endif // TEMPORARYIMAGEFILE_H
