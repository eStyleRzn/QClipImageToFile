#include "LineEdit.h"

#include <QClipboard>
#include <QMimeData>
#include <QDateTime>
#include <QGuiApplication>

#include "TemporaryImageFile.h"
#include "ImageSendDialog.h"

//======================================================================================================================
LineEdit::LineEdit(QWidget* parent)
  : _Base(parent)
{
}

//----------------------------------------------------------------------------------------------------------------------
LineEdit::~LineEdit()
{

}

//----------------------------------------------------------------------------------------------------------------------
void LineEdit::insertFromMimeData(const QMimeData* source)
{
  if (source->hasImage())
  {
    ImageType img = qvariant_cast<ImageType>(source->imageData());
    if (img.isNull())
      return;

    ImageSendDialog dlg(QPixmap::fromImage(img), this);

    if (QDialog::Accepted == dlg.exec())
    {
      saveImage(img);
    }

    return;
  }

  return _Base::insertFromMimeData(source);
}

////----------------------------------------------------------------------------------------------------------------------
//bool LineEdit::pasteData()
//{
//  QClipboard* clipboard = QGuiApplication::clipboard();
//  ImageType img = clipboard->image();

//  if (img.isNull())
//    return false;

//  return saveImage(img);
//}

//----------------------------------------------------------------------------------------------------------------------
void LineEdit::saveImage(const LineEdit::ImageType& img)
{
  static const QString ext = "PNG";

  // Set background image
  tempImageFile_.reset(new TemporaryImageFile(ext.toLower()));
  if (tempImageFile_->open())
  {
    auto dummy = tempImageFile_->fileName();
    if (img.save(tempImageFile_->fileName(), "PNG"))
    {
      tempImageFile_->close();
      emit imagePasted(tempImageFile_->fileName());
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
QString LineEdit::makeFileName() const
{
  static const QString timeFormat = "yy-MM-dd_HH-mm-ss";

  auto fileName = "pic_" + QDateTime::currentDateTime().toString(timeFormat) + ".XXXXX";

  // RVO ?
  return fileName;
}
