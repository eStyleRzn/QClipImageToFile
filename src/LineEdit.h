#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QTextEdit>
#include <QScopedPointer>

class TemporaryImageFile;
class QImage;

//======================================================================================================================
// TODO Place class description here
class LineEdit : public QTextEdit
{
  using _Base = QTextEdit;
  using ImageType = QImage;
  Q_OBJECT
public:
  LineEdit(QWidget* parent);
  virtual ~LineEdit();

signals:
  void imagePasted(const QString&);

protected:
  virtual void insertFromMimeData(const QMimeData *source) override;

private:
//  bool pasteData();
  void saveImage(const ImageType&);
  QString makeFileName() const;


private:
  // Disable copying
  LineEdit(const LineEdit&) = delete;
  LineEdit& operator=(const LineEdit&) = delete;

  QScopedPointer<TemporaryImageFile> tempImageFile_;
};


#endif // LINEEDIT_H
